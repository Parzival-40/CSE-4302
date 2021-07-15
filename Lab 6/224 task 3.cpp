#include <iostream>

using namespace std;

class Float {
private:
	float data;

public:
	Float(float data = 0)
	  : data(data) {}

	friend Float operator+(const Float& a, const Float& b);
	friend Float operator-(const Float& a, const Float& b);
	friend Float operator*(const Float& a, const Float& b);
	friend Float operator/(const Float& a, const Float& b);

	friend ostream& operator<<(ostream& out, Float a);
};

ostream& operator<<(ostream& out, Float a) {
	out << a.data;
	return out;
}

Float operator+(const Float& a, const Float& b) {
	return Float(a.data + b.data);
}
Float operator-(const Float& a, const Float& b) {
	return Float(a.data - b.data);
}
Float operator*(const Float& a, const Float& b) {
	return Float(a.data * b.data);
}
Float operator/(const Float& a, const Float& b) {
	return Float(a.data / b.data);
}

int main() {
	Float f1, f2;
	f1 = 2.5;
	f2 = 3.1;
	cout << "f1+f2: "
		 << (f1 + f2) << endl
		 << "f1-f2: "
		 << (f1 - f2) << endl
		 << "f1*f2: "
		 << (f1 * f2) << endl
		 << "f1/f2: "
		 << (f1 / f2) << endl;
}
