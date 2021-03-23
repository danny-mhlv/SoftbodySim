#include "vertex.h"

vertex::vertex()
{
	xc = 0.0f; yc = 0.0f;
	vx = 0.0f; vy = 0.0f;
	fx = 0.0f; fy = 0.0f;
	index = -1;

	pNext = nullptr; pPrev = nullptr;
}

vertex::vertex(float x, float y) : xc(x), yc(y)
{
	vx = 0.0f; vy = 0.0f;
	fx = 0.0f; fy = 0.0f;
	index = -1;

	pNext = nullptr; pPrev = nullptr;
}

vertex::vertex(SDL_Point p) : xc(p.x), yc(p.y)
{
	vx = 0.0f; vy = 0.0f;
	fx = 0.0f; fy = 0.0f;
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

void vertex::relocate(float x, float y)
{
	xc = x; yc = y;
}

void vertex::draw()
{
	
}

/*
	Get/Set
*/

float vertex::getX() { return xc; }
void vertex::setX(float x) { xc = x; }
float vertex::getY() { return yc; }
void vertex::setY(float y) { yc = y; }

SDL_Point vertex::getVert()
{
	SDL_Point p; p.x = xc; p.y = yc;
	return p;
}

float vertex::getFX() { return fx; } void vertex::setFX(float arg_fx) { fx = arg_fx; }
float vertex::getFY() { return fy; } void vertex::setFY(float arg_fy) { fy = arg_fy; }

float vertex::getVX() { return vx; } void vertex::setVX(float arg_vx) { vx = arg_vx; }
float vertex::getVY() { return vy; } void vertex::setVY(float arg_vy) { vy = arg_vy; }

vertex* vertex::getPrev() { return pPrev; }
vertex* vertex::getNext() { return pNext; }

void vertex::setPrev(vertex* prev) { pPrev = prev; }
void vertex::setNext(vertex* next) { pNext = next; }

int vertex::getIndex()
{
	return index;
}

void vertex::setIndex(int i)
{
	index = i;
}