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

const Color COLOR_RED(255, 0, 0);
const Color COLOR_YELLOW(255, 255, 0);
const Color COLOR_GREEN(0, 255, 0);
const Color COLOR_GRAY(40, 40, 40);

class Graphics {
public:
	SDL_Window* window;
	SDL_Renderer* renderer;

    int width;
    int height;

    Graphics(int width, int height);
    void SetDrawColor(const Color& color);
    void FillRect(const SDL_Rect& rect);
    void FillCircle(int radius, int x, int y);
    void Render();
    ~Graphics();
};