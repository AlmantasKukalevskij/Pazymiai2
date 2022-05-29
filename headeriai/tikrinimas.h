#pragma once

#include <iostream>
#include <sstream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;

class tikrinimas
{
private:

public:
	tikrinimas();
	~tikrinimas();
	int validMode(int from, int to);
	int IntTikrinimas();
	bool PazTikrinimas(int t);
};





