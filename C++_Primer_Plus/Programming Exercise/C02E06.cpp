#include <iostream>

double light2astronomical(double d_Light){
	return d_Light * 63240;
}

int main(int argc, char *argv[]) {
	double d_Light;
	double d_Astronomals;
	std::cout << "Enter the number of light years: ";
	std::cin >> d_Light;
	std::cout << d_Light << " light years = " << light2astronomical(d_Light) << " astronomical units." << std::endl;
	return 0;
}