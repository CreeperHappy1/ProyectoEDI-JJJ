#ifndef ESTACION_H
#define ESTACION_H

#include "Cola.h"
#include "patinete.h"
#include <string>

class Estacion //Pero si falta romperPatinete y quitarPatinete xd //También, qué pasa con los patinetes no averiados ni disponibles? solo pueden no estar disponibles si no están estacionados?
{
private:
    std::string identificador;
    std::string direccion;
    int numDisponibles;
    Cola<Patinete *> *averiados;
    Cola<Patinete *> *disponibles;
    void mostrarCola(Cola<Patinete *> *);

public:
    //constructores
    Estacion();
    Estacion(std::string identificador, std::string direccion); //parametrizado
    Estacion(Estacion const &original);                         //por copia
    //otros
    void agregarPatinete(Patinete *patinete);
    void mostrarAveriados();
    void mostrarDisponibles();
    void mostrar();
    void arreglarPatinete();
    //Getters/Setters
    std::string getIdentificador() const;
    void setIdentificador(const std::string &newIdentificador);
    std::string getDireccion() const;
    void setDireccion(const std::string &newDireccion);
    int getNumDisponibles() const;

    ~Estacion();
};

#endif // ESTACION_H
