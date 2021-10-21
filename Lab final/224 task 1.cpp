#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Bike {
public:
	Bike(){};
	Bike(const string& model, const double& price, const string& manufacturer)
	  : model(model), price(price), manufacturer(manufacturer) {}

	void display();

	friend bool operator<(Bike& a, Bike& b);	 //std::string comparison based on manufacturer
	friend bool operator>(Bike& a, Bike& b);	 //std::string comparison based on manufacturer
	friend bool operator>=(Bike& a, Bike& b);	 //std::string comparison based on manufacturer
	friend bool operator<=(Bike& a, Bike& b);	 //std::string comparison based on manufacturer
	friend bool operator==(Bike& a, Bike& b);	 //std::string comparison based on manufacturer
	friend bool operator!=(Bike& a, Bike& b);	 //std::string comparison based on manufacturer

private:
	string model;
	double price;
	string manufacturer;
};

//modified after end of exam: parameter n for array length removed
void sortByManufacturer(vector<Bike>& aray) {
	sort(aray.begin(), aray.end());
}

int main() {
	int n;
	//added after end of exam
	cout << "no. of bikes: ";
	cin >> n;
	vector<Bike> aray;
	for (int i = 0; i < n; i++) {
		string model;
		double price;
		string manufacturer;
		//added after end of exam
		cout << "model price manufacturer" << endl;
		cin >> model >> price >> manufacturer;
		aray.push_back(Bike(model, price, manufacturer));
	}

	//modified after end of exam
	sortByManufacturer(aray);

	for (auto& i : aray) {
		i.display();
	}
	cin.get();
}

bool operator<(Bike& a, Bike& b) {
	return a.manufacturer < b.manufacturer;
}
bool operator>(Bike& a, Bike& b) {
	return a.manufacturer > b.manufacturer;
}
bool operator>=(Bike& a, Bike& b) {
	return a.manufacturer >= b.manufacturer;
}
bool operator<=(Bike& a, Bike& b) {
	return a.manufacturer <= b.manufacturer;
}
bool operator==(Bike& a, Bike& b) {
	return a.manufacturer == b.manufacturer;
}
bool operator!=(Bike& a, Bike& b) {
	return a.manufacturer != b.manufacturer;
}

//added after end of exam
void Bike::display() {
	cout << "manufacturer: " << manufacturer << endl
		 << "model: " << model << endl
		 << "price: " << price << endl;
}