#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>

class Persona {
private:
    std::string nombre;

public:
    Persona(std::string nombreIn){
		nombre = nombreIn;
	}

    std::string getNombre() const {
        return nombre;
    }

    virtual std::string getTipo() const = 0;
    
    virtual ~Persona() {}
};

#endif
