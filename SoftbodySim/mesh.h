#pragma once
#include <iostream>

#include "vertex.h"
#include "spring.h"

const float POINT_MASS = 20.0f;
const float G_CONST = 9.8f; // Gravitational constant
const float P_CONST = 8.31f; // Gas constant
const float DT = 0.01f;
const float Ks = 10.0f; // Elasticity coefficient of the spring
const float Kd = 10.0f; // Damping coefficient

enum class cur_pos : int
{
	first,
	next,
	last
};

class mesh
{
public:
	mesh();
	~mesh();

	// Shape initialization
	void initBall(int x, int y, int numOfPoints, int r);

	// Movement and physics
	void calculateForces();
	void integrate();

	/*----------*/
	/*|  POINT |*/
	/*----------*/

	void add_p(vertex* newNode); // Add to the end
	void addTo_p(vertex* newNode, int i); // Add after certain index

	// Construct and add new
	void add_p(int x, int y);
	void add_p(SDL_Point p);
	void addTo_p(int x, int y, int i);
	void addTo_p(SDL_Point p, int i);

	/*----------*/
	/*| SPRING |*/
	/*----------*/

	void add_s(spring* newNode); // Adds a spring to the list.
	void add_s(vertex* vert); // Connects selected vertex and the next(pNext) one.
	void add_s(vertex* vert1, vertex* vert2); // Sets vert1 and vert2 as v1/v2 respectively

	// Deletion by index
	void del(int i);
	// Deletion by coordinates
	void del(int x, int y);
	// Deletion by point
	void del(SDL_Point p);

	// pCur manipulation (Pointer to the current VERTEX-object in list)
	void setPCurrent(cur_pos flag);
	vertex* getPCurrent();
	// sCur manipulation (Pointer to the current SPRING-object in list)
	void setSCurrent(cur_pos flag);
	spring* getSCurrent();
private:
	// List of points (vertices)
	vertex* pFirst; vertex* pCur; vertex* pLast;
	spring* sFirst; spring* sCur; spring* sLast;
};

