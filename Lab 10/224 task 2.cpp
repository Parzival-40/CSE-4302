#include <iostream>

using namespace std;

class A {
private:
	int i;
	string s;
	double d;

public:
	A(int i, string s, double d)
	  : i(i), s(s), d(d) {}	   //costructor
	A(const A& b)
	  : A(b.i, b.s, b.d) {}		 //copy initialization
	A operator=(const A& b) {	 //assignment operator
		return A(b.i, b.s, b.d);
	}
	void display() {
		cout << i << ' ' << s << ' ' << d << endl;
	}

	/*public:
	A(const A& b);
	A& operator=(const A&);*/
};

int main() {
	A a(1, "str", 1.2);	   //calling the constructor
	cout << 'a' << ": ";
	a.display();
	A b(2, "smr", 1.4);
	cout << 'b' << ": ";
	b.display();
	A t(a);	   //calling copy constructor
	cout << 't' << ": ";
	t.display();
	a = b;	  //calling assignment operator
	cout << 'a' << ": ";
	a.display();
	b = t;
	cout << 'b' << ": ";
	b.display();
}
