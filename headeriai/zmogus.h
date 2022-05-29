#pragma once

#include <iostream>
#include <string>
#include <fstream>

using std::string;

class zmogus
{
protected:
	string vardas;
	string pavarde;

public:
	virtual void f() = 0;
public:
	zmogus();
	~zmogus();
	zmogus(const zmogus& z);
	void setFirstName(string& name);
	void setFirstName(std::istream& name);
	void setLastName(string& name);
	void setLastName(std::istream& name);
	void setEgzaminas(int paz);

	std::string getFirstName() const;
	std::string getLastName() const;
};