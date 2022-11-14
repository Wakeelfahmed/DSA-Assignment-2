#include"Circular_Queue.h"
#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
#include"Process.h"
using namespace std;
void Display_font_rear(Circular_Queue Queue) {
	cout << "Front:" << Queue.get_Front() << "  Rear:" << Queue.get_Rear() << endl;
}
int Levels_of_Priorities, Number_Of_Processes;
void read_File(Process p1[]) {
	ifstream file("Input.txt");
	if (!file) {
		cout << "File Not Found"; return;
	}
	file >> Levels_of_Priorities;
	file >> Number_Of_Processes;
	cout << "Levels_of_Priorities:" << Levels_of_Priorities
		<< "\nNumber_Of_Processes:" << Number_Of_Processes << endl;
	string Time, Hrs, Min;
	int loop = 0;
	while (!file.eof())
	{
		file >> p1[loop].Process_Name >> p1[loop].Priority >> Time >> p1[loop].execution_time;
		p1[loop].Extract_Time_fr_string(Time);
		loop++;
	}
	cout << endl;
}
void Swap(Process& Process_Array, Process& Process_Array1) {
	Process Temp = Process_Array1;
	Process_Array1 = Process_Array;
	Process_Array = Temp;
}
void Sort(Process Process_Array[], int Number_of_Process) {
	int j;
	cout << "Array Before Sorting\n";
	for (int i = 0; i < Number_of_Process; i++)
		Process_Array[i].Display_Process_Details();
	for (int loop = 0; loop < Number_of_Process; loop++)
		for (j = 0; j < Number_of_Process - loop; j++) {
			if (Process_Array[j].Priority < Process_Array[j + 1].Priority == 1)
			{
				Swap(Process_Array[j], Process_Array[j + 1]);
				/*	Process Temp = Process_Array[j];
					Process_Array[j] = Process_Array[j + 1];
					Process_Array[j + 1] = Temp;*/
			}
			if (Process_Array[j].Priority == Process_Array[j + 1].Priority
				&& !(Process_Array[j].arrival_time < Process_Array[j + 1].arrival_time == 1)) {
				Swap(Process_Array[j], Process_Array[j + 1]);
				/*Process Temp = Process_Array[j];
				Process_Array[j] = Process_Array[j + 1];
				Process_Array[j + 1] = Temp;*/
			}
		}
	cout << "\Array List:\n";
	for (int i = 0; i < Number_of_Process; i++)
		Process_Array[i].Display_Process_Details();

}
int main() {
	Process p1[50];
	read_File(p1);
	Circular_Queue Queue(10);
	int val = 0;
	Sort(p1, Number_Of_Processes);
	//while (val != 100)
	//{
	//	cout << "Enter value to enqueue"; cin >> val;
	//	Queue.Enqueue(val);
	//	Queue.Display_Queue();
	//}
	//system("CLS");
	//while (1)
	//{
	//	Queue.Display_Queue();
	//	Queue.dequeue();
	//	_getch();
	//}
}