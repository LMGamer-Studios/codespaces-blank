#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>
#include <cstdlib>

class Persona{
	private:
        std::string nombre = "N/A";
	public:
        Persona(std::string nombreIn){
            nombre = nombreIn;
        }

        std::string getNombres(){
	        return nombre;
        }
};

class Jugador : virtual public Persona{
    private:
        int goles = 0;
    public:
        int getGoles(){
            return goles;
        }
        int addGoles(){
            goles++;
        }
};

class Director : virtual public Persona{
    private:
        //void placeholder = 0;
    public:
        //void placeholder();
};
