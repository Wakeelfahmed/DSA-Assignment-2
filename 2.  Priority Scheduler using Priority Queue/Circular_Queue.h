#pragma once
#include"Process.h"
class Circular_Queue
{
//private:
public:
	Process* myArray;
	int front, rear, count, size;
	Process get_Front() const;
	Process get_Rear() const;
	Circular_Queue(int);
	bool isEmpty();
	bool isFull();
	void Enqueue(Process value);
	Process dequeue();
	void Display_Queue();
};


