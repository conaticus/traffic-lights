#include "rendering.h"
#include <SDL2/SDL.h>
#include <iostream>

const Color ColorRed = {252, 3, 3, 255};

void SetRenderColor(SDL_Renderer* renderer, Color color) {
	SDL_SetRenderDrawColor(renderer, color.red, color.green, color.blue, color.alpha);
}

#define WINDOW_SIZE 800

Graphics::Graphics() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "Failed to initialise SDL: " << SDL_GetError() << "\n";
		exit(1);
	}

	SDL_CreateWindowAndRenderer(WINDOW_SIZE, WINDOW_SIZE, 0, &window, &renderer);

	if (window == nullptr) {
		std::cout << "Could not create Window: " << SDL_GetError() << "\n";
		exit(1);
	}

	if (renderer == nullptr) {
		std::cout << "Could not create Renderer: " << SDL_GetError() << "\n";
		exit(1);
	}

	while (true) {
		SDL_Event event;

		while (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_QUIT:
					delete this;
					break;
				default: break;
			}
		}
	}
}

Graphics::~Graphics() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	exit(0);
}