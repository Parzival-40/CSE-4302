#include <fstream>
#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

const int maxStaff = 10;

enum class staffType { invalid = -1,
					   teacher = 0,
					   officer,
					   typist };
enum class typistType { invalid = -1,
						regular = 0,
						casual };

class staff {
private:
	string name;
	int code;
	static int n;
	static staff* staffs[];

public:
	virtual ~staff() {}
	virtual void getdata();
	virtual void putdata();

	virtual staffType getType();

	static void clear();
	static void add();
	static void display();
	static void write();
	static void read();
};
int staff::n;
staff* staff::staffs[maxStaff];

class teacher : public staff {
private:
	string subject;
	string publication;

public:
	void getdata();
	void putdata();
};

class officer : public staff {
private:
	string grade;

public:
	void getdata();
	void putdata();
};

class typist : public staff {
private:
	double speed;

public:
	virtual void getdata();
	virtual void putdata();

	virtual typistType _getType();
};

class regular : public typist {
private:
	double wage;

public:
	void getdata();
	void putdata();
};

class casual : public typist {
private:
	double daily_wage;

public:
	void getdata();
	void putdata();
};

int main() {
	char ch;
	while (true) {
		cout << "'a' -- add data for an staff" << endl
			 << "'d' -- display data for all staffs" << endl
			 << "'w' -- write all staff data to file" << endl
			 << "'r' -- read all staff data from file" << endl
			 << "'x' -- exit" << endl
			 << "Enter selection: " << endl;
		cin >> ch;
		switch (ch) {
		case 'a':
			staff::add();
			break;
		case 'd':
			staff::display();
			break;
		case 'w':
			staff::write();
			break;
		case 'r':
			staff::read();
			break;
		case 'x':
			return 0;
			break;
		default:
			cout << "Unknown command" << endl;
			break;
		}
	}
	return 0;
}

void staff::getdata() {
	cin.ignore(10, '\n');
	cout << "Name : ";
	cin >> name;
	cout << "Code : ";
	cin >> code;
}

void staff::putdata() {
	cout << "  Name: " << name << endl;
	cout << "  Code: " << code << endl;
}

void teacher::getdata() {
	staff::getdata();
	cin.ignore(10, '\n');
	cout << "Subject : ";
	getline(cin, subject);
	cout << "Publication : ";
	getline(cin, publication);
}

void teacher::putdata() {
	staff::putdata();
	cout << "  Subject: " << subject << endl;
	cout << "  Publication: " << publication << endl;
}

void officer::getdata() {
	staff::getdata();
	cin.ignore(10, '\n');
	cout << "Grade : ";
	cin >> grade;
}

void officer::putdata() {
	staff::putdata();
	cout << "  Grade: " << grade << endl;
}

void typist::getdata() {
	staff::getdata();
	cout << "Speed : ";
	cin >> speed;
}

void typist::putdata() {
	staff::putdata();
	cout << "  Speed: " << speed << endl;
}

typistType typist::_getType() {
	if (typeid(*this) == typeid(regular)) {
		return typistType::regular;
	} else if (typeid(*this) == typeid(casual)) {
		return typistType::casual;
	} else
		return typistType::invalid;
}

void regular::getdata() {
	typist::getdata();
	cout << "Wage : ";
	cin >> wage;
}

void regular::putdata() {
	typist::putdata();
	cout << "  Wage: " << wage << endl;
}

void casual::getdata() {
	typist::getdata();
	cout << "Daily wage : ";
	cin >> daily_wage;
}

void casual::putdata() {
	typist::putdata();
	cout << "  Daily wage: " << daily_wage << endl;
}

staffType staff::getType() {
	if (typeid(*this) == typeid(teacher)) {
		return staffType::teacher;
	} else if (typeid(*this) == typeid(officer)) {
		return staffType::officer;
	} else if (typeid(*this) == typeid(regular) || typeid(*this) == typeid(casual)) {
		return staffType::typist;
	} else
		return staffType::invalid;
}

