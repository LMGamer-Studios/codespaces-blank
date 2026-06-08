#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>
#include <cstdlib>
#include "Persona.h"

#ifndef DIRECTOR_H
#define DIRECTOR_H

class Director : public Persona {
	public:
	    Director(std::string nombreIn) : Persona(nombreIn) {}
	
	    std::string getTipo() const override {
	        return "Director Tecnico";
	    }
};

#endif
