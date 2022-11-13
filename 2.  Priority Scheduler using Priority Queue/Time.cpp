#include "Time.h"
#include<iostream>
using namespace std;
void Time::setTime(int HR, int MIN, int SEC)
{
	this->HR = HR;	this->MIN = MIN;	this->SEC = SEC;
}
void Time::showTime()
{
	cout << endl
		<< HR << ":" << MIN << ":" << SEC;
}
void Time::normalize()// time in standard form
{
	MIN = MIN + SEC / 60;
	SEC = SEC % 60;
	HR = HR + MIN / 60;
	MIN = MIN % 60;
}