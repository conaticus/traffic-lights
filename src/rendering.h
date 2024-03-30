#pragma once
#include <SDL2/SDL.h>
#include <vector>

struct Color {
    Uint8 red;
    Uint8 green;
    Uint8 blue;
    Uint8 alpha;

    Color(Uint8 r = 0, Uint8 g = 0, Uint8 b = 0, Uint8 a = 255) : red(r), green(g), blue(b), alpha(a) {}
};

class Graphics {
public:
	SDL_Window* window;
	SDL_Renderer* renderer;

    int width;
    int height;

	Graphics(int width, int height);
    void SetDrawColor(Color& color);
    void FillRect(SDL_Rect& rect);
    void Draw();
	~Graphics();
};