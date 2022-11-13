#pragma once
class Time
{
public:
	int HR, MIN, SEC;
	void setTime(int x, int y, int z);
	void showTime();
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
};

