//
// Created by samuel on 22-2-23.
//

#ifndef PICOSTREAMDECK_DEFINITIONS_H
#define PICOSTREAMDECK_DEFINITIONS_H

#include <PinNames.h>

typedef enum {
    ACTIVATE_WHEN_RISE = 0,
    ACTIVATE_WHEN_FALL,
    ACTIVATE_WHEN_CHANGE,
} ActivationState;

typedef struct {
    PinName pin;
    int16_t key;
    ActivationState activation;
    bool previous_state;
} PinKeyMap;

#endif //PICOSTREAMDECK_DEFINITIONS_H
