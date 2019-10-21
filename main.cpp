#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

#include "Program.h"
#include "LinkedList.h"
#include "PushPop.h"
#include "Stack.h"
#include "Queue.h"

void testPushPop(PushPop* pp)
{
	pp->push(Program("MyApp", "1.0", true, true, false, 9.99, "Me", false, "C++"));
	pp->push(Program("Someone's App", "2.3b", true, false, true, 0, "Some jerk", true, "Java"));
	pp->push(Program("YetAnotherApp", "0.7", false, true, false, 5, "Unknown", false, "ObjectiveC"));
	pp->push(Program("Instagram", "3.5", true, true, true, 0, "Facebook", false, "Java"));

	while (!pp->isEmpty())
	{
		std::cout << pp->pop();
	}
}

int main()
{
	LinkedList lst;
	std::ifstream ifs("list.txt");
	ifs >> lst;
	std::cout << lst;

	return 0;
}