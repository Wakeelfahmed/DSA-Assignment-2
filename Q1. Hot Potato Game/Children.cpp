#include "Children.h"
Children::Children() : Name(""), age(0) { }
Children::Children(string Name, int age) : Name(Name), age(age) {}
void Children::set_Name(string Name) { this->Name = Name; }
void Children::set_age(int age) { this->age = age; }
string Children::get_Name()const { return Name; }
int Children::get_age()const { return age; }
bool Children::operator==(Children c1) {
	if (Name == c1.get_Name() && age == c1.get_age())
		return true;
	return false;
}
void Children::input() {
	cout << "Enter Player Name:"; cin >> Name;
	cout << "Enter Age:"; cin >> age;
}