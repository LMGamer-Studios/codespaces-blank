#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>
#include <cstdlib>

#ifndef PERSONA_H
#define PERSONA_H

class Persona {
protected:
    std::string nombre;

public:
    Persona(std::string nombreIn) : nombre(nombreIn) {}

    std::string getNombre() const {
        return nombre;
    }

    virtual std::string getTipo() const = 0;
    
    virtual ~Persona() {}
};

#endif
