#ifndef SELECCION_H
#define SELECCION_H

#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>
#include "Jugador.h"
#include "Director.h"

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
	
	    Persona* getPersona(int i) const {
	        if (i < 0 || i >= cantidadActual) {
	            throw std::out_of_range("Indice invalido");
	        }
	        return listaPersonas[i];
	    }
	
	    void agregarJugador(const std::string& nombre) {
	        if (cantidadActual >= jugMax) {
	            throw std::out_of_range("Limite alcanzado");
	        }
	
	        listaPersonas[cantidadActual] = new Jugador(nombre);
	        cantidadActual++;
	    }
	    
	    bool perteneceElJugador(Jugador* jugIn) {
		    if (jugIn == nullptr) {
		        return false;
		    }
		    
		    for (int i = 0; i < cantidadActual; i++) {
		        if (listaPersonas[i] == jugIn) {
		            return true;
		        }
		    }
		
		    return false;
		}
	    
	    ~Seleccion() {
    		for (int i = 0; i < cantidadActual; i++) {
        	delete listaPersonas[i];
    		}
		}
};

#endif
