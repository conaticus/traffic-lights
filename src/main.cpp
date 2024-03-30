#include <SDL2/SDL.h>
#include "Graphics.h"
#include <iostream>

#define HEIGHT_PERCENTAGE 0.9
#define WIDTH_PERCENTAGE 0.4
#define TRAFFIC_LIGHT_OFFSET 50

void DrawLights(Graphics& app, SDL_Rect lightBox) {
	int circleRadius = static_cast<int>(lightBox.w * 0.22);
	int spacing = (lightBox.h) / 3;

	for (int i = 0; i < 3; i++) {
		int xPos = lightBox.x + (lightBox.w / 2);
		int yPos = lightBox.y + (i * spacing) + (circleRadius + (circleRadius/2));
		app.FillCircle(circleRadius, xPos, yPos);
	}
}

int main(int argc, char* argv[])
{
	Graphics app(960, 800);

	Color bg(22, 22, 22);
	app.SetDrawColor(bg);
	SDL_RenderClear(app.renderer);

	SDL_Rect lightBoxLeft {
		.x = TRAFFIC_LIGHT_OFFSET,
		.y = static_cast<int>((app.height * (1 - HEIGHT_PERCENTAGE)) / 2),
		.w = static_cast<int>(app.width * WIDTH_PERCENTAGE),
		.h = static_cast<int>(app.height * HEIGHT_PERCENTAGE),
	};

	Color black;
	app.SetDrawColor(black);
	app.FillRect(lightBoxLeft);

	SDL_Rect lightBoxRight = lightBoxLeft;
	lightBoxRight.x = app.width - (TRAFFIC_LIGHT_OFFSET + lightBoxRight.w);

	app.FillRect(lightBoxRight);

	Color gray(54, 54, 54);
	app.SetDrawColor(gray);

	DrawLights(app, lightBoxLeft);
	DrawLights(app, lightBoxRight);

	app.Render();

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