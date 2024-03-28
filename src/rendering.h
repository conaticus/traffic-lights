#pragma once
#include <SDL2/SDL.h>

struct Color {
    Uint8 red;
    Uint8 green;
    Uint8 blue;
    Uint8 alpha;
};

class Graphics {
public:
	SDL_Window* window;
	SDL_Renderer* renderer;

	Graphics();
	~Graphics();
};

void SetRenderColor(SDL_Renderer* renderer, Color color);