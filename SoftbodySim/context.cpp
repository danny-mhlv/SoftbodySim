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

void context::drawCircle(int x_center, int y_center, int r, SDL_Color color, shape_form form)
{
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

	// If radius is 0 - single dot is rendered
	if (r == 0)
	{
		SDL_RenderDrawPoint(renderer, x_center, y_center);
		return;
	}

	int x = 0, y = r;
	int f = 1 - r;
	int incrE = 3;
	int incrSE = 5 - 2 * r;

	SDL_RenderDrawPoint(renderer, x_center + x, y_center + y);
	while (x <= y)
	{
		if (f >= 0)
		{
			y--;
			f += incrSE;
			incrSE += 4;
		}
		else
		{
			f += incrE;
			incrSE += 2;
		}
		incrE += 2;

		// Shape form - hollow/filled
		switch (form)
		{
		case shape_form::hollow:
			SDL_RenderDrawPoint(renderer, x + x_center, y + y_center);
			SDL_RenderDrawPoint(renderer, -x + x_center, y + y_center);
			SDL_RenderDrawPoint(renderer, x + x_center, -y + y_center);
			SDL_RenderDrawPoint(renderer, -x + x_center, -y + y_center);
			SDL_RenderDrawPoint(renderer, y + x_center, x + y_center);
			SDL_RenderDrawPoint(renderer, -y + x_center, x + y_center);
			SDL_RenderDrawPoint(renderer, y + x_center, -x + y_center);
			SDL_RenderDrawPoint(renderer, -y + x_center, -x + y_center);
			break;
		case shape_form::filled:
			SDL_RenderDrawLine(renderer, x + x_center, y + y_center, -x + x_center, y + y_center);
			SDL_RenderDrawLine(renderer, x + x_center, -y + y_center, -x + x_center, -y + y_center);
			SDL_RenderDrawLine(renderer, y + x_center, x + y_center, -y + x_center, x + y_center);
			SDL_RenderDrawLine(renderer, y + x_center, -x + y_center, -y + x_center, -x + y_center);
			break;
		}

		x++;
	}
}

void context::render(mesh* list)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);

	// Background color
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	
	// Loop through the whole list and render
	list->setPCurrent(cur_pos::first);
	list->setSCurrent(cur_pos::first);
	while (list->getPCurrent() != nullptr)
	{
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderDrawLine(renderer, list->getSCurrent()->get_V1()->getX(), list->getSCurrent()->get_V1()->getY(), 
							list->getSCurrent()->get_V2()->getX(), list->getSCurrent()->get_V2()->getY());
		drawCircle(list->getPCurrent()->getX(), list->getPCurrent()->getY(), 8, RED, shape_form::filled);

		list->setPCurrent(cur_pos::next);
		list->setSCurrent(cur_pos::next);
	}
	list->setPCurrent(cur_pos::first); // Return current to the first element
	list->setSCurrent(cur_pos::first);

	SDL_RenderPresent(renderer);
}