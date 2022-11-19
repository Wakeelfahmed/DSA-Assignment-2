#pragma once
#include<iostream>
using namespace std;
class Time
{
	int HR, MIN;
public:
	Time();
	Time(int HR, int MIN);
	void setTime(int HR, int MIN);
	int get_HR() const;
	int get_Min() const;
	void Display_Time() const;
	bool operator<(Time t) const;
	bool operator>(Time t) const;
	~Time();
};

