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
    num = 0;
    if(!otroArbol->estaVacio()){
        par = otroArbol->getDato();
        Usuario *u = par.getValue();
        KeyValue<string, Usuario*> parCopia(par.getKey(), u);
        aUsuarios->insertar(parCopia);
        num++;
        
        if(otroArbol->getIzq() != nullptr){
            copiarArbol(otroArbol->getIzq());
        }
        
        if(otroArbol->getDer() != nullptr){
            copiarArbol(otroArbol->getDer());
        }
    }
}

int GestorUsuarios::mostrarRec(BSTree<KeyValue<string, Usuario *> > *a) const
{
    int numElem;
    
    if(!aUsuarios->estaVacio()){
        aUsuarios->getDato().getValue()->mostrar();
        numElem++;
        
        if(aUsuarios->getIzq() != nullptr){
            numElem += mostrarRec(aUsuarios->getIzq());
        }
        
        if(aUsuarios->getDer() != nullptr){
            numElem += mostrarRec(aUsuarios->getDer());
        }
    }
    
    return numElem;
}

int GestorUsuarios::mostrarRecCont(BSTree<KeyValue<string, Usuario *> > *a)
{
    int numElem = 0;
    
    if(!aUsuarios->estaVacio()){
        numElem++;
        
        if(aUsuarios->getIzq() != nullptr){
            numElem += mostrarRecCont(aUsuarios->getIzq());
        }
        
        if(aUsuarios->getDer() != nullptr){
            numElem += mostrarRecCont(aUsuarios->getDer());
        }
    }
    
    return numElem;
}

void GestorUsuarios::mostrar(){
    std::cout << "El número de elementos total es: " << mostrarRec(this->aUsuarios) << endl;
}

BSTree<KeyValue<string,Usuario*>>* GestorUsuarios::buscarR(const std::string DNI, BSTree<KeyValue<string,Usuario*>>* aux){
    BSTree<KeyValue<string,Usuario*>>* ret = nullptr;
    if(aux != nullptr){
        if(aux->getDato().getKey() == DNI)
            ret = aux;
        else if(aux->getDato().getKey() > DNI)
            ret = buscarR(DNI, aux->getIzq());
        else
            ret = buscarR(DNI, aux->getDer());
    }
    return ret;
}
Usuario* GestorUsuarios::buscar(const std::string DNI){
    Usuario* ret = nullptr;
    if(!aUsuarios->estaVacio()){
        BSTree<KeyValue<string,Usuario*>>* aux = aUsuarios;
        ret = buscarR(DNI, aux)->getDato().getValue();
    }
    return ret;
}

const int GestorUsuarios::numElementos()
{
    return num;
}

//Creo que no hay otra que buscar el DNI dos veces (sin romper encapsulación),
//  una es porque es composición y otra porque en la template de BSTree no hay una función para borrar desde el nodo ya encontrado (y creo que llamar eliminar sobre ese nodo dejaría un dangling pointer)
void GestorUsuarios::eliminarUsuario(const std::string DNI){
    if(!aUsuarios->estaVacio()){
        BSTree<KeyValue<string,Usuario*>>* aux = aUsuarios;
        BSTree<KeyValue<string,Usuario*>>* H = buscarR(DNI, aux);
        if(H != nullptr){
            delete H->getDato().getValue();//composición
            aUsuarios->eliminar(DNI);
        }
    }
}
#endif