void staff::add() {
	char ch;
	cout << "'t' to add a teacher." << endl
		 << "'o' to add a officer." << endl
		 << "'y' to add a typist." << endl
		 << "Enter selection: " << endl;
	cin >> ch;
	switch (ch) {
	case 't':
		staffs[n] = new teacher;
		break;
	case 'o':
		staffs[n] = new officer;
		break;
	case 'y':
		cout << "'r' to add a regular typist." << endl
			 << "'c' to ada a casual typist." << endl
			 << "Enter selection:" << endl;
		cin >> ch;
		switch (ch) {
		case 'r':
			staffs[n] = new regular;
			break;
		case 'c':
			staffs[n] = new casual;
			break;
		default:
			cout << "Invalid typist type" << endl;
			break;
		}
		break;
	default:
		cout << "Invalid staff type." << endl;
		break;
	}
	staffs[n++]->getdata();
}

void staff::display() {
	for (int i = 0; i < n; i++) {
		cout << i + 1 << '.';
		switch (staffs[i]->getType()) {
		case staffType::teacher:
			cout << "Teacher" << endl;
			staffs[i]->putdata();
			break;
		case staffType::officer:
			cout << "Officer" << endl;
			staffs[i]->putdata();
			break;
		case staffType::typist:
			cout << "Typist";
			switch (static_cast<typist*>(staffs[i])->_getType()) {
			case typistType::regular:
				cout << "(Regular)" << endl;
				staffs[i]->putdata();
				break;
			case typistType::casual:
				cout << "(Casual)" << endl;
				staffs[i]->putdata();
				break;
			case typistType::invalid:
				cout << "\tInvalid typist data." << endl;
				break;
			}
			break;
		case staffType::invalid:
			cout << "Invalid staff data." << endl;
			break;
		}
	}
}

void staff::write() {
	int size;
	cout << "Writing " << n << " staffs into staffs.dat" << endl;
	ofstream fout("staffs.dat", ios::trunc | ios::binary);
	if (!fout) {
		cout << "Error Opening file!!!" << endl;
		return;
	}
	staffType stype;
	typistType ttype;
	for (int i = 0; i < n; i++) {
		stype = staffs[i]->getType();
		fout.write((char*)&stype, sizeof(stype));
		if (stype == staffType::typist) {
			ttype = static_cast<typist*>(staffs[i])->_getType();
			fout.write((char*)&ttype, sizeof(ttype));
		}
		switch (stype) {
		case staffType::teacher:
			size = sizeof(teacher);
			break;
		case staffType::officer:
			size = sizeof(officer);
			break;
		case staffType::typist:
			switch (ttype) {
			case typistType::regular:
				size = sizeof(regular);
				break;
			case typistType::casual:
				size = sizeof(casual);
				break;
			case typistType::invalid:
				size = 0;
				break;
			}
			break;
		case staffType::invalid:
			size = 0;
			break;
		}
		fout.write((char*)(staffs[i]), size);
		if (!fout) {
			cout << "Error Writing to file!!!" << endl;
			return;
		}
	}
}

void staff::read() {
	int size;
	cout << "Reading from staffs.dat" << endl;
	ifstream fin("staffs.dat", ios::binary);
	if (!fin) {
		cout << "Error Opening file!!!" << endl;
		return;
	}
	staff::clear();
	staffType stype;
	typistType ttype;
	while (true) {
		fin.read((char*)&stype, sizeof(stype));
		if (stype == staffType::typist) {
			fin.read((char*)&ttype, sizeof(ttype));
		}
		if (fin.eof())
			break;
		if (!fin) {
			cout << "Error Opening file!!!" << endl;
		}
		switch (stype) {
		case staffType::teacher:
			size = sizeof(teacher);
			break;
		case staffType::officer:
			size = sizeof(officer);
			break;
		case staffType::typist:
			switch (ttype) {
			case typistType::regular:
				size = sizeof(regular);
				break;
			case typistType::casual:
				size = sizeof(casual);
				break;
			case typistType::invalid:
				size = 0;
				break;
			}
			break;
		case staffType::invalid:
			size = 0;
			break;
		}
		fin.read((char*)(staffs[n++]), size);
		if (!fin) {
			cout << "Error Reading from file!!!" << endl;
			return;
		}
	}
}

void staff::clear() {
	for (auto& i : staffs)
		delete (i);
	n = 0;
}
