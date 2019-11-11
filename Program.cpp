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

bool operator==(const Program& lhs, const Program& rhs)
{
	if (lhs.name == rhs.name)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator==(const std::string& lhs, const Program& rhs)
{
	if (lhs == rhs.name)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator==(const Program& lhs, const std::string& rhs)
{
	if (lhs.name == rhs)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator<(const Program& lhs, const Program& rhs)
{
	if (lhs.price < rhs.price)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator<(const Program& lhs, const double& rhs)
{
	if (lhs.price < rhs)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator>(const Program& lhs, const Program& rhs)
{
	if (lhs.price > rhs.price)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator>(const Program& lhs, const double& rhs)
{
	if (lhs.price > rhs)
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::ostream& operator<< (std::ostream& os, const Program& rhs)
{
	using namespace std;
	os << left << setw(1) << "|" << setw(20) << "Name" << setw(1) << "|"
		<< setw(8) << "Version" << setw(1) << "|"
		<< setw(8) << "Android" << setw(1) << "|"
		<< setw(5) << "iOS" << setw(1) << "|"
		<< setw(5) << "Free" << setw(1) << "|"
		<< setw(6) << "Price" << setw(1) << "|"
		<< setw(20) << "Developer" << setw(1) << "|"
		<< setw(12) << "Open-source" << setw(1) << "|"
		<< setw(12) << "Language" << setw(1) << "|" << endl;
	os << setfill('-');
	os << left << setw(1) << "|" << setw(20) << "-" << setw(1) << "|"
		<< setw(8) << "-" << setw(1) << "|"
		<< setw(8) << "-" << setw(1) << "|"
		<< setw(5) << "-" << setw(1) << "|"
		<< setw(5) << "-" << setw(1) << "|"
		<< setw(6) << "-" << setw(1) << "|"
		<< setw(20) << "-" << setw(1) << "|"
		<< setw(12) << "-" << setw(1) << "|"
		<< setw(12) << "-" << setw(1) << "|" << endl;
	os << boolalpha << setfill(' ');
	os << left << setw(1) << "|" << setw(20) << rhs.name << setw(1) << "|"
		<< setw(8) << rhs.version << setw(1) << "|"
		<< setw(8) << rhs.android << setw(1) << "|"
		<< setw(5) << rhs.ios << setw(1) << "|"
		<< setw(5) << rhs.free << setw(1) << "|"
		<< setw(6) << rhs.price << setw(1) << "|"
		<< setw(20) << rhs.developer << setw(1) << "|"
		<< setw(12) << rhs.open_source << setw(1) << "|"
		<< setw(12) << rhs.lang << setw(1) << "|" << endl;
	return os;
}

std::istream& operator>> (std::istream& is, Program& rhs)
{
	using namespace std;

	cout << "Name?\n> ";
	is >> rhs.name;
	cout << "Version?\n> ";
	is >> rhs.version;
	cout << "Android? (0 or 1)\n> ";
	is >> rhs.android;
	cout << "iOS? (0 or 1)\n> ";
	is >> rhs.ios;
	cout << "Free? (0 or 1)\n> ";
	is >> rhs.free;
	cout << "Price?\n> ";
	is >> rhs.price;
	cout << "Developer?\n> ";
	is >> rhs.developer;
	cout << "Open-source? (0 or 1)\n> ";
	is >> rhs.open_source;
	cout << "Language?\n> ";
	is >> rhs.lang;

	return is;
}

std::ofstream& operator<< (std::ofstream& ofs, Program& rhs)
{
	if (ofs.is_open())
	{
		ofs << rhs.toString();
	}
	return ofs;
}

std::ifstream& operator>> (std::ifstream& ifs, Program& rhs)
{
	std::string line;
	if (ifs.is_open())
	{
		if (getline(ifs, line))
		{
			rhs.fromString(line);
		}
	}
	return ifs;
}

std::string Program::getName() const { return name; }
void Program::setName(std::string name) { this->name = name; }

std::string Program::getVersion() const { return version; }
void Program::setVersion(std::string version) { this->version = version; }

bool Program::getAndroid() const { return android; }
void Program::setAndroid(bool android) { this->android = android; }

bool Program::getIos() const { return ios; }
void Program::setIos(bool ios) { this->ios = ios; }

bool Program::getFree() const { return free; }
void Program::setFree(bool free) { this->free = free; }

double Program::getPrice() const { return price; }
void Program::setPrice(float price) { this->price = price; }

std::string Program::getDeveloper() const { return developer; }
void Program::setDeveloper(std::string developer) { this->developer = developer; }

bool Program::getOpenSource() const { return open_source; }
void Program::setOpenSource(bool open_source) { this->open_source = open_source; }

std::string Program::getLang() const { return lang; }
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

