#ifndef PRUEBAGESTORUSUARIOS_H
#define PRUEBAGESTORUSUARIOS_H

//Se ha minimizado los módulos requeridos por cada módulo de prueba, la mayoría sólo requieren el correcto funcionamiento del constructor por defecto y del insertar
//Para los métodos de mostrar no se hacen pruebas ya que son usados únicamente para estas pruebas (si falla todas las pruebas supervisadas se verán erróneas)

///Define la flag de precompilación ARBOLYPUBLICADOS para activar las pruebas de los métodos privados de GestorUsuarios (Si usas CMake sólo es descomentar una línea)
#ifdef ARBOLYPUBLICADOS
#ifndef LISTA
///Módulos privados

//Creamos un árbol original con cuatro usuarios a los que guardamos punteros y usamos copiarArbol() para copiarlo a un gestor vacío
//Luego usamos mostrar para comprobar que haya 4 usuarios y usamos buscar para comprobar que los datos coincidan y que sean copias
//Omitimos el caso de copiar sobre un gestor no vacío ya que este caso nunca se dará y no es para lo que está hecho el método privado
//Depende de que buscar() funcione correctamente para comprobar los datos y punteros de los usuarios
void pruebaCopiarArbol();
void pruebaMostrarRec();
void pruebaBuscarR();
void pruebaDestructorR();

#endif //LISTA
#endif //ARBOLYPUBLICADOS

//Probamos el constructor por defecto usandolo e insertando un usuario, luego usamos el constructor por copia para hacer una copia en la que insertamos otro usuario
//Mostramos ambos gestores, el primero debería tener un usuario y el segundo es más otro usuario; 
//si esto se verifica los constructores seguramente inicializarán correctamente los gestores
void pruebasConstructores();

//Vamos insertando usuarios y con el método mostrar comprobamos si se han insertado correctamente
//Caso 1: insertar un usuario en el gestor vacío
//Caso 2: insertar un usuario vacío salvo por el dni, que es el mismo que el anterior -> no debería crearse otro usuario
//Caso 3: insertar otro usuario -> deberían mostrarse sólo dos usuarios correctamente
void pruebaInsertar();

//Insertamos y eliminamos usuarios para crear los casos, comprobando con el método mostrar()
//Caso 1: se inserta un usuario y se elimina -> debería acabar vacío
//Caso 2: se insertan tres usuarios y se elimina uno de ellos -> deberían mostrarse los otros dos
void pruebaEliminarUsuario();

//Como el método buscar devuelve un puntero al usuario que encuentra podemos hacer estas pruebas automatizadas usando los getters de Usuario para comprobar los datos
//Caso 1: buscar cualquier usuario en el gestor vacío -> no se debería de encontrar, devolviendo nullptr
//Caso 2: se busca un usuario siendo este el único
//Caso 3: se busca un usuario de en medio habiendo 4
//Caso 4: se busca el último usuario
//Caso 5: se busca un usuario que no está en el gestor -> debería devolver nullptr
void pruebaBuscar();

//Usamos insertar() y eliminarUsuario() y comprobamos si estos aumentan y reducen propiamente el contador de elementos en la estructura de datos
//Primero comprobamos que tras el constructor por defecto sea 0
//Luego insertamos 1 y comprobamos, siguiente otro y comprobamos otra vez, y finalmente eliminamos uno y comprobamos que se reduzca de vuelta a 1
void pruebaNumElementos();

//Llama las otras pruebas de la clase GestorUsuarios
void pruebasGestorUsuarios();

#endif // PRUEBAGESTORUSUARIOS_H
