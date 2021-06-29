#include <iostream>

using namespace std;

class BankAccount{
private:
	long number;
	string holder_name;
	string type;
	double current_balance;
	double minimum_balance;
public:
	BankAccount(long number,string holder_name,string type,double current_balance,double minimum_balance)
		:number(number)
		,holder_name(holder_name)
		,type(type)
		,current_balance(current_balance)
		,minimum_balance(minimum_balance)
		{}
	~BankAccount(){
		cout<<"Account of "<<holder_name
			<<"with account number "<<number
			<<"is destroyed with a balance BDT "<<current_balance<<endl;
	}
	void info(){
		cout<<"Account Holder: "<<holder_name<<endl
			<<"Account number: "<<number<<endl
			<<"Account Type: "<<type<<endl
			<<"Current balance: "<<current_balance<<endl
			<<"Minimum balance: "<<minimum_balance<<endl;
	}
	void showBalance(){
		cout<<"Current balance: "<<current_balance<<endl;
	}
	void diposite(double amount){
		if(amount<=0)return;
		current_balance+=amount;
	}
	void withdraw(double amount){
		if(current_balance-amount<minimum_balance)return;
		current_balance-=amount;
	}
	void giveInterest(double interest=3){
		double net_interest;
		net_interest=current_balance*interest/100;
		current_balance+=(net_interest-net_interest*.1);
	}
};
