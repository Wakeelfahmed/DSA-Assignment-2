#include<iostream>
#include"circular_list.h"
#include<conio.h>
#include<ctime>
#include<windows.h>
using namespace std;
HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
int Search_in_list(Children Value_to_Search, circular_list list) {
	int pos = 1;
	Node* p = list.get_head();
	do
	{
		if (p->Data == Value_to_Search)
			return pos;
		p = p->next;
		pos++;
	} while (p != list.get_head());
	return -1; // Not in list
}
void Play_Game(circular_list list, int Timer_set) {

	bool check = 1;
	cout << "Starting Players:";	list.Display_list();
	cout << "# of Starting Players " << list.Number_of_Nodes() << endl;
	int round = 1;
	Children Value_to_delete;
	time_t start, end, timetaken;
	circular_list duplicate_list;
	for (int i = 1; i <= list.Number_of_Nodes(); i++)
		duplicate_list.insert_end(list.getNode(i)->Data);
	Node* p = duplicate_list.get_head();
	cout << "\33[2K\n";
	while (1)
	{
		SetConsoleCursorPosition(Console, { 51,9 });
		cout << "\33[2KGame Running . . .";
		start = time(NULL);
		do
		{
			end = time(0);
			timetaken = end - start;
			SetConsoleCursorPosition(Console, { 57,3 });
			cout << "Timer:" << (Timer_set - timetaken) << " ";
			SetConsoleCursorPosition(Console, { 30,5 });
			duplicate_list.Display_list(p->Data);
			for (size_t i = 0; i < 59999999; i++) {} //Artifical Lag(optional) in the see the Working of game .
			if (timetaken == Timer_set)
			{
				cout << "\n\33[2K\Round:" << round << "  Eliminated: \"" << p->Data.get_Name() << "\"" << endl;
				check = 0;
				break;
			}
			p = p->next;
		} while (check == 1);
		check = 1;
		round++;
		Value_to_delete = p->Data;
		p = p->next;
		duplicate_list.delete_Node(Value_to_delete);
		cout << "\33[2KPlayers in Game -> ";
		duplicate_list.Display_list();
		if (duplicate_list.Number_of_Nodes() == 1) {
			SetConsoleTextAttribute(Console, 10);
			SetConsoleCursorPosition(Console, { 45,9 });
			cout << "\33[2KWinner is " << p->Data.get_Name() << " \tPos in List was: " << Search_in_list(p->Data, list) << endl;
			SetConsoleTextAttribute(Console, 15);
			SetConsoleCursorPosition(Console, { 48,12 });
			cout << "Press any key to Leave\n";
			_getch();
			return;
		}
		SetConsoleCursorPosition(Console, { 48,9 });
		cout << "\33[2KPress any key to Resume Round";
		_getch();
		SetConsoleCursorPosition(Console, { 30,5 });
		cout << "\33[2K\n";
	}
}
int input[2];
void Main_Menu() {
	cout << "WELCOME TO HOT POTATO GAME\n";
	cout << "1. Add Players     2. Remove Players     3. Start Game     4.Display Players     5. Exit Game\n";
	input[0] = _getch() - '0';
	system("CLS");
}
int main() {
	Node* p = NULL;
	circular_list list;
	Children c1("Wakeel", 19);
	list.insert_end(c1);
	Children c2("Mubeen", 19);
	list.insert_end(c2);
	Children c3("Kaleem", 19);
	list.insert_end(c3);
	Children c4("qwertyuiop", 19);
	list.insert_end(c4);
	Children c5("qwertyuisdffsop", 19);
	list.insert_end(c5);
	while (1)
	{
		Main_Menu();
		switch (input[0]) {
			case 1:
			{
				c1.input();
				list.insert_end(c1);
				break;
			}
			case 2:
			{
				cout << "Enter Details of Player to remove\n";
				c1.input();
				list.delete_Node(c1);
				break;
			}
			case 3:
			{
				if (list.isEmpty() || list.Number_of_Nodes() == 1)
				{
					cout << "No Enough Players In Game !\n\n"; break;
				}
				cout << "Set the timer of the Game:";
				cin >> input[1];
				Play_Game(list, input[1]);
				system("CLS");
				break;
			}
			case 4:
			{
				cout << "Players in game are:\n";
				list.Display_list();    cout << "\n";
				break;
			}
			case 5:
			{
				exit(0);
			}
		}
	}
}