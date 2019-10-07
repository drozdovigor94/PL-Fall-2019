#include "Stack.h"

Stack::Stack() : LinkedList() {}
Stack::Stack(const Stack& other) : LinkedList(other) {}

void Stack::push(const Program& element)
{
	this->addTail(element);
}

Program Stack::pop()
{
	return this->removeTail();
}