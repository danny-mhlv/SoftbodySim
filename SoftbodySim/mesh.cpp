#include "mesh.h"

mesh::mesh()
{
	pFirst = nullptr;
	pCur = nullptr;
	pLast = nullptr;

	sFirst = nullptr;
	sCur = nullptr;
	sLast = nullptr;
}

//Destroy all nodes
mesh::~mesh()
{

}

		/*----------*/
		/*|  POINT |*/
		/*----------*/

void mesh::add_p(vertex* newNode)
{
	if (pFirst == nullptr)
	{
		pFirst = newNode;
		pCur = newNode;
		pLast = newNode;

		pFirst->setIndex(1);
 	}
	else
	{
		// In case pCur was modified by another function
		pCur = pLast;

		pCur->setNext(newNode);
		newNode->setPrev(pCur);
		pCur = newNode;
		pLast = newNode;

		pCur->setIndex(pCur->getPrev()->getIndex() + 1);
	}
}

void mesh::addTo_p(vertex* newNode, int i)
{
	pCur = pFirst;

	while (pCur->getIndex() != i)
	{
		pCur = pCur->getNext();
		if (pCur == nullptr)
		{
			std::cout << "Failed to add new node at index: " << i << std::endl;
			std::cout << "No such index." << std::endl;
			return;
		}
	}

	pCur->getNext()->setPrev(newNode);
	newNode->setNext(pCur->getNext());
	pCur->setNext(newNode);
	newNode->setPrev(pCur);

	pCur = newNode;
	while (pCur != nullptr)
	{
		pCur->setIndex(pCur->getPrev()->getIndex() + 1);
		pCur = pCur->getNext();
	}
	pCur = newNode;
}

void mesh::add_p(int x, int y)
{
	vertex* vert = new vertex(x, y);

	if (pFirst == nullptr)
	{
		pFirst = vert;
		pCur = vert;
		pLast = vert;

		pFirst->setIndex(1);

		std::cout << "Added first element: " << x << "|" << y << std::endl;
	}
	else
	{
		// In case pCur was modified by another function
		pCur = pLast;

		pCur->setNext(vert);
		vert->setPrev(pCur);
		pCur = vert;
		pLast = vert;

		pCur->setIndex(pCur->getPrev()->getIndex() + 1);

		std::cout << "Added element: " << x << "|" << y << std::endl;
		std::cout << "Prev element: " << vert->getPrev()->getX() << "|" << vert->getPrev()->getY() << std::endl;
	}
}

void mesh::add_p(SDL_Point p)
{
	vertex* vert = new vertex(p);

	if (pFirst == nullptr)
	{
		pFirst = vert;
		pCur = vert;
		pLast = vert;

		pFirst->setIndex(1);
	}
	else
	{
		// In case pCur was modified by another function
		pCur = pLast;

		pCur->setNext(vert);
		vert->setPrev(pCur);
		pCur = vert;
		pLast = vert;

		pCur->setIndex(pCur->getPrev()->getIndex() + 1);
	}
}

void mesh::addTo_p(int x, int y, int i)
{
	vertex* vert = new vertex(x, y);

	pCur = pFirst;

	while (pCur->getIndex() != i)
	{
		pCur = pCur->getNext();
		if (pCur == nullptr)
		{
			std::cout << "Failed to add new node at index: " << i << std::endl;
			std::cout << "No such index." << std::endl;
			return;
		}
	}

	pCur->getNext()->setPrev(vert);
	vert->setNext(pCur->getNext());
	pCur->setNext(vert);
	vert->setPrev(pCur);

	pCur = vert;
	while (pCur != nullptr)
	{
		pCur->setIndex(pCur->getPrev()->getIndex() + 1);
		pCur = pCur->getNext();
	}
	pCur = vert;
}

