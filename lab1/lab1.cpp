#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

class Program 
{
private:
	string name, version, developer, lang;
	bool android, ios, free, open_source;
	float price;

public:
	// constructors
	Program(string name, string version, bool android, bool ios, bool free, float price, string developer, bool open_source, string lang)
	{
		this->name = name;
		this->version = version;
		this->android = android;
		this->ios = ios;
		this->free = free;
		this->price = price;
		this->developer = developer;
		this->open_source = open_source;
		this->lang = lang;
	}
	Program()
	{
		this->name = "None";
		this->version = "None";
		this->android = false;
		this->ios = false;
		this->free = false;
		this->price = 0;
		this->developer = "None";
		this->open_source = false;
		this->lang = "None";
	}
	Program(string repr)
	{
		fromString(repr);
	}
	// destructor
	~Program()
	{

	}

	// getters and setters
	string getName() {return name;}
	void setName(string name) {this->name = name;}

	string getVersion() { return version; }
	void setVersion(string version) { this->version = version; }

	bool getAndroid() { return android; }
	void setAndroid(bool android) { this->android = android; }

	bool getIos() { return ios; }
	void setIos(bool ios) { this->ios = ios; }

	bool getFree() { return free; }
	void setFree(bool free) { this->free = free; }

	float getPrice() { return price; }
	void setPrice(float price) { this->price = price; }

	string getDeveloper() { return developer; }
	void setDeveloper(string developer) { this->developer = developer; }

	bool getOpenSource() { return open_source; }
	void setOpenSource(bool open_source) { this->open_source = open_source; }

	string getLang() { return lang; }
	void setLang(string lang) { this->lang = lang; }

	void read() 
	{
		cout << "Name?\n> ";
		cin >> name;
		cout << "Version?\n> ";
		cin >> version;
		cout << "Android? (0 or 1)\n> ";
		cin >> android;
		cout << "iOS? (0 or 1)\n> ";
		cin >> ios;
		cout << "Free? (0 or 1)\n> ";
		cin >> free;
		cout << "Price?\n> ";
		cin >> price;
		cout << "Developer?\n> ";
		cin >> developer;
		cout << "Open-source? (0 or 1)\n> ";
		cin >> open_source;
		cout << "Language?\n> ";
		cin >> lang;
	}

	void print() 
	{
		cout << left << setw(1) << "|" << setw(20) << "Name" << setw(1) << "|"
			 << setw(8) << "Version" << setw(1) << "|"
			 << setw(8) << "Android" << setw(1) << "|"
			 << setw(5) << "iOS" << setw(1) << "|"
			 << setw(5) << "Free" << setw(1) << "|"
			 << setw(6) << "Price" << setw(1) << "|"
			 << setw(20) << "Developer" << setw(1) << "|"
			 << setw(12) << "Open-source" << setw(1) << "|"
			 << setw(12) << "Language" << setw(1) << "|" << endl;
		cout << setfill('-');
		cout << left << setw(1) << "|" << setw(20) << "-" << setw(1) << "|"
			<< setw(8) << "-" << setw(1) << "|"
			<< setw(8) << "-" << setw(1) << "|"
			<< setw(5) << "-" << setw(1) << "|"
			<< setw(5) << "-" << setw(1) << "|"
			<< setw(6) << "-" << setw(1) << "|"
			<< setw(20) << "-" << setw(1) << "|"
			<< setw(12) << "-" << setw(1) << "|"
			<< setw(12) << "-" << setw(1) << "|" << endl;
		cout << boolalpha << setfill(' ');
		cout << left << setw(1) << "|" << setw(20) << name << setw(1) << "|"
			 << setw(8) << version << setw(1) << "|"
			 << setw(8) << android << setw(1) << "|"
			 << setw(5) << ios << setw(1) << "|"
			 << setw(5) << free << setw(1) << "|"
			 << setw(6) << price << setw(1) << "|"
			 << setw(20) << developer << setw(1) << "|"
			 << setw(12) << open_source << setw(1) << "|"
			 << setw(12) << lang << setw(1) << "|" << endl;
	}

