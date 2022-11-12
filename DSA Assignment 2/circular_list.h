#pragma once
#include"Node.h"
class circular_list
{
private:
	Node* head;
public:
	circular_list();
	Node* get_head() const;
	void insert_beg(int v);
	void insert_end(int value);
	void insert_specfic_Position(int place, int value);
	void insert_after(int oldvalue, int newvalue);
	void delete_Node(int Value_to_delete);
	void Display_list() const;
	bool isEmpty() const;
	int Number_of_Nodes()const;
	~circular_list();
	circular_list concatenate(const circular_list & list2);
	circular_list(circular_list& list);	//Copy constructor
	Node* getNode(int pos);
};