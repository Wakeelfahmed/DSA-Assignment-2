#pragma once
#include"Time.h"
#include<string.h>
using namespace std;
class Process
{
public:
	string Process_Name;
	int Priority;
	Time arrival_time;
	int execution_time;//in Mins
	void Display_Process_Details() const {
		cout << "Process Name:" << Process_Name << endl;
		cout << "Priority:" << Priority << endl;
		cout << "Arrival Time:"; arrival_time.Display_Time();
		cout << "Execution Time:" << execution_time << " Mins" << endl;
	}
	void Extract_Time_fr_string(string Time) {
		string HR, Min; //seperate Time in hrs & mins -> store in Temp strings 
		//-> convert string to int & store in arrival_time. 
		int i = 0;
		while (Time[i] != ':')
		{
			HR += Time[i];
			i++;
		}
		arrival_time.HR = stoi(HR);
		for (i++; i < Time.size(); i++) //start fr One index ahead to skip ':'
			Min += Time[i];
		arrival_time.MIN = stoi(Min);
	}
	void Sort() {
		for (int i = 0; i < length; i++)
		{

		}
	}
};