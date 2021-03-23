#pragma once
#include <SDL.h>
#include <iostream>

#include "mesh.h"

#define BLACK {0, 0, 0, 255}
#define RED {255, 0, 0, 255}

const int WINDOW_W = 500;
const int WINDOW_H = 500;

enum class shape_form : int
{
	hollow,
	filled,
};

class context
{
public:
	context();
	context(Uint32 flags);
	context(const char* winName);
	context(Uint32 flags, const char* winName);
	~context();

	void drawCircle(int x_center, int y_center, int r, SDL_Color color = {0, 0, 0, 255}, shape_form form = shape_form::hollow);

	void render(mesh* list);
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};

