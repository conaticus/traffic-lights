#pragma once
#include <SDL2/SDL.h>

struct Color {
    Uint8 red;
    Uint8 green;
    Uint8 blue;
    Uint8 alpha;
};

void setRenderColor(SDL_Renderer* renderer, Color color);