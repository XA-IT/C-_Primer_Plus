#include <iostream>

int main(int argc, char *argv[]) {
	int age;
	int month;
	std::cout << "Enter your age:";
	std::cin >> age;
	month = age * 12;
	std::cout << month << std::endl;
	return 0;
}