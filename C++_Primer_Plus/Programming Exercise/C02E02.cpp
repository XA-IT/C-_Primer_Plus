#include <iostream>

int conversion(int furlong);

using namespace std;
int main(int argc, char *argv[]) {
	int furlong;
	std::cin >> furlong;
	std::cout << conversion(furlong) << std::endl;
	return 0;
}

int conversion(int furlong){
	return 220 * furlong;
}