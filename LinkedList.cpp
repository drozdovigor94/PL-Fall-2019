#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "LinkedList.h"

template <typename T>
LinkedList<T>::ListElement::ListElement(T* element)
{
	this->element = element;
	this->next = nullptr;
}

template <typename T>
LinkedList<T>::ListElement::~ListElement()
{
	delete element;
}

template <typename T>
T& LinkedList<T>::getByNegativeIndex(int neg_index)
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
		throw ListWrongIndexException(neg_index);
	}
	else
	{
		return this->get(pos_index);
	}
}

template <typename T>
LinkedList<T>::LinkedList()
{
	head = nullptr;
	tail = nullptr;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other)
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

template <typename T>
LinkedList<T>::~LinkedList()
{
	ListElement* current_element = head;
	while (current_element)
	{
		ListElement* temp = current_element;
		current_element = current_element->next;
		delete temp;
	}
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other)
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

template <typename T>
LinkedList<T>& LinkedList<T>::operator+=(const T& rhs)
{
	this->addTail(rhs);
	return *this;
}

// TODO: rework for template
template <typename T>
std::ostream& operator<< (std::ostream& os, const LinkedList<T>& rhs)
{
	typename LinkedList<T>::ListElement* current_element;
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

// TODO: rework for template
template <typename T>
void operator<< (std::ofstream& ofs, const LinkedList<T>& rhs)
{
	typename LinkedList<T>::ListElement* current_element = rhs.head;

	if (ofs.is_open())
	{
		while (current_element)
		{
			ofs << current_element->element->toString() << "\n";
			current_element = current_element->next;
		}
	}
}

template <typename T>
void operator>> (std::ifstream& ifs, LinkedList<T>& rhs)
{
	T element;

	if (ifs.is_open())
	{
		while (ifs.peek() != EOF)
		{
			ifs >> element;
			rhs.addTail(element);
		}
	}
}

template <typename T>
T& LinkedList<T>::operator[] (int index)
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

template <typename T>
LinkedList<T> operator+ (const T& lhs, const LinkedList<T>& rhs)
{
	LinkedList<T> lst = rhs;
	lst.addHead(lhs);
	return lst;
}

template <typename T>
LinkedList<T> operator+ (const LinkedList<T>& lhs, const T& rhs)
{
	LinkedList<T> lst = lhs;
	lst.addTail(rhs);
	return lst;
}

template <typename T>
void LinkedList<T>::addTail(const T& element)
{
	ListElement* temp = new ListElement(new T(element));
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

template <typename T>
void LinkedList<T>::addHead(const T& element)
{
	ListElement* temp = new ListElement(new T(element));
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

template <typename T>
void LinkedList<T>::insert(const T& element, int place)
{
	if (place < 0)
	{
		throw ListWrongIndexException(place);
	}

	// if we're inserting at the beginning of the list, simply call addHead() method
	if (place == 0)
	{
		this->addHead(element);
	}
	// but if not, and the list is empty, that's an error
	else if (!head)
	{
		throw ListWrongIndexException(place);
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
		}
		// ...or the place we want is out of the list's range, so it's an error
		else
		{
			throw ListWrongIndexException(place);
		}

	}
	// we're inside the list and we need to insert new element in place of existing one
	else
	{
		ListElement* temp = new ListElement(new T(element));
		prev_element->next = temp;
		temp->next = current_element;
	}
}

template <typename T>
T LinkedList<T>::removeHead()
{
	// can't remove from empty list
	if (!head)
	{
		throw ListEmptyOpException();
	}
	// if list has only one element
	else if (head == tail)
	{
		T res = *head->element;
		delete head;
		head = nullptr;
		tail = nullptr;
		return res;
	}
	// if list has more than one element
	else
	{
		T res = *head->element;
		ListElement* temp = head;
		head = temp->next;
		delete temp;
		return res;
	}
}

template <typename T>
T LinkedList<T>::removeTail()
{
	// can't remove from empty list
	if (!head)
	{
		throw ListEmptyOpException();
	}
	// if list has only one element
	else if (head == tail)
	{
		T res = *tail->element;
		delete head;
		head = nullptr;
		tail = nullptr;
		return res;
	}
	// if list has more than one element
	else
	{
		T res = *tail->element;
		ListElement* current_element = head;
		while (current_element->next != tail)
		{
			current_element = current_element->next;
		}
		tail = current_element;
		delete current_element->next;
		current_element->next = nullptr;
		return res;
	}
}

template <typename T>
void LinkedList<T>::remove(int place)
{
	if (place < 0)
	{
		throw ListWrongIndexException(place);
	}

	if (place == 0)
	{
		this->removeHead();
	}
	else if (!head || head == tail)
	{
		throw ListWrongIndexException(place);
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
		throw ListWrongIndexException(place);
	}

	if (current_element == tail)
	{
		tail = prev_element;
		prev_element->next = nullptr;
		delete current_element;
	}
	else
	{
		prev_element->next = current_element->next;
		delete current_element;
	}
}

template <typename T>
void LinkedList<T>::print()
{
	ListElement* current_element;
	int i = 0;
	current_element = head;
	while (current_element)
	{
		std::cout << "Element #" << i << ":" << std::endl;
		std::cout << current_element->element << std::endl;
		current_element = current_element->next;
		i++;
	}
}

template <typename T>
T& LinkedList<T>::get(int place)
{
	int current_idx = 0;
	ListElement* current_element = head;

	if (place < 0)
	{
		throw ListWrongIndexException(place);
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
		throw ListWrongIndexException(place);
	}
}

// TODO: rework for template
template <typename T>
void LinkedList<T>::save(const char* filename)
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

// TODO: rework for template
template <typename T>
void LinkedList<T>::load(const char* filename)
{
	std::ifstream file(filename);
	std::string line;

	if (file.is_open())
	{
		while (getline(file, line))
		{
			this->addTail(T(line));
		}
	}
	file.close();
}

template <typename T>
bool LinkedList<T>::isEmpty()
{
	if (!head)
	{
		return true;
	}
	else
	{
		return false;
	}
}