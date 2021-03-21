#pragma once
#include <SDL.h>
#include <iostream>

const int WINDOW_W = 500;
const int WINDOW_H = 500;

class context
{
public:
	context();
	context(Uint32 flags);
	context(const char* winName);
	context(Uint32 flags, const char* winName);
	~context();


private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};

