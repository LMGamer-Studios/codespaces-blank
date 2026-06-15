#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>
#include "Persona.h"

class Jugador : public Persona {
	private:
    	int goles;
		
	public:
   		Jugador(std::string nombreIn) : Persona(nombreIn) {
			goles = 0;
		}
		
		void setGoles(int golesIn) {

    	if (golesIn < 0) {
    		
        	throw std::invalid_argument("Cantidad de goles invalida");
    	}

    		goles = golesIn;
		}
	
    	int getGoles() const {
        	return goles;
    	}
	
    	void agregarGoles(int cantidad) {
        	goles = goles + cantidad;
    	}
		
    	std::string getTipo() const override {
        	return "Jugador";
    	}
};

#endif

