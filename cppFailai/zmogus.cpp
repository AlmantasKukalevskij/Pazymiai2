#include "zmogus.h"

void zmogus::setFirstName(string& name)
{
	this->vardas = name;
}
void zmogus::setFirstName(std::istream& name)
{
	name >> this->vardas;
}
void zmogus::setLastName(string& name)
{
	this->pavarde = name;
}
void zmogus::setLastName(std::istream& name)
{
	name >> this->pavarde;
}
std::string zmogus::getFirstName() const
{
	return vardas;
}
std::string zmogus::getLastName() const
{
	return pavarde;
}
zmogus::zmogus() : vardas(""), pavarde("")
{

}
zmogus::~zmogus()
{

}