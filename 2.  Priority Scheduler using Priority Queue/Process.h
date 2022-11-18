#pragma once
#include"Time.h"
class Process
{
public:
	string Process_Name;
	int Priority;
	Time Arrival_Time;
	int Execution_Time;//in Mins
	Process();
	void Display_Process_Details() const;
	void Extract_Time_fr_string(string Time);
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
	~Process();
	bool operator<(Process p2) const;
	bool operator>(Process p2) const {
		if (Priority == p2.Priority)
			return (Arrival_Time < p2.Arrival_Time);
		else
			return (Priority > p2.Priority);
		return true;
	}

};