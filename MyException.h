#pragma once

#include <exception>
#include <string>

class MyException : public std::exception
{
public:
	virtual const char* what() const noexcept { return "My exception occured"; }
};

class ListException : public MyException
{
public:
	virtual const char* what() const noexcept { return "Some List exception occured"; }
};

class ListWrongIndexException : public ListException
{
	std::string msg;
public:
	ListWrongIndexException(int idx)
	{
		this->msg = std::string("Index ") + std::to_string(idx) + std::string(" is not a valid index");
	}
	virtual const char* what() const noexcept 
	{
		return msg.c_str();
	}
};

class ListEmptyOpException : public ListException
{
public:
	virtual const char* what() const noexcept { return "Unable to perform required operation: List is empty"; }
};
