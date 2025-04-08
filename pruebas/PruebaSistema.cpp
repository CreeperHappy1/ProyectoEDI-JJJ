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
    cout << "pruebas de los constructores de Sistema finalizadas\n\n";
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
    cout << "Prueba de buscarUsuario() finalizada\n\n";
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
    cout << "prueba insertarPatinete() finalizada\n\n";
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
    cout << "prueba insertarEstacion() finalizada\n\n";
}

// void mostrarEstaciones();
///otro mostrar que no requiere módulo de pruebas

// ~Sistema();
///el destructor evidentemente no le haremos un módulo de pruebas

// Patinete* buscarPatinete(std::string const identificador);
/* generaremos un sistema con .csv proveído en el campus
 * Caso 1: buscaremos el patinete de id A1158 (el primero), y el patinete que devuelva tendrá los datos A1158;ACER;AES025;No;Si
 * Caso 2: buscaremos el patinete de id C1005, y el patinete que devuelva tendrá los datos C1005;NAVEE;ST3 Pro-E;Si;No
 * Caso 3: buscaremos el patinete de id A1121 (el último), y el patinete que devuelva tendrá los datos A1121;ZWHEEL;S4-00;No;Si
 * Caso 4: buscaresmos un id no existente entre los patinetes (notanid) (debería devolver un nullptr)
*/
void pruebaBuscarPatinete(){
    std::cout << "Iniciando pruebas de buscarPatinete()...\n";
    Sistema* S = new Sistema();
    Patinete* aux;
    //Caso 1:
    aux = S->buscarPatinete("A1158");
    if(aux->getIdentificador() != "A1158")
        std::cerr << "ERROR: (Caso 1) el id no coincide con el del patinete buscado!\n";
    if(aux->getMarca() != "ACER")
        std::cerr << "ERROR: (Caso 1) la marca no coincide con la del patinete buscado!\n";
    if(aux->getModelo() != "AES025")
        std::cerr << "ERROR: (Caso 1) el módelo no coincide con el del patinete buscado!\n";
    if(aux->getAveriado() != false)
        std::cerr << "ERROR: (Caso 1) el patinete encontrado está averiado, el buscado no!\n";
    if(aux->getDisponible() != true)
        std::cerr << "ERROR: (Caso 1) el patinete encontrado no está disponible, el buscado sí!\n";
    
    //Caso 2:
    aux = S->buscarPatinete("C1005");
    if(aux->getIdentificador() != "C1005")
        std::cerr << "ERROR: (Caso 2) el id no coincide con el del patinete buscado!\n";
    if(aux->getMarca() != "NAVEE")
        std::cerr << "ERROR: (Caso 2) la marca no coincide con la del patinete buscado!\n";
    if(aux->getModelo() != "ST3 Pro-E")
        std::cerr << "ERROR: (Caso 2) el módelo no coincide con el del patinete buscado!\n";
    if(aux->getAveriado() != true)
        std::cerr << "ERROR: (Caso 2) el patinete encontrado no está averiado, el buscado sí!\n";
    if(aux->getDisponible() != false)
        std::cerr << "ERROR: (Caso 2) el patinete encontrado está disponible, el buscado no!\n";
    
    //Caso 3:
    aux = S->buscarPatinete("A1121");
    if(aux->getIdentificador() != "A1121")
        std::cerr << "ERROR: (Caso 3) el id no coincide con el del patinete buscado!\n";
    if(aux->getMarca() != "ZWHEEL")
        std::cerr << "ERROR: (Caso 3) la marca no coincide con la del patinete buscado!\n";
    if(aux->getModelo() != "S4-00")
        std::cerr << "ERROR: (Caso 3) el módelo no coincide con el del patinete buscado!\n";
    if(aux->getAveriado() != false)
        std::cerr << "ERROR: (Caso 3) el patinete encontrado está averiado, el buscado no!\n";
    if(aux->getDisponible() != true)
        std::cerr << "ERROR: (Caso 3) el patinete encontrado no está disponible, el buscado sí!\n";
    
    //Caso 4:
    aux = S->buscarPatinete("notanid");
    if(aux != nullptr)
        std::cerr << "ERROR: (Caso 4) al buscar un id no existente no devuelve nullptr!\n";
    
    delete S;
    std::cout << "Pruebas de buscarPatinete() finalizadas\n\n";
}

