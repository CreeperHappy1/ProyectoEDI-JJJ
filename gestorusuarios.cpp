#include "gestorusuarios.h"

GestorUsuarios::GestorUsuarios() {
    lUsuarios = new ListaDPI<Usuario *>();
}

GestorUsuarios::GestorUsuarios(const GestorUsuarios &other){
    lUsuarios = new ListaDPI<Usuario *>();
    other.lUsuarios->moverPrimero();
    for(/*aquí crearíamos el iterador (el PI)*/; !other.lUsuarios->alFinal(); other.lUsuarios->avanzar())
        lUsuarios->insertar(new Usuario(*other.lUsuarios->consultar()));
}

void GestorUsuarios::insertar(const string &apellidoNombre, const string &telefono, int edad, const string numeroCuenta, const float saldo, const string DNI, const string email){
    lUsuarios->moverPrimero();
    bool enc = false;
    while (!lUsuarios->alFinal() && lUsuarios->consultar()->getDNI() < DNI && !enc) {
        if (lUsuarios->consultar()->getDNI() == DNI)
            enc = true; 
        lUsuarios->avanzar();
    }
    if(!enc || lUsuarios->estaVacia())
        lUsuarios->insertar(new Usuario(apellidoNombre, telefono, edad, numeroCuenta, saldo, DNI, email));
}

Usuario* GestorUsuarios::buscar(const string DNI){
    Usuario* ret = nullptr;
    lUsuarios->moverPrimero();
    while (!lUsuarios->alFinal() && DNI != lUsuarios->consultar()->getDNI())
        lUsuarios->avanzar();
    if(!lUsuarios->alFinal())
        ret = lUsuarios->consultar();
    return ret;
}

const int GestorUsuarios::numElementos(){
    return occ;
}

void GestorUsuarios::mostrar(){
    lUsuarios->moverPrimero();
    for(; !lUsuarios->alFinal(); lUsuarios->avanzar())
        lUsuarios->consultar()->mostrar();
}

void GestorUsuarios::eliminarUsuario(const string DNI)
{
    lUsuarios->moverPrimero();
    while (!lUsuarios->alFinal() && DNI != lUsuarios->consultar()->getDNI())
        lUsuarios->avanzar();
    delete lUsuarios->consultar();
    lUsuarios->eliminar();
}

string GestorUsuarios::DevolverCadenaUsuarioFichero(int pos)
{
    this->lUsuarios->moverPrimero();
    
    for(int i = pos; i > 0; i--){
        this->lUsuarios->avanzar();
    }
    
    return this->lUsuarios->consultar()->pasarACadenaFichero();
}

GestorUsuarios::~GestorUsuarios(){
    lUsuarios->moverPrimero();
    while(!lUsuarios->estaVacia()){
        delete lUsuarios->consultar();
        lUsuarios->eliminar();
    }
    delete lUsuarios;
}
