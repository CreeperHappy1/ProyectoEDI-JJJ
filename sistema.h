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
    
    void cargarUsuarios();//Este método debe ser privado y se invocará en los constructores de esta clase. Esta operación debe procesar el fichero de texto usuarios.csv, usando los datos leídos de cada usuario para invocar al método insertar de la clase GestorUsuarios.
    void cargarPatinetes();//Si un valor bool es diferente de Si se asume false//Este método debe ser privado y se invocará en los constructores de esta clase. Esta operación debe procesar el fichero de texto patinetes.csv, usando los datos leídos de cada patinete para invocar al método insertarPatinete de esta clase
    void cargarEstaciones();
    
    void distribuirPatinetesEnEstaciones();
    void alquilarDevolverUnPatinete(std::string const& idEstOrigen, std::string const& DNI, std::string const& idEstDestino);
    
public:
    Sistema();//NOTE: no tiene sentido que el constructor por defecto cargue nada, sería mejor que los metodos para cargar tomasen como argumento en path al .csv
    Sistema(std::string nombreSistema);

    Sistema(Sistema const& other);//por copia
    
    void mostrarUsuarios();//muestra el número de usuarios total del sistema y la información de todos ellos.
    std::string buscarUsuario(std::string const DNI);//recibe como parámetro de entrada el DNI de un usuario y, si lo encuentra, devuelve toda la información del usuario (p.ej., para luego poder mostrarlo).
    
    void insertarPatinete(const std::string identificador, const std::string marca, const std::string modelo, const bool averiado, const bool disponible);//Añade un nuevo patinete a la lista lPatinetes. Este método recibe como parámetros de entrada los datos de un patinete y los utilizará para crear una instancia dinámica (puntero a un objeto) de la clase Patinete. Una vez creado el puntero al patinete, lo insertará en la lista lPatinetes. El orden de inserción queda a criterio de los desarrolladores.
    void mostrarPatinetes();//muestra el número de patinetes total del sistema y la información de todos ellos.
    Patinete* buscarPatinete(std::string const identificador);
    
    void insertarEstacion(std::string identificador, std::string direccion);
    void mostrarEstaciones();
    Estacion* buscarEstacion(std::string const identificador);
    
    void agregarPatineteEnEstacion(std::string identificadorP, std::string identificadorE);
    
    
    ~Sistema();
};

#endif // SISTEMA_H
