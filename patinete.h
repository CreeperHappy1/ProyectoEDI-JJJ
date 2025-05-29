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
    
    //PRE: 
    //DESC: 
    //Complejidad: 
    Patinete();
    
    
    Patinete(const std::string identificador, const std::string marca, const std::string modelo, const bool averiado, const bool disponible);
    
    
    Patinete(const Patinete& original);
    //getters/setters
    
    
    std::string getIdentificador() const;
    
    
    void setIdentificador(const std::string &newIdentificador);
    
    
    std::string getMarca() const;
    
    
    void setMarca(const std::string &newMarca);
    
    
    std::string getModelo() const;
    
    
    void setModelo(const std::string &newModelo);
    
    
    bool getAveriado() const;
    
    
    void setAveriado(bool newAveriado);
    
    
    bool getDisponible() const;
    
    
    void setDisponible(bool newDisponible);
    
    
    Usuario *getUsuarioActual() const;
    
    
    void setUsuarioActual(Usuario *newUsuarioActual);
    //otros
    
    
    void mostrar();//bools are display according to std::boolalpha
    
    
    bool operator==(const Patinete& other);
    //Destructores
    
    
    ~Patinete();
    
};

#endif // PATINETE_H
