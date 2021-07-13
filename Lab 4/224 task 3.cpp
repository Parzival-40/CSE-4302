#include <iostream>

using namespace std;

class Employee {
private:
	string EmpName;
	int ID;
	int age;
	float salary;
	string getstatus() {
		if (age > 25) {
			if (salary <= 21000)
				return "Low";
			else if (salary > 21000 && salary <= 60000)
				return "Moderate";
			else
				return "High";
		} else {
			if (salary <= 20000)
				return "Low";
			else
				return "Moderate";
		}
	}

public:
	Employee() {}
	void FeedInfo(string EmpName, int ID, int age, float salary) {
		this->EmpName = EmpName;
		this->ID = ID;
		this->age = age;
		this->salary = salary;
	}
	void ShowInfo() {
		cout << "Name: " << EmpName << endl
			 << "ID: " << ID << endl
			 << "Age: " << age << endl
			 << "Salary: " << salary << endl
			 << "Status: " << getstatus() << " Salaried Person" << endl;
	}
};

int main() {
	Employee a;
	a.FeedInfo("Kafi", 224, 20, 3000);
	a.ShowInfo();
}
