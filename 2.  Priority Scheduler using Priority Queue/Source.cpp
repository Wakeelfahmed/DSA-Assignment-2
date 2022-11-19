#include"Process.h"
#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
#include<queue>     //Header-file for queue
#include<iomanip>
using namespace std;
int Levels_of_Priorities, Number_Of_Processes;
priority_queue<Process> Priority_Process_Schedule; //STL Priority Queue
Process Temp_for_Process; //temp storage for Processes
void Read_fr_File_AND_Push_to_Priority_Queue() {
	ifstream file("Input.txt");
	if (!file) {
		cout << "File(Input.txt) Not Found !!\n"; _getch(); exit(1);
	}
	file >> Levels_of_Priorities >> Number_Of_Processes;
	string Time; //For Time in file, then convert to int.
	while (!file.eof())
	{
		file >> Temp_for_Process.Process_Name >> Temp_for_Process.Priority >> Time >> Temp_for_Process.Execution_Time;
		Temp_for_Process.Extract_Time_fr_string(Time);//seperates ':' and gives hr & min in int.
		Priority_Process_Schedule.push(Temp_for_Process);
	}
}
int main() {
	Read_fr_File_AND_Push_to_Priority_Queue();//Read Processes fr file & push to Priority Queue
	cout << "Levels of Priorities:" << Levels_of_Priorities
		<< "\nNumber Of Processes:" << Number_Of_Processes << endl; //Read(red) fr File
	cout << "\x1b[3;96mPriority\tProcess Name\t\tArrival Time(hr:min)\tExecution Time(mins)\n\033[0m";//Italic text
	int Total_Execution_Time = 0;
	while (!Priority_Process_Schedule.empty())
	{
		Temp_for_Process = Priority_Process_Schedule.top();
		Priority_Process_Schedule.pop();
		Total_Execution_Time += Temp_for_Process.Execution_Time;
		cout << setfill(' ') << setw(5) << Temp_for_Process.Priority
			<< setfill(' ') << setw(28) << Temp_for_Process.Process_Name
			<< setfill(' ') << setw(15); Temp_for_Process.Arrival_Time.Display_Time();
		cout << setfill(' ') << setw(21) << Temp_for_Process.Execution_Time << endl;
	}
	cout << "\nTotal Completion Time is:" << Total_Execution_Time << " mins\n\n";
	cout << "\033[5m\t\tExit?\033[0m"; //Blinking text
	_getch();
}