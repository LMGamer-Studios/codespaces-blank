#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>
#include <cstdlib>
#include <fstream>
#include "Seleccion.h"
#include "Partido.h"
#include "Estadistica.h"
#include "Grupo.h"

std::string lin = "--------------------------------\n";

int main() {
	
	//Grupos precargados
	Director dt("Luis Enrique");
    Seleccion espana("Espania", dt);
    espana.agregarJugador("Pedri");
    espana.agregarJugador("Gavi");
    espana.agregarJugador("manueh");
    espana.agregarJugador("Pablo");
    espana.agregarJugador("Juan");
    espana.agregarJugador("Ricardo");
    espana.agregarJugador("Carlos");
    espana.agregarJugador("Gabriel");
    espana.agregarJugador("Mauricio");
    espana.agregarJugador("Emiliano");
    
    Director dtMexico("Roberto Campos");
	Seleccion mexico("Mexico", dtMexico);
	mexico.agregarJugador("guillermo");
    mexico.agregarJugador("Erik");
    mexico.agregarJugador("Edson");
    mexico.agregarJugador("Gilberto");
    mexico.agregarJugador("Orbelin");
    mexico.agregarJugador("Alvaro"); 
    mexico.agregarJugador("Obed");
    mexico.agregarJugador("Alexis");
    mexico.agregarJugador("Hugo");
    mexico.agregarJugador("Rafael");
    
	Director dtUSA("Brian Greyson");
	Seleccion uSA("USA", dtUSA);
	uSA.agregarJugador("Christian");
    uSA.agregarJugador("Giovanni");
    uSA.agregarJugador("Weston");
    uSA.agregarJugador("Tyler");
    uSA.agregarJugador("Folarin");
    uSA.agregarJugador("Chris");
    uSA.agregarJugador("matt");
    uSA.agregarJugador("Timothy");
    uSA.agregarJugador("Tim");
    uSA.agregarJugador("Antonee");
    
    Director dtCanada("Alphonso Davies");
	Seleccion canada("Canada", dtCanada);
	canada.agregarJugador("Jonathan");
    canada.agregarJugador("Stephen");
    canada.agregarJugador("Cyle");
    canada.agregarJugador("Tajon");
    canada.agregarJugador("Moise");
    canada.agregarJugador("Maxime");
    canada.agregarJugador("Jacob");
    canada.agregarJugador("Niko");
    canada.agregarJugador("Ismael");
    canada.agregarJugador("Tani");
    
    Grupo grupoA;
	grupoA.agregarSeleccion(&espana);
	grupoA.agregarSeleccion(&mexico); 
	grupoA.agregarSeleccion(&uSA);
	grupoA.agregarSeleccion(&canada);
	
	Director dtFrancia("Mike Maignan");
    Seleccion francia("Francia", dtFrancia);
    francia.agregarJugador("Brice");
    francia.agregarJugador("Robin");
    francia.agregarJugador("William");
    francia.agregarJugador("Jules");
    francia.agregarJugador("Juan");
    francia.agregarJugador("Dayot");
    francia.agregarJugador("Theo");
    francia.agregarJugador("Lucas");
    francia.agregarJugador("Malo");
    francia.agregarJugador("Maxence");
    
    Director dtAlemania("Alexander Nubel");
	Seleccion alemania("Alemania", dtAlemania);
	alemania.agregarJugador("Oliver");
    alemania.agregarJugador("Antonio");
    alemania.agregarJugador("Waldemar");
    alemania.agregarJugador("Nathaniel");
    alemania.agregarJugador("David");
    alemania.agregarJugador("Malick"); 
    alemania.agregarJugador("Aleksandar");
    alemania.agregarJugador("Joshua");
    alemania.agregarJugador("Leon");
    alemania.agregarJugador("Jamal");
    
	Director dtItalia("Gianluigi Donnarumma");
	Seleccion italia("Italia", dtItalia);
	italia.agregarJugador("Lorenzo");
    italia.agregarJugador("Alessandro");
    italia.agregarJugador("Federico");
    italia.agregarJugador("Gianluca");
    italia.agregarJugador("Raoul");
    italia.agregarJugador("Leonardo");
    italia.agregarJugador("Nicolo");
    italia.agregarJugador("Sandro");
    italia.agregarJugador("Samuele");
    italia.agregarJugador("Matteo");
    
    Director dtArgentina("Nahuel Molina");
	Seleccion argentina("Argentina", dtArgentina);
	argentina.agregarJugador("Cristian");
    argentina.agregarJugador("Lisandro");
    argentina.agregarJugador("Nicolas");
    argentina.agregarJugador("Rodrigo");
    argentina.agregarJugador("Enzo");
    argentina.agregarJugador("Lionel");
    argentina.agregarJugador("Julian");
    argentina.agregarJugador("Lautaro");
    argentina.agregarJugador("Diego");
    argentina.agregarJugador("Alfredo");
    
    Grupo grupoB;
	grupoB.agregarSeleccion(&francia);
	grupoB.agregarSeleccion(&alemania); 
	grupoB.agregarSeleccion(&italia);
	grupoB.agregarSeleccion(&argentina);
	
	//Partidos Precargados
	Partido partido1(&mexico,&espana);
	Partido partido2(&uSA,&canada);
	Partido partido3(&francia,&alemania);
	Partido partido4(&italia,&argentina);
	
	//Goles precargados
	Jugador* mexico1=mexico.getPersona(3);
	partido1.registrarGol(mexico1);
	
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
