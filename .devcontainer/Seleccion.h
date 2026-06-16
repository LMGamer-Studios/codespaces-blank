#ifndef SELECCION_H
#define SELECCION_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <cassert>

#include "Jugador.h"
#include "Director.h"
#include "Estadistica.h"

class Seleccion {

private:

    static const int jugMax = 26;

    Jugador* listaPersonas[jugMax];
    int cantidadActual;

    Director directorTecnico;
    std::string nombrePais;

    Estadistica estadisticas;

public:

    Seleccion(std::string pais, Director dir)
        : nombrePais(pais),
          directorTecnico(dir),
          cantidadActual(0),
          estadisticas()
    {
        for (int i = 0; i < jugMax; i++) {
            listaPersonas[i] = nullptr;
        }
    }

    Seleccion(const Seleccion& other)
        : nombrePais(other.nombrePais),
          directorTecnico(other.directorTecnico),
          cantidadActual(other.cantidadActual),
          estadisticas(other.estadisticas)
    {
        for (int i = 0; i < jugMax; i++) {
            listaPersonas[i] = nullptr;
        }

        for (int i = 0; i < cantidadActual; i++) {
            listaPersonas[i] = new Jugador(*other.listaPersonas[i]);
        }
    }

    Seleccion& operator=(const Seleccion& other) {

        if (this == &other) return *this;

        for (int i = 0; i < cantidadActual; i++) {
            delete listaPersonas[i];
            listaPersonas[i] = nullptr;
        }

        nombrePais = other.nombrePais;
        directorTecnico = other.directorTecnico;
        estadisticas = other.estadisticas;
        cantidadActual = other.cantidadActual;

        for (int i = 0; i < jugMax; i++) {
            listaPersonas[i] = nullptr;
        }

        for (int i = 0; i < cantidadActual; i++) {
            listaPersonas[i] = new Jugador(*other.listaPersonas[i]);
        }

        return *this;
    }

    std::string getNombrePais() const {
        return nombrePais;
    }

    int getCantidadPersonas() const {
        return cantidadActual;
    }

    void agregarJugador(const std::string& nombre) {

        if (nombre.empty()) {
            throw std::invalid_argument("Error! Nombre invalido!");
        }

        if (cantidadActual >= jugMax) {
            throw std::out_of_range("Error! Limite alcanzado!");
        }

        listaPersonas[cantidadActual] = new Jugador(nombre);

        assert(listaPersonas[cantidadActual] != nullptr);

        cantidadActual++;
    }

    Jugador* getPersona(int i) {
        if (i < 0 || i >= cantidadActual) {
            throw std::out_of_range("Jugador invalido");
        }
        return listaPersonas[i];
    }

    bool perteneceElJugador(Jugador* jugIn) {

        if (jugIn == nullptr) return false;

        for (int i = 0; i < cantidadActual; i++) {
            assert(listaPersonas[i] != nullptr);

            if (listaPersonas[i] == jugIn) {
                return true;
            }
        }

        return false;
    }

    void actualizarEstadistica(const Estadistica& est){
        estadisticas.acumular(est);
    }

    int getPartidosJugados() const {
        return estadisticas.getPartidosJugados();
    }

    int getPartidosGanados() const {
        return estadisticas.getPartidosGanados();
    }

    int getPartidosEmpatados() const {
        return estadisticas.getPartidosEmpate();
    }

    int getPartidosPerdidos() const {
        return estadisticas.getPartidosPerdidos();
    }

    int getGolesFavor() const {
        return estadisticas.getGolesFavor();
    }

    int getGolesContra() const {
        return estadisticas.getGolesContra();
    }

    int getDiferenciaGoles() const {
        return estadisticas.getDiferenciaGoles();
    }

    int getPuntos() const {
        return estadisticas.getPuntos();
    }

    ~Seleccion() {
        for (int i = 0; i < cantidadActual; i++) {
            delete listaPersonas[i];
            listaPersonas[i] = nullptr;
        }
    }
};

#endif
