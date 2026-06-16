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
#include "Archivotexto.h"

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

    // GRUPO A

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

    // GRUPO B

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
	
	/* Tests */
	
	/*
	// Idoneo
	try {
	    Director dt("Test");
	    Seleccion s("CR", dt);
	    s.agregarJugador("J1");
	    Partido p(&s, &s);
	    p.registrarGol(*s.getPersona(0));
	    std::cout << "IDONEO OK\n";
	} catch (const std::exception& e) {
	    std::cout << e.what() << "\n";
	}
	*/
	
	/*
	// Limite: equipos = 0
	try {
	    int n = 0;
	    if (n <= 0 || n > 4) throw std::out_of_range("Numero de equipos invalido (1-4)");
	} catch (const std::exception& e) {
	    std::cout << e.what() << "\n";
	}
	*/
	
	/*
	// Limite: indice jugador
	try {
	    int idx = 0;
	    if (idx <= 0) throw std::out_of_range("Indice de jugador invalido");
	} catch (const std::exception& e) {
	    std::cout << e.what() << "\n";
	}
	*/
	
	/*
	// Extremo: goles negativos
	try {
	    int g = -1;
	    if (g < 0) throw std::invalid_argument("Cantidad de goles no puede ser negativa");
	} catch (const std::exception& e) {
	    std::cout << e.what() << "\n";
	}
	*/
	
	/*
	// Extremo: archivo inexistente
	try {
	    Archivotexto a;
	    Grupo g;
	    Seleccion pool[5] = {
	        Seleccion("A", Director("x")),
	        Seleccion("B", Director("x")),
	        Seleccion("C", Director("x")),
	        Seleccion("D", Director("x")),
	        Seleccion("E", Director("x"))
	    };
	    int idx = 0;
	    a.cargarGrupo("no.txt", g, pool, idx);
	} catch (const std::exception& e) {
	    std::cout << e.what() << "\n";
	}
	*/
	
	/*
	// Extremo: overflow selecciones REAL
	try {
	    int cant = MAX_SELECCIONES;
	    int add = 1;
	    if (cant + add > MAX_SELECCIONES)
	        throw std::out_of_range("Excede el maximo de selecciones");
	} catch (const std::exception& e) {
	    std::cout << e.what() << "\n";
	}
	*/
	
	/*
	// Extremo: indices partido invalidos (negativos y grandes)
	try {
	    int idxLocal = -1, idxVis = 100;
	    if (idxLocal < 0 || idxVis < 0 || idxLocal >= MAX_SELECCIONES || idxVis >= MAX_SELECCIONES)
	        throw std::out_of_range("Indices de seleccion invalidos");
	} catch (const std::exception& e) {
	    std::cout << e.what() << "\n";
	}
	*/
	
	/*
	// Extremo: jugador inexistente REAL
	try {
	    Director dt("T");
	    Seleccion s1("A", dt), s2("B", dt);
	    Partido p(&s1, &s2);
	    // NO agregamos jugadores → debería fallar
	    p.registrarGol(*s1.getPersona(0));
	} catch (const std::exception& e) {
	    std::cout << e.what() << "\n";
	}
	*/
	
	/*
	// Extremo: subopcion invalida
	try {
	    int sub = 99;
	    if (sub != 1 && sub != 2)
	        throw std::invalid_argument("Subopcion invalida");
	} catch (const std::exception& e) {
	    std::cout << e.what() << "\n";
	}
	*/
	
	/*
	// 🔥 NUEVO: duplicar grupo (BUG PRINCIPAL QUE TENIAS)
	try {
	    std::string archivo = "grupoA.txt";
	
	    std::string nombres[2] = {"grupoA.txt", "grupoB.txt"};
	    int cant = 2;
	
	    for (int i = 0; i < cant; i++) {
	        if (nombres[i] == archivo) {
	            throw std::invalid_argument("Ese archivo ya fue cargado");
	        }
	    }
	} catch (const std::exception& e) {
	    std::cout << e.what() << "\n";
	}
	*/
	
	/*
	// 🔥 NUEVO: grupo lleno
	try {
	    Grupo g;
	    Director dt("X");
	
	    Seleccion s1("A", dt), s2("B", dt), s3("C", dt), s4("D", dt), s5("E", dt);
	
	    g.agregarSeleccion(&s1);
	    g.agregarSeleccion(&s2);
	    g.agregarSeleccion(&s3);
	    g.agregarSeleccion(&s4);
	    g.agregarSeleccion(&s5); // debería explotar
	} catch (const std::exception& e) {
	    std::cout << e.what() << "\n";
	}
	*/
	
	/*
	// 🔥 NUEVO: partido con equipo fuera del grupo
	try {
	    Grupo g;
	    Director dt("X");
	
	    Seleccion s1("A", dt), s2("B", dt), s3("C", dt);
	
	    g.agregarSeleccion(&s1);
	    g.agregarSeleccion(&s2);
	
	    Partido p(&s1, &s3); // s3 no está en el grupo
	
	    g.registrarPartido(&p);
	} catch (const std::exception& e) {
	    std::cout << e.what() << "\n";
	}
	*/
	
	/*
	// 🔥 NUEVO: puntero nulo en grupo
	try {
	    Grupo g;
	    g.agregarSeleccion(nullptr);
	} catch (const std::exception& e) {
	    std::cout << e.what() << "\n";
	}
	*/
	
	/* Fin Tests */
	
	
	do {
	    try {
	        std::cout << lin << "Que accion desea realizar?\n" << lin;
	        std::cout << "1. Cargar grupos y selecciones\n\n";
	        std::cout << "2. Cargar resultados de partidos\n\n";
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
					
					    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					    for (int i = 0; i < numEquipos; i++) {
					
					        std::string nombrePais, nombreDT;
					
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
					
					        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // OK (este sí)
					
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
					
					    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					    
					    std::cout << "Nombre del archivo a cargar: ";
					    std::getline(std::cin, archivoName);
					
					    if (archivoName.size() < 4 || archivoName.substr(archivoName.size() - 4) != ".txt") {
					        archivoName += ".txt";
					    }
					
					    for (int i = 0; i < cantGruposCreados; i++) {
					        if (nombresGrupos[i] == archivoName) {
					            throw std::invalid_argument("Ese archivo ya fue cargado");
					        }
					    }
					
					    if (cantSeleccionesCreadas >= MAX_SELECCIONES) {
					        throw std::out_of_range("No hay espacio para mas selecciones");
					    }
					
					    gruposCreados[cantGruposCreados] = Grupo();
					
					    persistence->cargarGrupo(
					        archivoName,
					        gruposCreados[cantGruposCreados],
					        seleccionesCreadas,
					        cantSeleccionesCreadas
					    );
					
					    nombresGrupos[cantGruposCreados] = archivoName;
					
					    cantGruposCreados++;
					
					    std::cout << "Grupo cargado correctamente.\n";
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
