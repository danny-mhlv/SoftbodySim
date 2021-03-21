#pragma once
#include <iostream>
#include "vertex.h"

enum class cur_pos : int
{
	first,
	next,
	last
};

class vertex_list
{
public:
	vertex_list();
	~vertex_list();

	// Add to the end
	void add(vertex* newNode);
	// Add after certain index
	void addTo(vertex* newNode, int i);

	// Construct and add new
	void add(int x, int y);
	void add(SDL_Point p);
	void addTo(int x, int y, int i);
	void addTo(SDL_Point p, int i);

	// Deletion by index
	void del(int i);
	// Deletion by coordinates
	void del(int x, int y);
	// Deletion by point
	void del(SDL_Point p);

	void setCurrent(cur_pos flag);
	vertex* getCurrent();
private:
	vertex* pFirst; vertex* pCur; vertex* pLast;
};

