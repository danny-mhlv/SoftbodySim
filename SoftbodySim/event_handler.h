#pragma once
#include <SDL.h>

#include "vertex_list.h"

class event_handler
{
public:
	event_handler();
	~event_handler();

	void process_events(vertex_list* list);
	void handle_mouse(vertex_list* list);

	bool isExited();
private:
	SDL_Event evt;

	bool exit_flag;
};