// Estacion* buscarEstacion(std::string const identificador);
/* generaremos un sistema con .csv proveído en el campus
 * Caso 1: buscaremos la estación de id 56 (el primero), y la estación que devuelva tendrá los datos 56;Plaza De Argel
 * Caso 2: buscaremos la estación de id 3998, y la estación que devuelva tendrá los datos 3998;Calle Hilanderas
 * Caso 3: buscaremos la estación de id 541 (el último), y la estación que devuelva tendrá los datos 541;Avda Virgen De La Montaña
 * Caso 4: buscaresmos un id no existente entre las estaciones (notanid) (debería devolver un nullptr)
*/
void pruebaBuscarEstacion(){
    std::cout << "Iniciando pruebas de buscarEstacion()...\n";
    Sistema* S = new Sistema();
    Estacion* aux;
    //Caso 1:
    aux = S->buscarEstacion("56");
    if(aux->getIdentificador() != "56")
        std::cerr << "ERROR: (Caso 1) el id no coincide con el de la estación buscada!\n";
    if(aux->getDireccion() != "Plaza De Argel")
        std::cerr << "ERROR: (Caso 1) la dirección no coincide con la de la estación buscada!\n";
    
    //Caso 2:
    aux = S->buscarEstacion("3998");
    if(aux->getIdentificador() != "3998")
        std::cerr << "ERROR: (Caso 2) el id no coincide con el de la estación buscada!\n";
    if(aux->getDireccion() != "Calle Hilanderas")
        std::cerr << "ERROR: (Caso 2) la dirección no coincide con la de la estación buscada!\n";
    
    //Caso 3:
    aux = S->buscarEstacion("541");
    if(aux->getIdentificador() != "541")
        std::cerr << "ERROR: (Caso 3) el id no coincide con el de la estación buscada!\n";
    if(aux->getDireccion() != "Avda Virgen De La Montaña")
        std::cerr << "ERROR: (Caso 3) la dirección no coincide con la de la estación buscada!\n";
    
    //Caso 4:
    aux = S->buscarEstacion("notanid");
    if(aux != nullptr)
        std::cerr << "ERROR: (Caso 4) al buscar un id no existente no devuelve nullptr!\n";
    
    delete S;
    std::cout << "Pruebas de buscarEstacion() finalizadas\n\n";
}

// void agregarPatineteEnEstacion(std::string identificadorP, std::string identificadorE);
// Probaremos a agregar un patinete, otros dos en una estación distinta; comprobando los datos añadidos.
// otro en una estación no existente, y un patinete no existente a una estación existente
void pruebaAgregarPatineteEnEstacion(){
    std::cout << "Iniciando pruebas de agregarPatineteEnEstacion()...\n";
    Sistema* S = new Sistema();
    //Caso 1: patinete sólo
    S->insertarPatinete("id1", "marca1", "modelo1", false, true);
    S->insertarEstacion("est1", "dir1");
    S->agregarPatineteEnEstacion("id1", "est1");
    cout << "Se debería mostrar una estación con un sólo patinete \"\"id1\", \"marca1\", \"modelo1\", false, true\"\n";
    S->buscarEstacion("est1")->mostrar();
    
    //Caso 2: dos patinetes en la misma estación
    S->insertarPatinete("id2", "marca2", "modelo2", false, true);
    S->insertarEstacion("est2", "dir2");
    S->agregarPatineteEnEstacion("id2", "est2");
    cout << "Se debería mostrar una estación con un sólo patinete \"\"id2\", \"marca2\", \"modelo2\", false, true\"\n";
    S->buscarEstacion("est2")->mostrar();
    S->insertarPatinete("id3", "marca3", "modelo3", false, true);
    S->agregarPatineteEnEstacion("id3", "est2");
    cout << "Se debería mostrar la misma estación con otro patinete nuevo \"\"id3\", \"marca3\", \"modelo3\", false, true\"\n";
    S->buscarEstacion("est2")->mostrar();
    
    //Caso 3: estación no existente
    S->insertarPatinete("id4", "marca4", "modelo4", false, true);
    S->agregarPatineteEnEstacion("id4", "notastation");//no debería ocurrir nada
    
    //Caso 4: patinete no existente
    S->insertarEstacion("est3", "dir3");
    S->agregarPatineteEnEstacion("notapatinete", "est3");
    cout << "Se debería mostrar una estación vacía:\"";
    S->buscarEstacion("est3")->mostrar();
    
    delete S;//como es composición sólo hará falta borrar el sistema
    std::cout << "Pruebas de agregarPatineteEnEstacion() finalizadas\n\n";
}

