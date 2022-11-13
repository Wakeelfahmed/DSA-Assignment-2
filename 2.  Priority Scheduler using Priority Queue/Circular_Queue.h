#pragma once
class Circular_Queue
{
private:
	int* myArray;
	int front, rear, count, size;
public:
	int get_Front() const;
	int get_Rear() const;
	Circular_Queue(int);
	bool isEmpty();
	bool isFull();
	void Enqueue(int value);
	int dequeue();
	void Display_Queue();
};


