#include "rendering.h"
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

void Graphics::Draw() {
	SDL_RenderPresent(renderer);
}

Graphics::~Graphics() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	exit(0);
}