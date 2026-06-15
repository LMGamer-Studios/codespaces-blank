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
#include "IArchivo.h"

std::string lin = "--------------------------------\n";

int main() {
    Archivotexto archivoTextoTxt; 
    IArchivo* persistence = &archivoTextoTxt;
    
    const int MAX_GRUPOS = 5; const int MAX_SELECCIONES = 4; const int MAX_PARTIDOS = 6; 
    Grupo gruposCreados[MAX_GRUPOS]; std::string nombresGrupos[MAX_GRUPOS]; int cantGruposCreados = 0;

    Director dtDefecto("Por Asignar");
    Director poolDirectores[MAX_SELECCIONES] = { Director("Por Asignar"), Director("Por Asignar"), Director("Por Asignar"), Director("Por Asignar") };
    Seleccion seleccionesCreadas[MAX_SELECCIONES] = { Seleccion("Vacio", dtDefecto), Seleccion("Vacio", dtDefecto), Seleccion("Vacio", dtDefecto), Seleccion("Vacio", dtDefecto) };
    int cantSeleccionesCreadas = 0;

    Partido poolPartidos[MAX_PARTIDOS] = {
        Partido(&seleccionesCreadas[0], &seleccionesCreadas[1]), Partido(&seleccionesCreadas[0], &seleccionesCreadas[1]),
        Partido(&seleccionesCreadas[0], &seleccionesCreadas[1]), Partido(&seleccionesCreadas[0], &seleccionesCreadas[1]),
        Partido(&seleccionesCreadas[0], &seleccionesCreadas[1]), Partido(&seleccionesCreadas[0], &seleccionesCreadas[1])
    };
    int cantPartidosRegistrados = 0;

    int opcion = 0;
    do {
        std::cout << "- - - - - - Bienvenido al sistema de simulacion de la copa del mundo 2026! - - - - - -\n\n";
        std::cout << lin << "Que accion desea realizar?\n" << lin;
        std::cout << "1. Registrar / Cargar grupos y selecciones\n\n";
        std::cout << "2. Registrar, Guardar y Cargar resultados de partidos\n\n";
        std::cout << "3. Mostrar tabla de posiciones\n\n";
        std::cout << "4. Mostrar tabla de goleadores\n\n";
        std::cout << "5. Salir del programa\n";
        std::cout << lin << "Digite su seleccion a continuacion: ";
        std::cin >> opcion;
        
        switch(opcion) {
            case 1: {
                std::system("cls");
                std::cout << "=== GESTION DE GRUPOS ===\n";
                std::cout << "1. Registrar grupo nuevo manualmente\n";
                std::cout << "2. Cargar un grupo completo desde un archivo\n";
                int subOpcion = 0; std::cout << "Seleccione una opcion: "; std::cin >> subOpcion;

                if (subOpcion == 1) {
                    std::string nomGrupo; std::cout << "\nNombre del grupo: "; std::cin.ignore(); std::getline(std::cin, nomGrupo);
                    nombresGrupos[cantGruposCreados] = nomGrupo;

                    int numEquipos = 0; std::cout << "Cuantas selecciones desea agregar (Max 4): "; std::cin >> numEquipos;
                    int indiceInicio = cantSeleccionesCreadas;

                    for (int i = 0; i < numEquipos; i++) {
                        std::string nombrePais, nombreDT; std::cin.ignore();
                        std::cout << "Nombre del Pais: "; std::getline(std::cin, nombrePais);
                        std::cout << "Nombre del DT: "; std::getline(std::cin, nombreDT);

                        poolDirectores[cantSeleccionesCreadas] = Director(nombreDT);
                        seleccionesCreadas[cantSeleccionesCreadas] = Seleccion(nombrePais, poolDirectores[cantSeleccionesCreadas]);
                        Seleccion& seleccionInsertada = seleccionesCreadas[cantSeleccionesCreadas];
                        cantSeleccionesCreadas++;

                        int cantJugadoresManual = 0; std::cout << "¿Cuantos jugadores?: "; std::cin >> cantJugadoresManual;
                        std::cin.ignore();
                        for (int j = 0; j < cantJugadoresManual; j++) {
                            std::string nomJug; std::getline(std::cin, nomJug);
                            if (!nomJug.empty()) seleccionInsertada.agregarJugador(nomJug);
                        }
                        gruposCreados[cantGruposCreados].agregarSeleccion(&seleccionInsertada);
                    }

                    char guardarTxt; std::cout << "¿Desea exportar el grupo? (s/n): "; std::cin >> guardarTxt;
                    if (guardarTxt == 's' || guardarTxt == 'S') {
                        std::string archivoName; std::cout << "Nombre de archivo: "; std::cin >> archivoName;
                        
                        persistence->guardarGrupo(archivoName, nomGrupo, &seleccionesCreadas[indiceInicio], numEquipos);
                    }
                    cantGruposCreados++;

                } else if (subOpcion == 2) {
                    std::string archivoLectura; std::cout << "Ingrese el archivo a cargar: "; std::cin >> archivoLectura;
                    
                    persistence->cargarGrupo(archivoLectura, gruposCreados[cantGruposCreados], seleccionesCreadas, cantSeleccionesCreadas);
                    nombresGrupos[cantGruposCreados] = "Grupo Importado " + std::to_string(cantGruposCreados + 1);
                    cantGruposCreados++;
                }
                std::system("pause"); std::system("cls");
                break;
            }
            
            case 2: {
                std::system("cls");
                std::cout << "=== GESTION DE PARTIDOS ===\n";
                std::cout << "1. Registrar partido manualmente\n";
                std::cout << "2. Cargar historico de partidos\n";
                int subOpcPartido = 0; std::cout << "Seleccione una opcion: "; std::cin >> subOpcPartido;

                if (cantGruposCreados == 0) { break; }
                Grupo& grupoActualActivo = gruposCreados[cantGruposCreados - 1];

                if (subOpcPartido == 1) {
                    int idxLocal, idxVis; std::cout << "Local (numero): "; std::cin >> idxLocal;
                    std::cout << "Visitante (numero): "; std::cin >> idxVis;
                    idxLocal--; idxVis--;

                    poolPartidos[cantPartidosRegistrados] = Partido(&seleccionesCreadas[idxLocal], &seleccionesCreadas[idxVis]);
                    Partido& partidoActual = poolPartidos[cantPartidosRegistrados];

                    int totalGoles = 0; std::cout << "Goles totales: "; std::cin >> totalGoles;
                    for (int g = 0; g < totalGoles; g++) {
                        int opAnotador; std::cin >> opAnotador;
                        Seleccion* equipoAnotador = (opAnotador == 1) ? &seleccionesCreadas[idxLocal] : &seleccionesCreadas[idxVis];
                        int idxJugador; std::cin >> idxJugador; idxJugador--;
                        partidoActual.registrarGol(equipoAnotador->getPersona(idxJugador));
                    }

                    seleccionesCreadas[idxLocal].actualizarEstadistica(partidoActual.getEstadisticaLocal());
                    seleccionesCreadas[idxVis].actualizarEstadistica(partidoActual.getEstadisticaVisitante());
                    grupoActualActivo.registrarPartido(&partidoActual);
                    cantPartidosRegistrados++;

                    char guardarPartidos; std::cout << "¿Guardar historial? (s/n): "; std::cin >> guardarPartidos;
                    if (guardarPartidos == 's' || guardarPartidos == 'S') {
                        persistence->guardarPartidos("historico_partidos.txt", poolPartidos, cantPartidosRegistrados);
                    }
                } else if (subOpcPartido == 2) {
                    std::string archivoPartidosName; std::cout << "Nombre del archivo de partidos: "; std::cin >> archivoPartidosName;
                    
                    persistence->cargarPartidos(archivoPartidosName, poolPartidos, cantPartidosRegistrados, seleccionesCreadas, cantSeleccionesCreadas, grupoActualActivo);
                }
                std::system("pause"); std::system("cls");
                break;
            }
            case 3:
            	std::cout << "Funcionalidad de tablas en desarrollo...\n";
                std::system("pause"); std::system("cls");
                break;
                
            case 4:
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
			
			    grupoElegido--;
			
			    gruposCreados[grupoElegido].tablaGoleadores();
			
			    std::system("pause");
			    std::system("cls");
			
			    break;
                
                
            case 5:
                std::cout << "Gracias por usar el programa! Saliendo...\n";
                std::system("pause"); std::system("cls");
                break;
                
            default:
                std::cout << "Opcion invalida, vuelva a intentarlo\n";
                std::system("pause"); std::system("cls");
        }
        
    } while(opcion != 5);

    return 0;
}
