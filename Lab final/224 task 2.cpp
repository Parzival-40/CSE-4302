#include <iostream>

using namespace std;

class Account {
public:
	Account() {}
	virtual ~Account() {}
	Account(const int& accountNo, const double& initialBalance);
	virtual void withdraw(const double& value);	   //paramerer added after end of exam
	virtual void deposit(const double& value);	   //paramerer added after end of exam

private:
	int accountNo;
	double balance;
};

class ABBank : Account {
public:
	ABBank() {}
	ABBank(const string& accountName, const int& accountNo, const double& initialBalance);
	void withdraw(const double& value);	   //paramerer added after end of exam
	void deposit(const double& value);	   //paramerer added after end of exam

private:
	string accountName;
	const string bankName = "AB Bank";
};

class IslamiBank : Account {
public:
	IslamiBank() {}
	IslamiBank(const double& interestRate, const int& accountNo, const double& initialBalance);
	void withdraw(const double& value);	   //paramerer added after end of exam
	void deposit(const double& value);	   //paramerer added after end of exam

private:
	double interestRate;
	const string bankName = "Islami Bank";
};

//main function completed after end of exam
int main() {
	ABBank a("kafi", 224, 35236.43);
	IslamiBank i(7.3, 226, 232525.52);
}

//All definition written after end of exam

Account::Account(const int& accountNo, const double& initialBalance)
  : accountNo(accountNo), balance(initialBalance) {}

void Account::withdraw(const double& value) {
	if (balance < value || value < 0) return;
	balance -= value;
}

void Account::deposit(const double& value) {
	if (value < 0) return;
	balance += value;
}

ABBank::ABBank(const string& accountName, const int& accountNo, const double& initialBalance)
  : Account(accountNo, initialBalance), accountName(accountName) {}

void ABBank::withdraw(const double& value) {
	Account::withdraw(value);
	/////////////
	//
	//do sth
	//
	////////////
}

void ABBank::deposit(const double& value) {
	Account::deposit(value);
	////////////
	//
	//do sth else
	//
	////////////
}

IslamiBank::IslamiBank(const double& interestRate, const int& accountNo, const double& initialBalance)
  : Account(accountNo, initialBalance), interestRate(interestRate) {}

void IslamiBank::withdraw(const double& value) {
	Account::withdraw(value);
	/////////////
	//
	//do sth
	//
	////////////
}

void IslamiBank::deposit(const double& value) {
	Account::deposit(value);
	////////////
	//
	//do sth else
	//
	////////////
}