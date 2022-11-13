#pragma once
#include"Children.h"
class Node
{
public:
	Children Data;
	Node* next;
	Node();
	Node(Children Data);
};