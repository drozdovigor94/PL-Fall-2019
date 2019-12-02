#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm>


#include "Program.h"
#include "DerivedList.h"

bool comparePrice(const Program& a, const Program& b)
{
	return (a.getPrice() < b.getPrice());
}

struct findByNamePred
{
	char cond;
	std::string value;

	findByNamePred(char cond, const std::string value) : cond(cond), value(value) {}
	bool operator() (const Program& p)
	{
		switch (cond)
		{
		case '=':
			return (p.getName() == value);
			break;
		case '<':
			return (p.getName() < value);
			break;
		case '>':
			return (p.getName() > value);
			break;
		default:
			break;
		}
	}
};

int main()
{
	DerivedList<Program> lst;
	//lst->addTail(new Program("MyApp", "1.0", true, true, false, 9.99, "Me", false, "C++"));
	//lst->addTail(new Program("Someone's App", "2.3b", true, false, true, 0, "Some jerk", true, "Java"));
	//lst->addTail(new Program("YetAnotherApp", "0.7", false, true, false, 5, "Unknown", false, "ObjectiveC"));
	std::ifstream ifs("list.txt");
	ifs >> lst;
	DerivedList<Program> lst2;
	lst2.push_back(Program("MyApp", "1.0", true, true, false, 9.99, "Me", false, "C++"));
	lst2.push_back(Program("YetAnotherApp", "0.7", false, true, false, 5, "Unknown", false, "ObjectiveC"));
	//std::cout << (lst + lst2);
	
	//lst.sort(&comparePrice);
	//std::cout << lst;

	auto res = std::find_if(lst.begin(), lst.end(), findByNamePred('=', "YetAnotherApp"));
	std::cout << *res;

	return 0;
}