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
	
	int opcion=0;
	
	do{
	std::cout<<"- - - - - - Bienvenido al sistema de simulacion de la copa del mundo 2026! - - - - - -"<<'\n';
	std::cout<<'\n';
	std::cout<<lin<<"Que accion desea realizar?"<<'\n'<<lin;
	std::cout<<"1.Registrar grupos y selecciones"<<'\n';
	std::cout<<'\n';
	std::cout<<"2.Registrar resultados"<<'\n';
	std::cout<<'\n';
	std::cout<<"3.Mostrar tabla de posiciones"<<'\n';
	std::cout<<'\n';
	std::cout<<"4.Mostrar tabla de goleadores"<<'\n';
	std::cout<<'\n';
	std::cout<<"5.salir del programa"<<'\n';
	std::cout<<lin<<"Dijite su selecion a continuacion: ";
	std::cin>>opcion;
	
	switch(opcion){
		case 1:
			//Placeholder para el registro de Grupos
			std::system("pause");
			std::system("cls");
			
			break;
		
		case 2:
			//Placeholder para el registro de resultados de un mismo grupo.
			std::system("pause");
			std::system("cls");
			break;
		case 3:
			//Placeholder para mostrar y generar la tabla de posiciones de un grupo.
			std::system("pause");
			std::system("cls");
			break;
		case 4:
			//Placeholder para mostrar y generar la tabla de goleadores de un torneo.
			std::system("pause");
			std::system("cls");
			break;
		case 5:
			std::cout<<"Gracias por usar el programa! saliendo..."<<'\n';
			std::system("pause");
			std::system("cls");
			break;
		default:
			std::cout<<"Opcion invalida, vuelva a intentarlo"<<'\n';
			std::system("pause");
			std::system("cls");
	}
	
	}while(opcion!=5);

	//std::system("cls");
	/*std::cout << "\033[H\033[2J" << std::flush;
	
	Director dt("Luis Enrique");
    Seleccion espana("Espania", dt);

    espana.agregarJugador("Pedri");
    espana.agregarJugador("Gavi");
    
    Persona* p = espana.getPersona(1);
	std::string nombre = p->getNombre();
	*/
	
    return 0;
}
