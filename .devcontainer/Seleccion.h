#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>
#include <cstdlib>
#include "Jugador.h"
#include "Director.h"

#ifndef SELECCION_H
#define SELECCION_H

class Seleccion {
	private:
	    static const int jugMax = 26;
	
	    Persona* listaPersonas[jugMax];
	    int cantidadActual;
	
	    Director directorTecnico;
	    std::string nombrePais;
	
	public:
	    Seleccion(std::string pais, Director dir)
	        : nombrePais(pais), directorTecnico(dir), cantidadActual(0) {}
	
	    std::string getNombrePais() const {
	        return nombrePais;
	    }
	
	    int getCantidadPersonas() const {
	        return cantidadActual;
	    }
	
	    Persona* getPersona(int index) const {
	        if (index < 0 || index >= cantidadActual) {
	            throw std::out_of_range("Indice invalido");
	        }
	        return listaPersonas[index];
	    }
	
	    void agregarJugador(const std::string& nombre) {
	        if (cantidadActual >= jugMax) {
	            throw std::out_of_range("Limite alcanzado");
	        }
	
	        listaPersonas[cantidadActual] = new Jugador(nombre);
	        cantidadActual++;
	    }
	    
	    ~Seleccion() {
    		for (int i = 0; i < cantidadActual; i++) {
        	delete listaPersonas[i];
    		}
		}
};

class Grupo{
    private:
        //void placeholder = 0;
    public:
        //void placeholder();
};

#endif
