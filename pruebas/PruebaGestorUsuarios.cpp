#include "PruebaGestorUsuarios.h"
#include "../gestorusuarios.h"
//TODO: pruebas gestorUsuarios
void pruebasConstructores()
{
    GestorUsuarios *g1 = new GestorUsuarios();
    
    g1->insertar("SanchezGilJorge", "809", 37, "52", -3, "909087A", "SanchezGilJorge@alumnos.unex.es");
    
    GestorUsuarios *g2 = new GestorUsuarios(*g1);
    
    g1->mostrar();
    g2->mostrar();
    
    delete g1;
    delete g2;
}

void pruebaInsertar()
{
    GestorUsuarios *g1 = new GestorUsuarios();
    
    g1->insertar("SanchezGilJorge", "809", 37, "52", -3, "909087A", "SanchezGilJorge@alumnos.unex.es");
    
    g1->mostrar();
    
    delete g1;
}

void pruebaBuscar()
{
    GestorUsuarios *g1 = new GestorUsuarios();
    
    g1->insertar("SanchezGilJorge", "809", 37, "52", -3, "909087A", "SanchezGilJorge@alumnos.unex.es");
    
    g1->buscar("909087A");
    
    delete g1;
}

void pruebaNumElementos()
{
    GestorUsuarios *g1 = new GestorUsuarios();
    
    g1->insertar("SanchezGilJorge", "809", 37, "52", -3, "909087A", "SanchezGilJorge@alumnos.unex.es");
    
    cout << "Los elementos tienen que ser 1, es: " << g1->numElementos() << endl;
    
    g1->insertar("AzpeitiaDelPozoJorgeJuan", "546", 54, "37", 45, "850379J", "AzpeitiaDelPozoJorgeJuan@alumnos.unex.es");
    
    cout << "Los elementos tienen que ser 2, es: " << g1->numElementos() << endl;
    
    delete g1;
}

void pruebasGestorUsuarios()
{
    cout << "Inicio de pruebas de GestorUsuarios" << endl;
    
    pruebasConstructores();
    pruebaInsertar();
    pruebaBuscar();
    pruebaNumElementos();
    
    cout << "Fin pruebas de GestorUsuarios" << endl;
}
