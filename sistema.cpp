#include "sistema.h"
#include <fstream>

void Sistema::cargarUsuarios(){
    this->usuarios = new GestorUsuarios();
    std::string in[7];
    std::ifstream fEnt;
    fEnt.open("usuarios.csv");
    if(fEnt.is_open()){
        if(!fEnt.eof())
            getline(fEnt, in[0]);
        while(!fEnt.eof()){
            for(int i = 0; i < 6; i++)
                getline(fEnt, in[i], ';');//NOTE: aquí seguirá leyendo aunque la línea sea inválida
            if(in[0] != ""){
                getline(fEnt, in[6]);
                this->usuarios->insertar(in[0], in[3], std::stoi(in[4]), in[5], std::stof(in[6]), in[1], in[2]);
            }
        }
        fEnt.close();
    }else
        std::cerr << "No se pudo abrir \"usuarios.csv\"\n";
}

void Sistema::cargarPatinetes(){
    this->lPatinetes = new ListaDPI<Patinete *>;
    std::string in[5];
    std::ifstream fEnt;
    fEnt.open("patinetes.csv");
    if(fEnt.is_open()){
        if(!fEnt.eof())
            getline(fEnt, in[0]);
        while(!fEnt.eof()){
            for(int i = 0; i < 4; i++)
                getline(fEnt, in[i], ';');//NOTE: aquí seguirá leyendo aunque la línea sea inválida
            if(in[0] != ""){
                getline(fEnt, in[4]);
                this->lPatinetes->insertar(new Patinete(in[0], in[1], in[2], in[3] == "Si", in[4] == "Si"));
            }
        }
        fEnt.close();
    }else
        std::cerr << "No se pudo abrir \"patinetes.csv\"\n";
}


void Sistema::cargarEstaciones()
{
    this->lEstaciones = new ListaDPI<Estacion *>;
    std::string in[2];
    std::ifstream fEnt;
    fEnt.open("estaciones.csv");
    if(fEnt.is_open()){
        if(!fEnt.eof())
            getline(fEnt, in[0]);
        while(!fEnt.eof()){
            getline(fEnt, in[0], ';');
            if(in[0] != ""){
                getline(fEnt, in[1]);
                this->lEstaciones->insertar(new Estacion(in[0], in[1]));
            }
        }
        fEnt.close();
    }else
        std::cerr << "No se pudo abrir \"estaciones.csv\"\n";
}

void Sistema::alquilarDevolverUnPatinete(const string &idEstOrigen, const string &DNI, const string &idEstDestino)
{
   // 1. El precio por alquilar un patinete es de 10€.
    ///esto no es un paso???
   // 2. Se debe buscar la estación de origen, si tiene patinetes disponibles y existe el
   //         usuario que lo quiere alquilar y éste tiene suficiente dinero en su cuenta
   //             UEx - Escuela Politécnica Sesión 9.1
   //     ESTRUCTURAS DE DATOS Y DE LA INFORMACIÓN
   //         bancaria, el patinete es alquilado, se saca de la cola de disponibles de la
   //     estación y se procede al cobro del alquiler al usuario. Es recomendable crear
   //         un nuevo método en la Estacion para alquilar un patinete.
    Usuario* user = usuarios->buscar(DNI);
   Estacion* origen = buscarEstacion();
   // 3. Si la estación de origen, no existe o no tiene patinetes disponibles, se muestra
   //     un mensaje de error en la pantalla.
   // 4. Si el usuario no existe o no tiene suficiente dinero, se muestra un mensaje de
   //     error en la pantalla.
   // 5. Continuando con el punto 2, se simula el proceso para devolver el patinete.
   // Para ello, se debe buscar la estación de destino, poner el patinete como
   //     disponible y agregarlo en la estación de destino.
   // 6. La estación de destino no existe: Si la estación de destino no existe suponemos
   //     que el patinete no se devuelve, se debe mostrar en pantalla el identificador del
   //     patinete, el nombre completo y dni del usuario que lo alquiló y se procede a
   //     sancionar con 110€ a este usuario, pero si no tiene suficiente saldo será
   //     expulsado del Sistema, eliminándolo de la lista de usuarios del GestorUsuarios.
   // Estos datos se deben mostrar en la pantalla.
}

