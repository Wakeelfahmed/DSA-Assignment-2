#include"Node.h"
#include<iostream>
using namespace std;
Node::Node() : next(0) {}
Node::Node(Children Data) : Data(Data), next(0) {}