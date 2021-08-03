#include <iostream>

using namespace std;

class staff {
private:
	int code;
	string name;

public:
	staff(int code = 0, string name = "")
	  : code(code), name(name) {}

	void set_code(int c) {
		code = c;
	}
	void set_name(string n) {
		name = n;
	}

	int get_code() {
		return code;
	}
	string get_name() {
		return name;
	}

	virtual void whoAmI() {
		cout << "- Staff" << endl;
	}

	virtual void display() {
		cout << "Name: " << name << '\t'
			 << "Code: " << code << endl;
	}
};

class teacher : public staff {
private:
	string subject;
	string publication;

public:
	teacher(int code = 0, string name = "", string sub = "", string pub = "")
	  : staff(code, name), subject(sub), publication(pub) {}

	void set_subject(string sub) {
		subject = sub;
	}
	void set_publication(string pub) {
		publication = pub;
	}

	string get_subject() {
		return subject;
	}
	string get_publication() {
		return publication;
	}

	void whoAmI() {
		cout << "- Teacher ";
		staff::whoAmI();
	}

	void display() {
		staff::display();
		cout << "Subject: " << subject << '\t'
			 << "Publication: " << publication << endl;
	}
};

class officer : public staff {
private:
	string grade;

public:
	officer(int code = 0, string name = "", string grade = "")
	  : staff(code, name), grade(grade) {}

	void set_grade(string g) {
		grade = g;
	}
	string get_grade() {
		return grade;
	}

	void whoAmI() {
		cout << "- Officer ";
		staff::whoAmI();
	}

	void display() {
		staff::display();
		cout << "Grade: " << grade << endl;
	}
};

class typist : public staff {
private:
	double speed;

public:
	typist(int code = 0, string name = "", double speed = 0)
	  : staff(code, name), speed(speed) {}

	void set_speed(double s) {
		speed = s;
	}
	double get_speed() {
		return speed;
	}
	virtual void whoAmI() {
		cout << "- Typist ";
		staff::whoAmI();
	}
	virtual void display() {
		staff::display();
		cout << "Speed: " << speed << endl;
	}
};

class regular : public typist {
private:
	double wage;

public:
	regular(int code = 0, string name = "", double speed = 0, double wage = 0)
	  : typist(code, name, speed), wage(wage) {}

	void set_wage(double w) {
		wage = w;
	}
	double get_wage() {
		return wage;
	}

	void whoAmI() {
		cout << "- Regular ";
		typist::whoAmI();
	}

	void display() {
		typist::display();
		cout << "Wage: " << wage << endl;
	}
};

class casual : public typist {
private:
	double daily_wage;

public:
	casual(int code = 0, string name = "", double speed = 0, double daily_wage = 0)
	  : typist(code, name, speed), daily_wage(daily_wage) {}

	void set_daily_wage(double d) {
		daily_wage = d;
	}
	double get_daily_wage() {
		return daily_wage;
	}

	void whoAmI() {
		cout << "- Casual ";
		typist::whoAmI();
	}
	void display() {
		typist::display();
		cout << "Daily wage: " << daily_wage << endl;
	}
};

int main() {
	/*
	staff a;
	cout << "I am a ";
	a.whoAmI();
	a.display();
	*/
	teacher b(420, "Ataur", "programming with c++", "Tata McGraw Hill");
	cout << "I am a ";
	b.whoAmI();
	b.display();
	officer c(222, "Md. Rashed", "First class");
	cout << "I am a ";
	c.whoAmI();
	c.display();
	/*
	typist d;
	cout << "I am a ";
	d.whoAmI();
	d.display();
	*/
	regular e(333, "Robiul Awal", 85.5, 15000);
	cout << "I am a ";
	e.whoAmI();
	e.display();
	casual f(334, "Kawser Ahmed", 78.900002, 10000);
	cout << "I am a ";
	f.whoAmI();
	f.display();
}
