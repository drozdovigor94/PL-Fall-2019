#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

#include "Program.h"
#include "LinkedList.h"
#include "Stack.h"
#include "Stack.h"

int main()
{
	//LinkedList list1;
	////lst->addTail(new Program("MyApp", "1.0", true, true, false, 9.99, "Me", false, "C++"));
	////lst->addTail(new Program("Someone's App", "2.3b", true, false, true, 0, "Some jerk", true, "Java"));
	////lst->addTail(new Program("YetAnotherApp", "0.7", false, true, false, 5, "Unknown", false, "ObjectiveC"));
	////lst->insert(new Program("Instagram", "3.5", true, true, true, 0, "Facebook", false, "Java"), 2);
	//std::ifstream ifs("list.txt");
	//ifs >> list1;
	//ifs.close();
	//std::cout << list1;
	////Program prog("TestApp", "0.1a", true, true, true, 5, "TestGroup", true, "Python");

	Stack s;
	s.push(Program("MyApp", "1.0", true, true, false, 9.99, "Me", false, "C++"));
	s.push(Program("Someone's App", "2.3b", true, false, true, 0, "Some jerk", true, "Java"));
	s.push(Program("YetAnotherApp", "0.7", false, true, false, 5, "Unknown", false, "ObjectiveC"));
	s.push(Program("Instagram", "3.5", true, true, true, 0, "Facebook", false, "Java"));

	std::cout << s << "\n\n\n";

	std::cout << s.pop() << "\n";
	std::cout << s.pop() << "\n\n\n";

	std::cout << s << "\n";
	return 0;
}