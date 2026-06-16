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

#endif
