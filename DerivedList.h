#pragma once
#include <list>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>

template <typename T>
class DerivedList : public std::list<T>
{
public:
	void print();
	void save(const char* filename);
	void load(const char* filename);
	DerivedList<T>& operator+= (const T& rhs);
};

template <typename T>
void DerivedList<T>::print()
{
	for (T element : *this)
	{
		std::cout << element << "\n";
	}
}

template <typename T>
void DerivedList<T>::save(const char* filename)
{
	std::ofstream file(filename);

	if (file.is_open())
	{
		for (T element : *this)
		{
			file << element << "\n";
		}
	}
	file.close();
}

template <typename T>
void DerivedList<T>::load(const char* filename)
{
	std::ifstream file(filename);
	T element;

	if (file.is_open())
	{
		while (file >> element)
		{
			this->push_back(element);
		}
	}
	file.close();
}

template <typename T>
DerivedList<T>& DerivedList<T>::operator+= (const T& rhs)
{
	this->push_back(rhs);
	return *this;
}

template <typename T>
std::ostream& operator<< (std::ostream& os, const DerivedList<T>& rhs)
{
	for (T element : rhs)
	{
		os << element << "\n";
	}
	return os;
}

template <typename T>
void operator<< (std::ofstream& ofs, const DerivedList<T>& rhs)
{
	if (ofs.is_open())
	{
		for (T element : rhs)
		{
			ofs << element << "\n";
		}
	}
}

template <typename T>
void operator>> (std::ifstream& ifs, DerivedList<T>& rhs)
{
	T element;

	if (ifs.is_open())
	{
		while (ifs >> element)
		{
			rhs.push_back(element);
		}
	}
}

template <typename T>
DerivedList<T> operator+ (const DerivedList<T>& lhs, const DerivedList<T>& rhs)
{
	DerivedList<T> result(lhs);
	std::copy(rhs.begin(), rhs.end(), std::back_inserter(result));
	return result;
}