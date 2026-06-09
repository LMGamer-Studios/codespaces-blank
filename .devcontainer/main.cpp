#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>
#include <cstdlib>
#include <fstream>
#include "Seleccion.h"
#include "Partido.h"
#include "Estadistica.h"

std::string lin = "--------------------------------\n";

int main() {

	//std::system("cls");
	std::cout << "\033[H\033[2J" << std::flush;
	
	Director dt("Luis Enrique");
    Seleccion espana("Espania", dt);

    espana.agregarJugador("Pedri");
    espana.agregarJugador("Gavi");
    
    Persona* p = espana.getPersona(1);
	std::string nombre = p->getNombre();
	std::cout << nombre << '\n';
    std::cout << lin << "Seleccion: " << espana.getNombrePais() << '\n';
    std::cout << "Jugadores registrados: " << espana.getCantidadPersonas() << '\n' << lin;
	
    return 0;
}
