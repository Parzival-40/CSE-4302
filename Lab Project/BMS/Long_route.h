#pragma once
#include <iostream>
using namespace std;
class long_route{
public:
	long_route(string dn, string st, string aet, bool ac);

private:
	string driver_name;
	string starting_time;
	string approximate_ending_time;
	bool ac;
};
