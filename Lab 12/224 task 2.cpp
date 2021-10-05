#include <iostream>

using namespace std;

template <class t>
int amax(t arr[], int n) {
	t m = 0;
	for (int i = 0; i < n; i++) {
		m = max(arr[i], m);
	}
	return m;
}

int main() {
	int a[10];
	for (int i = 0; i < 10; i++) {
		a[i] = i * 2;
	}
	cout << amax(a, 10) << endl;
	double d[10];
	for (int i = 0; i < 10; i++) {
		d[i] = i * 1.3;
	}
	cout << amax(d, 10) << endl;
	char c[10];
	for (int i = 0; i < 10; i++) {
		c[i] = i + 'a';
	}
	cout << amax(c, 10) << endl;
}