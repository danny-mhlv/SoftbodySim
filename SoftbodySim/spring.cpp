#include "spring.h"

spring::spring()
{
	v1 = nullptr; v2 = nullptr;
	length = 0.0f;
	nx = 0.0f; ny = 0.0f;

	sPrev = nullptr; sNext = nullptr;
}

spring::spring(vertex* vert)
{
	v1 = vert; v2 = vert->getNext();

	float dx = vert->getX() - vert->getNext()->getX();
	float dy = vert->getY() - vert->getNext()->getY();
	length = sqrt(dx * dx + dy * dy);

	nx = 0.0f; ny = 0.0f;

	sPrev = nullptr; sNext = nullptr;
}

spring::spring(vertex* vert1, vertex* vert2)
{
	v1 = vert1; v2 = vert2;

	float dx = vert1->getX() - vert2->getX();
	float dy = vert1->getY() - vert2->getY();
	length = sqrt(dx * dx + dy * dy);

	nx = 0.0f; ny = 0.0f;

	sPrev = nullptr; sNext = nullptr;
}

spring::~spring()
{}

spring* spring::getPrev() { return sPrev; }
spring* spring::getNext() { return sNext; }

void spring::setPrev(spring* prev) { sPrev = prev; }
void spring::setNext(spring* next) { sNext = next; }