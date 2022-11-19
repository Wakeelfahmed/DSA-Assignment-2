#pragma once
#include"Time.h"
class Process
{
public:
	string Process_Name;
	int Priority;
	Time Arrival_Time; //hr:min
	int Execution_Time; //in Mins
	void set_Arrival_Time(int HR, int min) {
		Arrival_Time.setTime(HR, min);
	}
	Process();
	void Display_Process_Details() const;
	void Extract_Time_fr_string(string Time);
	~Process();
	bool operator<(Process p2) const;
};