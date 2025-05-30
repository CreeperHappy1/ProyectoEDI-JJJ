#ifndef GESTORUSUARIOS_H
#define GESTORUSUARIOS_H

#include "Usuario.h"

#if defined(LISTA)
#include "ListaDPI.h"
class GestorUsuarios
{
private:
    ListaDPI<Usuario*> *lUsuarios;
    int occ;//añadido para hacer numElementos() O(1) (aunque ListaDPI ya debería tener eso)
public:
    GestorUsuarios();
    GestorUsuarios(GestorUsuarios const& other);
    
    void insertar(const std::string &apellidoNombre, const std::string &telefono, int edad, const std::string numeroCuenta, const float saldo, const std::string DNI, const std::string email);
    
    //PRE:
    //DESC:
    //Complejidad:
    void eliminarUsuario(const std::string DNI);//busca un usuario y lo elimina de la lista (se elimina el objeto [composición])
    
    Usuario* buscar(const std::string DNI);//Mariscal ha puesto como header "bool buscarUsuario(string dni, Usuario *&usu);" pero si quiero devolver fallo devuelvo nullptr o una excepción
    const int numElementos();
    void mostrar();
    
    ~GestorUsuarios();
};
#else
#include "BSTree.h"
#include "KeyValue.h"
class GestorUsuarios
{
private:
    BSTree<KeyValue<string,Usuario*>> *aUsuarios;//composición con Usuario
    int num;//número de elementos en el árbol
    
#ifdef ARBOLYPUBLICADOS //definir ARBOLYPUBLICADOS activará en las pruebas de la clase las pruebas de los métodos privados
public:
#endif
    //PRE: puntero válido a árbol de KeyValue<string, Usuario*> 
    //DESC: Copia los elementos de otroArbol y los inserta en el árbol de usuarios de este gestor
    //Complejidad: O(n)
    void copiarArbol(BSTree<KeyValue<string,Usuario*>> *otroArbol);
    
    //PRE:
    //DESC:
    //Complejidad:
    int mostrarRec(BSTree<KeyValue<string,Usuario*>> *a) const;
    
    //PRE:
    //DESC:
    //Complejidad:
    Usuario *buscarR(const std::string DNI, BSTree<KeyValue<string,Usuario*>>* aux);
    
    //PRE:
    //DESC:
    //Complejidad:
    void destructorR(BSTree<KeyValue<string,Usuario*>> *a);
#ifndef ARBOLYPUBLICADOS
public:
#endif
    //PRE:
    //DESC:
    //Complejidad:
    GestorUsuarios();
    
    //PRE:
    //DESC:
    //Complejidad:
    GestorUsuarios(GestorUsuarios const& other);
    
    
    //PRE:
    //DESC:
    //Complejidad:
    void insertar(const std::string &apellidoNombre, const std::string &telefono, int edad, const std::string numeroCuenta, const float saldo, const std::string DNI, const std::string email);
    
    //PRE:
    //DESC:
    //Complejidad:
    void eliminarUsuario(const std::string DNI);//busca un usuario y lo elimina del árbol (se elimina el objeto [composición])
    
    
    //PRE:
    //DESC:
    //Complejidad:
    Usuario* buscar(const std::string DNI);
    
    //PRE:
    //DESC:
    //Complejidad:
    const int numElementos();
    
    //PRE:
    //DESC:
    //Complejidad:
    void mostrar();
    
    
    //PRE:
    //DESC:
    //Complejidad:
    ~GestorUsuarios();
};
#endif // LISTA
#endif // GESTORUSUARIOS_H
