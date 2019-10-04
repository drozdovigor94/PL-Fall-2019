#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "LinkedList.h"

LinkedList::ListElement::ListElement(Program* element)
{
	this->element = element;
	this->next = nullptr;
}

LinkedList::ListElement::~ListElement()
{
	delete element;
}

Program& LinkedList::getByNegativeIndex(int neg_index)
{
	ListElement* current_element = head;
	int size = 0;
	
	while (current_element)
	{
		size++;
		current_element = current_element->next;
	}

	int pos_index = size + neg_index;
	if (pos_index < 0)
	{
		std::cout << "Error getting list element: index is out of bounds" << std::endl;
		std::exit(1);
	}
	else
	{
		return this->get(pos_index);
	}
}

LinkedList::LinkedList()
{
	head = nullptr;
	tail = nullptr;
}

LinkedList::LinkedList(const LinkedList& other)
{
	head = nullptr;
	tail = nullptr;

	ListElement* current_element = other.head;
	while (current_element)
	{
		this->addTail(*(current_element->element));
		current_element = current_element->next;
	}
}

LinkedList::~LinkedList()
{
	ListElement* current_element = head;
	while (current_element)
	{
		ListElement* temp = current_element;
		current_element = current_element->next;
		delete temp;
	}
}

LinkedList& LinkedList::operator=(const LinkedList& other)
{
	if (this == &other)
	{
		return *this;
	}

	ListElement* current_element = head;
	while (current_element)
	{
		ListElement* temp = current_element;
		current_element = current_element->next;
		delete temp;
	}

	head = nullptr;
	tail = nullptr;

	current_element = other.head;
	while (current_element)
	{
		this->addTail(*(current_element->element));
		current_element = current_element->next;
	}

	return *this;
}

LinkedList& LinkedList::operator+=(const Program& rhs)
{
	this->addTail(rhs);
	return *this;
}

LinkedList& LinkedList::operator-=(const std::string& rhs)
{
	ListElement* current_element = head;
	ListElement* prev_element = nullptr;
	ListElement* temp;
	while (current_element)
	{
		if (*(current_element->element) == rhs)
		{
			if (current_element == head)
			{
				temp = current_element;
				current_element = current_element->next;
				head = current_element;
				delete temp;
			}
			else if (current_element == tail)
			{
				tail = prev_element;
				delete current_element;
				current_element = nullptr;
				prev_element->next = nullptr;
			}
			else
			{
				temp = current_element;
				prev_element->next = current_element->next;
				prev_element = current_element;
				current_element = current_element->next;
				delete temp;
			}
		}
		else
		{
			prev_element = current_element;
			current_element = current_element->next;
		}
	}
	return *this;
}

std::ostream& operator<< (std::ostream& os, const LinkedList& rhs)
{
	LinkedList::ListElement* current_element;
	int i = 0;
	current_element = rhs.head;
	while (current_element)
	{
		os << "Element #" << i << ":" << std::endl;
		os << *(current_element->element) << std::endl;
		current_element = current_element->next;
		i++;
	}
	
	return os;
}

void operator<< (std::ofstream& ofs, const LinkedList& rhs)
{
	LinkedList::ListElement* current_element = rhs.head;

	if (ofs.is_open())
	{
		while (current_element)
		{
			ofs << current_element->element->toString() << "\n";
			current_element = current_element->next;
		}
	}
}

void operator>> (std::ifstream& ifs, LinkedList& rhs)
{
	std::string line;

	if (ifs.is_open())
	{
		while (getline(ifs, line))
		{
			rhs.addTail(Program(line));
		}
	}
}

Program& LinkedList::operator[] (int index)
{	
	if (index < 0)
	{
		return this->getByNegativeIndex(index);
	}
	else
	{
		return this->get(index);
	}
}

LinkedList operator+ (const Program& lhs, const LinkedList& rhs)
{
	LinkedList lst = rhs;
	lst.addHead(lhs);
	return lst;
}

LinkedList operator+ (const LinkedList& lhs, const Program& rhs)
{
	LinkedList lst = lhs;
	lst.addTail(rhs);
	return lst;
}

void LinkedList::addTail(Program element)
{
	ListElement* temp = new ListElement(new Program(element));
	if (!head)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
}

void LinkedList::addHead(Program element)
{
	ListElement* temp = new ListElement(new Program(element));
	if (!head)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		temp->next = head;
		head = temp;
	}
}

