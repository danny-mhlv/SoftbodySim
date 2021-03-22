#pragma once

#include "vertex.h"

class spring
{
public:
	spring();
	~spring();
private:
	float length;
	int nx, ny;

	vertex* v1; vertex* v2;
};

