#ifndef PARTIDO_H
#define PARTIDO_H

#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>
#include "Seleccion.h"
#include "Jugador.h"
#include "Estadistica.h"

class Partido{
    
private:
    Seleccion* local;
    Seleccion* visitante;

    int golLoc = 0, golVis = 0;

public:

    Partido(Seleccion* Loc, Seleccion* Vis)
        : local(Loc), visitante(Vis)
    {
        if (Loc == nullptr || Vis == nullptr) {
            throw std::invalid_argument("Error! Selecciones invalidas!");
        }
        if (Loc == Vis) {
            throw std::invalid_argument("Error! Una seleccion no puede jugar contra si misma!");
        }
    }
	
    void setResultado(int golLocIn, int golVisIn){ //para testeos o cargas rapidas de datos de un partido. USAR ESE SOLO PARA TESTEO!
			if (golLocIn < 0 || golVisIn < 0) {
    			throw std::invalid_argument("Los goles no pueden ser negativos");
			}
			
			golLoc = golLocIn;
			golVis = golVisIn;
		}
	
    void registrarGol(Jugador* jug){ //para simulaciones de partido. USAR PRINCIPALMENTE ESTE!
			
			if (jug == nullptr){
				throw std::invalid_argument("Error! El jugador dado no es valido");
			}
			
			if (local->perteneceElJugador(jug)) {
			    golLoc++;
			}
			else if (visitante->perteneceElJugador(jug)) {
			    golVis++;
			}
			else {
			    throw std::invalid_argument("El jugador no pertenece a ninguna seleccion");
			}
			
			jug->agregarGoles(1);
		}
		
    // esto es para sacar estadisticas 
    Estadistica getEstadisticaLocal() const{
        return Estadistica(golLoc, golVis);
    }

    Estadistica getEstadisticaVisitante() const{
        return Estadistica(golVis, golLoc);
    }

	bool hayEmpate() const{
		if (golLoc == golVis){
			return true;
		}else{
			return false;
		}
	}
		
	std::string getGanador() const{
		if (golLoc > golVis)
		    return local->getNombrePais();
		else if (golVis > golLoc)
		    return visitante->getNombrePais();
		else
		    return "Empate";
	}

    int getGolLoc() const{
        return golLoc;
    }

    int getGolVis() const{
        return golVis;
    }

    std::string getLocal() const{
        return local->getNombrePais();
    }

    std::string getVisitante() const{
        return visitante->getNombrePais();
    }
    
    Seleccion* getSeleccionLocal() const {
	    return local;
	}
	
	Seleccion* getSeleccionVisitante() const {
	    return visitante;
	}
};

#endif
