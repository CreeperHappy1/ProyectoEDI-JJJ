#ifndef GESTORUSUARIOS_H
#define GESTORUSUARIOS_H

#include "ListaDPI.h"
#include "Usuario.h"

class GestorUsuarios
{
private:
    ListaDPI<Usuario*> *lUsuarios;
    int occ;//añadido para hacer numElementos() O(1) (aunque ListaDPI ya debería tener eso)
public:
    
    //PRE: No hay
    //DESC: Inicia la lista de usuarios
    //Complejidad: O(1)
    GestorUsuarios();
    
    //PRE: Parámetro de entrada otro gestor de usuarios
    //DESC: Copia el gestor de usuarios de entrada en este
    //Complejidad: O(n)
    GestorUsuarios(GestorUsuarios const& other);
    
    //PRE: Parámetros de entrada de cada una de las variables que tiene un usuario
    //DESC: Inserta el usuario
    //Complejidad: O(n)
    void insertar(const std::string &apellidoNombre, const std::string &telefono, int edad, const std::string numeroCuenta, const float saldo, const std::string DNI, const std::string email);
    
    //PRE: Parámetro de entrada de tipo string que sea un DNI
    //DESC: Busca y devuelve un usuario si lo encuentra en la lista con el DNI en el parámetro de entrada
    //Complejidad: O(n)
    Usuario* buscar(const std::string DNI);//Mariscal ha puesto como header "bool buscarUsuario(string dni, Usuario *&usu);" pero si quiero devolver fallo devuelvo nullptr o una excepción
    
    //PRE: No hay
    //DESC: Devuelve el número de usuarios en la lista
    //Complejidad: O(1)
    const int numElementos();
    
    //PRE: No hay
    //DESC: Muestra los usuarios que hay en la lista
    //Complejidad: O(n)
    void mostrar();
    
    //PRE: Parámetro de entrada de tipo string que sea un DNI
    //DESC: Elimina al usuario con un DNI igual al del parámetro de entrada si lo encuentra
    //Complejidad: O(n)
    void eliminarUsuario(const std::string DNI);//busca un usuario y lo elimina de la lista (se elimina el objeto [composición])
    
    //PRE: 
    //DESC:
    //Complejidad:
    ~GestorUsuarios();
};

#endif // GESTORUSUARIOS_H
