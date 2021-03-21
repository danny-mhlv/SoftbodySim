#pragma once
#include <SDL.h>
class vertex
{
public:
	vertex();
	vertex(int x, int y);
	vertex(SDL_Point p);
	~vertex();

	void relocate(SDL_Point p);
	void relocate(int x, int y);

	void draw();

	// Get/Set
	int getX();
	int getY();
	SDL_Point getVert();

	vertex* getPrev();
	vertex* getNext();

	void setPrev(vertex* prev);
	void setNext(vertex* next);

	int getIndex();
	void setIndex(int i);
private:
	int xc, yc;
	int vx, vy; // Velocity
	int fx, fy; // Force accumulator

	int index;
	vertex* pPrev; vertex* pNext;
};