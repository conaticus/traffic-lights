#include <SDL2/SDL.h>
#include "rendering.h"
#include <iostream>

#define HEIGHT_PERCENTAGE 0.8
#define WIDTH_PERCENTAGE 0.4
#define TRAFFIC_LIGHT_OFFSET 50

int main(int argc, char* argv[])
{
	Graphics app(960, 800);

	Color bg(38, 38, 38);
	app.SetDrawColor(bg);
	SDL_RenderClear(app.renderer);

	SDL_Rect lightBoxLeft {
		.x = TRAFFIC_LIGHT_OFFSET,
		.y = static_cast<int>((app.height * (1 - HEIGHT_PERCENTAGE)) / 2),
		.w = static_cast<int>(app.width * WIDTH_PERCENTAGE),
		.h = static_cast<int>(app.height * HEIGHT_PERCENTAGE),
	};

	app.Draw();

	while (true) {
		SDL_Event event;

		while (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_QUIT:
					delete &app;
					break;
				default: break;
			}
		}
	}
	
	return 0;
}