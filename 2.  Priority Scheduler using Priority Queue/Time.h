#pragma once
#include<iostream>
using namespace std;
class Time
{
public:
	int HR, MIN;
	Time();
	Time(int HR, int MIN);
	void setTime(int HR, int MIN);
	void normalize();
	//Time operator+(Time t)
	//{
	//	Time temp;
	//	temp.SEC = SEC + t.SEC;
	//	temp.MIN = MIN + t.MIN;
	//	temp.HR = HR + t.HR;
	//	temp.normalize();
	//	return (temp);
	//}
	bool operator==(Time t)
	{
		if (HR == t.HR && MIN == t.MIN)
			return true;
		return false;
	}
	int get_HR() const;
	int get_Min() const;
	void Display_Time() const;
	bool operator<(Time t)const;
	bool operator>(Time t)const;
	bool operator==(Time t)const;
	~Time();
};

