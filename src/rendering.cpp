#include "rendering.h"

const Color ColorRed = {252, 3, 3, 255};

void SetRenderColor(SDL_Renderer* renderer, Color color) {
	SDL_SetRenderDrawColor(renderer, color.red, color.green, color.blue, color.alpha);
}