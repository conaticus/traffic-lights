#include "Graphics.h"
#include "LightCycle.h"

constexpr int CYCLE_LENGTH = 6;

const std::array<LightColorsArray, CYCLE_LENGTH> LIGHT_CYCLE {{
    { COLOR_RED, COLOR_GRAY, COLOR_GRAY },
    { COLOR_RED, COLOR_GRAY, COLOR_GRAY },
    { COLOR_RED, COLOR_GRAY, COLOR_GRAY },
    { COLOR_RED, COLOR_GRAY, COLOR_GRAY },
    { COLOR_GRAY, COLOR_GRAY, COLOR_GREEN },
    { COLOR_GRAY, COLOR_YELLOW, COLOR_GRAY },
}};

void LightCycle::NextStage() {
    cycleStage = (++cycleStage) % CYCLE_LENGTH;
}

LightColorsArray LightCycle::GetLightColors() {
    return LIGHT_CYCLE[cycleStage];
}