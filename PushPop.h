#pragma once

#include "Program.h"

class PushPop
{
public:
	virtual void push(const Program&) = 0;
	virtual Program pop() = 0;
	virtual bool isEmpty() = 0;
};