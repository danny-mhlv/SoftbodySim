#include "event_handler.h"

event_handler::event_handler()
{
	exit_flag = false;
}

event_handler::~event_handler()
{

}

void event_handler::process_events(vertex_list* list)
{
	while (SDL_PollEvent(&evt) != 0)
	{
		switch (evt.type)
		{
		case SDL_MOUSEBUTTONDOWN:
			handle_mouse(list);
			break;
		case SDL_MOUSEBUTTONUP:
			handle_mouse(list);
			break;
		case SDL_QUIT:
			exit_flag = true;
			break;
		}
	}
}

void event_handler::handle_mouse(vertex_list* list)
{
	if (SDL_MOUSEBUTTONDOWN)
	{
		

		list->setCurrent(cur_pos::first);
		while (list->getCurrent() != nullptr)
		{
			

			list->setCurrent(cur_pos::next);
		}
	}
}

bool event_handler::isExited()
{
	return exit_flag;
}