#include <cmath>

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
		return atan(width/length);
	}
	void set_width(double width){
		if(width<1||width>20)return;
		this->width=width;
	}
	double get_width(){
		return width;
	}
	void set_lenght(double length){
		if(length<1||length>20)return;
		this->length=length;
	}
	double get_length(){
		return length;
	}
};
