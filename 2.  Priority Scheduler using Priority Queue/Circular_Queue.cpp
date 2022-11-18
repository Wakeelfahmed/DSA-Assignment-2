#include "Circular_Queue.h"
#include<iostream>
using namespace std;
Circular_Queue::Circular_Queue(int s)
{
	myArray = new Process[s];
	size = s;
	front = rear = count = 0;
}
Process Circular_Queue::get_Front() const {
	return myArray[front];
}
Process Circular_Queue::get_Rear() const {
	return myArray[rear + 1];
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
void Circular_Queue::Enqueue(Process value) {
	if (!isFull())
	{
		myArray[rear] = value;
		rear = (rear + 1) % size;
		count++;
	}
	else
		cout << "Queue Overflow";
}
Process Circular_Queue::dequeue() {
	if (!isEmpty()) {
		Process val = myArray[front];
		myArray[front].~Process();
		front = (front + 1) % size;
		count--;
		return val;
	}
	else
		cout << "Queue Underflow";
}
//Process Circular_Queue::dequeue() {
//	if (!isEmpty()) {
//		Process val = myArray[front];
//		myArray[front].Process_Name = "";
//		if (front == rear) {
//			front = -1;
//			rear = -1;
//		}
//		// Q has only one element,
//		// so we reset the queue after deleting it.
//		else {
//			front = (front + 1) % size;
//		}
//		return val;
//		//cout << "Dequeuing " << val.Process_Name << endl;
//		//front = (front + 1) % size;
//		//count--;
//		//return val;
//	}
//	else
//		cout << "Queue Underflow";
//	//return -1;
//}
void Circular_Queue::Display_Queue() {
	int i;
	if (isEmpty())
	{
		cout << "Queue is empty\n"; return;
	}
	cout << "Front: ";
	for (i = front; i != rear; i = ((i + 1) % size)) {
		cout << myArray[i].Process_Name << "     "; // print elem
	}
	cout << "\b\b\b:Rear\n";
}