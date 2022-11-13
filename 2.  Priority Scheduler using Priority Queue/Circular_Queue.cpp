#include "Circular_Queue.h"
#include<iostream>
using namespace std;
Circular_Queue::Circular_Queue(int s)
{
	myArray = new int[s];
	size = s;
	front = rear = count = 0;
}
int Circular_Queue::get_Front() const {
	return myArray[front];
}
int Circular_Queue::get_Rear() const {
	return myArray[rear-1];
}
bool Circular_Queue::isEmpty() {
	if (count == 0)
		return true;
	else
		return false;
}
bool Circular_Queue::isFull() {
	if (count == size)
		return true;
	else
		return false;
}
void Circular_Queue::Enqueue(int value) {
	if (!isFull())
	{
		myArray[rear] = value;
		rear = (rear + 1) % size;
		count++;
	}
	else
		cout << "Queue Overflow";
}
int Circular_Queue::dequeue() {
	if (!isEmpty()) {
		int val = myArray[front];
		front = (front + 1) % size;
		count--;
		return val;
	}
	else
		cout << "Queue Underflow";
	return -1;
}
void Circular_Queue::Display_Queue() {
	cout << "Front: ";
	for (int i = 0; i < count; i++)
	{
		cout << myArray[i] << "    ";
	}
	cout << "\b\b\b:Rear\n";
}