#include <chrono>
#include <tuple>
#include "TrafficLights.h"
#include "Graphics.h"
#include "LightCycle.h"

using namespace std::chrono;

constexpr double HEIGHT_PERCENTAGE = 0.9;
constexpr double WIDTH_PERCENTAGE = 0.4;
constexpr int TRAFFIC_LIGHT_OFFSET = 50;
constexpr int SECONDS_INTERVAL = 4;

TrafficLights::TrafficLights() : app(Graphics(960, 800)) {
    // Set background color
	Color bg(22, 22, 22);
	app.SetDrawColor(bg);
	SDL_RenderClear(app.renderer);

    DrawTrafficLights();
}

void TrafficLights::DrawTrafficLights() {
    SDL_Rect lightBoxLeft, lightBoxRight;
    std::tie(lightBoxLeft, lightBoxRight) = DrawBoxes();

	LightCycle leftCycle(READY_GO);
	LightCycle rightCycle(STOP);

	DrawBulbs(lightBoxLeft, leftCycle);
	DrawBulbs(lightBoxRight, rightCycle);
	app.Render();

	steady_clock::time_point prevTime = steady_clock::now();
	steady_clock::time_point wakeupTime = prevTime + seconds(4);

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
		
		if (steady_clock::now() < wakeupTime)
			continue;

		leftCycle.NextStage();
		rightCycle.NextStage();

		DrawBulbs(lightBoxLeft, leftCycle);
		DrawBulbs(lightBoxRight, rightCycle);
		
		app.Render();

		prevTime = steady_clock::now();
		wakeupTime = prevTime + seconds(4);
	}
}

std::pair<SDL_Rect, SDL_Rect> TrafficLights::DrawBoxes() {
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

    return { std::move(lightBoxLeft), std::move(lightBoxRight) };
}

void TrafficLights::DrawBulbs(SDL_Rect& lightBox, LightCycle& cycle) {
	int circleRadius = static_cast<int>(lightBox.w * 0.22);
	int spacing = (lightBox.h) / 3;

	const Color* lightColors = cycle.GetLightColors();

	for (int i = 0; i < 3; i++) {
		int xPos = lightBox.x + (lightBox.w / 2);
		int yPos = lightBox.y + (i * spacing) + (circleRadius + (circleRadius/2));
		app.SetDrawColor(const_cast<Color&>(lightColors[i]));
		app.FillCircle(circleRadius, xPos, yPos);
	}
}