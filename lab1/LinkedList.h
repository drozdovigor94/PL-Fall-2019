#pragma once

#include <iostream>
#include <string>

#include "Program.h"


class LinkedList
{
private:
	struct ListElement
	{
		Program* element;
		ListElement* next;

		ListElement(Program* );
		~ListElement();
	};

	ListElement* head;
	ListElement* tail;

public:
	LinkedList();
	~LinkedList();

	void addTail(Program* );
	void addHead(Program* );
	bool insert(Program* , int );

	bool removeHead();
	bool removeTail();
	bool remove(int );

	void print();

	void save(const char* );
	void load(const char* );
	LinkedList* searchByName(std::string );
};