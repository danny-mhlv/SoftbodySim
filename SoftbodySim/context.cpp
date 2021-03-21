#include "context.h"

context::context()
{
	window = nullptr;
	renderer = nullptr;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "Failed to initialize SDL! Error: " << SDL_GetError() << std::endl;
		exit(-1);
	}

	window = SDL_CreateWindow("DefaultName", 100, 100, WINDOW_W, WINDOW_H, SDL_WINDOW_SHOWN);
	if (window == nullptr)
	{
		std::cout << "Failed to create window! Error: " << SDL_GetError() << std::endl;
		exit(-2);
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr)
	{
		std::cout << "Failed to create renderer! Error: " << SDL_GetError() << std::endl;
		exit(-3);
	}
}

context::context(const char* winName)
{
	window = nullptr;
	renderer = nullptr;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "Failed to initialize SDL! Error: " << SDL_GetError() << std::endl;
		exit(-1);
	}

	window = SDL_CreateWindow(winName, 100, 100, WINDOW_W, WINDOW_H, SDL_WINDOW_SHOWN);
	if (window == nullptr)
	{
		std::cout << "Failed to create window! Error: " << SDL_GetError() << std::endl;
		exit(-2);
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr)
	{
		std::cout << "Failed to create renderer! Error: " << SDL_GetError() << std::endl;
		exit(-3);
	}
}

context::context(Uint32 flags)
{
	window = nullptr;
	renderer = nullptr;

	if (SDL_Init(flags) < 0)
	{
		std::cout << "Failed to initialize SDL! Error: " << SDL_GetError() << std::endl;
		exit(-1);
	}

	window = SDL_CreateWindow("DefaultName", 100, 100, WINDOW_W, WINDOW_H, SDL_WINDOW_SHOWN);
	if (window == nullptr)
	{
		std::cout << "Failed to create window! Error: " << SDL_GetError() << std::endl;
		exit(-2);
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr)
	{
		std::cout << "Failed to create renderer! Error: " << SDL_GetError() << std::endl;
		exit(-3);
	}
}

context::context(Uint32 flags, const char* winName)
{
	window = nullptr;
	renderer = nullptr;

	if (SDL_Init(flags) < 0)
	{
		std::cout << "Failed to initialize SDL! Error: " << SDL_GetError() << std::endl;
		exit(-1);
	}

	window = SDL_CreateWindow(winName, 100, 100, WINDOW_W, WINDOW_H, SDL_WINDOW_SHOWN);
	if (window == nullptr)
	{
		std::cout << "Failed to create window! Error: " << SDL_GetError() << std::endl;
		exit(-2);
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr)
	{
		std::cout << "Failed to create renderer! Error: " << SDL_GetError() << std::endl;
		exit(-3);
	}
}

context::~context()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}