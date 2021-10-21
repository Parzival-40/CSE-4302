#include "Long_route.h"

long_route::long_route(string dn, string st, string aet, bool ac){
	driver_name = dn;
	starting_time = st;
	approximate_ending_time = aet;
	this->ac = ac;
}