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
    GestorUsuarios();
    GestorUsuarios(GestorUsuarios const& other);
    void insertar(const std::string &apellidoNombre, const std::string &telefono, int edad, const std::string numeroCuenta, const float saldo, const std::string DNI, const std::string email);
    Usuario* buscar(const std::string DNI);//Mariscal ha puesto como header "bool buscarUsuario(string dni, Usuario *&usu);" pero si quiero devolver fallo devuelvo nullptr o una excepción
    const int numElementos();
    void mostrar();
    
    ~GestorUsuarios();
};

#endif // GESTORUSUARIOS_H
