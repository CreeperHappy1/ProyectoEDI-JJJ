#ifndef PRUEBASISTEMA_H
#define PRUEBASISTEMA_H

// Sistema();
// Sistema(std::string nombreSistema);
// Sistema(Sistema const& other);//por copia
void pruebaConstructores();
/*construiremos uno con el constructor por defecto y comprobaremos que todos sus valores sean los por defecto
 * construiremos uno parametrizado y comprobaremos sus valores
 * insertaremos elementos al segundo y usaremos el constructor por copia para copiarlo (debería ser igual pero con sus propios elementos)
*/

// void mostrarUsuarios();//muestra el número de usuarios total del sistema y la información de todos ellos.
///mostrarUsuarios() no le haremos prueba ya que lo vamos a usar con el resto de pruebas (si funciona mal todo estará mal xd)

void pruebaBuscarUsuario();
// std::string buscarUsuario(std::string const DNI);//recibe como parámetro de entrada el DNI de un usuario y, si lo encuentra, devuelve toda la información del usuario (p.ej., para luego poder mostrarlo).
/* generaremos un sistema con .csv proveído en el campus
 * Caso 1: buscaremos el usuario de DNI 71555558Q (el primero), y el usuario que devuelva tendrá los datos HINOJAL SANCHEZ, ISMAEL;71555558Q;ihinojays@unex.es;351166056;24;ES1172508452101879000096;32
 * Caso 2: buscaremos el usuario de DNI 76060709P, y el usuario que devuelva tendrá los datos ROBLES TRIPIANA, MARIO;76060709P;meriorovyestritiene@unex.es;656656800;23;ES1992590452102699001058;92
 * Caso 3: buscaremos el usuario de DNI 09519900M (el último), y el usuario que devuelva tendrá los datos PEREZ SUAREZ, LUIS;09519900M;yterezsuerez82@unex.es;688885606;21;ES1872578452102579001046;124
 * Caso 4: buscaresmos un DNI no existente entre los usuarios (notadni) (debería devolver una string vacía)
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

void pruebaBuscarPatinete();
// Patinete* buscarPatinete(std::string const identificador);
/* generaremos un sistema con .csv proveído en el campus
 * Caso 1: buscaremos el patinete de id A1158 (el primero), y el patinete que devuelva tendrá los datos A1158;ACER;AES025;No;Si
 * Caso 2: buscaremos el patinete de id A1149, y el patinete que devuelva tendrá los datos A1149;MINIMOTORS;MINI SPECIAL;No;Si
 * Caso 3: buscaremos el patinete de id A1121 (el último), y el patinete que devuelva tendrá los datos A1121;ZWHEEL;S4-00;No;Si
 * Caso 4: buscaresmos un id no existente entre los patinetes (notanid) (debería devolver un nullptr)
*/

void pruebaBuscarEstacion();
// Estacion* buscarEstacion(std::string const identificador);
/* generaremos un sistema con .csv proveído en el campus
 * Caso 1: buscaremos la estación de id 56 (el primero), y la estación que devuelva tendrá los datos 56;Plaza De Argel
 * Caso 2: buscaremos la estación de id 3998, y la estación que devuelva tendrá los datos 3998;Calle Hilanderas
 * Caso 3: buscaremos la estación de id 541 (el último), y la estación que devuelva tendrá los datos 541;Avda Virgen De La Montaña
 * Caso 4: buscaresmos un id no existente entre las estaciones (notanid) (debería devolver un nullptr)
*/

void pruebaAgregarPatineteEnEstacion();
// void agregarPatineteEnEstacion(std::string identificadorP, std::string identificadorE);
// Probaremos a agregar un patinete, otros dos en una estación distinta; comprobando los datos añadidos.
// otro en una estación no existente, y un patinete no existente a una estación existente

void pruebaAlquilarDevolverPatinetes();
// void alquilarDevolverPatinetes();//lee automáticamente del fichero "alquilerPatinetes.csv"
// La única posibilidad de probarla es ejecutarlo y comprobar manualmente que los cambios ejecutados se correspondan con los listados en el archivo
// (según la especificación dada no se permite modificación del archivo o de cual archivo se lee)

void pruebaRepararPatinetesEstacion();
// int repararPatinetesEstacion(std::string const identificadorE);

void pruebaBuscarPatinetesExtraviados();
// void buscarPatinetesExtraviados();

void pruebasSistema();

#endif // PRUEBASISTEMA_H
