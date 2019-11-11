#pragma once

template <typename T>
class PushPop
{
public:
	virtual void push(const T&) = 0;
	virtual T pop() = 0;
	virtual bool isEmpty() = 0;
};