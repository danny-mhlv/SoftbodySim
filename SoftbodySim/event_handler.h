#pragma once
#include <SDL.h>

#include "mesh.h"

class event_handler
{
public:
	event_handler();
	~event_handler();

	void process_events(mesh* list);
	void handle_mouse(mesh* list);

	bool isExited();
private:
	SDL_Event evt;

	bool exit_flag;
};

