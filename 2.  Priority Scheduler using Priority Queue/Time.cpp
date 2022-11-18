#include "Time.h"
#include<iostream>
#include<iomanip>
using namespace std;
Time::Time() : HR(0), MIN(0) {}
Time::Time(int HR, int MIN) : HR(HR), MIN(MIN) {}
void Time::setTime(int HR, int MIN)
{
	this->HR = HR;	this->MIN = MIN;
}
void Time::Display_Time() const
{
	if (HR < 10) { cout << std::setfill(' ') << std::setw(14); cout << "0"; }
	cout << HR << ":";
	if (MIN < 10) cout << "0";
	cout << MIN;
}
int Time::get_HR() const { return HR; }
int Time::get_Min() const { return MIN; }
bool Time::operator<(Time t)const
{
	if (HR < t.HR && MIN < t.MIN)
		return true;
	/*if (HR <= t.HR && MIN < t.MIN)
		return true;*/
	else if (HR == t.HR && MIN < t.MIN)
		return true;
	//return false;
	//cout << "FALSE";
	//return isFemale && !compareHuman.isFemale;
}
bool Time::operator>(Time t)const
{
	if (HR > t.HR && MIN > t.MIN)
		return true;
	/*if (HR <= t.HR && MIN < t.MIN)
		return true;*/
	else if (HR == t.HR && MIN > t.MIN)
		return true;
	//return false;
	//cout << "FALSE";
	//return isFemale && !compareHuman.isFemale;
}
bool Time::operator==(Time t)const
{
	if (HR == t.HR && MIN == t.MIN)
		return true;
	return false;
	//cout << "FALSE";
}
Time::~Time() {
	HR = 0; MIN = 0;
}