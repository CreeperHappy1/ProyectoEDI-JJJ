#ifndef PATINETE_H
#define PATINETE_H

#include <string>
#include "Usuario.h"

class Patinete
{
private:
    std::string identificador;
    std::string marca;
    std::string modelo;
    bool averiado;
    bool disponible;
    Usuario* usuarioActual;//de agregación
public:
    //Constructores
    
    //PRE: No hay
    //DESC: Inicia los string identificador, marca y modelo a "", los bool averiado y disponible a false y el puntero usuario actual a nullptr
    //Complejidad: O(1)
    Patinete();
    
    //PRE: Los string identificador, marca y modelo, los bool averiado y disponible y el puntero usuario actual como parámetros de entrada
    //DESC: Inicia los string identificador, marca y modelo y los bool averiado y disponible según sus respectivos parámetros de entrada, y el puntero usuario actual a nullptr
    //Complejidad: O(1)
    Patinete(const std::string identificador, const std::string marca, const std::string modelo, const bool averiado, const bool disponible);
    
    //PRE: Un patinete como parámetro de entrada por referencia constante
    //DESC: Copia los parámetros del patinete que hay como parámetro de entrada en este
    //Complejidad: O(1)
    Patinete(const Patinete& original);
    //getters/setters
    
    //PRE: No hay
    //DESC: Devuelve el string del identificador del patinete
    //Complejidad: O(1)
    std::string getIdentificador() const;
    
    //PRE: String como parámetro de entrada por referencia constante
    //DESC: Devuelve el identificador del patinete mediante el string que hay como parámetro de entrada y salida
    //Complejidad: O(1)
    void setIdentificador(const std::string &newIdentificador);
    
    //PRE: No hay
    //DESC: Devuelve el string de la marca del patinete
    //Complejidad: O(1)
    std::string getMarca() const;
    
    //PRE: Parámetro de entrada por referencia constante string
    //DESC: Modifica el parámetro marca del patinete según el parámetro de entrada y salida
    //Complejidad: O(1)
    void setMarca(const std::string &newMarca);
    
    //PRE: No hay
    //DESC: Devuelve el modelo del patinete
    //Complejidad: O(1)
    std::string getModelo() const;
    
    //PRE: Parámetro de entrada por referencia constante tipo string
    //DESC: Modifica el modelo del patinete según el parámetro de entrada y salida
    //Complejidad: O(1)
    void setModelo(const std::string &newModelo);
    
    //PRE: NO hay
    //DESC: Devuelve si el patinete está averiado
    //Complejidad: O(1)
    bool getAveriado() const;
    
    //PRE: Parámetro de entrada bool
    //DESC: Modifica el bool de si está averiado del patinete según el parámetro de entrada
    //Complejidad: O(1)
    void setAveriado(bool newAveriado);
    
    //PRE: No hay
    //DESC: Devuelve el bool de si está disponible el patinete
    //Complejidad: O(1)
    bool getDisponible() const;
    
    //PRE: Parámetro de entrada tipo bool 
    //DESC: Modifica si el patinete está disponible o no según el parámetro de entrada
    //Complejidad: O(1)
    void setDisponible(bool newDisponible);
    
    //PRE: No hay
    //DESC: Devuelve el usuario del patinete
    //Complejidad: O(1)
    Usuario *getUsuarioActual() const;
    
    //PRE: Parámetro de entrada de tipo puntero de un usuario
    //DESC: Modifica el usuario actual del patinete según el parámetro de entrada
    //Complejidad: O(1)
    void setUsuarioActual(Usuario *newUsuarioActual);
    
    //otros
    
    //PRE: No hay
    //DESC: Devuelve los parámetros del patinete
    //Complejidad: O(1)
    void mostrar();//bools are display according to std::boolalpha
    
    //PRE: Parámetro de entrada por referencia constante de tipo patinete
    //DESC: Devuelve si el identificador del patinete es igual al del patinete como parámetro de entrada y salida
    //Complejidad: O(1)
    bool operator==(const Patinete& other);
    //Destructores
    
    //PRE: No hay
    //DESC: Elimina los parámetros del patinete
    //Complejidad: O(1)
    ~Patinete();
    
};

#endif // PATINETE_H
