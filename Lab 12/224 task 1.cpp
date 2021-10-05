#include <iostream>
using namespace std;
const int limit = 100;

template <class t>
class safearay {
private:
	t arr[limit];

public:
	void putel(int n, t elvalue) {
		if (n < 0 || n >= limit) {
			cout << "Array out of bound." << endl;
			return;
		}
		arr[n] = elvalue;
	}
	t getel(int n) {
		if (n < 0 || n >= limit) {
			cout << "Array out of bound." << endl;
			return -1;
		}
		return arr[n];
	}
};

int main() {
	safearay<int> sa1;
	for (int i = 0; i < limit; i++) {
		sa1.putel(i, i * 10);
	}
	for (int i = 0; i < limit; i++) {
		int temp = sa1.getel(i);
		cout << "Element" << i << " is " << temp << endl;
	}
	safearay<float> sa2;
	for (int i = 0; i < limit; i++) {
		sa2.putel(i, i * 1.50);
	}
	for (int i = 0; i < limit; i++) {
		float temp = sa2.getel(i);
		cout << "Element" << i << " is " << temp << endl;
	}
	return 0;
}