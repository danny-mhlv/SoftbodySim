#include "event_handler.h"

event_handler::event_handler()
{
	exit_flag = false;
}

event_handler::~event_handler()
{

}

void event_handler::process_events(mesh* list)
{
	list->setPCurrent(cur_pos::first);
	while (list->getPCurrent() != nullptr)
	{
		list->getPCurrent()->setFX(0);
		list->getPCurrent()->setFY(POINT_MASS * G_CONST);

		list->setPCurrent(cur_pos::next);
	}
	list->setPCurrent(cur_pos::first);

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

void event_handler::handle_mouse(mesh* list)
{
	if (evt.type == SDL_MOUSEBUTTONDOWN)
	{
		//list->add(evt.button.x, evt.button.y);
	}
	else if (evt.type == SDL_MOUSEBUTTONUP)
	{

	}
	else if (evt.type == SDL_MOUSEMOTION)
	{

	}
}

bool event_handler::isExited()
{
	return exit_flag;
}