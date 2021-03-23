#pragma once
#include <SDL.h>

class vertex
{
public:
	vertex();
	vertex(float x, float y);
	vertex(SDL_Point p);
	~vertex();

	void relocate(SDL_Point p);
	void relocate(float x, float y);

	void draw();

	// Get/Set
	float getX(); void setX(float x);
	float getY(); void setY(float y);
	SDL_Point getVert();

	float getFX(); void setFX(float arg_fx);
	float getFY(); void setFY(float arg_fy);

	float getVX(); void setVX(float arg_vx);
	float getVY(); void setVY(float arg_vy);

	vertex* getPrev();
	vertex* getNext();
	void setPrev(vertex* prev);
	void setNext(vertex* next);

	int getIndex();
	void setIndex(int i);
private:
	float xc, yc;
	float vx, vy; // Velocity
	float fx, fy; // Force accumulator

	int index;
	vertex* pPrev; vertex* pNext;
};