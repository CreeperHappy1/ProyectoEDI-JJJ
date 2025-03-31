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
    while(lUsuarios->consultar()->getDNI() < DNI && !lUsuarios->alFinal() && !enc){
        if(lUsuarios->consultar()->getDNI() == DNI)
            enc = true;    //return;// EL GRAN TRUCO QUE LOS PROFESORES DE PROGRAMACIÓN NO QUIEREN QUE SEPAS!!!1!
        lUsuarios->avanzar();
    }
    if(!enc || lUsuarios->estaVacia())//Desconozco el funcionamiento de alFinal en el caso de una lista vacía, pero según mariscal devolverá true immediatamente, por lo que no se entrará en el while en ese caso
        lUsuarios->insertar(new Usuario(apellidoNombre, telefono, edad, numeroCuenta, saldo, DNI, email));
}

Usuario *GestorUsuarios::buscar(const string DNI){
    lUsuarios->moverPrimero();
    while(DNI != lUsuarios->consultar()->getDNI() && !lUsuarios->alFinal())
        lUsuarios->avanzar();
    return lUsuarios->consultar();
}

const int GestorUsuarios::numElementos(){
    return occ;
}

void GestorUsuarios::mostrar(){
    lUsuarios->moverPrimero();
    for(; !lUsuarios->alFinal(); lUsuarios->avanzar())
        lUsuarios->consultar()->mostrar();
}

GestorUsuarios::~GestorUsuarios(){
    lUsuarios->moverPrimero();
    while(!lUsuarios->estaVacia()){
        delete lUsuarios->consultar();
        lUsuarios->eliminar();
    }
    delete lUsuarios;
}
