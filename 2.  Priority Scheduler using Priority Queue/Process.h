#pragma once
#include"Time.h"
#include<string.h>
using namespace std;
class Process
{
public:
	string Process_Name;
	int Priority;
	Time arrival_time;
	int execution_time;
};