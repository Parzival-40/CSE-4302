#include <iostream>
#include <fstream>
#include <map>
#include <vector>

#include "Account.h"
#include "Bus.h"
#include "Long_route.h"
#include "Person.h"
#include "Short_route.h"
#include "Station.h"

using namespace std;

template<class A>
vector<A>& operator+=(vector<A>& v1, A& x){
	v1.push_back(x);
	return v1;
}

vector<Person>vp;
vector<Account>va;
vector<string>vs;
map<string, vector<string> >mps;

map<string, int>dest_wise_fare {{"Chittagong",700},{"Rajshahi",650},{"Rangpur",550},{"Khulna",1000},{"Sylhet",350},
							   {"Dhaka",660},{"Mymensingh",220},{"Barishal",990}};
int main(){
	cout << "Welcome to Bus reservation System" << endl;
	cout << "Destination         Fare" << endl;
	for(auto x : dest_wise_fare){
		cout << x.first << "         " << x.second << endl;
	}
	cout << endl << endl;
	cout << "How many Passenger we have:";
	int x;
	cin >> x;
	vp.clear();
	while(x--){
		cout << "Enter Passenger Name: ";
		string n;
		cin >> n;

		fflush(stdin);

		cout << "Enter Age: ";
		int age;
		cin >> age;

		fflush(stdin);

		cout << "Enter Address:";
		string address;
		cin >> address;

		fflush(stdin);

		cout << "Enter Account No: ";
		int acc;
		cin >> acc;
		fflush(stdin);

		Person p(n, age, address);
		vp += p;
		Account a(n, acc);
		va += a;
		vs += n;

		cout << "Where passenger want to go?";
		string des;
		cin >> des;
		mps[des].push_back(n);
		fflush(stdin);
	}

	ofstream fout("Passenger.txt");
	for(unsigned i = 0; i < va.size(); i++){
		fout.write((char*) &vp[i], sizeof(vp[i]));
	}

	for(auto& x : mps){
		cout << x.first << " " << x.second.size() << endl;
	}
}