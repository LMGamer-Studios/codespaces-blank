#ifndef GRUPO_H
#define GRUPO_H

#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>
#include "Seleccion.h"
#include "Partido.h"
#include "Estadistica.h"

class Grupo {
	private:
		static const int seleccionesMax = 4; //4 selecciones por grupo
		static const int partidosMax = 6; //6 partidos por grupo es estandard
		int cantSele = 0, cantPartido = 0;
		
    	Seleccion* selecciones[seleccionesMax];
    	Partido* partidos[partidosMax];
    public:
    	Grupo(){
    		for (int i = 0; i < seleccionesMax; i++){
    			selecciones[i] = nullptr;
			}
			
			for (int i = 0; i < partidosMax; i++){
				partidos[i] = nullptr;
			}
			
			cantSele = 0;
			cantPartido = 0;
		}
    	
    	void agregarSeleccion(Seleccion* seleIn){
		    if (seleIn == nullptr){
		        throw std::invalid_argument("Error! Seleccion dada invalida!");
		    }
		
		    for (int i = 0; i < cantSele; i++){
		        if (selecciones[i] == seleIn){
		            throw std::invalid_argument("Error! La seleccion ya esta en el grupo!");
		        }
		    }
		
		    if (cantSele >= seleccionesMax){
		        throw std::out_of_range("Error! Limite alcanzado!");
		    }
		
		    selecciones[cantSele] = seleIn;
		    cantSele++;
		}
		
		void jugarPartido(Partido* partidoIn){
			if (partidoIn == nullptr){
		        throw std::invalid_argument("Error! Partido dado invalido!");
		    }
		    
		    if (cantPartido >= partidosMax){
		        throw std::out_of_range("Error! Limite alcanzado!");
		    }
		    
		    
		}
		
		void tabla(/*inputs*/){
			//logic
		}
		
		void getGanador(/*inputs*/){
			//logic
		}
};

#endif
