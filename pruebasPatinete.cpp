#include "pruebas.h"
#include "../patinete.h"
#include <iostream>

using namespace std;

void pruebaPatinete(){
    cout << "Iniciando pruebas de la clase Patinete...\n";
    // //Constructores
    // Patinete();
    Patinete *p1 = new Patinete();
    if(p1->getIdentificador() != "")
        cerr << "ERROR: getIdentificador no devuelve \"\" con constructor por defecto\n";
    if(p1->getMarca() != "")
        cerr << "ERROR: getMarca no devuelve \"\" con constructor por defecto\n";
    if(p1->getModelo() != "")
        cerr << "ERROR: getModelo no devuelve \"\" con constructor por defecto\n";
    if(p1->getAveriado() != false)//yes, comparing a bool is kinda dumb, but it's more legible
        cerr << "ERROR: getAveriado no devuelve false con constructor por defecto\n";
    if(p1->getDisponible() != false)
        cerr << "ERROR: getDisponible no devuelve false con constructor por defecto\n";
    if(p1->getUsuarioActual() != nullptr)
        cerr << "ERROR: getUsuarioActual no devuelve nullptr con constructor por defecto\n";
    // Patinete(const std::string identificador, const std::string marca, const std::string modelo, const bool averiado, const bool disponible);
    Patinete *p2 = new Patinete("idej", "marcaej", "modeloej", true, true);
    if(p2->getIdentificador() != "idej")
        cerr << "ERROR: getIdentificador no devuelve \"idej\" con constructor parametrizado\n";
    if(p2->getMarca() != "marcaej")
        cerr << "ERROR: getMarca no devuelve \"marcaej\" con constructor parametrizado\n";
    if(p2->getModelo() != "modeloej")
        cerr << "ERROR: getModelo no devuelve \"modeloej\" con constructor parametrizado\n";
    if(p2->getAveriado() != true)
        cerr << "ERROR: getAveriado no devuelve true con constructor parametrizado\n";
    if(p2->getDisponible() != true)
        cerr << "ERROR: getDisponible no devuelve true con constructor parametrizado\n";
    if(p2->getUsuarioActual() != nullptr)
        cerr << "ERROR: getUsuarioActual no devuelve nullptr con constructor parametrizado\n";
    // Patinete(const Patinete& original);
    Patinete *p3 = new Patinete(*p2);
    if(p3->getIdentificador() != "idej")
        cerr << "ERROR: getIdentificador no devuelve \"idej\" con constructor por copia\n";
    if(p3->getMarca() != "marcaej")
        cerr << "ERROR: getMarca no devuelve \"marcaej\" con constructor por copia\n";
    if(p3->getModelo() != "modeloej")
        cerr << "ERROR: getModelo no devuelve \"modeloej\" con constructor por copia\n";
    if(p3->getAveriado() != true)
        cerr << "ERROR: getAveriado no devuelve true con constructor por copia\n";
    if(p3->getDisponible() != true)
        cerr << "ERROR: getDisponible no devuelve true con constructor por copia\n";
    if(p3->getUsuarioActual() != nullptr)
        cerr << "ERROR: getUsuarioActual no devuelve nullptr con constructor por copia\n";
    // //getters/setters
    p1->setIdentificador("idprb");
    if(p1->getIdentificador() != "idprb")
        cerr << "ERROR: getIdentificador no devuelve el valor introducido con setIdentificador\n";
    p1->setMarca("marcaprb");
    if(p1->getMarca() != "marcaprb")
        cerr << "ERROR: getMarca no devuelve el valor introducido con setMarca\n";
    p1->setModelo("modeloprb");
    if(p1->getModelo() != "modeloprb")
        cerr << "ERROR: getModelo no devuelve el valor introducido con setModelo\n";
    p1->setAveriado(true);
    if(p1->getAveriado() != true)
        cerr << "ERROR: getAveriado no devuelve el valor introducido con setAveriado\n";
    p1->setDisponible(true);
    if(p1->getDisponible() != true)
        cerr << "ERROR: getDisponible no devuelve el valor introducido con setDisponible\n";
    Usuario* U = new Usuario();
    p1->setUsuarioActual(U);
    if(p1->getUsuarioActual() != U)
        cerr << "ERROR: getUsuarioActual no devuelve el puntero introducido con setUsuarioActual\n";
    if(p1->getDisponible() != false)
        cerr << "ERROR: getDisponible no devuelve false tras introducir usuario\n";
    // //otros
    // void mostrar();
    p1->getUsuarioActual()->setNombre("pruebanomber");
    cout << "Ahora se debería mostrar un patinete con id \"idprb\", marca \"marcaprb\", modelo \"modeloprb\", averiado true, disponible false, y usuario \"pruebanomber\"\n";
    p1->mostrar();
    
    p1->setDisponible(true);
    if(p1->getUsuarioActual() != nullptr)
        cerr << "ERROR: getUsuarioActual no devuelve nullptr tras ejecutar setDisponible(true)\n";
    // bool operator==(const Patinete& other);
    p2->setIdentificador("tumadr");
    if(*p2 == *p3)
        cerr << "ERROR: operator== devuelve true aunque los identificadores sean distintos\n";
    p3->setIdentificador("tumadr");
    if(!(*p2 == *p3))
        cerr << "ERROR: operator== devuelve false aunque los identificadores sean iguales\n";
    cout << "Pruebas de la clase Patinete finalizadas\n";
}
