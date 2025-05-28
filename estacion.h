#ifndef ESTACION_H
#define ESTACION_H

#include <string>
#include "Cola.h"
#include "patinete.h"

class Estacion//Pero si falta romperPatinete y quitarPatinete xd //También, qué pasa con los patinetes no averiados ni disponibles? solo pueden no estar disponibles si no están estacionados?
{
private:
    std::string identificador;
    std::string direccion;
    int numDisponibles;
    int numAveriadas;
    Cola<Patinete*>* averiados;
    Cola<Patinete*>* disponibles;
    
    //PRE: Una cola
    //DESC: Muestra los valores en la cola
    //Complejidad: O(n)
    void mostrarCola(Cola<Patinete*>*);
    
public:
    //constructores
    
    //PRE: No hay
    //DESC: Inicia todos los valores de la estación a 0 si son números o "" si son string e inicia las colas de patinetes averiados y disponibles
    //Complejidad: O(0)
    Estacion();
    
    //PRE: Parámetros de entrada tipo string para el identificador y la direccion de la estacion
    //DESC: Inicia los float de la estación a 0, crea las colas de patinetes averiados y disponibles y con los parámetros de entrada inicializa los string
    //Complejidad: O(0)
    Estacion(std::string identificador, std::string direccion);//parametrizado
    
    //PRE: Parámetro de entrada de otra estación
    //DESC: Copia los valores de la otra estación a esta
    //Complejidad: O(n)
    Estacion(Estacion const& original);//por copia
    //otros
    
    //PRE: Parámetro de entrada de patinete 
    //DESC: Agrega un patinete a una de las dos colas, según si está averiado o disponible
    //Complejidad: O(0)
    void agregarPatinete(Patinete* patinete);
    
    //PRE: No hay
    //DESC: Muestra los patinetes averiados en la estación
    //Complejidad: O(n)
    void mostrarAveriados();
    
    //PRE: No hay
    //DESC: Muestra los patinetes disponibles en la estación
    //Complejidad: O(n)
    void mostrarDisponibles();
    
    //PRE: No hay
    //DESC: Muestra todos los datos de la estación incluyendo las dos colas de patinetes averiados y disponibles
    //Complejidad: O(n)
    void mostrar();
    
    //PRE: Que haya patinetes en la cola de patinetes averiados
    //DESC: Arregla el primer patinete en las cola de averiados
    //Complejidad: O(0)
    void arreglarPatinete();
    
    //PRE: Hay al menos un patinete disponible
    //DESC: Quita un patinete de la cola de disponibles y devuelve un puntero a este
    //Complejidad: O(0)
    Patinete* alquilarPatinete();
    
    //Getters/Setters
    
    //PRE: No hay
    //DESC: Devuelve el identificador de la estación
    //Complejidad: O(0)
    std::string getIdentificador() const;
    
    //PRE: Parámetro de entrada y salida de tipo string que sea un identificador
    //DESC: Cambia el identificador de la estación por la del parámetro
    //Complejidad: O(0)
    void setIdentificador(const std::string &newIdentificador);
    
    //PRE: No hay
    //DESC: Devuelve la dirección de la estación
    //Complejidad:
    std::string getDireccion() const;
    
    //PRE: Parámetro de entrada y salida de tipo string que sea una dirección
    //DESC: Cambia la dirección de la estación por la del parámetro
    //Complejidad:
    void setDireccion(const std::string &newDireccion);
    
    //PRE: No hay
    //DESC: Devuelve el número de patinetes disponibles en la estación
    //Complejidad: O(0)
    int getNumDisponibles() const;
    
    //PRE: No hay
    //DESC: Devuelve el número de patinetes averiados en la estación
    //Complejidad: O(0)
    int getNumAveriadas() const;
    
    //PRE: 
    //DESC:
    //Complejidad:
    ~Estacion();
};

#endif // ESTACION_H
