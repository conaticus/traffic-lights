#pragma once
#include "Graphics.h"
#include "LightCycle.h"

class TrafficLights {
    Graphics app;

public:
    TrafficLights(); 
private:
    void DrawTrafficLights();
    void DrawBulbs(SDL_Rect& lightBox, LightCycle& cycle);
    std::pair<SDL_Rect, SDL_Rect> DrawBoxes();
};
