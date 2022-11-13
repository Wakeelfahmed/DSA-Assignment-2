#pragma once
#include"Node.h"
class circular_list
{
private:
	Node* head;
public:
	circular_list();
	Node* get_head() const;
	void insert_beg(Children v);
	void insert_end(Children value);
	void insert_specfic_Position(int place, Children value);
	void insert_after(Children oldvalue, Children newvalue);
	void delete_Node(Children Value_to_delete);
	void Display_list(Children data) const;
	void Display_list() const;
	bool isEmpty() const;
	int Number_of_Nodes()const;
	Node* getNode(int pos);
};