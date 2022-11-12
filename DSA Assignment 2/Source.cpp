#include<iostream>
#include"circular_list.h"
#include<conio.h>
using namespace std;
void Play_Game(circular_list& list) {
	Node* p = list.get_head();
	bool check = 1;
	list.Display_list();
	cout << "# of Nodes " << list.Number_of_Nodes() << endl;
	int Value_to_delete;
	int Timer_set = 20;
	int Timer_Count = Timer_set, round = 0;
	time_t cd, start, end, timetaken;
	while (1)
	{
		cout << "Game Running: \n";
		start = time(0);
		do
		{
			cout << p->Data << "\n";
			//cout << "Timer:" << Timer_Count << "\t";
			end = time(0);
			timetaken = end - start;
			cout << "Timer:" << timetaken << "\t";
			//if (Timer_Count == 0)
			if (timetaken == Timer_set)
			{
				cout << "Time taken by round:" << timetaken << endl;
				/*cout << "Timer: " << Timer_Count << "\t";
				cout << p->Data << "\n";*/
				check = 0;
				Timer_Count = Timer_set;
				break;
			}
			p = p->next;
			Timer_Count--;
			//for (size_t i = 0; i < 5000000000; i++) {}
			//for (size_t i = 0; i < 500000900; i++) {}
		} while (check == 1);
		cout << "End Time:" << end << endl;
		check = 1;
		cout << "\nROUND " << round << "  eliminated " << p->Data << endl << endl;
		cout << "Time taken by round:" << end - start << endl;
		round++;
		Value_to_delete = p->Data;
		p = p->next;
		list.delete_Node(Value_to_delete);
		if (list.Number_of_Nodes() == 1) {
			cout << "\nWinner is " << p->Data << endl;
			return;
		}
		list.Display_list();
		_getch();
		for (size_t i = 0; i < 100000000; i++)
		{

		}
	}
}
int main() {
	Node* p = NULL;
	circular_list mylist;
	mylist.insert_end(95);
	mylist.insert_end(100);
	mylist.insert_end(12);
	mylist.insert_end(65);
	mylist.insert_end(84);
	mylist.insert_end(41);
	mylist.insert_end(1);
	int input;
	Play_Game(mylist);
	//cout << "Enter # of children playing\n";
	//int Input[2];
	//cin >> Input[0];
	/*for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < mylist.Number_of_Nodes(); j++)
		{
			p = mylist.getNode(j);
		}
	}
	cout << "winner is;" << p->Data << endl;*/
}