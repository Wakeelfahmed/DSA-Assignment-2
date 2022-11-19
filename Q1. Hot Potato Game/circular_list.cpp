#include"circular_list.h"
#include<iostream>
using namespace std;
#include<windows.h>
#include<iomanip>
HANDLE Console1 = GetStdHandle(STD_OUTPUT_HANDLE);
circular_list::circular_list() : head(NULL) { }
Node* circular_list::get_head() const { return head; }
bool circular_list::isEmpty() const {
	if (head == NULL)
		return true;
	return false;
}
void circular_list::insert_beg(Children v) {
	Node* NewNode = new Node(v);
	if (isEmpty()) {
		head = NewNode;
		NewNode->next = head;
	}
	else {
		NewNode->next = head;
		Node* p = head;
		while (p->next != head)
			p = p->next;
		head = NewNode;
		p->next = head;
	}
}
void circular_list::insert_specfic_Position(int Position, Children newvalue) {
	int position_count = 1;
	if (Position > Number_of_Nodes()) {
		cout << "List has less nodes than the place, Node CAN't be inserted!!\n";
		return;
	}
	Node* NewNode = new Node(newvalue);		//NewNode->Data = newvalue;
	Node* p = head;
	while (p != head)
	{
		if (Position == 1) {
			insert_beg(newvalue);
			return;
		}
		else if (Position == Number_of_Nodes()) {
			insert_end(newvalue);
			return;
		}
		else if (position_count == Position - 1 && Position != 0) {
			NewNode->next = p->next;
			p->next = NewNode;
			return;
		}
		p = p->next;		//move to next node
		position_count++;
	}
}
void circular_list::insert_after(Children oldvalue, Children newvalue) {
	Node* p = head;
	if (isEmpty())
		return;
	do
	{
		if (p->Data == oldvalue)
		{
			Node* NewNode = new Node(newvalue);
			NewNode->next = p->next;
			p->next = NewNode;
			return;
		}
		p = p->next;
	} while (p != head);
}
void circular_list::insert_end(Children value) {
	Node* NewNode = new Node(value);
	if (isEmpty()) {
		head = NewNode;
		NewNode->next = head;
	}
	else {
		Node* p = head;
		do
		{
			p = p->next;
		} while (p->next != head);
		p->next = NewNode;
		NewNode->next = head;
		return;
	}
}
void circular_list::Display_list() const {
	if (isEmpty())
	{
		cout << "list is empty!!" << endl;
		return;
	}
	Node* p = head;
	do
	{
		cout << p->Data.get_Name() << "     ";
		p = p->next;
	} while (p != head);
	cout << endl;
}
void circular_list::Display_list(Children data) const {
	if (isEmpty())
	{
		cout << "list is empty!!" << endl;
		return;
	}
	Node* p = head;
	do
	{
		if (p->Data == data) {
			SetConsoleTextAttribute(Console1, 64);
			cout << p->Data.get_Name();
			SetConsoleTextAttribute(Console1, 15);
			cout << "     ";
		}
		else
			cout << p->Data.get_Name() << "     ";
		p = p->next;
	} while (p != head);
}
int Search_in_List(Children Value_to_search, circular_list& list) {
	Node* p = list.get_head();
	int Position_counter = 1;
	do {
		if (p->Data == Value_to_search)
			return Position_counter;
		p = p->next;
		Position_counter++;
	} while (p != list.get_head());
	return 0; // no record found
}
void circular_list::delete_Node(Children Value_to_delete) {
	if (isEmpty()) {
		cout << "List is Empty\n"; return;
	}
	else if (!Search_in_List(Value_to_delete, *this)) {
		cout << "Not found in list\n"; return;
	}
	Node* p = head;
	Node* Temp;
	if (Value_to_delete == head->Data) {
		Temp = p;
		if (head->next == head) {
			delete Temp; head = NULL; return;
		}
		else
		{
			do
			{
				p = p->next;
			} while (p->next != head);
			p->next = head->next;
			head = head->next;
			delete Temp;
			return;
		}
	}
	else
	{
		p = head;
		do
		{
			if (p->next->Data == Value_to_delete)
			{
				Temp = p->next;
				p->next = p->next->next;
				delete Temp;
				return;
			}
			p = p->next;
		} while (p->next != head);
	}
}
int circular_list::Number_of_Nodes() const {
	if (isEmpty())
	{
		cout << "list is empty!! \n there are no nodes." << endl;
		return 0;
	}
	int Counter = 0;
	Node* p = head;
	do {
		Counter++;
		p = p->next;
	} while (p != head);
	return Counter;
}
Node* circular_list::getNode(int pos) {
	Node* p = head;
	if (isEmpty())
	{
		cout << "list is empty!!" << endl;
		return head;
	}
	int position = 0;
	//cout << "List: \t";
	do
	{
		position++;
		if (position == pos)
		{
			return p;
		}
		//cout << p->Data << "\t";
		p = p->next;
	} while (p != head);
}
