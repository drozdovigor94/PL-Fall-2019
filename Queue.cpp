#include "Queue.h"

Queue::Queue() : LinkedList() {}
Queue::Queue(const Queue& other) : LinkedList(other) {}

void Queue::push(const Program& element)
{
	this->addHead(element);
}

Program Queue::pop()
{
	return this->removeTail();
}