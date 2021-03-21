#include <SDL.h>

#include "vertex_list.h"
#include "context.h"
#include "event_handler.h"

int main(int argc, char* argv[])
{
	context mainContext("My Window");
	event_handler evtHandler;

	while (!evtHandler.isExited())
	{
		evtHandler.process_events();
	}

	return 0;
}