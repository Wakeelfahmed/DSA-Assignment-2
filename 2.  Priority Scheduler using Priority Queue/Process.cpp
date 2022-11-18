#include"Process.h"
#include<string.h>
#include<string>
using namespace std;
Process::Process() :Process_Name(""), Priority(0), Execution_Time(0) {}
void Process::Display_Process_Details() const {
	cout << "Process Name: " << Process_Name << endl;
	cout << "Priority: " << Priority << endl;
	cout << "Arrival Time: "; Arrival_Time.Display_Time();
	cout << "   Execution Time: " << Execution_Time << " Mins" << endl;
}
void Process::Extract_Time_fr_string(string Time) {
	string HR, Min; //seperate Time in hrs & mins -> store in Temp strings 
	//-> convert string to int & store in arrival_time. 
	int i = 0;
	while (Time[i] != ':')
	{
		HR += Time[i];
		i++;
	}
	Arrival_Time.HR = stoi(HR);
	for (i++; i < Time.size(); i++) //start fr One index ahead to skip ':'
		Min += Time[i];
	Arrival_Time.MIN = stoi(Min);
}
Process::~Process() {
	Process_Name = ""; Priority = 0; Execution_Time = 0;
}
bool Process::operator<(Process p2) const {
	if (Priority == p2.Priority) {
		return (Arrival_Time < p2.Arrival_Time);
	}
	return (Priority > p2.Priority);
}
