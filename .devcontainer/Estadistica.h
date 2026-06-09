#ifndef ESTADISTICA_H
#define ESTADISTICA_H

#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>

class Estadistica {
    
    private:
        int partidosJugados = 0;
        int partidosEmpate = 0;
        int partidosGanados = 0;
        int partidosPerdidos = 0;
        int golesFavor = 0;
        int golesContra = 0;
        int diferenciaGoles = 0;
        int puntos = 0;

    public:
        Estadistica() = default;
        
        Estadistica(int golesFavorIn, int golesContraIn) {

		    if (golesFavorIn < 0 || golesContraIn < 0) {
		        throw std::invalid_argument("Error! Los goles no pueden ser negativos!");
		    }
		
		    partidosJugados = 1;
		    golesFavor = golesFavorIn;
		    golesContra = golesContraIn;
		    diferenciaGoles = golesFavorIn - golesContraIn;
		
		    if (golesFavorIn > golesContraIn) {
		        partidosGanados = 1;
		        puntos = 3;
		    } 
		    else if (golesFavorIn == golesContraIn) {
		        partidosEmpate = 1;
		        puntos = 1;
		    } 
		    else {
		        partidosPerdidos = 1;
		        puntos = 0;
		    }
		}
		
		void acumular(const Estadistica& otra) {
		
		    partidosJugados += otra.partidosJugados;
		    partidosGanados += otra.partidosGanados;
		    partidosEmpate += otra.partidosEmpate;
		    partidosPerdidos += otra.partidosPerdidos;
		
		    golesFavor += otra.golesFavor;
		    golesContra += otra.golesContra;
		    diferenciaGoles = golesFavor - golesContra;
		
		    puntos += otra.puntos;
		}
        
        int getPartidosJugados() const {
			return partidosJugados;
		}
        
        int getPartidosEmpate() const {
			return partidosEmpate;
		}
        
        int getPartidosGanados() const {
			return partidosGanados;
		}
        
        int getPartidosPerdidos() const {
			return partidosPerdidos;
		}
        
        int getGolesFavor() const {
			return golesFavor;
		}
        
        int getGolesContra() const {
			return golesContra;
		}
        
        int getDiferenciaGoles() const {
			return diferenciaGoles;
		}
        
        int getPuntos() const {
			return puntos;
		}
};

#endif
