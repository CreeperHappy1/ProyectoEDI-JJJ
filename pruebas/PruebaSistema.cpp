#include "PruebaSistema.h"
#include "../sistema.h"

// Sistema();
// Sistema(std::string nombreSistema);
// Sistema(Sistema const& other);//por copia
/*construiremos uno con el constructor por defecto y comprobaremos que todos sus valores sean los por defecto
 * construiremos uno parametrizado y comprobaremos sus valores
 * insertaremos elementos al segundo y usaremos el constructor por copia para copiarlo (debería ser igual pero con sus propios elementos)
*/
void pruebaConstructores(){
    
}

// void mostrarUsuarios();//muestra el número de usuarios total del sistema y la información de todos ellos.
///mostrarUsuarios() no le haremos prueba ya que lo vamos a usar con el resto de pruebas (si funciona mal todo estará mal xd)

void pruebaBuscarUsuario();
// std::string buscarUsuario(std::string const DNI);//recibe como parámetro de entrada el DNI de un usuario y, si lo encuentra, devuelve toda la información del usuario (p.ej., para luego poder mostrarlo).
/* generaremos una lista de usuarios con todos los datos a 1, a 2, a 3, a 4, y a 5
 * Caso 1: buscaremos el usuario de DNI 1, y nos debería devolver la cadena generada por un usuario con todo 1s
 * Caso 2: buscaremos el usuario de DNI 3, y nos debería devolver la cadena generada por un usuario con todo 3s
 * Caso 3: buscaremos el usuario de DNI 5, y nos debería devolver la cadena generada por un usuario con todo 5s
 * Caso 4: buscaresmos un DNI no existente entre los usuarios (debería devolver una string vacía)
*/

void pruebaInsertarPatinete();
// void insertarPatinete(const std::string identificador, const std::string marca, const std::string modelo, const bool averiado, const bool disponible);//Añade un nuevo patinete a la lista lPatinetes. Este método recibe como parámetros de entrada los datos de un patinete y los utilizará para crear una instancia dinámica (puntero a un objeto) de la clase Patinete. Una vez creado el puntero al patinete, lo insertará en la lista lPatinetes. El orden de inserción queda a criterio de los desarrolladores.
// Probaremos a instertar tres patinetes y mostrarlos

// void mostrarPatinetes();//muestra el número de patinetes total del sistema y la información de todos ellos.
///mostrarPatinetes() no le haremos prueba ya que la vamos a usar para las otras pruebas (sólo es para debug)

void pruebaInsertarEstacion();
// void insertarEstacion(std::string identificador, std::string direccion);
// Probaremos a insertar tres estaciones y mostrarlas

// void mostrarEstaciones();
///otro mostrar que no requiere módulo de pruebas

// ~Sistema();
///el destructor evidentemente no le haremos un módulo de pruebas

void pruebasSistema(){
    pruebaConstructores();
    pruebaBuscarUsuario();
    pruebaInsertarPatinete();
    pruebaInsertarEstacion();
}

