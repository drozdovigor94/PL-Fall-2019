#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

#include "Program.h"
#include "LinkedList.h"
#include "PushPop.h"

#include "LinkedList.h"
#include "Program.h"

#include<iostream>
#include<fstream>

//void testPushPop(PushPop* pp)
//{
//	pp->push(Program("MyApp", "1.0", true, true, false, 9.99, "Me", false, "C++"));
//	pp->push(Program("Someone's App", "2.3b", true, false, true, 0, "Some jerk", true, "Java"));
//	pp->push(Program("YetAnotherApp", "0.7", false, true, false, 5, "Unknown", false, "ObjectiveC"));
//	pp->push(Program("Instagram", "3.5", true, true, true, 0, "Facebook", false, "Java"));
//
//	while (!pp->isEmpty())
//	{
//		std::cout << pp->pop();
//	}
//}

bool programEqualsName(const Program& prog, const std::string& name)
{
	if (prog.getName() == name)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool programGreaterThanPrice(const Program& prog, const double& price)
{
	if (prog.getPrice() > price)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool doubleLEQ(const double& d, const double& value)
{
	if (d <= value)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	LinkedList<Program> lst;
	std::ifstream ifs("list.txt");
	ifs >> lst;
	std::cout << lst << "\n\n\n";
	LinkedList<Program> filteredLst = lst.filter<std::string>("YetAnotherApp", &programEqualsName);
	std::cout << "Filtered List:" << std::endl;
	std::cout << filteredLst;

}