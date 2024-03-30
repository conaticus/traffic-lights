#include "Graphics.h"
#include <SDL2/SDL.h>
#include <iostream>

Graphics::Graphics(int width, int height) : width(width), height(height) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "Failed to initialise SDL: " << SDL_GetError() << "\n";
		exit(1);
	}

	SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer);

	if (window == nullptr) {
		std::cout << "Could not create Window: " << SDL_GetError() << "\n";
		exit(1);
	}

	if (renderer == nullptr) {
		std::cout << "Could not create Renderer: " << SDL_GetError() << "\n";
		exit(1);
	}
}

void Graphics::SetDrawColor(Color& color) {
	SDL_SetRenderDrawColor(renderer, color.red, color.green, color.blue, color.alpha);
}

void Graphics::FillRect(SDL_Rect& rect) {
	SDL_RenderFillRect(renderer, &rect);
}

void Graphics::FillCircle(int radius, int x, int y) {
    for (int w = 0; w < radius * 2; w++)
    {
        for (int h = 0; h < radius * 2; h++)
        {
            int dx = radius - w; // horizontal offset
            int dy = radius - h; // vertical offset
            if ((dx*dx + dy*dy) <= (radius * radius))
                SDL_RenderDrawPoint(renderer, x + dx, y + dy);
        }
    }
}

void Graphics::Render() {
	SDL_RenderPresent(renderer);
}

Graphics::~Graphics() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	exit(0);
}