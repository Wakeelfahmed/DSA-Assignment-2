#pragma once
#include<iostream>
using namespace std;
class Children
{
private:
	string Name;
	int age;
public:
	Children();
	Children(string Name, int age);
	void set_Name(string Name);
	void set_age(int age);
	string get_Name() const;
	int get_age() const;
	bool operator==(Children c1);
	void input();
};

