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
    
    //PRE: puntero válido a árbol de KeyValue<string, Usuario*> 
    //DESC: Muestra los datos de todos usuarios en el árbol dado por consola
    //Complejidad: O(n)
    void mostrarRec(BSTree<KeyValue<string,Usuario*>> *a) const;
    
    //PRE: string DNI a buscar en el árbol cuya raíz es *aux
    //DESC: Devuelve el puntero al Usuario con ese DNI en el árbol *aux, nullptr si no se encontró
    //Complejidad: O(log n)
    Usuario *buscarR(const std::string DNI, BSTree<KeyValue<string,Usuario*>>* aux);
    
    //PRE: a apunta a un árbol no vacío con punteros Usuario* válidos (no se ha liberado su memoria todavía)
    //DESC: Destruye todos los objetos Usuario en el árbol (inválida todos los punteros *Usuario del árbol)
    //Complejidad: O(n)
    void destructorR(BSTree<KeyValue<string,Usuario*>> *a);
#ifndef ARBOLYPUBLICADOS
public:
#endif
    //PRE: No hay
    //DESC: inicializa el contador de usuarios a 0 y el árbol de usuarios
    //Complejidad: O(1)
    GestorUsuarios();
    
    //PRE: parámetro por referencia constante a un GestorUsuarios válido
    //DESC: Copia el contador del otro gestor y copia sus usuarios por composición a su propio árbol
    //Complejidad: O(n)
    GestorUsuarios(GestorUsuarios const& other);
    
    
    //PRE: Parámetros de entrada string por referencia constante apellidoNombre, telefono, por valor DNI, email y el número de cuenta; int edad, float saldo
    //DESC: Construye un nuevo Usuario inplace con los parametros dados y lo inserta con un par KeyValue (DNI como key) en el árbol de usuarios, e incrementa el contador de usuarios
    //Complejidad: O(log n)
    void insertar(const std::string &apellidoNombre, const std::string &telefono, int edad, const std::string numeroCuenta, const float saldo, const std::string DNI, const std::string email);
    
    //PRE: Parámetro por valor (constante en la función) tipo string DNI
    //DESC: Elimina el usuario con ese DNI, destruyendo el objeto y eliminándolo del árbol; si no se encuentra o el árbol está vacío no hace nada
    //Complejidad: O(log n)
    void eliminarUsuario(const std::string DNI);//busca un usuario y lo elimina del árbol (se elimina el objeto [composición])
    
    
    //PRE: parámetro por valor (constante en la función) tipo string DNI
    //DESC: Devuelve un puntero al Usuario con ese DNI si se encuentra en al árbol, sino devuelve nullptr
    //Complejidad: O(log n)
    Usuario* buscar(const std::string DNI);
    
    //PRE: No hay
    //DESC: Devuelve el número de usuarios en el gestor
    //Complejidad: O(1)
    const int numElementos();
    
    //PRE: El GestorUsuarios y sus parametros (incluyendo los punteros de Usuario en el árbol) siguen siendo válidos (no se han eliminado)
    //DESC: Muestra los datos de todos los usuarios del gestor y el número total de usuarios en el gestor por consola
    //Complejidad: O(n)
    void mostrar();
    
    
    //PRE: Los punteros de Usuario del árbol no han sido eliminados
    //DESC: Destruye todos los usuarios en el gestor y todos los parámetros de este
    //Complejidad: O(n)
    ~GestorUsuarios();
};
#endif // LISTA
#endif // GESTORUSUARIOS_H
