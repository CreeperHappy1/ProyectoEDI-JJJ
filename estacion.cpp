#include "estacion.h"


Estacion::Estacion() {
    identificador = "";
    direccion = "";
    numDisponibles = 0;
    numAveriadas = 0;
    numAlquilados = 0;
    averiados = new Cola<Patinete*>;
    disponibles = new Cola<Patinete*>;
}

Estacion::Estacion(string identificador, string direccion)
{
    this->identificador = identificador;
    this->direccion = direccion;
    numDisponibles = 0;
    numAveriadas = 0;
    numAlquilados = 0;
    averiados = new Cola<Patinete*>;
    disponibles = new Cola<Patinete*>;
}

Estacion::Estacion(const Estacion &original)
{
    identificador = original.identificador;
    direccion = original.direccion;
    numDisponibles = original.numDisponibles;
    numAveriadas = original.numAveriadas;
    numAlquilados = original.numAlquilados;
    averiados = new Cola<Patinete*>;
    Cola<Patinete*>* aux = new Cola<Patinete*>;
    while(!original.averiados->estaVacia()){
        aux->encolar(original.averiados->getPrimero());
        original.averiados->desencolar();
    }
    while(!aux->estaVacia()){
        averiados->encolar(aux->getPrimero());
        original.averiados->encolar(aux->getPrimero());
        aux->desencolar();
    }
    disponibles = new Cola<Patinete*>;
    while(!original.disponibles->estaVacia()){
        aux->encolar(original.disponibles->getPrimero());
        original.disponibles->desencolar();
    }
    while(!aux->estaVacia()){
        disponibles->encolar(aux->getPrimero());
        original.disponibles->encolar(aux->getPrimero());
        aux->desencolar();
    }
    delete aux;
}

void Estacion::agregarPatinete(Patinete *patinete)
{
    if(patinete != nullptr){
        if(patinete->getAveriado()){
            averiados->encolar(patinete);
            numAveriadas++;
        }    
        else{
            disponibles->encolar(patinete);
            numDisponibles++;
        }
    }
}

void Estacion::mostrarCola(Cola<Patinete*>* cola){
    Cola<Patinete*>* aux = new Cola<Patinete*>;
    while(!cola->estaVacia()){
        aux->encolar(cola->getPrimero());
        cola->desencolar();
    }
    while(!aux->estaVacia()){
        std::cout << '\t';
        aux->getPrimero()->mostrar();
        cola->encolar(aux->getPrimero());
        aux->desencolar();
    }
    delete aux;
}

void Estacion::mostrarAveriados()
{
    std::cout << "Patinetes averiados en esta estación:\n";
    mostrarCola(averiados);
}

void Estacion::mostrarDisponibles()
{
    std::cout << "Patinetes disponibles en esta estación:\n";
    mostrarCola(disponibles);
}

void Estacion::mostrar()
{
    std::cout << "Identificador: " << identificador << std::endl;
    std::cout << "Dirección: " << direccion << std::endl;
    std::cout << "Disponibles: " << numDisponibles << std::endl;
    std::cout << "Patinetes averiados:\n";
    mostrarAveriados();
    std::cout << "Patinetes disponibles:\n";
    mostrarDisponibles();
}

void Estacion::arreglarPatinete()
{
    averiados->getPrimero()->setAveriado(false);
    disponibles->encolar(averiados->getPrimero());
    averiados->desencolar();
    numDisponibles++;
    numAveriadas--;
}

Patinete *Estacion::alquilarPatinete()
{
    Patinete* ret = nullptr;
    if(!this->disponibles->estaVacia()){
        Patinete* ret = disponibles->getPrimero();
        disponibles->desencolar();
        ret->setDisponible(false);
        numAlquilados++;
    }
    return ret;
}

std::string Estacion::getIdentificador() const
{
    return identificador;
}

void Estacion::setIdentificador(const std::string &newIdentificador)
{
    identificador = newIdentificador;
}

std::string Estacion::getDireccion() const
{
    return direccion;
}

void Estacion::setDireccion(const std::string &newDireccion)
{
    direccion = newDireccion;
}

int Estacion::getNumDisponibles() const
{
    return numDisponibles;
}

int Estacion::getNumAveriadas() const
{
    return numAveriadas;
}

int Estacion::getNumAlquilados() const
{
    return numAlquilados;
}

Estacion::~Estacion()
{
    delete averiados;
    delete disponibles;
}
