#include "Time.h"
#include<iostream>
using namespace std;
Time::Time() : HR(0), MIN(0), SEC(0) {}
Time::Time(int HR, int MIN) : HR(HR), MIN(MIN), SEC(0) {}
void Time::setTime(int HR, int MIN, int SEC)
{
	this->HR = HR;	this->MIN = MIN;	this->SEC = SEC;
}
void Time::Display_Time() const
{
	cout << HR << ":" << MIN << endl;
}
void Time::normalize()// time in standard form
{
	MIN = MIN + SEC / 60;
	SEC = SEC % 60;
	HR = HR + MIN / 60;
	MIN = MIN % 60;
}
int Time::get_HR() const { return HR; }
int Time::get_Min() const { return MIN; }