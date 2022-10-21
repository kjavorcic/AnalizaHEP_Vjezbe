
#include <iostream>

float _my_cube(float number){
	return number*number*number;
}

int main() {
	float x;
	std::cout << "Unesite broj: ";
	std::cin >> x;
   	std::cout << "Kub tog broj je: " << _my_cube(x);
    return 0;
}


