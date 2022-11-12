#include"circular_list.h"
#include<iostream>
using namespace std;
circular_list::circular_list() : head(NULL) { }
Node* circular_list::get_head() const { return head; }
bool circular_list::isEmpty() const {
	if (head == NULL)
		return true;
	return false;
}
void circular_list::insert_beg(int v) {
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
void circular_list::insert_specfic_Position(int Position, int newvalue) {
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
void circular_list::insert_after(int oldvalue, int newvalue) {
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
void circular_list::insert_end(int value) {
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
	cout << "List: \t";
	do
	{
		cout << p->Data << "\t";
		p = p->next;
	} while (p != head);
	cout << endl;
	//Node* temp = head;
}
int Search_in_List(int Value_to_search, circular_list& list) {
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
void circular_list::delete_Node(int Value_to_delete) {
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
circular_list circular_list::concatenate(const circular_list& list2) {
	circular_list Result = *this;
	Node* p = get_head();	Node* loop2 = list2.get_head();
	while (p->next != get_head())
		p = p->next;
	while (loop2->next != list2.get_head())
		loop2 = loop2->next;
	loop2->next = head;	//connect last node of list2 to head of list1 making circular
	p->next = list2.get_head();//connect last node of list1 to head of list2.
	cout << "Concatenated list is:\n";
	Result.Display_list();
	return Result;
}
int circular_list::Number_of_Nodes() const {
	if (isEmpty())
	{
		cout << "list is empty!! \n there are no nodes." << endl;
		return 0;
	}
	int Counter = 0;
	Node* p = head;
	do{
		Counter++;
		p = p->next;
	} while (p != head);
	return Counter;
}
circular_list::~circular_list() {
	//cout << "Entering ~\n";
	if (isEmpty())
		return;
	Node* p = head;
	Node* q = head->next;
	do {
		//cout << "Deleteing:" << p->Data << endl;
		delete p;
		p = q;
		if (p != head)
			q = q->next;
		if (p == head) {
			//cout << "Returing ~\n";
			//return;
		}
	} while (p != head);
	//cout << "Leaving ~\n";
}
circular_list::circular_list(circular_list& list) {
	head = list.head;
}
Node* circular_list::getNode(int pos) {
	Node* p = head;
	if (isEmpty())
	{
		cout << "list is empty!!" << endl;
		return head;
	}
	int position = 0;
	cout << "List: \t";
	do
	{
		position++;
		if (position == pos)
		{
			return p;
		}
		cout << p->Data << "\t";
		p = p->next;
	} while (p != head);
}