	string toString()
	{
		ostringstream oss;
		oss << name << "|" << version << "|" << android << "|"
			<< ios << "|" << free << "|" << price << "|"
			<< developer << "|" << open_source << "|" << lang << "|";
		return oss.str();
	}

	void fromString(string str)
	{
		string field_value;
		stringstream ss(str);

		getline(ss, field_value, '|');
		name = field_value; 

		getline(ss, field_value, '|');
		version = field_value;

		getline(ss, field_value, '|');
		istringstream(field_value) >> android;

		getline(ss, field_value, '|');
		istringstream(field_value) >> ios;

		getline(ss, field_value, '|');
		istringstream(field_value) >> free;

		getline(ss, field_value, '|');
		istringstream(field_value) >> price;

		getline(ss, field_value, '|');
		developer = field_value;

		getline(ss, field_value, '|');
		istringstream(field_value) >> open_source;

		getline(ss, field_value, '|');
		lang = field_value;
	}
};


class LinkedList
{
private:
	struct ListElement
	{
		Program* element;
		ListElement* next;

		ListElement(Program* element)
		{
			this->element = element;
			this->next = nullptr;
		}

		~ListElement()
		{
			delete element;
		}
	};

	ListElement* head;
	ListElement* tail;

public:
	LinkedList()
	{
		head = nullptr;
		tail = nullptr;
	}

	~LinkedList()
	{
		ListElement* current_element = head;
		while (current_element) 
		{
			ListElement* temp = current_element;
			current_element = current_element->next;
			delete temp;
		}
	}

	void addTail(Program* element)
	{
		ListElement* temp = new ListElement(element);
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

	void addHead(Program* element)
	{
		ListElement* temp = new ListElement(element);
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

	void print()
	{
		ListElement* current_element;
		int i = 0;
		current_element = head;
		while (current_element)
		{
			cout << "Element #" << i << ":" << endl;
			current_element->element->print();
			cout << endl;
			current_element = current_element->next;
			i++;
		}
	}

	bool insert(Program* element, int place)
	{
		if (place < 0)
		{
			cout << "List insert failed: index " << place <<" is not a valid index" << endl;
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
			cout << "List insert failed: index " << place << " is out of list's range" << endl;
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
				cout << "List insert failed: index " << place << " is out of list's range" << endl;
				return false;
			}

		}
		// we're inside the list and we need to insert new element in place of existing one
		else
		{
			ListElement* temp = new ListElement(element);
			prev_element->next = temp;
			temp->next = current_element;
			return true;
		}
	}

	bool removeHead()
	{
		// can't remove from empty list
		if (!head)
		{
			cout << "Failed to remove head element: list is empty" << endl;
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

	bool removeTail()
	{
		// can't remove from empty list
		if (!head)
		{
			cout << "Failed to remove tail element: list is empty" << endl;
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

	bool remove(int place)
	{
		if (place < 0)
		{
			cout << "List remove failed: index " << place << " is not a valid index" << endl;
			return false;
		}

		if (place == 0)
		{
			return this->removeHead();
		}
		else if (!head || head == tail) 
		{
			cout << "Failed to remove element: index " << place << " is out of list's range" << endl;
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
			cout << "Failed to remove element: index " << place << " is out of list's range" << endl;
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

	void save(const char* filename)
	{
		ofstream file(filename);
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

	void load(const char* filename)
	{
		ifstream file(filename);
		string line;

		if (file.is_open())
		{
			while (getline(file, line))
			{
				this->addTail(new Program(line));
			}
		}
		file.close();
	}

	LinkedList* searchByName(string name)
	{
		LinkedList* result_list = new LinkedList();
		ListElement* current_element = head;

		while (current_element)
		{
			if (current_element->element->getName() == name)
			{
				result_list->addTail(current_element->element);
			}
			current_element = current_element->next;
		}

		return result_list;
	}
};

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