#include <iostream>

double Celsius2Fahrenheit(double Celsius)
{
	return (1.8 * Celsius + 32.0);
}

int main(int argc, char *argv[]) {
	double Celsius;
	double Fahrenheit;
	std::cout << "Please enter a Celsius value: ";
	std::cin >> Celsius;
	std::cout << Celsius << " degrees Celsius is " << Celsius2Fahrenheit(Celsius) << " degrees Fahrenheit." << std::endl;
	return 0;
}