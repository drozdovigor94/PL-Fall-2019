#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

#include "Program.h"


Program::Program(std::string name, std::string version, bool android, bool ios, bool free, double price, std::string developer, bool open_source, std::string lang) :
	name(name), version(version), android(android), ios(ios), free(free), price(price), developer(developer), open_source(open_source), lang(lang) {}

Program::Program()
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
Program::Program(std::string repr)
{
	fromString(repr);
}

Program::~Program()
{

}

std::string Program::getName() { return name; }
void Program::setName(std::string name) { this->name = name; }

std::string Program::getVersion() { return version; }
void Program::setVersion(std::string version) { this->version = version; }

bool Program::getAndroid() { return android; }
void Program::setAndroid(bool android) { this->android = android; }

bool Program::getIos() { return ios; }
void Program::setIos(bool ios) { this->ios = ios; }

bool Program::getFree() { return free; }
void Program::setFree(bool free) { this->free = free; }

double Program::getPrice() { return price; }
void Program::setPrice(float price) { this->price = price; }

std::string Program::getDeveloper() { return developer; }
void Program::setDeveloper(std::string developer) { this->developer = developer; }

bool Program::getOpenSource() { return open_source; }
void Program::setOpenSource(bool open_source) { this->open_source = open_source; }

std::string Program::getLang() { return lang; }
void Program::setLang(std::string lang) { this->lang = lang; }

void Program::read()
{
	using namespace std;

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

void Program::print()
{
	using namespace std;
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

std::string Program::toString()
{
	std::ostringstream oss;
	oss << name << "|" << version << "|" << android << "|"
		<< ios << "|" << free << "|" << price << "|"
		<< developer << "|" << open_source << "|" << lang << "|";
	return oss.str();
}

void Program::fromString(std::string str)
{
	std::string field_value;
	std::stringstream ss(str);

	getline(ss, field_value, '|');
	name = field_value;

	getline(ss, field_value, '|');
	version = field_value;

	getline(ss, field_value, '|');
	std::istringstream(field_value) >> android;

	getline(ss, field_value, '|');
	std::istringstream(field_value) >> ios;

	getline(ss, field_value, '|');
	std::istringstream(field_value) >> free;

	getline(ss, field_value, '|');
	std::istringstream(field_value) >> price;

	getline(ss, field_value, '|');
	developer = field_value;

	getline(ss, field_value, '|');
	std::istringstream(field_value) >> open_source;

	getline(ss, field_value, '|');
	lang = field_value;
}