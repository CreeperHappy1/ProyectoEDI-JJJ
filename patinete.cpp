#include "patinete.h"
#include <iostream>

Patinete::Patinete()
{
    identificador = "";
    marca = "";
    modelo = "";
    averiado = false;
    disponible = false;//así no se cuelan patinetes inválidos
    usuarioActual = nullptr;
}

Patinete::Patinete(const std::string identificador, const std::string marca, const std::string modelo, const bool averiado, const bool disponible) :
    identificador(identificador), marca(marca), modelo(modelo), averiado(averiado), disponible(disponible), usuarioActual(nullptr) { }

Patinete::Patinete(const Patinete &original)
{
    identificador = original.identificador;
    marca = original.marca;
    modelo = original.modelo;
    averiado = original.averiado;
    disponible = original.disponible;
    usuarioActual = original.usuarioActual;
}

std::string Patinete::getIdentificador() const
{
    return identificador;
}

void Patinete::setIdentificador(const std::string &newIdentificador)
{
    identificador = newIdentificador;
}

std::string Patinete::getMarca() const
{
    return marca;
}

void Patinete::setMarca(const std::string &newMarca)
{
    marca = newMarca;
}

std::string Patinete::getModelo() const
{
    return modelo;
}

void Patinete::setModelo(const std::string &newModelo)
{
    modelo = newModelo;
}

bool Patinete::getAveriado() const
{
    return averiado;
}

void Patinete::setAveriado(bool newAveriado)
{
    averiado = newAveriado;
}

bool Patinete::getDisponible() const
{
    return disponible;
}

void Patinete::setDisponible(bool newDisponible)
{
    disponible = newDisponible;
    if(disponible)
        usuarioActual = nullptr;
}

Usuario *Patinete::getUsuarioActual() const
{
    Usuario *aux = nullptr;
    
    if(usuarioActual != nullptr){
        aux = usuarioActual;
    }
    return aux;
}

void Patinete::setUsuarioActual(Usuario *newUsuarioActual)
{
    usuarioActual = newUsuarioActual;
    if(usuarioActual == nullptr)
        disponible = true;
    else
        disponible = false;
}

void Patinete::mostrar()
{
    std::cout << "Patinete (identificador: " << identificador << "):\nmarca: " << marca << "\nmodelo: " << modelo << "\naveriado: " << averiado << "\ndisponible: " << disponible << std::endl;
    if (usuarioActual != nullptr)
        std::cout << "usuarioActual(nombre): " << usuarioActual->getNombre() << std::endl;
}

bool Patinete::operator==(const Patinete& other){
    return (identificador == other.identificador);
}

Patinete::~Patinete()
{
    
}
