#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>
#include <cstdlib>
#include "Persona.h"

class Seleccion{
    private:
        std::string nombreSeleccion= "N/A";
        Jugador** arregloJugadores[26];
        int posicion = 0;
    public:
        Seleccion(std::string nombreSeleccionIn){
            nombreSeleccion = nombreSeleccionIn;
        }
        void añadirJugadores (Jugador* JugadorIn){
            if (posicion >=26){
                std::throw out_of_range("Error: Limite de 26 jugadores excedido!");
            }else{
                arregloJugadores[posicion] = JugadorIn;
                posicion++;
            }
        }
};

class Grupo{
    private:
        //void placeholder = 0;
    public:
        //void placeholder();
};
