#include <iostream>
#include <set>
#include <vector>

using namespace std;

void merge(int* arr, const int& n, set<int>& st, vector<int>& v) {
	int i = 0;
	int j = 0;
	auto k = st.begin();
	while (i < n || j < n) {
		while ((j < st.size() && i >= n) || (k != st.end() && *k < arr[i])) {
			v.push_back(*(k++));
			j++;
		}
		while ((i < n && j >= st.size()) || (k != st.end() && arr[i] < *k)) {
			v.push_back(arr[i++]);
		}
	}
}

int main() {
	int arr[10];
	for (int i = 0; i < 10; i++) {
		arr[i] = 2 * (i + 1);
	}
	set<int> st;
	for (int i = 0; i < 10; i++) {
		st.insert(2 * i + 1);
	}
	vector<int> v;
	merge(arr, 10, st, v);
	for (auto& i : arr)
		cout << i << ' ';
	cout << endl;
	for (auto& i : st)
		cout << i << ' ';
	cout << endl;
	for (auto& i : v)
		cout << i << ' ';
	cout << endl;
}