#include "LightCycle.h"
#include "Graphics.h"

const Color LIGHT_CYCLE[4][3] = {
    { COLOR_RED, COLOR_GRAY, COLOR_GRAY },
    { COLOR_RED, COLOR_YELLOW, COLOR_GRAY },
    { COLOR_GRAY, COLOR_GRAY, COLOR_GREEN },
    { COLOR_RED, COLOR_YELLOW, COLOR_GRAY }
};

void LightCycle::NextStage() {
    if (cycleStage == 3) {
        cycleStage = 0;
        return;
    }

    cycleStage++;
}

const Color* LightCycle::GetLightColors() {
    return LIGHT_CYCLE[cycleStage];
}