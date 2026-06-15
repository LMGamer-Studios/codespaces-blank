#ifndef IARCHIVO_H
#define IARCHIVO_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

#include "Seleccion.h"
#include "Grupo.h"
#include "Partido.h"
#include "Jugador.h"
#include "Director.h"

class IArchivo {
	public:
		virtual void guardarGrupo(const std::string& nombreArchivo, const std::string& nombreGrupo, Seleccion* poolSelecciones, int cantSelecciones) = 0;
		virtual void cargarGrupo(const std::string& nombreArchivo, Grupo& grupoDestino, Seleccion* poolSelecciones, int& indiceGlobalSelecciones) = 0;
		virtual void guardarPartidos(const std::string& nombreArchivo, Partido* poolPartidos, int cantPartidos) = 0;
		virtual void cargarPartidos(const std::string& nombreArchivo, Partido* poolPartidos, int& cantPartidosDestino, Seleccion* poolSelecciones, int cantSelecciones, Grupo& grupoDestino) = 0;
		
		virtual ~IArchivo() = default;
	
};

class Archivotexto : public IArchivo {
	private:
		Seleccion* buscarSeleccionEnPool(const std::string& nombrePais, Seleccion* poolSelecciones, int cantSelecciones) {
		for (int i = 0; i < cantSelecciones; i++) {
		if (poolSelecciones[i].getNombrePais() == nombrePais)
		return &poolSelecciones[i];
		}
		return nullptr;
		}
		
	public:
		void guardarGrupo(const std::string& nombreArchivo, const std::string& nombreGrupo, Seleccion* poolSelecciones, int cantSelecciones) override {
			std::ofstream archivo(nombreArchivo);
				if (!archivo.is_open()) {
				throw std::runtime_error("No se pudo abrir el archivo para guardar grupo");
			}
		    archivo << nombreGrupo << "\n" << cantSelecciones << "\n";
		
		    for (int i = 0; i < cantSelecciones; i++) {
		        archivo << poolSelecciones[i].getNombrePais() << "\n";
		
		        int cantJugadores = poolSelecciones[i].getCantidadPersonas();
		        archivo << cantJugadores << "\n";
		
		        for (int j = 0; j < cantJugadores; j++) {
		            Jugador* jugador = poolSelecciones[i].getPersona(j);
		
		            archivo << jugador->getNombre() << "\n";
		            archivo << jugador->getGoles() << "\n";
		        }
		    }
		
		    archivo.close();
		    std::cout << "¡Grupo guardado en TXT exitosamente!\n";
		}
		
		void cargarGrupo(const std::string& nombreArchivo, Grupo& grupoDestino, Seleccion* poolSelecciones, int& indiceGlobalSelecciones) override {
		    std::ifstream archivo(nombreArchivo);
		    if (!archivo.is_open()) {
		        throw std::runtime_error("No se pudo abrir el archivo para cargar grupo");
		    }
		
		    std::string nombreGrupo;
		    int cantSelecciones = 0;
		
		    std::getline(archivo, nombreGrupo);
		    archivo >> cantSelecciones;
		    archivo.ignore();
		
		    for (int i = 0; i < cantSelecciones; i++) {
		        std::string nombrePais;
		        std::getline(archivo, nombrePais);
		
		        int cantJugadores = 0;
		        archivo >> cantJugadores;
		        archivo.ignore();
		
		        Director dtCargado("DT " + nombrePais);
		
		        poolSelecciones[indiceGlobalSelecciones] = Seleccion(nombrePais, dtCargado);
		        Seleccion& selecActual = poolSelecciones[indiceGlobalSelecciones];
		
		        for (int j = 0; j < cantJugadores; j++) {
		            std::string nombreJugador;
		            int golesJugador;
		
		            std::getline(archivo, nombreJugador);
		            archivo >> golesJugador;
		            archivo.ignore();
		
		            if (!nombreJugador.empty()) {
		                selecActual.agregarJugador(nombreJugador);
		
		                Jugador* jug = selecActual.getPersona(
		                    selecActual.getCantidadPersonas() - 1
		                );
		
		                jug->setGoles(golesJugador);
		            }
		        }
		
		        grupoDestino.agregarSeleccion(&selecActual);
		        indiceGlobalSelecciones++;
		    }
		
		    archivo.close();
		}
		
		void guardarPartidos(const std::string& nombreArchivo, Partido* poolPartidos, int cantPartidos) override {
		    std::ofstream archivo(nombreArchivo);
		    if (!archivo.is_open()) {
		        throw std::runtime_error("No se pudo abrir el archivo para guardar partidos");
		    }
		
		    archivo << cantPartidos << "\n";
		
		    for (int i = 0; i < cantPartidos; i++) {
		        archivo << poolPartidos[i].getLocal() << "\n";
				archivo << poolPartidos[i].getVisitante() << "\n";
		        archivo << poolPartidos[i].getGolLoc() << "\n";
		        archivo << poolPartidos[i].getGolVis() << "\n";
		    }
		
		    archivo.close();
		}
		
		void cargarPartidos(const std::string& nombreArchivo, Partido* poolPartidos, int& cantPartidosDestino, Seleccion* poolSelecciones, int cantSelecciones, Grupo& grupoDestino) override {
		    std::ifstream archivo(nombreArchivo);
		    if (!archivo.is_open()) {
		        throw std::runtime_error("No se pudo abrir el archivo para cargar partidos");
		    }
		
		    int cantPartidosGuardados = 0;
		    archivo >> cantPartidosGuardados;
		    archivo.ignore();
		
		    for (int i = 0; i < cantPartidosGuardados; i++) {
		        std::string nombreLocal, nombreVisitante;
		        int golesLocal = 0, golesVisitante = 0;
		
		        std::getline(archivo, nombreLocal);
		        std::getline(archivo, nombreVisitante);
		
		        archivo >> golesLocal;
		        archivo >> golesVisitante;
		        archivo.ignore();
		
		        Seleccion* local = buscarSeleccionEnPool(nombreLocal, poolSelecciones, cantSelecciones);
		        Seleccion* visitante = buscarSeleccionEnPool(nombreVisitante, poolSelecciones, cantSelecciones);
		
		        if (!local || !visitante) {
		            throw std::runtime_error("Seleccion no encontrada en el pool");
		        }
		
		        poolPartidos[cantPartidosDestino] = Partido(local, visitante);
		        Partido& partidoCargado = poolPartidos[cantPartidosDestino];
		
		        partidoCargado.setResultado(golesLocal, golesVisitante);
		
		        local->actualizarEstadistica(partidoCargado.getEstadisticaLocal());
		        visitante->actualizarEstadistica(partidoCargado.getEstadisticaVisitante());
		
		        grupoDestino.registrarPartido(&partidoCargado);
		        cantPartidosDestino++;
		    }
		
		    archivo.close();
		}
};

#endif
