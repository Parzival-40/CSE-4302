#include <iostream>

using namespace std;

class RationalNumber{
private:
	int numerator;
	int denominator;
public:
	RationalNumber():numerator(0),denominator(1){}
	void assign(int numerator,int denominator){
		if(!denominator){
			cout<<"Error!!"<<endl;
			cout<<"denominator cannot be zero"<<endl;
			return;
		}
		this->numerator=numerator;
		this->denominator= denominator;
	}
	double convert(){return (double)numerator/(double)denominator;}
	void invert(){
		if(!numerator){
			cout<<"Error!!"<<endl;
			cout<<"denominator cannot be zero"<<endl;
			return;
		}
		swap(denominator,numerator);
	}
	void print(){cout<<numerator<<'/'<<denominator<<endl;}
};