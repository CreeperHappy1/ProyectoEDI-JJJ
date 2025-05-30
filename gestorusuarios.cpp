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
    if(!lUsuarios->estaVacia()){
        lUsuarios->moverPrimero();
        while (!lUsuarios->alFinal() && DNI != lUsuarios->consultar()->getDNI())
            lUsuarios->avanzar();
        if(!lUsuarios->alFinal()){
            delete lUsuarios->consultar();
            lUsuarios->eliminar();
        }
    }
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
GestorUsuarios::GestorUsuarios(){
    aUsuarios = new BSTree<KeyValue<string,Usuario*>>();
    num = 0;
}

GestorUsuarios::GestorUsuarios(GestorUsuarios const& other){
    num = other.num;
    copiarArbol(other.aUsuarios);
}

void GestorUsuarios::insertar(const string &apellidoNombre, const string &telefono, int edad, const string numeroCuenta, const float saldo, const string DNI, const string email){
    aUsuarios->insertar(KeyValue<string,Usuario*>(DNI, new Usuario(apellidoNombre, telefono, edad, numeroCuenta, saldo, DNI, email)));
    num++;
}

void GestorUsuarios::copiarArbol(BSTree<KeyValue<string, Usuario *> > *otroArbol)
{
    KeyValue<string, Usuario*> par;
    Usuario *u = nullptr;
    if(!otroArbol->estaVacio()){
        par = otroArbol->getDato();
        Usuario *u = par.getValue();
        KeyValue<string, Usuario*> parCopia(par.getKey(), u);
        aUsuarios->insertar(parCopia);
        
        if(otroArbol->getIzq() != nullptr){
            copiarArbol(otroArbol->getIzq());
        }
        
        if(otroArbol->getDer() != nullptr){
            copiarArbol(otroArbol->getDer());
        }
    }
}

void GestorUsuarios::mostrarRec(BSTree<KeyValue<string, Usuario *> > *a) const
{
    if(!aUsuarios->estaVacio()){
        
        if(aUsuarios->getIzq() != nullptr){
            mostrarRec(aUsuarios->getIzq());
        }
        
        if(aUsuarios->getDer() != nullptr){
            mostrarRec(aUsuarios->getDer());
        }
        
        aUsuarios->getDato().getValue()->mostrar();
    }
    return;
}

void GestorUsuarios::mostrar(){
    mostrarRec(this->aUsuarios);
    std::cout << "El número de elementos total es: " << this->num << endl;
}

Usuario* GestorUsuarios::buscarR(const std::string DNI, BSTree<KeyValue<string,Usuario*>>* aux){
    Usuario* ret = nullptr;
    if(aux != nullptr){
        if(aux->getDato().getKey() == DNI)
            ret = aux->getDato().getValue();
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
        ret = buscarR(DNI, aux);
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
        Usuario* H = buscarR(DNI, aux);
        if(H != nullptr){//se ha encontrado
            delete H;//composición
            aUsuarios->eliminar(DNI);
            num--;
        }
    }
}

void GestorUsuarios::destructorR(BSTree<KeyValue<string, Usuario *> > *a)
{
    if(a->getIzq() != nullptr){
        destructorR(aUsuarios->getIzq());
    }
    
    if(a->getDer() != nullptr){
        destructorR(aUsuarios->getDer());
    }
    
    Usuario *aux = a->getDato().getValue();
    
    delete aux;
}

GestorUsuarios::~GestorUsuarios()
{
    destructorR(aUsuarios);
    delete aUsuarios;
}
#endif
