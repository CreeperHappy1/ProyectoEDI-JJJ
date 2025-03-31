#include "../estacion.h"
#include "pruebasEstacion.h"
#include <iostream>

//Mariscal ha dicho que no hace falta que hagamos pruebas de mostrar pero realmente como modifican el valor y luego lo intentan restaurar sería mejor probarlos pero bueno xd

void pruebaConstructores()
{
    cout << "\tInicio de prueba de constructores...\n";
    //Por defecto:
    Estacion* E1 = new Estacion();
    if(E1->getIdentificador() != "")
        cerr << "ERROR: Constructor por defecto -> identificador no es \"\"\n";
    if(E1->getDireccion() != "")
        cerr << "ERROR: Constructor por defecto -> direccion no es \"\"\n";
    if(E1->getNumDisponibles() != 0)
        cerr << "ERROR: Constructor por defecto -> numDisponibles no es 0\n";
    cout << "Ahora no se debería mostrar ningún patinete averiado ni disponible\n";
    E1->mostrarDisponibles();
    E1->mostrarAveriados();
    
    //Parametrizado
    Estacion* E2 = new Estacion("Idprueba", "direccionprueba");
    if(E2->getIdentificador() != "Idprueba")
        cerr << "ERROR: Constructor parametrizado -> identificador no es \"\"\n";
    if(E2->getDireccion() != "direccionprueba")
        cerr << "ERROR: Constructor parametrizado -> direccion no es \"\"\n";
    if(E2->getNumDisponibles() != 0)
        cerr << "ERROR: Constructor parametrizado -> numDisponibles no es 0\n";
    cout << "Ahora no se debería mostrar ningún patinete averiado ni disponible\n";
    E2->mostrarDisponibles();
    E2->mostrarAveriados();
    
    //Por copia
    Patinete* P = new Patinete("id", "marca", "modelo", false, true);
    Patinete* P2 = new Patinete("id2", "marca2", "modelo2", true, false);
    E2->agregarPatinete(P);
    E2->agregarPatinete(P2);
    Estacion* E3 = new Estacion(*E2);
    if(E3->getIdentificador() != "Idprueba")
        cerr << "ERROR: Constructor por copia -> identificador no es \"\"\n";
    if(E3->getDireccion() != "direccionprueba")
        cerr << "ERROR: Constructor por copia -> direccion no es \"\"\n";
    if(E3->getNumDisponibles() != 1)
        cerr << "ERROR: Constructor por copia -> numDisponibles no es 1\n";
    cout << "Ahora se debería mostrar un patinete averiado y uno disponible\n";
    E3->mostrarDisponibles();
    E3->mostrarAveriados();
    
    delete E3;
    delete P;
    delete P2;
    delete E2;
    delete E1;
    cout << "\tPruebas de constructores finalizadas\n";
}

void pruebaAgregarPatinete()
{
    cout << "\tInicio de prueba de agregarPatinete()...\n";
    Estacion* E = new Estacion();
    Patinete* P1 = new Patinete("id", "marca", "modelo", false, true);
    Patinete* P2 = new Patinete("id2", "marca2", "modelo2", true, false);
    Patinete* P3 = new Patinete("id3", "marca3", "modelo3", false, false);
    E->agregarPatinete(P1);
    if(E->getNumDisponibles() != 1)
        cerr << "ERROR: numDisponibles no es 1 tras añadir un patinete disponible\n";
    E->agregarPatinete(P2);
    if(E->getNumDisponibles() != 1)
        cerr << "ERROR: numDisponibles no es 1 tras añadir un patinete averiado\n";
    E->agregarPatinete(P3);
    if(E->getNumDisponibles() != 2)
        cerr << "ERROR: numDisponibles no es 2 tras añadir un patinete no averiado\n";
    
    cout << "Se debería mostrar el siguiente patinete: ";
    P2->mostrar();
    E->mostrarAveriados();
    
    cout << "Se debería mostrar los siguientes patinetes:\n\t";
    P1->mostrar();
    cout << '\t';
    P3->mostrar();
    E->mostrarDisponibles();
    
    delete P3;
    delete P1;
    delete P2;
    delete E;
    cout << "\tPrueba de agregarPatinete() finalizada\n";
}

void pruebaArreglarPatinete()
{
    cout << "\tInicio de prueba de arreglarPatinete()...\n";
    Estacion* E = new Estacion();
    Patinete* P2 = new Patinete("id2", "marca2", "modelo2", true, false);
    Patinete* P3 = new Patinete("id3", "marca3", "modelo3", true, true);
    E->agregarPatinete(P2);
    E->agregarPatinete(P3);
    
    cout << "Se debería mostrar los siguientes patinetes como averiados:\n\t";
    P2->mostrar();
    cout << '\t';
    P3->mostrar();
    E->mostrarAveriados();
    
    E->arreglarPatinete();
    cout << "Ahora sólo se debería mostrar el patinete de id3:\n";
    E->mostrarAveriados();
    
    cout << "Ahora se debería mostrar el patinete id2 como disponible:\n\t";
    E->mostrarDisponibles();
    
    delete P3;
    delete P2;
    delete E;
    cout << "\tPrueba de arreglarPatinete() finalizada\n";
}

void pruebasGettersSetters()
{
    cout << "\tInicio de pruebas de getters y setters...\n";
    Estacion* E = new Estacion();
    delete E;
    cout << "\tPruebas de getters y setters finalizadas\n";
}

void pruebasEstacion()
{
    pruebasGettersSetters();
    pruebaAgregarPatinete();
    pruebaConstructores();
    pruebaArreglarPatinete();
}
