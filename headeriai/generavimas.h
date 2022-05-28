# pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <random>
#include <iomanip>
#include <string>
#include "timer.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::left;
using std::mt19937;
using std::setw;

class Generatorius
{
private:
	std::string file_name;
	int MokSkaicius;
	int ndSkaicius;
	Timer genTimer;

public:
	Generatorius();
	~Generatorius();
	void set_file_name(std::string name);
	void set_mok_count(int number);
	void set_nd_count(int number);

	int atsitiktinioPazKurimas();
	void failoGen();

	std::stringstream generateMokStringStream(int ndSkaicius);
	int randomInt(int from, int to);
	std::string randFirstName();
	std::string randLastName();
};