bool LinkedList::insert(Program element, int place)
{
	if (place < 0)
	{
		std::cout << "List insert failed: index " << place << " is not a valid index" << std::endl;
		return false;
	}

	// if we're inserting at the beginning of the list, simply call addHead() method
	if (place == 0)
	{
		this->addHead(element);
		return true;
	}
	// but if not, and the list is empty, that's an error
	else if (!head)
	{
		std::cout << "List insert failed: index " << place << " is out of list's range" << std::endl;
		return false;
	}

	// if our list is not empty, we're traversing it
	// until we hit place we want or until list has ended
	int current_idx = 0;
	ListElement* current_element = head;
	ListElement* prev_element = nullptr;

	while (current_idx < place && current_element)
	{
		current_idx++;
		prev_element = current_element;
		current_element = current_element->next;
	}

	// the list has ended, but we're haven't yet inserted new element
	// so we have two options...
	if (!current_element)
	{
		// ...we may be at the empty place at the end of the list, just where we want
		// our new element to be; it's like add to the end of the list
		if (current_idx == place)
		{
			this->addTail(element);
			return true;
		}
		// ...or the place we want is out of the list's range, so it's an error
		else
		{
			std::cout << "List insert failed: index " << place << " is out of list's range" << std::endl;
			return false;
		}

	}
	// we're inside the list and we need to insert new element in place of existing one
	else
	{
		ListElement* temp = new ListElement(new Program(element));
		prev_element->next = temp;
		temp->next = current_element;
		return true;
	}
}

bool LinkedList::removeHead()
{
	// can't remove from empty list
	if (!head)
	{
		std::cout << "Failed to remove head element: list is empty" << std::endl;
		return false;
	}
	// if list has only one element
	else if (head == tail)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
		return true;
	}
	// if list has more than one element
	else
	{
		ListElement* temp = head;
		head = temp->next;
		delete temp;
		return true;
	}
}

bool LinkedList::removeTail()
{
	// can't remove from empty list
	if (!head)
	{
		std::cout << "Failed to remove tail element: list is empty" << std::endl;
		return false;
	}
	// if list has only one element
	else if (head == tail)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
		return true;
	}
	// if list has more than one element
	else
	{
		ListElement* current_element = head;
		while (current_element->next != tail)
		{
			current_element = current_element->next;
		}
		tail = current_element;
		delete current_element->next;
		current_element->next = nullptr;
		return true;
	}
}

bool LinkedList::remove(int place)
{
	if (place < 0)
	{
		std::cout << "List remove failed: index " << place << " is not a valid index" << std::endl;
		return false;
	}

	if (place == 0)
	{
		return this->removeHead();
	}
	else if (!head || head == tail)
	{
		std::cout << "Failed to remove element: index " << place << " is out of list's range" << std::endl;
		return false;
	}

	int current_idx = 0;
	ListElement* current_element = head;
	ListElement* prev_element = nullptr;

	while (current_idx < place && current_element)
	{
		current_idx++;
		prev_element = current_element;
		current_element = current_element->next;
	}

	if (!current_element)
	{
		std::cout << "Failed to remove element: index " << place << " is out of list's range" << std::endl;
		return false;
	}

	if (current_element == tail)
	{
		tail = prev_element;
		prev_element->next = nullptr;
		delete current_element;
		return true;
	}
	else
	{
		prev_element->next = current_element->next;
		delete current_element;
		return true;
	}
}

void LinkedList::print()
{
	ListElement* current_element;
	int i = 0;
	current_element = head;
	while (current_element)
	{
		std::cout << "Element #" << i << ":" << std::endl;
		current_element->element->print();
		std::cout << std::endl;
		current_element = current_element->next;
		i++;
	}
}

Program& LinkedList::get(int place)
{
	int current_idx = 0;
	ListElement* current_element = head;

	if (place < 0)
	{
		std::cout << "Error getting list element: index is out of bounds" << std::endl;
		std::exit(1);
	}

	while (current_idx < place && current_element)
	{
		current_idx++;
		current_element = current_element->next;
	}

	if (current_element)
	{
		return *(current_element->element);
	}
	else
	{
		std::cout << "Error getting list element: index is out of bounds" << std::endl;
		std::exit(1);
	}
}

void LinkedList::save(const char* filename)
{
	std::ofstream file(filename);
	ListElement* current_element = head;

	if (file.is_open())
	{
		while (current_element)
		{
			file << current_element->element->toString() << "\n";
			current_element = current_element->next;
		}
	}
	file.close();
}

void LinkedList::load(const char* filename)
{
	std::ifstream file(filename);
	std::string line;

	if (file.is_open())
	{
		while (getline(file, line))
		{
			this->addTail(Program(line));
		}
	}
	file.close();
}

LinkedList LinkedList::searchByName(std::string name)
{
	LinkedList result_list;
	ListElement* current_element = head;

	while (current_element)
	{
		if (*(current_element->element) == name)
		{
			result_list.addTail(*(current_element->element));
		}
		current_element = current_element->next;
	}

	return result_list;
}