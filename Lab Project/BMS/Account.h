#pragma once
#include <iostream>
using namespace std;
class Account{
public:
	Account(string an, int accno);

	void withdraw_balance(int b);

	void add_money(int b);

	friend ostream& operator <<(ostream& out, const Account& obj);
private:
	string account_holder_name;
	int account_no;
	int retrive_balance;
	int amount = (rand() % (1001)) + 1000;
};
