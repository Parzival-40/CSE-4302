#include <iostream>

namespace my_namespace {
std::ostream& cout = std::cout;
std::istream& cin = std::cin;
}	 // namespace my_namespace

int main() {
	std::ostream& cout = my_namespace::cout;
	std::istream& cin = my_namespace::cin;
	int a;
	cout << "using declared cin and cout" << std::endl;
	cin >> a;
	cout << a << std::endl;
	std::cout << "using std::cin and std::cout" << std::endl;
	std::cin >> a;
	std::cout << a << std::endl;
	my_namespace::cout << "using my_namespace::cin and my_namespace::cout" << std::endl;
	my_namespace::cin >> a;
	my_namespace::cout << a << std::endl;
}