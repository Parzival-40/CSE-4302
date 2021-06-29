#include <iostream>
#include <cmath>

using namespace std;

class Rectangle{
private:
	double width,length;
public:
	Rectangle(double width=1,double length=1):width(width),length(length){}
	double Perimeter(){
		return 2*(width+length);
	}
	double area(){
		return width*length;
	}
	double diagonal(){
		return sqrt(width*width+length*length);
	}
	double angle_between_length_and_diagonal(){
		return atan(length/width);
	}
	void set_width(double width){
		if(width<1||width>20)return;
		this->width=width;
	}
	double get_width(){
		return width;
	}
	void set_length(double length){
		if(length<1||length>20)return;
		this->length=length;
	}
	double get_length(){
		return length;
	}
};

int main(){
	Rectangle a(20,10);

	cout<<"Length: "<<a.get_length()<<endl
		<<"Width: "<<a.get_width()<<endl
		<<"Area: "<<a.area()<<endl
		<<"Perimeter: "<<a.Perimeter()<<endl
		<<"Diagonal: "<<a.diagonal()<<endl
		<<"Angle between length and diagonal: "<<a.angle_between_length_and_diagonal()<<endl;
	
	a.set_width(10);
	a.set_length(20);

	cout<<"Length: "<<a.get_length()<<endl
		<<"Width: "<<a.get_width()<<endl
		<<"Area: "<<a.area()<<endl
		<<"Perimeter: "<<a.Perimeter()<<endl
		<<"Diagonal: "<<a.diagonal()<<endl
		<<"Angle between length and diagonal: "<<a.angle_between_length_and_diagonal()<<endl;

}