void mesh::addTo_p(SDL_Point p, int i)
{
	vertex* vert = new vertex(p);

	pCur = pFirst;

	while (pCur->getIndex() != i)
	{
		pCur = pCur->getNext();
		if (pCur == nullptr)
		{
			std::cout << "Failed to add new node at index: " << i << std::endl;
			std::cout << "No such index." << std::endl;
			return;
		}
	}

	pCur->getNext()->setPrev(vert);
	vert->setNext(pCur->getNext());
	pCur->setNext(vert);
	vert->setPrev(pCur);

	pCur = vert;
	while (pCur != nullptr)
	{
		pCur->setIndex(pCur->getPrev()->getIndex() + 1);
		pCur = pCur->getNext();
	}
	pCur = vert;
}

		/*----------*/
		/*| SPRING |*/
		/*----------*/

void mesh::add_s(spring* newNode)
{
	if (sFirst == nullptr)
	{
		sFirst = newNode;
		sCur = newNode;
		sLast = newNode;
	}
	else
	{
		// In case pCur was modified by another function
		sCur = sLast;

		sCur->setNext(newNode);
		newNode->setPrev(sCur);
		sCur = newNode;
		sLast = newNode;
	}
}

void mesh::add_s(vertex* vert)
{
	if (vert != nullptr && vert->getNext() != nullptr)
	{
		spring* spr = new spring(vert);

		if (sFirst == nullptr)
		{
			sFirst = spr;
			sCur = spr;
			sLast = spr;
		}
		else
		{
			// In case sCur was modified by another function
			sCur = sLast;

			sCur->setNext(spr);
			spr->setPrev(sCur);
			sCur = spr;
			sLast = spr;
		}
	}
}

void mesh::add_s(vertex* vert1, vertex* vert2)
{
	if (vert1 != nullptr && vert2 != nullptr)
	{
		spring* spr = new spring(vert1, vert2);

		if (sFirst == nullptr)
		{
			sFirst = spr;
			sCur = spr;
			sLast = spr;
		}
		else
		{
			// In case sCur was modified by another function
			sCur = sLast;

			sCur->setNext(spr);
			spr->setPrev(sCur);
			sCur = spr;
			sLast = spr;
		}
	}
}

void mesh::initBall(int x, int y, int numOfPoints, int r)
{
	// TODO: clear all list, then init shape

	for (int i = 1; i <= numOfPoints; i++)
	{
		this->add_p(r * sin(i * (2.0 * 3.14) / numOfPoints) + x, 
				  r * cos(i * (2.0 * 3.14) / numOfPoints) + y);
	}

	this->add_s(pFirst); // Creating and adding a spring between first two points
	pCur = pFirst->getNext(); // pCur is at second node in the list

	while (pCur != nullptr) // Iterate through all points and assign springs
	{
		if (pCur->getNext() == nullptr)
		{
			this->add_s(pCur, pFirst);
			break;
		}

		this->add_s(pCur);
		this->setPCurrent(cur_pos::next);
	}
	
	pCur = pFirst;
}

void mesh::del(int i)
{

}

void mesh::del(int x, int y)
{

}

void mesh::del(SDL_Point p)
{

}

void mesh::setPCurrent(cur_pos flag)
{
	switch (flag)
	{
	case cur_pos::first:
		pCur = pFirst;
		break;
	case cur_pos::next:
		if (pCur != nullptr)
		{
			pCur = pCur->getNext();
		}
		break;
	case cur_pos::last:
		pCur = pLast;
		break;
	}
}

vertex* mesh::getPCurrent()
{
	return pCur;
}

void mesh::setSCurrent(cur_pos flag)
{
	switch (flag)
	{
	case cur_pos::first:
		sCur = sFirst;
		break;
	case cur_pos::next:
		if (sCur != nullptr)
		{
			sCur = sCur->getNext();
		}
		break;
	case cur_pos::last:
		sCur = sLast;
		break;
	}
}

spring* mesh::getSCurrent()
{
	return sCur;
}