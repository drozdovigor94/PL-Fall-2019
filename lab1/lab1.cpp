#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

#include "Program.h"
#include "LinkedList.h"

int main()
{
	LinkedList list1;
	//lst->addTail(new Program("MyApp", "1.0", true, true, false, 9.99, "Me", false, "C++"));
	//lst->addTail(new Program("Someone's App", "2.3b", true, false, true, 0, "Some jerk", true, "Java"));
	//lst->addTail(new Program("YetAnotherApp", "0.7", false, true, false, 5, "Unknown", false, "ObjectiveC"));
	//lst->insert(new Program("Instagram", "3.5", true, true, true, 0, "Facebook", false, "Java"), 2);
	list1.load("list.txt");
	std::ofstream ofs("list2.txt");
	ofs << list1;
	ofs.close();
	LinkedList list2;
	std::ifstream ifs("list2.txt");
	ifs >> list2;
	std::cout << list2;
	//Program prog("TestApp", "0.1a", true, true, true, 5, "TestGroup", true, "Python");
	//prog = list1[3];
	return 0;
}