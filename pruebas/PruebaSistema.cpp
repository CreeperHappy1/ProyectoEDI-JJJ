#include "PruebaSistema.h"
#include "../sistema.h"

using namespace std;

// Sistema();
// Sistema(std::string nombreSistema);
// Sistema(Sistema const& other);//por copia
/*construiremos uno con el constructor por defecto y comprobaremos que todos sus valores sean los por defecto
 * construiremos uno parametrizado y comprobaremos sus valores
 * insertaremos elementos al segundo y usaremos el constructor por copia para copiarlo (debería ser igual pero con sus propios elementos)
*/
void pruebaConstructoresSistema(){
    cout << "Iniciando pruebas de los constructores de Sistema...\n";
    //construiremos uno con el constructor por defecto y comprobaremos que todos sus valores sean los por defecto
    Sistema *S1 = new Sistema();//por defecto
    cout << "Ahora se debería mostrar todas las partes del sistema con los elementos incluídos en los .csv:\n";
    S1->mostrarEstaciones();
    S1->mostrarPatinetes();
    S1->mostrarUsuarios();
    
    //construiremos uno parametrizado y comprobaremos sus valores
    Sistema *S2 = new Sistema("nombre");
    //NOTE: no hay manera de comprobar que el nombre se haya escrito correctamente (el atributo es privado y no hay getter)
    cout << "Ahora se debería mostrar todas las partes del sistema con los elementos incluídos en los .csv(otra vez):\n";
    S2->mostrarEstaciones();
    S2->mostrarPatinetes();
    S2->mostrarUsuarios();
    
    S2->insertarEstacion("id1", "dir1");
    S2->insertarPatinete("id1", "marca1", "mod1", false, false);
    Sistema *S3 = new Sistema(*S2);
    cout << "Se debería mostrar igual pero añadidos una estación de \"id1\" y \"dir1\", y un patinete  \"id1\", \"marca1\", \"mod1\", averiado, no disponible\n";
    S3->mostrarEstaciones();
    S3->mostrarPatinetes();
    S3->mostrarUsuarios();
    
    delete S3;
    delete S2;
    delete S1;
    cout << "pruebas de los constructores de Sistema finalizadas\n";
}

// void mostrarUsuarios();//muestra el número de usuarios total del sistema y la información de todos ellos.
///mostrarUsuarios() no le haremos prueba ya que lo vamos a usar con el resto de pruebas (si funciona mal todo estará mal xd)

// std::string buscarUsuario(std::string const DNI);//recibe como parámetro de entrada el DNI de un usuario y, si lo encuentra, devuelve toda la información del usuario (p.ej., para luego poder mostrarlo).
/* generaremos un sistema con .csv proveído en el campus
 * Caso 1: buscaremos el usuario de DNI 71555558Q (el primero), y el usuario que devuelva tendrá los datos HINOJAL SANCHEZ, ISMAEL;71555558Q;ihinojays@unex.es;351166056;24;ES1172508452101879000096;32
 * Caso 2: buscaremos el usuario de DNI 76060709P, y el usuario que devuelva tendrá los datos ROBLES TRIPIANA, MARIO;76060709P;meriorovyestritiene@unex.es;656656800;23;ES1992590452102699001058;92
 * Caso 3: buscaremos el usuario de DNI 09519900M (el último), y el usuario que devuelva tendrá los datos PEREZ SUAREZ, LUIS;09519900M;yterezsuerez82@unex.es;688885606;21;ES1872578452102579001046;124
 * Caso 4: buscaresmos un DNI no existente entre los usuarios (notadni) (debería devolver una string vacía)
*/
void pruebaBuscarUsuario(){
    cout << "Inicio prueba de buscarUsuario() de la clase Sistema...\n";
    Sistema *S = new Sistema();
    cout << "Se debería mostrar un usuario con los datos HINOJAL SANCHEZ, ISMAEL;71555558Q;ihinojays@unex.es;351166056;24;ES1172508452101879000096;32\n";
    cout << S->buscarUsuario("71555558Q");
    cout << "Se debería mostrar un usuario con los datos ROBLES TRIPIANA, MARIO;76060709P;meriorovyestritiene@unex.es;656656800;23;ES1992590452102699001058;92\n";
    cout << S->buscarUsuario("76060709P");
    cout << "Se debería mostrar un usuario con los datos PEREZ SUAREZ, LUIS;09519900M;yterezsuerez82@unex.es;688885606;21;ES1872578452102579001046;124\n";
    cout << S->buscarUsuario("09519900M");
    cout << "No se debería mostrar ningún usuario\n";
    cout << S->buscarUsuario("notadni");
    
    delete S;
    cout << "Prueba de buscarUsuario() finalizada\n";
}

// void insertarPatinete(const std::string identificador, const std::string marca, const std::string modelo, const bool averiado, const bool disponible);//Añade un nuevo patinete a la lista lPatinetes. Este método recibe como parámetros de entrada los datos de un patinete y los utilizará para crear una instancia dinámica (puntero a un objeto) de la clase Patinete. Una vez creado el puntero al patinete, lo insertará en la lista lPatinetes. El orden de inserción queda a criterio de los desarrolladores.
// Probaremos a instertar tres patinetes y mostrarlos
void pruebaInsertarPatinete(){
    cout << "Inicio prueba insertarPatinete()...\n";
    Sistema *S = new Sistema();
    
    S->insertarPatinete("id1", "marca1", "modelo1", true, false);//averiado no disponible
    S->insertarPatinete("id2", "marca2", "modelo2", false, true);//no averiado, disponible
    S->insertarPatinete("id3", "marca3", "modelo3", false, true);//segundo no averiado disponible
    
    cout << "se debería mostrar el patinete de id1 averiado y los de id2 e id3 no averiados:\n";
    S->mostrarPatinetes();
    
    delete S;
    cout << "prueba insertarPatinete() finalizada\n";
}

// void mostrarPatinetes();//muestra el número de patinetes total del sistema y la información de todos ellos.
///mostrarPatinetes() no le haremos prueba ya que la vamos a usar para las otras pruebas (sólo es para debug)

// void insertarEstacion(std::string identificador, std::string direccion);
// Probaremos a insertar tres estaciones y mostrarlas
void pruebaInsertarEstacion(){
    cout << "Inicio prueba insertarEstacion()...\n";
    Sistema *S = new Sistema();
    
    S->insertarEstacion("id1", "dirección1");
    S->insertarEstacion("id2", "dirección2");
    S->insertarEstacion("id3", "dirección3");
    
    cout << "se deberían mostrar tres estaciones de id1, id2 e id3 y direcciones numeradas de la misma manera:\n";
    S->mostrarEstaciones();
    
    delete S;
    cout << "prueba insertarEstacion() finalizada\n";
}

// void mostrarEstaciones();
///otro mostrar que no requiere módulo de pruebas

// ~Sistema();
///el destructor evidentemente no le haremos un módulo de pruebas

void pruebasSistema(){
    cout << boolalpha;//para que los bool se muestren como true y false
    pruebaConstructoresSistema();
    pruebaBuscarUsuario();
    pruebaInsertarPatinete();
    pruebaInsertarEstacion();
}

