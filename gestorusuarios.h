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
    Usuario* buscar(const std::string DNI);//Mariscal ha puesto como header "bool buscarUsuario(string dni, Usuario *&usu);" pero si quiero devolver fallo devuelvo nullptr o una excepción
    const int numElementos();
    void mostrar();
    void eliminarUsuario(const std::string DNI);//busca un usuario y lo elimina de la lista (se elimina el objeto [composición])
    
    ~GestorUsuarios();
};
#else
#include "BSTree.h"
#include "KeyValue.h"
class GestorUsuarios
{
private:
    BSTree<KeyValue<string,Usuario*>> *aUsuarios;
    void copiarArbol(BSTree<KeyValue<string,Usuario*>> *otroArbol);
    int mostrarRec(BSTree<KeyValue<string,Usuario*>> *a) const;
    int mostrarRecCont(BSTree<KeyValue<string,Usuario*>> *a);
    int num;//número de elementos en el árbol
    Usuario* buscarR(const std::string DNI, BSTree<KeyValue<string,Usuario*>>* aux);
public:
    GestorUsuarios();
    GestorUsuarios(GestorUsuarios const& other);
    void insertar(const std::string &apellidoNombre, const std::string &telefono, int edad, const std::string numeroCuenta, const float saldo, const std::string DNI, const std::string email);
    Usuario* buscar(const std::string DNI);
    const int numElementos();
    void mostrar();
    void eliminarUsuario(const std::string DNI);//busca un usuario y lo elimina de la lista (se elimina el objeto [composición])
    
    ~GestorUsuarios();
};
#endif // LISTA
#endif // GESTORUSUARIOS_H
