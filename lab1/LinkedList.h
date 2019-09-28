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
	LinkedList(const LinkedList&);
	~LinkedList();

	LinkedList& operator= (const LinkedList&);

	LinkedList& operator+= (const Program&);
	LinkedList& operator-= (const std::string&);

	friend std::ostream& operator<< (std::ostream&, const LinkedList&);

	friend void operator<< (std::ofstream&, const LinkedList&);
	friend void operator>> (std::ifstream&, LinkedList&);

	Program& operator[] (int index);

	void addTail(Program );
	void addHead(Program );
	bool insert(Program , int );

	bool removeHead();
	bool removeTail();
	bool remove(int );

	Program& get(int);

	void print();

	void save(const char* );
	void load(const char* );
	LinkedList searchByName(std::string );
};

LinkedList operator+ (const Program&, const LinkedList&);
LinkedList operator+ (const LinkedList&, const Program&);