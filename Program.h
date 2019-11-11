#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

class Program 
{
private:
	std::string name, version, developer, lang;
	bool android, ios, free, open_source;
	double price;
public:
	Program(std::string , std::string , bool , bool , bool , double , std::string , bool , std::string );
	Program();
	Program(std::string);
	~Program();

	friend bool operator==(const Program&, const Program&);
	friend bool operator==(const std::string&, const Program&);
	friend bool operator==(const Program&, const std::string&);

	friend bool operator<(const Program&, const Program&);
	friend bool operator<(const Program&, const double&);

	friend bool operator>(const Program&, const Program&);
	friend bool operator>(const Program&, const double&);

	friend std::ostream& operator<< (std::ostream&, const Program&);
	friend std::istream& operator>> (std::istream&, Program&);

	friend std::ofstream& operator<< (std::ofstream&, const Program&);
	friend std::ifstream& operator>> (std::ifstream&, Program&);

	std::string getName() const;
	void setName(std::string );

	std::string getVersion() const;
	void setVersion(std::string );

	bool getAndroid() const;
	void setAndroid(bool );

	bool getIos() const;
	void setIos(bool );

	bool getFree() const;
	void setFree(bool );

	double getPrice() const;
	void setPrice(float );

	std::string getDeveloper() const;
	void setDeveloper(std::string );

	bool getOpenSource() const;
	void setOpenSource(bool );

	std::string getLang() const;
	void setLang(std::string );

	void read();
	void print();

	std::string toString();
	void fromString(std::string );
};
