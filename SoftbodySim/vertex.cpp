#include "vertex.h"

vertex::vertex()
{
	xc = 0; yc = 0;
	index = -1;

	pNext = nullptr; pPrev = nullptr;
}

vertex::vertex(int x, int y) : xc(x), yc(y)
{
	index = -1;

	pNext = nullptr; pPrev = nullptr;
}

vertex::vertex(SDL_Point p) : xc(p.x), yc(p.y)
{
	index = -1;

	pNext = nullptr; pPrev = nullptr;
}

vertex::~vertex()
{

}

void vertex::relocate(SDL_Point p)
{
	xc = p.x; yc = p.y;
}

void vertex::relocate(int x, int y)
{
	xc = x; yc = y;
}

void vertex::draw()
{
	
}

/*
	Get/Set
*/

int vertex::getX() { return xc; }
void vertex::setX(int x) { xc = x; }
int vertex::getY() { return yc; }
void vertex::setY(int y) { yc = y; }

SDL_Point vertex::getVert()
{
	SDL_Point p; p.x = xc; p.y = yc;
	return p;
}

vertex* vertex::getPrev() { return pPrev; }
vertex* vertex::getNext() { return pNext; }

void vertex::setPrev(vertex* prev)
{
	pPrev = prev;
}

void vertex::setNext(vertex* next)
{
	pNext = next;
}

int vertex::getIndex()
{
	return index;
}

void vertex::setIndex(int i)
{
	index = i;
}