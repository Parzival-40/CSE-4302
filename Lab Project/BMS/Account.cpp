#include "Account.h"

Account::Account(string an, int accno){
	account_holder_name = an;
	account_no = accno;
}

void Account::withdraw_balance(int b){
	if(b + 100 == amount){
		cout << "Can't Withdraw" << endl;
	} else{
		amount -= b;
		cout << "Ticket Confirmed" << endl;
	}
}

void Account::add_money(int b){
	amount += b;
}

ostream& operator<<(ostream& out, const Account& obj){
	out << obj.account_no << "    " << obj.amount << endl;
	return out;
}