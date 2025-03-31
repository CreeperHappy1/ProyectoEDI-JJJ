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
    
}

void pruebaBuscar()
{
    
}

void pruebaNumElementos()
{
    
}

void pruebas()
{
    
}
