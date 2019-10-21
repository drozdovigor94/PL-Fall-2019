#pragma once

#include "Program.h"
#include "LinkedList.h"
#include "PushPop.h"

class Stack : public LinkedList, public PushPop
{
public:
	Stack();
	Stack(const Stack&);

	void push(const Program&);
	Program pop();
	bool isEmpty();
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