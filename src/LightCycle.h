#pragma once
#include "Graphics.h"
#include <iostream>
#include <array>

enum CycleStage {
    STOP = 0,
    READY_GO = 3,
};

typedef std::array<const Color, 3> LightColorsArray;

// This class controls light cycle for one traffic light.
class LightCycle {
public:
    int cycleStage;
    LightCycle(CycleStage cycleStage) : cycleStage(cycleStage) {}

    void NextStage();

    // Returns the three light colors in order of each light (top to bottom).
    LightColorsArray GetLightColors();
};