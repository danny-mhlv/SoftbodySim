#include "vertex_list.h"

vertex_list::vertex_list()
{
	pFirst = nullptr;
	pCur = nullptr;
	pLast = nullptr;
}

//Destroy all nodes
vertex_list::~vertex_list()
{

}

void vertex_list::add(vertex* newNode)
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
		pCur->setNext(newNode);
		newNode->setPrev(pCur);
		pCur = newNode;
		pLast = newNode;

		pCur->setIndex(pCur->getPrev()->getIndex() + 1);
	}
}

void vertex_list::addTo(vertex* newNode, int i)
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

void vertex_list::add(int x, int y)
{
	vertex* vert = new vertex(x, y);

	if (pFirst == nullptr)
	{
		pFirst = vert;
		pCur = vert;
		pLast = vert;

		pFirst->setIndex(1);
	}
	else
	{
		pCur->setNext(vert);
		vert->setPrev(pCur);
		pCur = vert;
		pLast = vert;

		pCur->setIndex(pCur->getPrev()->getIndex() + 1);
	}
}

void vertex_list::add(SDL_Point p)
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
		pCur->setNext(vert);
		vert->setPrev(pCur);
		pCur = vert;
		pLast = vert;

		pCur->setIndex(pCur->getPrev()->getIndex() + 1);
	}
}

void vertex_list::addTo(int x, int y, int i)
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

void vertex_list::addTo(SDL_Point p, int i)
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

void vertex_list::setCurrent(cur_pos flag)
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

vertex* vertex_list::getCurrent()
{
	return pCur;
}