// void alquilarDevolverPatinetes();//lee automáticamente del fichero "alquilerPatinetes.csv"
// La única posibilidad de probarla es ejecutarlo y comprobar manualmente que los cambios ejecutados se correspondan con los listados en el archivo
// (según la especificación dada no se permite modificación del archivo o de cual archivo se lee)
void pruebaAlquilarDevolverPatinetes(){
    string in;
    cout << "Iniciar prueba de alquilarDevolverPatinetes?\n(Advertencia: debido a la especificación dada se tendrán que mostrar todos los datos antes y después de la ejecución, será mucho texto)\nProceder? y/N: ";
    cin >> in;
    cin.ignore();
    if(tolower(in[0]) == 'y'){//para cualquier otro valor se asume n
        Sistema* S = new Sistema();
        cout << "\tEstado inicial del sistema:\n";
        S->mostrarEstaciones();
        S->mostrarPatinetes();
        S->mostrarUsuarios();
        S->alquilarDevolverPatinetes();
        cout << "\n\n\n\tEstado tras ejecutar:\n";
        S->mostrarEstaciones();
        S->mostrarPatinetes();
        S->mostrarUsuarios();
        delete S;
        cout << "Prueba de alquilarDevolverPatinetes() finalizada\n\n";
    }
}

// int repararPatinetesEstacion(std::string const identificadorE);
// insertaremos una estación vacía a la cual insertaremos 4 patinetes, dos averiados y dos no; luego ejecutaremos el módulo sobre esa estación.
// Comprobaremos entonces que haya 4 disponibles y 0 averiados, y que estos disponibles correspondan en todos los datos a los antes insertados
void pruebaRepararPatinetesEstacion(){
    cout << "Iniciando pruebas de repararPatinetesEstacion()...\n";
    Sistema* S = new Sistema();
    S->insertarEstacion("est", "dir");
    S->insertarPatinete("id1","marca1","modelo1",true, false);
    S->insertarPatinete("id2","marca2","modelo2",false, true);
    S->insertarPatinete("id3","marca3","modelo3",false, true);
    S->insertarPatinete("id4","marca4","modelo4",true, false);
    for(int i = 1; i <= 4; i++)
        S->agregarPatineteEnEstacion("id" + to_string(i), "est");
    
    //asumimos que los módulos anteriores funcionan correctamente
    S->repararPatinetesEstacion("est");
    if(S->buscarEstacion("est")->getNumAveriadas() != 0)
        cerr << "ERROR: numAveriadas no es 0 tras reparar los patinetes de la estación\n";
    if(S->buscarEstacion("est")->getNumDisponibles() != 4)
        cerr << "ERROR: numDisponibles no es 4 tras reparar los patinetes de la estación\n";
    cout << "Se deberían mostrar sólo 4 patinetes disponibles en la estación (con ids \"id1\", \"id2\", \"id3\", \"id4\"\n";
    S->buscarEstacion("est")->mostrar();
    
    delete S;
    cout << "pruebas de repararPatinetesEstacion() finalizadas\n\n";
}

