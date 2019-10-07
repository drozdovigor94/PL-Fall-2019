#pragma once

#include <iostream>
#include <string>

#include "Program.h"


class LinkedList
{
protected:
	struct ListElement
	{
		Program* element;
		ListElement* next;

		ListElement(Program* );
		~ListElement();
	};

	ListElement* head;
	ListElement* tail;

	Program& getByNegativeIndex(int );

public:
	LinkedList();
	LinkedList(const LinkedList&);
	~LinkedList();

	LinkedList& operator= (const LinkedList&);

	LinkedList& operator+= (const Program&);
	LinkedList& operator-= (const std::string&);

	friend std::ostream& operator<< (std::ostream&, const LinkedList&);

	friend void operator<< (std::ofstream&, const LinkedList&);
	friend void operator>> (std::ifstream&, LinkedList&);

	Program& operator[] (int index);

	void addTail(const Program& );
	void addHead(const Program& );
	bool insert(const Program& , int );

	Program removeHead();
	Program removeTail();
	bool remove(int );

	Program& get(int);

	void print();

	void save(const char* );
	void load(const char* );
	LinkedList searchByName(std::string );

	bool isEmpty();
};

LinkedList operator+ (const Program&, const LinkedList&);
LinkedList operator+ (const LinkedList&, const Program&);