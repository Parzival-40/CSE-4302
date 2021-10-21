#include "Person.h"

Person::Person(string name, int age, string address){
	this->name = name;
	this->age = age;
	this->address = address;
}

ostream& operator<<(ostream& out, const Person& obj){
	out << obj.name << "     " << obj.age << "   " << obj.address << endl;
	return out;
}