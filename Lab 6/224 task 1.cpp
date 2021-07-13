#include <iostream>

using namespace std;

class Counter {
private:
	int count;
	int step_val;

public:
	Counter(int count = 0, int step_val = 1)
	  : count(count),
		step_val(step_val) {}
	void setIncrementStep(int step_val) {
		this->step_val = step_val;
	}
	int getCount() {
		return count;
	}
	void increment() {
		count += step_val;
	}
	void resetCount() {
		count = 0;
	}

	Counter operator++() {
		return Counter(++count, step_val);
	}

	Counter operator++(int) {
		return Counter(count++, step_val);
	}

	friend Counter operator+(const Counter& a, const Counter& b);
	friend Counter operator+(const Counter& a, const int& b);
	friend Counter operator+(const int& a, const Counter& b);
	friend Counter operator+=(Counter& a, const Counter& b);
	friend ostream& operator<<(ostream& out, const Counter& a);
};

Counter operator+(const Counter& a, const Counter& b) {
	return Counter(a.count + b.count, a.step_val > b.step_val ? b.step_val : a.step_val);
}

Counter operator+(const Counter& a, const int& b) {
	return Counter(a.count + b, a.step_val);
}

Counter operator+(const int& a, const Counter& b) {
	return Counter(a + b.count, b.step_val);
}

Counter operator+=(Counter& a, const Counter& b) {
	return Counter(a.count += b.count, a.step_val);
}

ostream& operator<<(ostream& out, const Counter& a) {
	out << a.count;
	return out;
}

int main() {
	Counter c1, c2, c3;
	cout << (c1 = c2 + c3) << endl;
	int var = 5;
	cout << (c1 = var + c2) << endl
		 << (c1 = c2 + var) << endl
		 << (c1 += c2) << endl
		 << (c1 = ++c2) << endl
		 << (c1 = c2++) << endl;
}
