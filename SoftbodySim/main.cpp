#include <SDL.h>

#include "vertex_list.h"
#include "context.h"
#include "event_handler.h"

int main(int argc, char* argv[])
{
	context mainContext("My Window");
	event_handler evtHandler;

	vertex_list mainList;
	mainList.initBall(200, 200, 6, 60);

	while (!evtHandler.isExited())
	{
		evtHandler.process_events(&mainList);

		mainContext.render(&mainList);
	}
	return 0;
}