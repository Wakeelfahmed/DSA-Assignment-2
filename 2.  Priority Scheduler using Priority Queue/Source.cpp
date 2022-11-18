#include"Circular_Queue.h"
#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
#include<queue>     //Header-file for queue
#include<iomanip>
#include<Windows.h>
using namespace std;
int loop = 0;
HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
void Display_font_rear(Circular_Queue Queue) {
	SetConsoleTextAttribute(Console, 10); cout << "FRONT REAR::   Front[" << Queue.front << "]:" << Queue.get_Front().Process_Name << "       " << Queue.get_Rear().Process_Name << " : Rear[" << Queue.rear << "]" << endl;
	SetConsoleTextAttribute(Console, 15);
}
priority_queue<Process> PQ;
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
	loop = 0;
	while (!file.eof())
	{
		file >> p1[loop].Process_Name >> p1[loop].Priority >> Time >> p1[loop].Execution_Time;
		p1[loop].Extract_Time_fr_string(Time);
		//p1[loop].Display_Process_Details();
		loop++;
	}
	cout << endl;
}
void Swap(Process& Process1, Process& Process2) {
	Process Temp = Process2;
	Process2 = Process1;
	Process1 = Temp;
}
void Sort(Process Process_Array[], int Number_of_Process) {
	int j;
	cout << "\nArray Before Sorting\n";
	for (loop = 0; loop < Number_of_Process; loop++)
		Process_Array[loop].Display_Process_Details();
	for (loop = 0; loop < Number_of_Process; loop++)
		for (j = 0; j < Number_of_Process - loop; j++) {
			if (Process_Array[j].Priority < Process_Array[j + 1].Priority == 1)
				Swap(Process_Array[j], Process_Array[j + 1]);
			if (Process_Array[j].Priority == Process_Array[j + 1].Priority
				&& !(Process_Array[j].Arrival_Time < Process_Array[j + 1].Arrival_Time == 1))
				Swap(Process_Array[j], Process_Array[j + 1]);
		}
	cout << "\nArray After Sorting:\n";
	for (loop = 0; loop < Number_of_Process; loop++)
		Process_Array[loop].Display_Process_Details();
}
int main() {
	Process p1[50];
	read_File(p1);
	Circular_Queue Queue(10);
	int val = 0;
	//Sort(p1, Number_Of_Processes);
	loop = 0;
	//_getch();
	//system("CLS");
	while (loop != Number_Of_Processes)
	{
		PQ.push(p1[loop]);
		//Queue.Enqueue(p1[loop]);
		//Queue.Display_Queue();
		//Display_font_rear(Queue);
		//_getch();
		loop++;
		/*if (loop == 5)
			cout << "a";*/
			//cout << endl;
	}
	//system("CLS");
	int Sum = 0;
	SetConsoleTextAttribute(Console, 11);
	cout << "\x1b[3mPriority\tProcess Name\t\tArrival Time(hr:min)\tExecution Time(mins)\n";
	SetConsoleTextAttribute(Console, 15);
	while (!PQ.empty())
	{
		Process p = PQ.top();
		PQ.pop();
		Sum += p.Execution_Time;
		cout << std::setfill(' ') << std::setw(5) << p.Priority
			<< std::setfill(' ') << std::setw(28) << p.Process_Name;
			//<< "\t\t";		//if (p.Process_Name.size() <= 6) cout << "\t";
		cout << std::setfill(' ') << std::setw(15); p.Arrival_Time.Display_Time();
		cout << std::setfill(' ') << std::setw(21) << p.Execution_Time << endl;
	}
	cout << "\nTotal Completion Time Is :" << Sum << " mins\n";
	//while (1)
	//{
	//	//Display_font_rear(Queue);
	//	//Queue.Display_Queue();
	//	//Queue.dequeue();
	//	_getch();
	//	cout << endl;
	//}
	_getch();
}