Sistema::Sistema(){
    nombreSistema = "";
    //asumo que aunque sea por defecto tendrá que cargar los usuarios
    cargarUsuarios();
    cargarPatinetes();
    cargarEstaciones();
}

Sistema::Sistema(string nombreSistema) : nombreSistema(nombreSistema) {
    cargarUsuarios();
    cargarPatinetes();
    cargarEstaciones();    
}

Sistema::Sistema(const Sistema &other){
    this->nombreSistema = other.nombreSistema;
    usuarios = new GestorUsuarios(*other.usuarios);
    lPatinetes = new ListaDPI<Patinete*>();
    for(other.lPatinetes->moverPrimero(); !other.lPatinetes->alFinal(); other.lPatinetes->avanzar())
        lPatinetes->insertar(new Patinete(*other.lPatinetes->consultar()));//composición
    lEstaciones = new ListaDPI<Estacion *>();
    for(other.lEstaciones->moverPrimero(); !other.lEstaciones->alFinal(); other.lEstaciones->avanzar())
        lEstaciones->insertar(new Estacion(*other.lEstaciones->consultar()));//composición
}

void Sistema::mostrarUsuarios(){
    std::cout << "Número de usuarios: " << usuarios->numElementos() << std::endl;
    usuarios->mostrar();
}

string Sistema::buscarUsuario(const string DNI)
{
    std::string ret = "";
    Usuario* aux = usuarios->buscar(DNI);
    if(aux != nullptr)
        ret = aux->pasarACadena();
    return ret;
}

void Sistema::insertarPatinete(const std::string identificador, const std::string marca, const std::string modelo, const bool averiado, const bool disponible){
    //Criterio arbitrario actual: insertar al final
    lPatinetes->moverUltimo();
    lPatinetes->avanzar();
    
    lPatinetes->insertar(new Patinete(identificador, marca, modelo, averiado, disponible));//construcción emplace
}

void Sistema::mostrarPatinetes(){
    int i = 0;
    for(lPatinetes->moverPrimero(); !lPatinetes->alFinal(); lPatinetes->avanzar(), i++)
        lPatinetes->consultar()->mostrar();
    std::cout << "Número de patinetes: " << i << std::endl;
}

Patinete* Sistema::buscarPatinete(const string identificador)
{
    lPatinetes->moverPrimero();
    while (!lPatinetes->alFinal() && identificador != lPatinetes->consultar()->getIdentificador())
        lPatinetes->avanzar();
    if(lPatinetes->alFinal())
        return nullptr;//WARNING: [issue#3] no le gusta a los profes
    return lPatinetes->consultar();
}

void Sistema::insertarEstacion(std::string identificador, std::string direccion){
    //Criterio arbitrario actual: insertar al final
    lEstaciones->moverUltimo();
    lEstaciones->avanzar();
    
    lEstaciones->insertar(new Estacion(identificador, direccion));//construcción emplace
}

void Sistema::mostrarEstaciones(){
    int i = 0;
    for(lEstaciones->moverPrimero(); !lEstaciones->alFinal(); lEstaciones->avanzar(), i++)
        lEstaciones->consultar()->mostrar();
    std::cout << "Número de estaciones: " << i << std::endl;
}

Estacion* Sistema::buscarEstacion(const string identificador)
{
    lEstaciones->moverPrimero();
    while (!lEstaciones->alFinal() && identificador != lEstaciones->consultar()->getIdentificador())
        lEstaciones->avanzar();
    if(lEstaciones->alFinal())
        return nullptr;//WARNING: [issue#3] no le gusta a los profes
    return lEstaciones->consultar();
}

Sistema::~Sistema(){
    delete usuarios;
    lPatinetes->moverPrimero();
    while(!lPatinetes->estaVacia()){
        delete lPatinetes->consultar();
        lPatinetes->eliminar();//en vez de llamar el destructor y tener que iterar otra vez por todos los elementos borramos cada nodo tras cada elemento
    }
    delete lPatinetes;
    lEstaciones->moverPrimero();
    while(!lEstaciones->alFinal()){
        delete lEstaciones->consultar();
        lEstaciones->eliminar();
    }
    delete lEstaciones;
}
