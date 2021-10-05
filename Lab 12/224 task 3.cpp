#include <iostream>
using namespace std;
const int limit = 100;

template <class t>
class safearay {
private:
	t arr[limit];

public:
	class err {
	public:
		int i;
		err(int i)
		  : i(i) {}
	};
	t& operator[](int n) {
		if (n < 0 || n >= limit) {
			throw n;
		}
		return arr[n];
	}
	void putel(int n, t elvalue) {
		if (n < 0 || n >= limit) {
			throw err(n);
		}
		arr[n] = elvalue;
	}
	t getel(int n) {
		if (n < 0 || n >= limit) {
			throw err(n);
		}
		return arr[n];
	}
};

int main() {
	safearay<int> sa1;
	for (int i = 0; i < limit; i++) {
		try {
			sa1.putel(i, i * 10);
		} catch (safearay<int>::err e) {
			cout << "Error: " << e.i << endl;
		}
	}
	for (int i = 0; i < limit; i++) {
		int temp;
		try {
			temp = sa1.getel(i);
		} catch (safearay<int>::err e) {
			cout << "Error: " << e.i << endl;
		}
		cout << "Element" << i << " is " << temp << endl;
	}
	safearay<float> sa2;
	for (int i = 0; i < limit; i++) {
		try {
			sa2.putel(i, i * 1.5);
		} catch (safearay<int>::err e) {
			cout << "Error: " << e.i << endl;
		}
	}
	for (int i = 0; i < limit; i++) {
		float temp;
		try {
			temp = sa2.getel(i);
		} catch (safearay<int>::err e) {
			cout << "Error: " << e.i << endl;
		}
		cout << "Element" << i << " is " << temp << endl;
	}
	return 0;
}