#include "PluggableUSBHID.h"
#include "USBKeyboard.h"
#include "keycodes.h"
#include "definitions.h"

/**** CONFIGURATION ****/

// Run each scan loop only once every X milliseconds.
// Useful for debouncing.
#define LOOP_INTERVAL_MS 1000

// Mapping of onboard IO pins to actions (which key to press and when to press it).
// For each pin, you can specify what key to send when the pin level rises or falls.
#define PIN_KEY_MAP_SIZE 8
PinKeyMap pin_key_map[PIN_KEY_MAP_SIZE] = {
        {p0, KEY_F13, ACTIVATE_WHEN_RISE},
        {p0, KEY_F14, ACTIVATE_WHEN_FALL},
        {p1, KEY_F15, ACTIVATE_WHEN_RISE},
        {p1, KEY_F16, ACTIVATE_WHEN_FALL},
        {p2, KEY_F17, ACTIVATE_WHEN_RISE},
        {p2, KEY_F18, ACTIVATE_WHEN_FALL},
        {p3, KEY_F19, ACTIVATE_WHEN_RISE},
        {p3, KEY_F20, ACTIVATE_WHEN_FALL},
};

/**** END OF CONFIGURATION ****/

USBKeyboard Keyboard;

void print_pin_configuration(PinKeyMap *map, bool include_newline) {
    char buffer[256] = {0};
    sprintf(buffer, "Pin %d for key %d with action %d has previous state %s.%c",
            map->pin, map->key, map->activation,
            map->previous_state ? "on" : "off",
            include_newline ? '\n' : '\0');
    Serial.print(buffer);
}

void keyboard_send(int16_t key) {
    int key_code = key & 0xff;
    int modifier = (key >> 8) & 0xff;
    Keyboard.key_code(key_code, modifier);

    Serial.print("Key sent: ");
    Serial.print(key_code);
    Serial.print(" @ ");
    Serial.println(modifier);
}

void process_pin(PinKeyMap *map) {
    bool new_state = digitalRead(map->pin);

    switch (map->activation) {
        case ACTIVATE_WHEN_RISE:
            if (new_state && new_state != map->previous_state)
                keyboard_send(map->key);
            break;
        case ACTIVATE_WHEN_FALL:
            if (!new_state && new_state != map->previous_state)
                keyboard_send(map->key);
            break;
        case ACTIVATE_WHEN_CHANGE:
            if (new_state != map->previous_state)
                keyboard_send(map->key);
            break;
    }

    map->previous_state = new_state;
}

void setup() {
    Serial.begin(9600);
    for (PinKeyMap map: pin_key_map) {
        pinMode(map.pin, INPUT);
    }
    Serial.println("Ready.");
}

void loop() {
    delay(LOOP_INTERVAL_MS);

    digitalWrite(LED_BUILTIN, HIGH);
    for (PinKeyMap &map: pin_key_map) {
        process_pin(&map);
    }
    digitalWrite(LED_BUILTIN, LOW);
}