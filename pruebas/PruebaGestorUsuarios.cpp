#include "PruebaGestorUsuarios.h"
#include "../gestorusuarios.h"
//TODO: [issue#2] pruebas gestorUsuarios
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
    
    g1->insertar("AzpeitiaDelPozoJorgeJuan", "473", 26, "25", 200, "5349389B", "AzpeitiaDelPozoJorgeJuan@alumnos.unex.es");
    
    g1->mostrar();
    
    delete g1;
}

void pruebaBuscar()
{
    GestorUsuarios *g1 = new GestorUsuarios();
    
    g1->insertar("SanchezGilJorge", "809", 37, "52", -3, "909087A", "SanchezGilJorge@alumnos.unex.es");
    
    g1->insertar("AzpeitiaDelPozoJorgeJuan", "473", 26, "25", 200, "5349389B", "AzpeitiaDelPozoJorgeJuan@alumnos.unex.es");
    
    Usuario *u1 = new Usuario(*g1->buscar("909087A"));
    
    Usuario *u2 = new Usuario(*g1->buscar("5349389B"));
    
    u1->mostrar();
    u2->mostrar();
    
    delete g1;
    delete u1;
    delete u2;
}

void pruebaNumElementos()
{
    GestorUsuarios *g1 = new GestorUsuarios();
    
    cout << "No hay usuarios, el número de usuarios es: " << g1->numElementos() << endl;
    
    g1->insertar("SanchezGilJorge", "809", 37, "52", -3, "909087A", "SanchezGilJorge@alumnos.unex.es");
    
    cout << "Hay un usuario, el número de usuarios es: " << g1->numElementos() << endl;
    
    g1->insertar("AzpeitiaDelPozoJorgeJuan", "473", 26, "25", 200, "5349389B", "AzpeitiaDelPozoJorgeJuan@alumnos.unex.es");
    
    cout << "Hay dos usuarios, el número de usuarios es: " << g1->numElementos() << endl;
    
    delete g1;
}

void pruebaEliminarUsuario(){
    
    GestorUsuarios *g1 = new GestorUsuarios();
    
    g1->insertar("SanchezGilJorge", "809", 37, "52", -3, "909087A", "SanchezGilJorge@alumnos.unex.es");
    
    g1->insertar("AzpeitiaDelPozoJorgeJuan", "473", 26, "25", 200, "5349389B", "AzpeitiaDelPozoJorgeJuan@alumnos.unex.es");
    
    g1->mostrar();
    
    g1->eliminarUsuario("909087A");
    g1->eliminarUsuario("5349389B");
    
    delete g1;
}

void pruebas()
{
    
}
