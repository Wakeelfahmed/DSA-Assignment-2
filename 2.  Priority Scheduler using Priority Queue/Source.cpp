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
void read_File(Process p1[]) {
	ifstream file("Input.txt");
	if (!file) {
		cout << "File Not Found"; return;
	}
	int Levels_of_Priorities, Number_Of_Processes;
	file >> Levels_of_Priorities;
	file >> Number_Of_Processes;
	cout << "Levels_of_Priorities:" << Levels_of_Priorities
		<< "\nNumber_Of_Processes:" << Number_Of_Processes << endl;
	string Time, Hrs, Min;
	while (!file.eof())
	{
		int i = 0, loop = 0;
		file >> p1[loop].Process_Name >> Time >> p1[loop].execution_time >> p1[loop].Priority;
		p1[i].Extract_Time_fr_string(Time);
		/*while (Time[i] != ':')
		{
			Hrs += Time[i];
			i++;
		}
		p1[loop].arrival_time.HR = stoi(Hrs);
		for (i++; i < Time.size(); i++)
			Min += Time[i];
		p1[loop].arrival_time.MIN = stoi(Min);*/
		p1[loop].Display_Process_Details();
		cout << endl;
		loop++;
	}
}
int main() {
	Process p1[50];
	read_File(p1);
	Circular_Queue Queue(10);
	int val = 0;
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