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
		
		void registrarPartido(Partido* partidoIn){
		    if (partidoIn == nullptr){
		        throw std::invalid_argument("Error! Partido dado invalido!");
		    }
			
		    if (cantPartido >= partidosMax){
		        throw std::out_of_range("Error! Limite alcanzado!");
		    }
			
		    Seleccion* loc = partidoIn->getSeleccionLocal();
		    Seleccion* vis = partidoIn->getSeleccionVisitante();
			
		    bool locEstaEnElGrupo = false, visEstaEnElGrupo = false;
			
		    for (int i = 0; i < cantSele; i++){
		        if (selecciones[i] == loc){
		            locEstaEnElGrupo = true;
		            break;
		        }
		    }
			
		    for (int i = 0; i < cantSele; i++){
		        if (selecciones[i] == vis){
		            visEstaEnElGrupo = true;
		            break;
		        }
		    }
			
		    if (!locEstaEnElGrupo || !visEstaEnElGrupo){
		        throw std::invalid_argument("Error! Uno o mas de los equipos NO esta en el grupo!");
		    }
			
		    partidos[cantPartido] = partidoIn;
		    cantPartido++;
			
		    loc->actualizarEstadistica(partidoIn->getEstadisticaLocal());
		    vis->actualizarEstadistica(partidoIn->getEstadisticaVisitante());
		}
		
		void tabla(){
		
		    if (cantSele == 0){
		        throw std::logic_error("Error! No hay selecciones en el grupo");
		    }
		
		    Seleccion* temp[4];
		
		    for (int i = 0; i < cantSele; i++){
		        temp[i] = selecciones[i];
		    }
		
		    for (int i = 0; i < cantSele; ++i) {
		        for (int j = 0; j < cantSele - i - 1; ++j) {
		            if (
		                temp[j]->getPuntos() < temp[j + 1]->getPuntos() ||
		
		                (temp[j]->getPuntos() == temp[j + 1]->getPuntos() &&
		                 temp[j]->getDiferenciaGoles() < temp[j + 1]->getDiferenciaGoles()) ||
		
		                (temp[j]->getPuntos() == temp[j + 1]->getPuntos() &&
		                 temp[j]->getDiferenciaGoles() == temp[j + 1]->getDiferenciaGoles() &&
		                 temp[j]->getGolesFavor() < temp[j + 1]->getGolesFavor())
		            ){
		                Seleccion* aux = temp[j];
		                temp[j] = temp[j + 1];
		                temp[j + 1] = aux;
		            }
		        }
		    }
		
		    std::cout << "Tabla del grupo:\n";
		
		    for (int i = 0; i < cantSele; i++){
		        std::cout << i+1 << ". "
		                  << temp[i]->getNombrePais()
		                  << " | Pts: " << temp[i]->getPuntos()
		                  << " | DG: " << temp[i]->getDiferenciaGoles()
		                  << " | GF: " << temp[i]->getGolesFavor() << "\n";
		    }
		}
		
		Seleccion* getGanador(){
		
		    if (cantSele == 0){
		        throw std::logic_error("Error! No hay selecciones en el grupo");
		    }
		
		    Seleccion* mejor = selecciones[0];
		
		    for (int i = 1; i < cantSele; i++){
		        if (selecciones[i]->getPuntos() > mejor->getPuntos()){
		            mejor = selecciones[i];
		        }
		    }
		
		    return mejor;
		}
};

#endif
