#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

class Person {
protected:
	string name;
	int age;
	string gender;

public:
	Person(string n, int a, string g)
	  : name(n), age(a), gender(g) {}
	virtual void speak() = 0;
};

class Male : public Person {
public:
	Male(string n, int a)
	  : Person(n, a, "Male") {}
	virtual void speak() {
		cout << "Hello, my name is " << name << '.' << endl;
	}
};

class Female : public Person {
public:
	Female(string n, int a)
	  : Person(n, a, "Female") {}
	virtual void speak() {
		cout << "Hi, you can call me " << name << '.' << endl;
	}
};

class Boy : public Male {
public:
	Boy(string n, int a)
	  : Male(n, a) {}
	void speak() {
		Male::speak();
		cout << "And i like playing football." << endl;
	}
};

class Man : public Male {
public:
	Man(string n, int a)
	  : Male(n, a) {}
	void speak() {
		Male::speak();
		cout << "I have a stable job." << endl;
	}
};

class Girl : public Female {
public:
	Girl(string n, int a)
	  : Female(n, a) {}
	void speak() {
		Female::speak();
		cout << "I like chocolate." << endl;
	}
};

class Woman : public Female {
public:
	Woman(string n, int a)
	  : Female(n, a) {}
	void speak() {
		Female::speak();
		cout << "I want a stable job." << endl;
	}
};

string inline genName() {
	int size = rand() % 3 + 3;
	string name = "";
	while (size--) {
		name += 'a' + rand() % 26;
	}
	return name;
}

int inline genAge() {
	return 12 + rand() % 20;
}

int inline genGender() {
	return rand() % 2;
}

int main() {
	srand(time(nullptr));
	Person* array[5] = {};
	for (auto& i : array) {
		string name = genName();
		int age = genAge();
		int gender = genGender();
		if (gender) {
			if (age < 18)
				i = new Boy(name, age);
			else
				i = new Man(name, age);
		} else {
			if (age < 18)
				i = new Girl(name, age);
			else
				i = new Woman(name, age);
		}
	}
	for (auto& i : array) {
		i->speak();
		cout << endl;
	}
}
