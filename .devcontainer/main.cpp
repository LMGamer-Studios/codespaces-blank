#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>
#include <cstdlib>
#include "Seleccion.h"

std::string lin = "------------------------------\n";

int main() {

	//std::system("cls");
	std::cout << "\033[H\033[2J" << std::flush; std::cout << "erased\n";
	std::cout << lin << "         Hola mundo!\n" << lin;
	
	return 0;
}
