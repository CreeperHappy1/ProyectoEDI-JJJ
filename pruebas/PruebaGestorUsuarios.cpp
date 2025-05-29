#include "PruebaGestorUsuarios.h"
#include "../gestorusuarios.h"

void pruebasConstructores()
{
    cout << "Iniciando pruebas de los constructores...\n";
    
    GestorUsuarios *g1 = new GestorUsuarios();
    
    g1->insertar("SanchezGilJorge", "809", 37, "52", -3, "909087A", "SanchezGilJorge@alumnos.unex.es");
    
    GestorUsuarios *g2 = new GestorUsuarios(*g1);
    g2->insertar("Nombre2", "404", 17, "90", 122.314, "DNINUMERO2", "nombre@dominio.terminación");
    
    cout << "\tSe debería mostrar un usuario en el gestor con los datos \"SanchezGilJorge - 809 - 37 - C(52, -3) - 909087A - SanchezGilJorge@alumnos.unex.es\"\n";
    g1->mostrar();
    
    cout << "\tSe debería mostrar junto al usuario anterior el usuario \"Nombre2 - 404 - 17 - C(90, 122.314) - DNINUMERO2 - nombre@dominio.terminación\"\n";
    g2->mostrar();
    
    delete g1;
    delete g2;
    
    cout << "Pruebas de constructores finalizadas\n";
}

void pruebaInsertar()
{
    cout << "Iniciando pruebas de insertar()...\n";
    
    GestorUsuarios *g1 = new GestorUsuarios();
    
    g1->insertar("SanchezGilJorge", "809", 37, "52", -3, "909087A", "SanchezGilJorge@alumnos.unex.es");
    
    cout << "\tSe debería mostrar un usuario en el gestor con los datos \"SanchezGilJorge - 809 - 37 - C(52, -3) - 909087A - SanchezGilJorge@alumnos.unex.es\"\n";
    g1->mostrar();
    
    g1->insertar("", "", 0, "", 0, "909087A", "");
    cout << "\tSólo se debería mostrar el mismo usuario anterior (y no otro vacío salvo por el mismo DNI)\n";
    g1->mostrar();
    
    g1->insertar("Nombre2", "404", 17, "90", 122.314, "DNINUMERO2", "nombre@dominio.terminación");
    cout << "\tSe debería mostrar junto al usuario anterior el usuario \"Nombre2 - 404 - 17 - C(90, 122.314) - DNINUMERO2 - nombre@dominio.terminación\"\n";
    g1->mostrar();
    
    delete g1;
    
    cout << "Pruebas de insertar() finalizadas\n";
}

void pruebaBuscar()//TODO: añadir más casos
{
    cout << "Iniciando pruebas de buscar()...\n";
    
    GestorUsuarios *g1 = new GestorUsuarios();
    
    g1->insertar("SanchezGilJorge", "809", 37, "52", -3, "909087A", "SanchezGilJorge@alumnos.unex.es");
    
    g1->buscar("909087A")->mostrar();
    
    delete g1;
    
    cout << "Pruebas de buscar() finalizadas\n";
}

void pruebaNumElementos()
{
    cout << "Iniciando pruebas numElementos()...\n";
    
    GestorUsuarios *g1 = new GestorUsuarios();
    
    g1->insertar("SanchezGilJorge", "809", 37, "52", -3, "909087A", "SanchezGilJorge@alumnos.unex.es");
    
    cout << "Los elementos tienen que ser 1, es: " << g1->numElementos() << endl;
    
    g1->insertar("AzpeitiaDelPozoJorgeJuan", "546", 54, "37", 45, "850379J", "AzpeitiaDelPozoJorgeJuan@alumnos.unex.es");
    
    cout << "Los elementos tienen que ser 2, es: " << g1->numElementos() << endl;
    
    delete g1;
    
    cout << "Pruebas de numElementos() finalizadas\n";
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
