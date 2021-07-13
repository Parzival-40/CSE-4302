#include <cmath>
#include <iostream>

using namespace std;

class Coordinate {
private:
	float x, y;

public:
	Coordinate(float x = 0, float y = 0)
	  : x(x),
		y(y) {}
	float getDistance(const Coordinate& c) {
		return sqrt(pow(x - c.x, 2) + pow(y - c.y, 2));
	}
	float getDistance() {
		return sqrt(pow(x, 2) + pow(y, 2));
	}
	void move_x(float val) {
		x += val;
	}
	void move_y(float val) {
		y += val;
	}
	void move(float val) {
		move_x(val);
		move_y(val);
	}

	Coordinate operator++() {
		return Coordinate(++x, ++y);
	}
	Coordinate operator++(int) {
		return Coordinate(x++, y++);
	}
	Coordinate operator--() {
		return Coordinate(--x, --y);
	}
	Coordinate operator--(int) {
		return Coordinate(x--, y--);
	}

	friend bool operator<=(Coordinate& a, Coordinate& b);
	friend bool operator>=(Coordinate& a, Coordinate& b);
	friend bool operator<(Coordinate& a, Coordinate& b);
	friend bool operator<(Coordinate& a, Coordinate& b);
	friend bool operator==(Coordinate& a, Coordinate& b);
	friend bool operator!=(Coordinate& a, Coordinate& b);

	friend ostream& operator<<(ostream& out, Coordinate& a) {
		out << "(" << a.x << ',' << a.y << ")";
		return out;
	}
};

bool operator<=(Coordinate& a, Coordinate& b) {
	return a.getDistance() <= b.getDistance();
}
bool operator>=(Coordinate& a, Coordinate& b) {
	return a.getDistance() >= b.getDistance();
}
bool operator<(Coordinate& a, Coordinate& b) {
	return a.getDistance() < b.getDistance();
}
bool operator>(Coordinate& a, Coordinate& b) {
	return a.getDistance() < b.getDistance();
}
bool operator==(Coordinate& a, Coordinate& b) {
	return a.getDistance() == b.getDistance();
}
bool operator!=(Coordinate& a, Coordinate& b) {
	return a.getDistance() != b.getDistance();
}

void print(Coordinate& a, Coordinate& b, Coordinate& c) {
	cout << "(0,0)~a " << a << ":"
		 << a.getDistance() << endl
		 << "(0,0)~b " << b << ":"
		 << b.getDistance() << endl
		 << "(0,0)~c " << c << ":"
		 << c.getDistance() << endl
		 << "a" << a << "~c" << c << ": "
		 << a.getDistance(b) << endl
		 << "b" << b << "~c" << c << ": "
		 << b.getDistance(c) << endl
		 << "c" << c << "~a" << a << ": "
		 << c.getDistance(a) << endl
		 << "(a" << a << "<b" << b << "?): "
		 << (a < b) << endl
		 << "(a" << a << "<=b" << b << "?): "
		 << (a <= b) << endl
		 << "(a" << a << ">c" << c << "?): "
		 << (a > c) << endl
		 << "(a" << a << ">=c" << c << "?): "
		 << (a >= c) << endl
		 << "(a" << a << "==c" << c << "?): "
		 << (a == c) << endl
		 << "(a" << a << "!=b" << b << "?): "
		 << (a != b) << endl
		 << endl;
}

int main() {
	Coordinate a(3, 4), b(0, 5), c(4, 3);
	cout << "Coordinates: a(3, 4), b(0, 5), c(4, 3)" << endl;
	print(a, b, c);

	b = a++;
	cout << "b = a++" << endl;
	print(a, b, c);

	c = b--;
	cout << "c = b--" << endl;
	print(a, b, c);

	a = c++;
	cout << "a = c++" << endl;
	print(a, b, c);

	b = ++a;
	cout << "b = ++a" << endl;
	print(a, b, c);
}
