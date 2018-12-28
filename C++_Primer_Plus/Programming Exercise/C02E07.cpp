#include <iostream>

void time(int hours, int minutes){
	std::cout << "Time: " << hours << ":" << minutes << std::endl;
}
using namespace std;
int main(int argc, char *argv[]) {
	int hours;
	int minutes;
	std::cout << "Enter the number of hours: ";
	std::cin >> hours;
	std::cout << "Enter the number of minutes: ";
	std::cin >> minutes;
	time(hours, minutes);
	return 0;
}