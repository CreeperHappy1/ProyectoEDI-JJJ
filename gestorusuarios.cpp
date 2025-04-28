#include "gestorusuarios.h"

// #define LISTA

#if defined(LISTA)

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
            enc = true; //return;// EL GRAN TRUCO QUE LOS PROFESORES DE PROGRAMACIÓN NO QUIEREN QUE SEPAS!!!1!
        lUsuarios->avanzar();
    }
    if(!enc || lUsuarios->estaVacia())//Desconozco el funcionamiento de alFinal en el caso de una lista vacía, pero según mariscal devolverá true immediatamente, por lo que no se entrará en el while en ese caso
        lUsuarios->insertar(new Usuario(apellidoNombre, telefono, edad, numeroCuenta, saldo, DNI, email));
}

Usuario* GestorUsuarios::buscar(const string DNI){
    lUsuarios->moverPrimero();
    while (!lUsuarios->alFinal() && DNI != lUsuarios->consultar()->getDNI())
        lUsuarios->avanzar();
    if(lUsuarios->alFinal())
        return nullptr;//WARNING: [issue#3] no le gusta a los profes
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

void GestorUsuarios::eliminarUsuario(const string DNI)
{
    lUsuarios->moverPrimero();
    while (!lUsuarios->alFinal() && DNI != lUsuarios->consultar()->getDNI())
        lUsuarios->avanzar();
    delete lUsuarios->consultar();
    lUsuarios->eliminar();//si está al final no hará nada (no se encontró el usuario)
}

GestorUsuarios::~GestorUsuarios(){
    lUsuarios->moverPrimero();
    while(!lUsuarios->estaVacia()){
        delete lUsuarios->consultar();
        lUsuarios->eliminar();
    }
    delete lUsuarios;
}

#else
void GestorUsuarios::copiarArbol(BSTree<KeyValue<string, Usuario *> > *otroArbol)
{
    KeyValue<string, Usuario*> par;
    Usuario *u = nullptr;
    if(!otroArbol->estaVacio()){
        par = otroArbol->getDato();
        Usuario *u = par.getValue();
        Usuario *uCopia = new Usuario(*u);
        KeyValue<string, Usuario*>
            parCopia(par);
    }
}
#endif
