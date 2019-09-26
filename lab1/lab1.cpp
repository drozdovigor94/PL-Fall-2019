#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

#include "Program.h"
#include "LinkedList.h"

int main()
{
	LinkedList lst;
	//lst->addTail(new Program("MyApp", "1.0", true, true, false, 9.99, "Me", false, "C++"));
	//lst->addTail(new Program("Someone's App", "2.3b", true, false, true, 0, "Some jerk", true, "Java"));
	//lst->addTail(new Program("YetAnotherApp", "0.7", false, true, false, 5, "Unknown", false, "ObjectiveC"));
	//lst->insert(new Program("Instagram", "3.5", true, true, true, 0, "Facebook", false, "Java"), 2);
	lst.load("list.txt");
	Program* test_element = new Program("YetAnotherApp", "0.3a", true, true, false, 5.99, "Nobody", false, "Python");
	lst.insert(test_element, 1);
	lst.print();
	LinkedList* filtered_lst = lst.searchByName("YetAnotherApp");
	filtered_lst->print();
	return 0;
}