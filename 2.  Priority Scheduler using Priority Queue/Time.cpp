#include "Time.h"
#include<iostream>
using namespace std;
Time::Time() : HR(0), MIN(0) {}
Time::Time(int HR, int MIN) : HR(HR), MIN(MIN) {}
void Time::setTime(int HR, int MIN)
{
	this->HR = HR;	this->MIN = MIN;
}
void Time::Display_Time() const
{
	cout << HR << ":" << MIN << endl;
}
int Time::get_HR() const { return HR; }
int Time::get_Min() const { return MIN; }