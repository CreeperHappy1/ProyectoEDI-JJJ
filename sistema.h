#ifndef SISTEMA_H
#define SISTEMA_H

#include <string>
#include "gestorusuarios.h"
#include "ListaDPI.h"
#include "patinete.h"
#include "estacion.h"

class Sistema
{
private:
    std::string nombreSistema;
    GestorUsuarios *usuarios;
    ListaDPI <Patinete *> *lPatinetes;
    ListaDPI <Estacion *> *lEstaciones;
    
    //PRE: No hay
    //DESC: Carga desde el fichero usuarios.csv los datos de los usuarios al gestorUsuarios
    //Complejidad: O(n)
    void cargarUsuarios();//Este método debe ser privado y se invocará en los constructores de esta clase. Esta operación debe procesar el fichero de texto usuarios.csv, usando los datos leídos de cada usuario para invocar al método insertar de la clase GestorUsuarios.
    
    //PRE: No hay
    //DESC: Carga desde el fichero patinetes.csv los datos de los patinetes a la lista de Patinetes
    //Complejidad: O(n)
    void cargarPatinetes();//Si un valor bool es diferente de Si se asume false//Este método debe ser privado y se invocará en los constructores de esta clase. Esta operación debe procesar el fichero de texto patinetes.csv, usando los datos leídos de cada patinete para invocar al método insertarPatinete de esta clase
    
    //PRE: No hay
    //DESC: Carga desde el fichero estaciones.csv los datos de las estaciones en la lista de Estaciones
    //Complejidad: O(n)
    void cargarEstaciones();
    
    
    //PRE: No hay
    //DESC: Carga desde el ficher distribucionPatinetes.csv los datos de en qué estación está cada patinete
    //Complejidad: O(n)
    void distribuirPatinetesEnEstaciones();
    
    //PRE: Parámetros de entrada y salida string de id origen, DNI y id destino
    //DESC: Un usuario alquila un patinete, siendo los parámetros de entrada, idEstOrigen la estación de la que alquila el patinete, idEstDestino la estación en la que deja el patinete y DNI la persona que lo alquila
    //Complejidad: O(1)
    void alquilarDevolverUnPatinete(std::string const& idEstOrigen, std::string const& DNI, std::string const& idEstDestino);
    
    
    
public:
    
    //PRE: No hay
    //DESC: Inicia el nombre del sistema a "" e inicia los módulos de cargarUsuarios, cargarPatinetes y cargarEstaciones para procesar los archivos de texto
    //Complejidad: O(n)
    Sistema();//NOTE: no tiene sentido que el constructor por defecto cargue nada, sería mejor que los metodos para cargar tomasen como argumento en path al .csv
    
    //PRE: Parámetro de entrada string para el nombre del sistema
    //DESC: Inicia el nombre del sistema según el parámetro de entrada e inicia los módulos de cargarUsuarios, cargarPatinetes y cargarEstaciones para procesar los archivos de texto
    //Complejidad: O(n)
    Sistema(std::string nombreSistema);//NOTE: quizá esto debería ser const&
    
    //PRE: Parámetro de entrada por referencia constante de otro sistema
    //DESC: Copia el otro sistema en este
    //Complejidad: O(n)
    Sistema(Sistema const& other);//por copia
    
    //PRE: No hay
    //DESC: Muestra el número de usuarios y los usuarios del sistema
    //Complejidad: O(n)
    void mostrarUsuarios();//muestra el número de usuarios total del sistema y la información de todos ellos.
    
    //PRE: Parámetro de entrada string
    //DESC: Busca un usuario en la lista de usuarios con el DNI de entrada
    //Complejidad: O(n)
    std::string buscarUsuario(std::string const DNI);//recibe como parámetro de entrada el DNI de un usuario y, si lo encuentra, devuelve toda la información del usuario (p.ej., para luego poder mostrarlo).
    
    //PRE: Parámetros de entrada string identificador, marca y modelo, y bool averiado y disponible
    //DESC: Inserta un patinete al final de la lista de patinetes
    //Complejidad: O(1)
    void insertarPatinete(const std::string identificador, const std::string marca, const std::string modelo, const bool averiado, const bool disponible);//Añade un nuevo patinete a la lista lPatinetes. Este método recibe como parámetros de entrada los datos de un patinete y los utilizará para crear una instancia dinámica (puntero a un objeto) de la clase Patinete. Una vez creado el puntero al patinete, lo insertará en la lista lPatinetes. El orden de inserción queda a criterio de los desarrolladores.
    
    //PRE: No hay
    //DESC: Muestra los patinetes en la lista de patinetes y dice el número que hay
    //Complejidad: O(n)
    void mostrarPatinetes();//muestra el número de patinetes total del sistema y la información de todos ellos.
    
    //PRE: Parámetro de entrada string identificador
    //DESC: Busca y devuelve el patinete de la lista de patinetes según el identificador del patrón de entrada
    //Complejidad: O(n)
    Patinete* buscarPatinete(std::string const identificador);
    
    //PRE: Parámetros de entrada string identificador y dirección
    //DESC: Inserta una nueva estación con identificador y dirección del parámetro de entrada
    //Complejidad: O(1)
    void insertarEstacion(std::string identificador, std::string direccion);
    
    //PRE: No hay
    //DESC: Muestra los parámetros de las estaciones y los patinetes en ellos
    //Complejidad: O(n²)
    void mostrarEstaciones();
    
    //PRE: Parámetro de entrada string identificador
    //DESC: Busca la estación con el identificador que hay desde el parámetro de entrada
    //Complejidad: O(n)
    Estacion* buscarEstacion(std::string const identificador);
    
    //PRE: Parámetros string, identificador de patinete e identificador de estación
    //DESC: Agrega el patinete con el identificador del parámetro de entrada y lo añade a la estación con el identificador del parámetro de entrada
    //Complejidad: O(n)
    void agregarPatineteEnEstacion(std::string identificadorP, std::string identificadorE);
    
    //PRE: No hay
    //DESC: Lee el fichero alquilerPatinetes.csv y alquila los patinetes a los respectivos usuarios
    //Complejidad: O(n)
    void alquilarDevolverPatinetes();//lee automáticamente del fichero "alquilerPatinetes.csv"
    
    //PRE: Parámetro de entrada string identificador de estación
    //DESC: Repara los patinetes de la estación cuyo identificador es el del parámetro de entrada
    //Complejidad: O(n)
    int repararPatinetesEstacion(std::string const identificadorE);
    
    //PRE: No hay
    //DESC: Busca un usuario según el DNI que se introduzca por consola
    //Complejidad: O(n)
    void buscarUsuarioDNI();
    
    //PRE: No hay
    //DESC: Busca una estación según el id que se introduzca por consola
    //Complejidad: O(n)
    void buscarEstacionID();
  
    //PRE: No hay
    //DESC: Busca los patinetes extraviados
    //Complejidad: O(n²)
    void buscarPatinetesExtraviados();
    
    //PRE: No hay
    //DESC: Muestra la estación con más patinetes
    //Complejidad: O(n)
    void estacionConMasPatinetes();
    
    //PRE: No hay
    //DESC: Arregla los patinetes de la estación cuyo id es el recibido por consola
    //Complejidad: O(n)
    void arreglarPatinetesEstacion();
    
    //PRE: No hay
    //DESC: Sobreescribe el fichero con los usuarios actuales
    //Complejidad: O(n²)
    void cerrarSistema();
    
    //PRE: No hay
    //DESC: Elimina los elementos de las listas de estaciones y patinetes y también elimina las propias listas
    //Complejidad: O(n)
    ~Sistema();
};

#endif // SISTEMA_H
