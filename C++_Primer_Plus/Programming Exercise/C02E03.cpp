#include <iostream>

void str1(){
	std::cout << "Three blind mice\n";
}

void str2(){
	std::cout << "See how they run\n";
}

int main(int argc, char *argv[]) {
	str1();
	str1();
	str2();
	str2();
	return 0;		
}