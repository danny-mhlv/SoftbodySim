#pragma once

#include "vertex.h"

class spring
{
public:
	spring();
	spring(vertex* vert);
	spring(vertex* vert1, vertex* vert2);
	~spring();

	vertex* get_V1() { return v1; }
	vertex* get_V2() { return v2; }

	void setNX(float arg_nx);
	void setNY(float arg_ny);
	float getNX();
	float getNY();

	float getLength();

	// Double-linked list functions
	spring* getPrev();
	spring* getNext();

	void setPrev(spring* prev);
	void setNext(spring* next);
private:
	vertex* v1; vertex* v2;
	float length;
	float nx, ny;

	// Double-linked list pointers
	spring* sPrev; spring* sNext;
};

