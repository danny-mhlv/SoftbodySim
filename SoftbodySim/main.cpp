#include <SDL.h>

#include "mesh.h"
#include "context.h"
#include "event_handler.h"

int main(int argc, char* argv[])
{
	context mainContext("My Window");
	event_handler evtHandler;

	mesh mainList;
	mainList.initBall(200, 200, 6, 60);

	while (!evtHandler.isExited())
	{
		evtHandler.process_events(&mainList);

		mainContext.render(&mainList);
	}
	return 0;
}