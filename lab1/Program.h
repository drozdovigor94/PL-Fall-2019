#pragma once

#include <string>

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

	std::string getName();
	void setName(std::string );

	std::string getVersion();
	void setVersion(std::string );

	bool getAndroid();
	void setAndroid(bool );

	bool getIos();
	void setIos(bool );

	bool getFree();
	void setFree(bool );

	double getPrice();
	void setPrice(float );

	std::string getDeveloper();
	void setDeveloper(std::string );

	bool getOpenSource();
	void setOpenSource(bool );

	std::string getLang();
	void setLang(std::string );

	void read();
	void print();

	std::string toString();
	void fromString(std::string );
};