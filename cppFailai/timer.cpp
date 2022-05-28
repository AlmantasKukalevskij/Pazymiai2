#include "timer.h"

Timer::Timer() : praejesLaikas(0)
{

}
Timer::~Timer()
{

}
void Timer::Start()
{
	pradziosTaskas = hrClock::now();
	praejesLaikas = 0;
}
void Timer::Stop()
{
	praejesLaikas += durationDouble(hrClock::now() - pradziosTaskas).count();
}
void Timer::Resume()
{
	pradziosTaskas = hrClock::now();
}
double Timer::returnTime()
{
	return praejesLaikas;
}
double Timer::StopReturn()
{
	Stop();
	return returnTime();
}