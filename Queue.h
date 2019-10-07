#pragma once

#include "Program.h"
#include "LinkedList.h"

class Queue : public LinkedList
{
public:
	Queue();
	Queue(const Queue&);

	void push(const Program&);
	Program pop();
private:

	using LinkedList::operator[];

	using LinkedList::operator+=;
	using LinkedList::operator-=;

	using LinkedList::addTail;
	using LinkedList::addHead;
	using LinkedList::insert;

	using LinkedList::removeHead;
	using LinkedList::removeTail;
	using LinkedList::remove;

	using LinkedList::get;
	using LinkedList::searchByName;
};