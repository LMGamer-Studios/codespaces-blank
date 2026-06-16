#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>
#include <cstdlib>
#include <fstream>
#include <limits>

#include "Seleccion.h"
#include "Partido.h"
#include "Estadistica.h"
#include "Grupo.h"
#include "IArchivo.h"

std::string lin = "--------------------------------\n";

int main() {

	Archivotexto archivoTextoTxt;
	IArchivo* persistence = &archivoTextoTxt;
	
const int MAX_GRUPOS = 5;
const int MAX_SELECCIONES = 8;
const int MAX_PARTIDOS = 12;
	
	Grupo gruposCreados[MAX_GRUPOS];
	std::string nombresGrupos[MAX_GRUPOS];
	int cantGruposCreados = 0;
	
	Director dtDefecto("Por Asignar");
	Seleccion seleccionesCreadas[MAX_SELECCIONES] = {
	    Seleccion("Vacio", dtDefecto),
	    Seleccion("Vacio", dtDefecto),
	    Seleccion("Vacio", dtDefecto),
	    Seleccion("Vacio", dtDefecto),
	    Seleccion("Vacio", dtDefecto),
	    Seleccion("Vacio", dtDefecto),
	    Seleccion("Vacio", dtDefecto),
	    Seleccion("Vacio", dtDefecto)
	};
	int cantSeleccionesCreadas = 0;
	
Partido poolPartidos[MAX_PARTIDOS] = {
    Partido(&seleccionesCreadas[0], &seleccionesCreadas[1]),
    Partido(&seleccionesCreadas[0], &seleccionesCreadas[1]),
    Partido(&seleccionesCreadas[0], &seleccionesCreadas[1]),
    Partido(&seleccionesCreadas[0], &seleccionesCreadas[1]),
    Partido(&seleccionesCreadas[0], &seleccionesCreadas[1]),
    Partido(&seleccionesCreadas[0], &seleccionesCreadas[1]),
    Partido(&seleccionesCreadas[0], &seleccionesCreadas[1]),
    Partido(&seleccionesCreadas[0], &seleccionesCreadas[1]),
    Partido(&seleccionesCreadas[0], &seleccionesCreadas[1]),
    Partido(&seleccionesCreadas[0], &seleccionesCreadas[1]),
    Partido(&seleccionesCreadas[0], &seleccionesCreadas[1]),
    Partido(&seleccionesCreadas[0], &seleccionesCreadas[1])
};
	int cantPartidosRegistrados = 0;
	
try {

    std::cout << "Iniciando precarga del sistema...\n";

    // ======================
    // GRUPO A
    // ======================

    nombresGrupos[cantGruposCreados] = "Grupo A";

    persistence->cargarGrupo(
        "grupoA.txt",
        gruposCreados[cantGruposCreados],
        seleccionesCreadas,
        cantSeleccionesCreadas
    );

    persistence->cargarPartidos(
        "partidosA.txt",
        poolPartidos,
        cantPartidosRegistrados,
        seleccionesCreadas,
        cantSeleccionesCreadas,
        gruposCreados[cantGruposCreados]
    );

    cantGruposCreados++;

    // ======================
    // GRUPO B
    // ======================

    nombresGrupos[cantGruposCreados] = "Grupo B";

    persistence->cargarGrupo(
        "grupoB.txt",
        gruposCreados[cantGruposCreados],
        seleccionesCreadas,
        cantSeleccionesCreadas
    );

    persistence->cargarPartidos(
        "partidosB.txt",
        poolPartidos,
        cantPartidosRegistrados,
        seleccionesCreadas,
        cantSeleccionesCreadas,
        gruposCreados[cantGruposCreados]
    );

    cantGruposCreados++;

    std::cout << "Precarga completada correctamente.\n";
    std::cout << "Selecciones cargadas: "
              << cantSeleccionesCreadas << "\n";

    std::cout << "Partidos cargados: "
              << cantPartidosRegistrados << "\n\n";

}
catch (const std::exception& e) {

    std::cerr << "Aviso en precarga: "
              << e.what() << "\n";

    cantGruposCreados = 0;
   
}
	
	int opcion = 0;
	
	/* Test */
	
	/*
	// Idoneo
	try {
	Director dt("Test");
	Seleccion s("CR", dt);
	s.agregarJugador("J1");
	Partido p(&s, &s);
	p.registrarGol(*s.getPersona(0));
	std::cout << "IDONEO OK\n";
	} catch (...) {
	std::cout << "IDONEO FAIL\n";
	}
	*/
	
	/*
	// Limite: equipos = 0
	try {
	int n = 0;
	if (n <= 0 || n > 4) throw std::out_of_range("equipos");
	} catch (const std::exception& e) {
	std::cout << "LIMITE equipos OK\n";
	}
	*/
	
	/*
	// Limite: indice jugador
	try {
	int idx = 0;
	if (idx <= 0) throw std::out_of_range("jugador");
	} catch (...) {
	std::cout << "LIMITE jugador OK\n";
	}
	*/
	
	/*
	// Extremo: goles negativos
	try {
	int g = -1;
	if (g < 0) throw std::invalid_argument("goles");
	} catch (...) {
	std::cout << "EXTREMO goles OK\n";
	}
	*/
	
	/*
	// Extremo: archivo inexistente
	try {
	Archivotexto a;
	Grupo g;
	Seleccion pool[5];
	int idx = 0;
	a.cargarGrupo("no.txt", g, pool, idx);
	} catch (...) {
	std::cout << "EXTREMO archivo OK\n";
	}
	*/
	
	/*
	// Extremo: overflow selecciones
	try {
	int cant = MAX_SELECCIONES;
	int add = 1;
	if (cant + add > MAX_SELECCIONES) throw std::out_of_range("overflow");
	} catch (...) {
	std::cout << "EXTREMO overflow OK\n";
	}
	*/
	
	/*
	// Extremo: indices partido invalidos
	try {
	int idxLocal = -1, idxVis = 100;
	if (idxLocal < 0 || idxVis < 0) throw std::out_of_range("partido");
	} catch (...) {
	std::cout << "EXTREMO partido OK\n";
	}
	*/
	
	/*
	// Extremo: jugador inexistente
	try {
	Director dt("T");
	Seleccion s1("A", dt), s2("B", dt);
	Partido p(&s1, &s2);
	p.registrarGol(*s1.getPersona(0));
	} catch (...) {
	std::cout << "EXTREMO jugador inexistente OK\n";
	}
	*/
	
	/*
	// Extremo: subopcion invalida
	try {
	int sub = 99;
	if (sub != 1 && sub != 2) throw std::invalid_argument("subop");
	} catch (...) {
	std::cout << "EXTREMO subop OK\n";
	}
	*/
	
	// Fin de Tests

	
	do {
	    try {
	        std::cout << lin << "Que accion desea realizar?\n" << lin;
	        std::cout << "1. Registrar / Cargar grupos y selecciones\n\n";
	        std::cout << "2. Registrar, Guardar y Cargar resultados de partidos\n\n";
	        std::cout << "3. Mostrar tabla de posiciones\n\n";
	        std::cout << "4. Mostrar tabla de goleadores\n\n";
	        std::cout << "5. Salir del programa\n";
	        std::cout << lin << "Digite su seleccion a continuacion: ";
	        std::cin >> opcion;
	
	        if (std::cin.fail()) throw std::invalid_argument("Entrada invalida en el menu");
	
	        switch(opcion) {
	
	            case 1: {
					std::system("cls");
					
					if (cantGruposCreados >= MAX_GRUPOS) {
					    throw std::out_of_range("Maximo de grupos alcanzado");
					}
					
					std::cout << "=== GESTION DE GRUPOS ===\n";
					std::cout << "1. Crear grupo manualmente\n";
					std::cout << "2. Cargar grupo desde archivo\n";
					
					int subOpcion;
					std::cout << "Seleccione una opcion: ";
					std::cin >> subOpcion;
					
					if (subOpcion == 1) {
					
					    std::string nomGrupo;
					    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					    std::cout << "Nombre del grupo: ";
					    std::getline(std::cin, nomGrupo);
					
					    nombresGrupos[cantGruposCreados] = nomGrupo;
					
					    int numEquipos;
					    std::cout << "Cuantas selecciones desea agregar (Max 4): ";
					    std::cin >> numEquipos;
					
					    if (numEquipos <= 0 || numEquipos > 4) {
					        throw std::out_of_range("Numero de equipos invalido (1-4)");
					    }
					
					    if (cantSeleccionesCreadas + numEquipos > MAX_SELECCIONES) {
					        throw std::out_of_range("Excede el maximo de selecciones");
					    }
					
					    int indiceInicio = cantSeleccionesCreadas;
					
					    for (int i = 0; i < numEquipos; i++) {
					
					        std::string nombrePais, nombreDT;
					        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					        std::cout << "Nombre del Pais: ";
					        std::getline(std::cin, nombrePais);
					
					        std::cout << "Nombre del DT: ";
					        std::getline(std::cin, nombreDT);
					
					        Director dtTemp(nombreDT);
					        seleccionesCreadas[cantSeleccionesCreadas] = Seleccion(nombrePais, dtTemp);
					
					        Seleccion& seleccionInsertada = seleccionesCreadas[cantSeleccionesCreadas];
					        cantSeleccionesCreadas++;
					
					        int cantJugadoresManual;
					        std::cout << "¿Cuantos jugadores?: ";
					        std::cin >> cantJugadoresManual;
					
					        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					        for (int j = 0; j < cantJugadoresManual; j++) {
					            std::string nomJug;
					            std::getline(std::cin, nomJug);
					
					            if (!nomJug.empty()) {
					                seleccionInsertada.agregarJugador(nomJug);
					            }
					        }
					
					        gruposCreados[cantGruposCreados].agregarSeleccion(&seleccionInsertada);
					    }
					
					    char guardarTxt;
					    std::cout << "¿Desea exportar el grupo? (s/n): ";
					    std::cin >> guardarTxt;
					
					    if (guardarTxt == 's' || guardarTxt == 'S') {
					        std::string archivoName;
					        std::cout << "Nombre de archivo: ";
					        std::cin >> archivoName;
					
					        persistence->guardarGrupo(archivoName, nomGrupo, &seleccionesCreadas[indiceInicio], numEquipos);
					    }
					
					    cantGruposCreados++;
					}
					
					else if (subOpcion == 2) {

						std::string archivoName;
						std::cout << "Nombre del archivo a cargar: ";
						std::cin >> archivoName;
						
						if (archivoName.size() < 4 || archivoName.substr(archivoName.size() - 4) != ".txt") {
					        archivoName += ".txt";
					    }
						
						persistence->cargarGrupo(archivoName, gruposCreados[cantGruposCreados], seleccionesCreadas, cantSeleccionesCreadas);
						nombresGrupos[cantGruposCreados] = "Grupo_Cargado";
						cantGruposCreados++;
						
						std::cout << "Grupo cargado correctamente.\n";
					}
					
					else {
					    throw std::invalid_argument("Subopcion invalida");
					}
					
					std::system("pause");
					std::system("cls");
					break;
					}
				
	            case 2: {
	                std::system("cls");
	
	                if (cantGruposCreados == 0) break;
	
	                Grupo& grupoActualActivo = gruposCreados[cantGruposCreados - 1];
	
	                int idxLocal, idxVis;
	                std::cout << "Local (numero): ";
	                std::cin >> idxLocal;
	
	                std::cout << "Visitante (numero): ";
	                std::cin >> idxVis;
	
	                if (idxLocal < 1 || idxLocal > cantSeleccionesCreadas ||
	                    idxVis < 1 || idxVis > cantSeleccionesCreadas) {
	                    throw std::out_of_range("Indices de seleccion invalidos");
	                }
	
	                idxLocal--;
	                idxVis--;
	
	                if (cantPartidosRegistrados >= MAX_PARTIDOS) {
	                    throw std::out_of_range("Maximo de partidos alcanzado");
	                }
	
	                poolPartidos[cantPartidosRegistrados] = Partido(&seleccionesCreadas[idxLocal], &seleccionesCreadas[idxVis]);
	                Partido& partidoActual = poolPartidos[cantPartidosRegistrados];
	
	                int totalGoles;
	                std::cout << "Goles totales: ";
	                std::cin >> totalGoles;
	
	                if (totalGoles < 0) {
	                    throw std::invalid_argument("Cantidad de goles no puede ser negativa");
	                }
	
	                for (int g = 0; g < totalGoles; g++) {
	
	                    int opAnotador;
	                    std::cin >> opAnotador;
	
	                    Seleccion* equipoAnotador = (opAnotador == 1)
	                        ? &seleccionesCreadas[idxLocal]
	                        : &seleccionesCreadas[idxVis];
	
	                    int idxJugador;
	                    std::cin >> idxJugador;
	
	                    if (idxJugador <= 0) {
	                        throw std::out_of_range("Indice de jugador invalido");
	                    }
	
	                    idxJugador--;
	
	                    partidoActual.registrarGol(
	                        *equipoAnotador->getPersona(idxJugador)
	                    );
	                }
	
	                grupoActualActivo.registrarPartido(&partidoActual);
	
	                cantPartidosRegistrados++;
	
	                char guardarPartidos;
	                std::cout << "¿Guardar historial? (s/n): ";
	                std::cin >> guardarPartidos;
	
	                if (guardarPartidos == 's' || guardarPartidos == 'S') {
	                    persistence->guardarPartidos("historico_partidos.txt", poolPartidos, cantPartidosRegistrados);
	                }
	
	                std::system("pause");
	                std::system("cls");
	                break;
	            }
	
	            case 3:
	             if (cantGruposCreados == 0) {
				        std::cout << "No hay grupos registrados.\n";
				        break;
				    }
				
				    std::cout << "Grupos disponibles:\n";
				
				    for (int i = 0; i < cantGruposCreados; i++) {
				        std::cout << i + 1 << ". " << nombresGrupos[i] << "\n";
				    }
				
				    int grupoElegido;
				    std::cout << "Seleccione un grupo: ";
				    std::cin >> grupoElegido;
				
				    if (grupoElegido < 1 || grupoElegido > cantGruposCreados) {
				        throw std::out_of_range("Grupo seleccionado invalido");
				    }
				
				    grupoElegido--;
				
				    gruposCreados[grupoElegido].tabla();
				
				    std::system("pause");
				    std::system("cls");
				    break;
	
	            case 4: {
	                if (cantGruposCreados == 0) {
	                    std::cout << "No hay grupos registrados.\n";
	                    break;
	                }
	
	                std::cout << "Grupos disponibles:\n";
	                for (int i = 0; i < cantGruposCreados; i++) {
	                    std::cout << i + 1 << ". " << nombresGrupos[i] << "\n";
	                }
	
	                int grupoElegido;
	                std::cout << "Seleccione un grupo: ";
	                std::cin >> grupoElegido;
	
	                if (grupoElegido < 1 || grupoElegido > cantGruposCreados) {
	                    throw std::out_of_range("Grupo seleccionado invalido");
	                }
	
	                grupoElegido--;
	
	                gruposCreados[grupoElegido].tablaGoleadores();
	
	                std::system("pause");
	                std::system("cls");
	                break;
	            }
	
	            case 5:
	                std::cout << "Saliendo del programa...\n";
	                break;
	
	            default:
	                std::cout << "Opcion invalida\n";
	                std::system("pause");
	                std::system("cls");
	        }
	
	    } catch (const std::exception& e) {
	        std::cout << "Error: " << e.what() << std::endl;
	
	        std::cin.clear();
	        std::cin.ignore(1000, '\n');
	
	        std::system("pause");
	        std::system("cls");
	    }
	
	} while(opcion != 5);
	
	return 0;
}
