#pragma once

#include "Program.h"
#include "LinkedList.h"
#include "PushPop.h"

template <typename T>
class Stack : public LinkedList<T>, public PushPop<T>
{
public:
	Stack();
	Stack(const Stack&);

	void push(const T&);
	T pop();
	bool isEmpty();
private:

	using LinkedList<T>::operator[];

	using LinkedList<T>::operator+=;
	using LinkedList<T>::operator-=;

	using LinkedList<T>::addTail;
	using LinkedList<T>::addHead;
	using LinkedList<T>::insert;

	using LinkedList<T>::removeHead;
	using LinkedList<T>::removeTail;
	using LinkedList<T>::remove;

	using LinkedList<T>::get;
	using LinkedList<T>::searchByName;
};