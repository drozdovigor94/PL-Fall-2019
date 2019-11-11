#include "Queue.h"

template <typename T>
Queue<T>::Queue() : LinkedList<T>() {}

template <typename T>
Queue<T>::Queue(const Queue<T>& other) : LinkedList<T>(other) {}

template <typename T>
void Queue<T>::push(const T& element)
{
	this->addHead(element);
}

template <typename T>
T Queue<T>::pop()
{
	return this->removeTail();
}

template <typename T>
bool Queue<T>::isEmpty()
{
	return LinkedList::isEmpty();
}