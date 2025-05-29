#ifndef PRUEBAGESTORUSUARIOS_H
#define PRUEBAGESTORUSUARIOS_H

//Primero utilizamos el constructor por defecto y comprobamos que está vacío y que se pueda insertar un usuario dummy
//Luego usamos el constructor de copia, comprobamos que sean iguales y modificamos el usuario insertado para comprobar que sea una copia
void pruebasConstructores();

//Insertamos cuatro usuarios con distintos DNIs y comprobamos con mostrar que estén en orden
void pruebaInsertar();

void pruebaEliminarUsuario();

//Probamos a buscar con la lista vacía
//Insertamos cuatro usuarios y buscamos uno de ellos, comprobamos que sea el mismo usuario
void pruebaBuscar();

//Insertamos elementos y comprobamos que el número encaje
void pruebaNumElementos();

//Llama las otras pruebas de la clase GestorUsuarios
void pruebasGestorUsuarios();

#endif // PRUEBAGESTORUSUARIOS_H
