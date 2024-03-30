#include "LightCycle.h"
#include "Graphics.h"

constexpr size_t CYCLE_LENGTH = 6;

const Color LIGHT_CYCLE[CYCLE_LENGTH][3] = {
    { COLOR_RED, COLOR_GRAY, COLOR_GRAY },
    { COLOR_RED, COLOR_GRAY, COLOR_GRAY },
    { COLOR_RED, COLOR_GRAY, COLOR_GRAY },
    { COLOR_RED, COLOR_YELLOW, COLOR_GRAY },
    { COLOR_GRAY, COLOR_GRAY, COLOR_GREEN },
    { COLOR_RED, COLOR_YELLOW, COLOR_GRAY }
};

void LightCycle::NextStage() {
    if (cycleStage == CYCLE_LENGTH - 1) {
        cycleStage = 0;
        return;
    }

    cycleStage++;
}

const Color* LightCycle::GetLightColors() {
    return LIGHT_CYCLE[cycleStage];
}