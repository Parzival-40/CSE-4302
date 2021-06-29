#include <iostream>

using namespace std;

class BankAccount{
private:
	enum ac{Current,Savings};
	long number;
	string holder_name;
	ac type;
	double current_balance;
	double minimum_balance;
public:
	BankAccount(){}
	~BankAccount(){}
	void info();
	void showBalance();
	void diposite(double amount);
	void withdraw(double amount);
	void giveInterest(double interest=3);
};
