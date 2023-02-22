# Pico Stream Deck

_Well, not really a stream deck. At the moment it's just a weird keyboard emulator. Future extension will be more like a stream deck with communication both ways between the computer and the microcontroller._ 

So this project started with the need to switch OBS scenes based on external parameters, like a physical switch. 

## Design

There are multiple ways to achieve this, but my goal is to make it cheap, easy, and future-proof. So instead of going with an ESP32 (or Pico W maybe?) with webserver which connects from any location over WiFi with OBS, I'm just going to start with the Raspberry PI Pico connected by USB with the computer running OBS. It's my first project with these little beauties. Initially, I wanted to go with a Arduino Nano, as it more than powerful enough for this project. But the Pico appears to be cheaper. And it can function as an HID device directly recognizable by the computer. So no need for software reading the serial ports. Win-win. 

The road map of this project is as follows:
1. **[current]** Use the MCU to emulate a keyboard. Configuration is hardcoded. 
2. Use the MCU to emulate a keyboard. Configuration can be changed by a custom tool.
3. Serial communication between the MCU and custom software on the computer. This allows for much more communication and complexer configuration.
4. Serial communication between the MCU and custom software ont he computer. Now also implementing configurable outputs on the MCU so you can connect your 'NOW LIVE' light.

### Current design

So currently the design is as follows:

#### Hardware

- Raspberry Pico as microcontroller
- Custom PCB to extend the MCU's inputs to handy connector blocks.
- USB cable

##### Embedded software

The microcontroller is programmed with the source code in this repository. The code is very straight forward:
- Configure PinKeyMappings which bind keybindings to events on the MCU input pins. For example: ```(PinKeyMap) {p0, KEY_F13, ACTIVATE_WHEN_RISE}``` will fire a F13 (function key 13, the same as SHIFT + F1) key stroke to the computer when the voltage on IO pin 0 goes from 0V to 3.3V. Note that you can specify any key code you want. Only a few (as I don't see the need for more) are defined using macros in `keycodes.h`.
- The processor will check all input pins once every `LOOP_INTERVAL_MS` milliseconds. This is a cheap way of debouncing the inputs and preventing keystroke spams to the computer.

The source code is written using PlatformIO (v6.1.6). I also downloaded the libraries 'Keyboard' (v1.0.4) and 'USBHost' (v1.0.5) using the Library Manager built in Arduino IDE. 

#### Software (computer side)

None :)


## Development

To compile and upload this project to your Pico, you must use PlatformIO (and all dependencies as stated in the section [Embedded software](#embedded-software)).

The Raspberry Pi Pico board and library comes with the newest PlatformIO version, so no need to install those.

Then simply run `pio run` to compile or `pio run --target upload` to compile and upload to your Pico (no need to press buttons on the Pico).

You can connect with the Pico using a serial monitor on baud rate 9600 (this baud rate is set low for better reliability in future features). The Pico will log when it's sending a key press, for debug purposes only.
