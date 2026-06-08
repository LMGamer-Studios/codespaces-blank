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
	
	Director dt("Luis Enrique");
    Seleccion espana("Espania", dt);

    espana.agregarJugador("Pedri");
    espana.agregarJugador("Gavi");

    std::cout << "Seleccion: " << espana.getNombrePais() << std::endl;
    std::cout << "Jugadores registrados: " << espana.getCantidadPersonas() << std::endl;
	
	return 0;
}
