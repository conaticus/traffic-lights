#include <iostream>
#include <SDL2/SDL.h>

#define WINDOW_SIZE 800

class App {
public:
	SDL_Window* window;
	SDL_Renderer* renderer;

	App() {
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
						destroy();
						break;
					default: break;
				}
			}
		}
	}

	void destroy() {
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		exit(0);
	}

	~App() {
		destroy();
	}
};

#ifdef _WIN32
int WinMain(int argc, char* argv[])
#else
int main(int argc, char* argv[])
#endif
{
	App app;
	return 0;
}