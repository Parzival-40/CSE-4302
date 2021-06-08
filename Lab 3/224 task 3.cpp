#include <iostream>

using namespace std;

class Medicine{
private:
	string name, genericName;
	double discountPercent, unitPrice;
	double unitSellingPrice(){
		return unitPrice-unitPrice*discountPercent/100;
	}
public:
	Medicine():name(""),genericName(""),discountPercent(0),unitPrice(0){}
	void assignName(char* name, char* genericName){
		this->name=name;
		this->genericName=genericName;
	}
	void assignPrice(double price=0){
		this->unitPrice=price;
	}
	void setDiscountPercent(double percent=5){
		this->discountPercent=percent;
	}
	double getSellingPrice(int nos){
		return nos*unitSellingPrice();
	}
	void display(){
		cout<<name<<' '<<'('<<genericName<<')'<<" has a unit price BDT "<<unitPrice<<" Current discount "<<discountPercent<<"%."<<endl;
	}
};