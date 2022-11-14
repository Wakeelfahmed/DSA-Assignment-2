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
	Process() :Process_Name(""), Priority(0), execution_time(0) {}
	void Display_Process_Details() const {
		cout << "Process Name: " << Process_Name << endl;
		cout << "Priority: " << Priority << endl;
		cout << "Arrival Time: "; arrival_time.Display_Time();
		cout << "Execution Time: " << execution_time << " Mins" << endl;
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
	//void Sort(Process Process_Array[], int Number_of_Process) {
	//	int j;
	//	cout << "List Before Sorting\n";
	//	for (int i = 0; i < Number_of_Process; i++)
	//	{
	//		Process_Array[i].Display_Process_Details();
	//	}
	//	for (int loop = 1; loop <= Number_of_Process; loop++) {
	//		for (j = 1; j <= Number_of_Process - loop; j++) {
	//			if (Process_Array[j].Priority < Process_Array[j + 1].Priority == 1)
	//			{
	//				Process Temp = Process_Array[j];
	//				Process_Array[j] = Process_Array[j + 1];
	//				Process_Array[j + 1] = Temp;
	//				//Process.insert_after(Process[j + 1], Process[j]);
	//				//Process.delete_Account_Node_fr_list(Process.get_Account_Node(j)->Account_Data);
	//			}
	//		}
	//	}
	//	cout << "\nSorted List:\n";
	//	for (int i = 0; i < Number_of_Process; i++)
	//	{
	//		Process_Array[i].Display_Process_Details();
	//	}
	//}
};