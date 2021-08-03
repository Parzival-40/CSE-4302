#include <iostream>

using namespace std;

class door {
private:
	string opening_mode;

public:
	door(string ope = "")
	  : opening_mode(ope) {}

	void set_opening_mode(string ope) {
		opening_mode = ope;
	}
	string get_opening_mode() {
		return opening_mode;
	}

	void display() {
		cout << "\t\tOpening mode: " << opening_mode << endl;
	}
};

class engine {
private:
	double max_fuel_con_rate;
	double max_energy_prod_rate;
	double avg_rpm;

public:
	engine(double m1 = 0.0, double m2 = 0.0, double m3 = 0.0)
	  : max_fuel_con_rate(m1), max_energy_prod_rate(m2), avg_rpm(m3) {}

	void set_max_fuel_con_rate(double m1) {
		max_fuel_con_rate = m1;
	}
	void set_max_energy_prod_rate(double m2) {
		max_energy_prod_rate = m2;
	}
	void set_avg_rpm(double m3) {
		avg_rpm = m3;
	}

	double get_max_fuel_con_rate() {
		return max_fuel_con_rate;
	}
	double get_max_energy_prod_rate() {
		return max_energy_prod_rate;
	}
	double get_avg_rpm() {
		return avg_rpm;
	}

	void display() {
		cout << "\t\tMaximum Fuel Consumption Rate: " << max_fuel_con_rate << endl
			 << "\t\tMaximum Energy Production Rate: " << max_energy_prod_rate << endl
			 << "\t\tAverage RPM: " << avg_rpm << endl;
	}
};

class wheel {
private:
	double radius;

public:
	wheel(double rad = 0.0)
	  : radius(rad) {}

	void set_radius(double rad) {
		radius = rad;
	}
	double get_radius() {
		return radius;
	}

	void display() {
		cout << "\t\tRadius: " << radius << endl;
	}
};

class seat {
private:
	string comfortability;
	bool warmer;

public:
	seat(string com = "", bool warm = false)
	  : comfortability(com), warmer(warm) {}

	void set_comfortability(string com) {
		comfortability = com;
	}
	void set_warmer(bool warm) {
		warmer = warm;
	}

	string get_comfortability() {
		return comfortability;
	}
	bool get_warmer() {
		return warmer;
	}

	void display() {
		cout << "\t\tSeat comfortability: " << comfortability << endl
			 << "\t\tPresence of seat warmer: " << (warmer ? "Yes" : "NO") << endl;
	}
};

class truck {
private:
	seat seats[2];
	wheel wheels[6];
	engine _engine;
	door doors[2];
	double maximum_acceleration;
	double fuel_capacity;
	double load_capacity;

	void set_seats() {
		string com;
		bool warm;
		cout << "Seat comfortability: ";
		cin >> com;
		cout << "Seat warmer(0/1): ";
		cin >> warm;
		for (auto& i : seats) {
			i.set_comfortability(com);
			i.set_warmer(warm);
		}
	}
	void set_wheels() {
		double rad;
		cout << "Wheel radius: ";
		cin >> rad;
		for (auto& i : wheels) {
			i.set_radius(rad);
		}
	}
	void set_engine() {
		double m1, m2, m3;
		cout << "Maximum Fuel Consumption Rate: ";
		cin >> m1;
		_engine.set_max_fuel_con_rate(m1);
		cout << "Maximum Energy Production Rate: ";
		cin >> m2;
		_engine.set_max_energy_prod_rate(m2);
		cout << "Average RPM: ";
		cin >> m3;
		_engine.set_avg_rpm(m3);
	}
	void set_doors() {
		string ope;
		cout << "Opening mode: ";
		cin >> ope;
		for (auto& i : doors) {
			i.set_opening_mode(ope);
		}
	}

public:
	truck(double m = 0.0, double f = 0.0, double l = 0.0)
	  : maximum_acceleration(m), fuel_capacity(f), load_capacity(l) {
		cout << "Seats:" << endl;
		set_seats();
		cout << "Wheels:" << endl;
		set_wheels();
		cout << "Engine:" << endl;
		set_engine();
		cout << "Doors:" << endl;
		set_doors();
	}

	void set_maximum_acceleration(double ma) {
		maximum_acceleration = ma;
	}
	void set_fuel_capacity(double fc) {
		fuel_capacity = fc;
	}
	void set_load_capacity(double lc) {
		load_capacity = lc;
	}

	double get_maximum_acceleration() {
		return maximum_acceleration;
	}
	double get_fuel_capacity() {
		return fuel_capacity;
	}
	double get_load_capacity() {
		return load_capacity;
	}

	void display() {
		cout << "Truck:" << endl
			 << "\tMaximum acceleratin: " << maximum_acceleration << endl
			 << "\tFuel capacity: " << fuel_capacity << endl
			 << "\tLoad capacity: " << load_capacity << endl;
		cout << "\tSeats:" << endl;
		seats[0].display();
		cout << "\tWheels:" << endl;
		wheels[0].display();
		cout << "\tEngine:" << endl;
		_engine.display();
		cout << "\tDoors:" << endl;
		doors[0].display();
	}
};

int main() {
	truck tata(30, 60, 50);
	tata.display();
}