// void buscarPatinetesExtraviados();
/* Tras ejecutar una vez para limpiar patinetes extraviados:
 * Caso 1: insertaremos un patinete en ninguna estación, sin usuario asociado. Ejecutamos y deberíamos ver la información de ese patinete
 * Caso 2: insertamos un patinete en ninguna estación, con usuario asociado. Ejecutamos y deberíamos ver la información de ese patinete y de su usuario
 * Caso 3: insertamos un patinete en una estación, con usuario asociado, y lo alquilamos de la estación. Ejecutamos y deberíamos ver la información de ese patinete y de su usuario
 * Caso 4: repetimos el paso anterior pero devolvemos el patinete en otra estación (lo agregamos). Ejecutamos y no debería pasar nada
 * (si alquilarDevolverUnPatinete no fuera privado o se pudiese dar otra entrada a alquilarDevolverPatinetes se podría probar ese método de extraviar)
 */
void pruebaBuscarPatinetesExtraviados(){
    cout << "Iniciando pruebas de buscarPatinetesExtraviados()...\n";
    Sistema* S = new Sistema();
    
    S->buscarPatinetesExtraviados();
    //Caso1:
    S->insertarPatinete("id1", "extraviado", "borrar", false, false);
    cout << "Se debería mostrar un patinete de id \"id1\" extraviado para ser eliminado:\n";
    S->buscarPatinetesExtraviados();
    
    //Caso 2:
    S->insertarPatinete("id2", "extraviado", "robado", false, false);
    Usuario* U = new Usuario("nombre1", "tel1", 123, "numcuent1", 123, "dni1", "email1");//S-> extraño que no se pueda agregar un usuario usando los métodos especificados
    S->buscarPatinete("id2")->setUsuarioActual(U);
    cout << "Se debería mostrar un patinete de id \"id2\" extraviado por un usuario \"nombre1\" para ser eliminado:\n";
    S->buscarPatinetesExtraviados();
    
    //Caso 3:
    S->insertarEstacion("est1", "dir1");
    S->insertarPatinete("id3", "marca3", "modelo3", false, true);
    Usuario* U2 = new Usuario("nombre2", "tel2", 124, "numcuent2", 124, "dni2", "email2");
    S->agregarPatineteEnEstacion("est1", "id3");
    S->buscarEstacion("est1")->alquilarPatinete()->setUsuarioActual(U2);
    cout << "Se debería mostrar un patinete de id \"id3\" extraviado por un usuario \"nombre2\" para ser eliminado:\n";
    S->buscarPatinetesExtraviados();
    
    //Caso 4:
    S->insertarEstacion("est2", "dir2");
    S->insertarPatinete("id4", "marca4", "modelo4", false, true);
    Usuario* U3 = new Usuario("nombre3", "tel3", 125, "numcuent3", 125, "dni3", "email3");
    S->agregarPatineteEnEstacion("est1", "id4");
    S->buscarEstacion("est1")->alquilarPatinete()->setUsuarioActual(U2);
    S->agregarPatineteEnEstacion("est2", "id4");
    cout << "No se debería mostrar que se elimine ninún patinete\n";
    S->buscarPatinetesExtraviados();
    
    delete U, delete U2, delete U3;
    delete S;
    cout << "Pruebas de buscarPatinetesExtraviados()\n\n";
}


void pruebasSistema(){
    cout << boolalpha;//para que los bool se muestren como true y false
    // pruebaConstructoresSistema();
    // pruebaBuscarUsuario();
    // pruebaInsertarPatinete();
    // pruebaInsertarEstacion();
    pruebaBuscarPatinete();
    pruebaBuscarEstacion();
    pruebaAgregarPatineteEnEstacion();//Fallida: posible causa, agregarPatineteEnEstacion() no tiene ningún salvaguarda en caso que la estación no exista, se debería o implementar esta o añadir una precondición (realmente es un caso inusual teniendo en cuenta la función del método)
    pruebaAlquilarDevolverPatinetes();
    pruebaRepararPatinetesEstacion();//Fallida: posible causa, arreglarPatinete() tiene la precondición de que Estacion.averiados no esté vacía, y aunque esto se comprueba correctamente es igual porque en el constructor de Estación no se inicializa numAveriadas
    pruebaBuscarPatinetesExtraviados();//Fallida: posible causa, línea 247 en sistema.cpp, parece entrar en un bucle infinito del cual no veo como saldría (no avanza, es sin más un while sobre las mismas condiciones parece)
}
