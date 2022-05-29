#pragma once

#include <iostream>
#include <chrono>

using timePoint = std::chrono::time_point<std::chrono::high_resolution_clock>;
using durationDouble = std::chrono::duration<double>;
using hrClock = std::chrono::high_resolution_clock;

class Timer
{
private:
	timePoint pradziosTaskas;
	double praejesLaikas;

public:
	Timer();
	~Timer();
	void Start();
	void Stop();
	void Resume();
	double returnTime();
	double StopReturn();
};

