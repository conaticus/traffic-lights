#pragma once

enum LightState {
    RED,
    YELLOW,
    GREEN,
    OFF
};

const int LIGHT_CYCLE[4][3] = {
    { RED, OFF, OFF },
    { RED, YELLOW, OFF },
    { OFF, OFF, GREEN },
    { OFF, YELLOW, OFF }
};

class LightCycle {
public:
    int cycleStage;

    LightCycle(int cycleStage) : cycleStage(cycleStage) {}
};