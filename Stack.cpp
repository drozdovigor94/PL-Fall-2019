#include "Stack.h"

template <typename T>
Stack<T>::Stack() : LinkedList<T>() {}

template <typename T>
Stack<T>::Stack(const Stack<T>& other) : LinkedList<T>(other) {}

template <typename T>
void Stack<T>::push(const T& element)
{
	this->addTail(element);
}

template <typename T>
T Stack<T>::pop()
{
	return this->removeTail();
}

template <typename T>
bool Stack<T>::isEmpty()
{
	return LinkedList<T>::isEmpty();
}