#pragma once
#include <iostream>
using namespace std;
class Station{
private:
	int ticekt_counter_no;
	string ticket_counter_bus;
	int total_ticket;
	string passenger_name;
	string ticket_provider_name;
public:
	void show();
};
