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
    	
    	void agregarSeleccion(/*input*/){
    		
    		assert(cantSele >= 0);
    		
    		if (cantSele <= seleccionesMax){
    			//agrege la seleccion
			}else if (cantSele > seleccionesMax){
				throw std::out_of_range("Error! Limite alcanzado!");
			}
    		
		}
		
		void jugarPartido(/* input Partido* */){
			//logic
		}
		
		void tabla(/*inputs*/){
			//logic
		}
		
		void getGanador(/*inputs*/){
			//logic
		}
};

#endif
