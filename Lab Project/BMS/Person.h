#pragma once
#include <iostream>
using namespace std;
class Person{
public:
	Person(string name, int age, string address);
	friend ostream& operator <<(ostream& out, const Person& obj);
protected:
	string name;
	int age;
	string address;
};
