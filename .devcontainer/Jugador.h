#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>
#include <cstdlib>
#include "Persona.h"

#ifndef JUGADOR_H
#define JUGADOR_H

class Jugador : public Persona {
	private:
    	int goles;
		
	public:
   		Jugador(std::string nombreIn) : Persona(nombreIn), goles(0) {}
	
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
