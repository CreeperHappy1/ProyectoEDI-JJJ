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

void Sistema::distribuirPatinetesEnEstaciones()
{
    std::string in[2];
    std::ifstream fEnt;
    
    Patinete *paux;
    Estacion *eaux;
        
    fEnt.open("distribucionPatinetes.csv");
    if(fEnt.is_open()){
        if(!fEnt.eof())
            getline(fEnt, in[0]);
        while(!fEnt.eof()){
            getline(fEnt, in[0], ';');
            paux = this->buscarPatinete(in[0]);
            if(paux != nullptr){
                getline(fEnt, in[1]);
                eaux = this->buscarEstacion(in[1]);
                eaux->agregarPatinete(paux);
            }
        }
        fEnt.close();
    }else
        std::cerr << "No se pudo abrir \"distribucionPatinetes.csv\"\n";
}

void Sistema::alquilarDevolverUnPatinete(const string &idEstOrigen, const string &DNI, const string &idEstDestino)
{
    Usuario* user = usuarios->buscar(DNI);
    Estacion* origen = buscarEstacion(idEstOrigen);
    if(origen != nullptr && origen->getNumDisponibles() > 0){
        if(user != nullptr && user->getSaldo() >= 10){
            //se simula alquilar un patinete:
            user->ingresar(-10);
            Patinete* pat = origen->alquilarPatinete();
            std::cout << user->getNombre() << " alquila el patinete " << pat->getIdentificador() << " de la estación " << idEstOrigen << " por 10€\n";
            //se simula devolver el patinete:
            Estacion* destino = buscarEstacion(idEstDestino);
            if(destino != nullptr){
                pat->setDisponible(true);
                destino->agregarPatinete(pat);
                std::cout << "Se devuelve el patinete " << pat->getIdentificador() << " a la estación " << idEstDestino << std::endl;
            }else{//suponemos que no se ha devuelto
                std::cout << "No se ha devuelto el patinete " << pat->getIdentificador() << ", alquilado por " << user->getNombre() << ", " << user->getDNI();
                if(user->getSaldo() >= 110){
                    user->ingresar(-110);
                    std::cout << " -> se le cobran 110€ de sanción\n";
                }else{
                    usuarios->eliminarUsuario(DNI);
                    std::cout << " -> se elimina al usuario del sistema por falta de fondos para pagar las sanción\n";
                }
            }
        }else
            std::cerr << "ERROR: (alquilarDevolverUnPatinete) el usuario no existe o no tiene suficiente dinero\n";
    }else
        std::cerr << "ERROR: (alquilarDevolverUnPatinete) la estación de origen " + idEstOrigen + " no existe o no tiene patinetes disonibles\n";
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
    else
        ret = "No se encontro un usuario con ese DNI";
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

Patinete* Sistema::buscarPatinete(const string identificador){
    Patinete* ret = nullptr;
    lPatinetes->moverPrimero();
    while (!lPatinetes->alFinal() && identificador != lPatinetes->consultar()->getIdentificador())
        lPatinetes->avanzar();
    if(!lPatinetes->alFinal())
        ret = lPatinetes->consultar();
    return ret;
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

Estacion* Sistema::buscarEstacion(const string identificador){
    Estacion* ret = nullptr;
    lEstaciones->moverPrimero();
    while (!lEstaciones->alFinal() && identificador != lEstaciones->consultar()->getIdentificador())
        lEstaciones->avanzar();
    if(!lEstaciones->alFinal())
        ret = lEstaciones->consultar();
    return ret;
}

void Sistema::agregarPatineteEnEstacion(string identificadorP, string identificadorE)
{
    Patinete *paux = this->buscarPatinete(identificadorP);
    Estacion *eaux = this->buscarEstacion(identificadorE);
    
    eaux->agregarPatinete(paux);
}

int Sistema::repararPatinetesEstacion(string const identificadorE)
{
    Estacion *eaux = this->buscarEstacion(identificadorE);
    
    int averiadas = eaux->getNumAveriadas();
    
    while(eaux->getNumAveriadas() > 0){
        eaux->arreglarPatinete();
    }
    
    return averiadas;
}

void Sistema::buscarUsuarioDNI()
{
    std::string DNIaux;
    cin >> DNIaux;
    cout << buscarUsuario(DNIaux) << endl;
}

void Sistema::buscarEstacionID()
{
    std::string idaux;
    cin >> idaux;
    Estacion* aux = buscarEstacion(idaux);
    if(aux == nullptr)
        cout << "No se encontró una estación con ese id\n";
    else
        buscarEstacion(idaux)->mostrar();
}

void Sistema::buscarPatinetesExtraviados()
{
    Patinete *paux;
    
    lPatinetes->moverPrimero();
    
    bool enc = false;
    
    while(!lPatinetes->alFinal()){
        lEstaciones->moverPrimero();
        
        while(!lEstaciones->alFinal() && !enc){
            paux = this->buscarPatinete(lEstaciones->consultar()->getIdentificador());
            
            if(paux != nullptr){
                enc = true;
            }
        }
        
        if(!enc){
            lPatinetes->consultar()->mostrar();
            lPatinetes->consultar()->getUsuarioActual()->mostrar();
            paux = lPatinetes->consultar();
            lPatinetes->eliminar();
            delete paux;
        }else{
            lPatinetes->avanzar();
        }
    }
}

void Sistema::estacionConMasPatinetes()
{
    lEstaciones->moverPrimero();
    Estacion *aux = lEstaciones->consultar();
    
    lEstaciones->avanzar();
        
    while (!lEstaciones->alFinal()){
        if (lEstaciones->consultar()->getNumAlquilados() > aux->getNumAlquilados()){
            aux = lEstaciones->consultar();
        }
        
        lEstaciones->avanzar();
    }
    
    aux->mostrar();
}

void Sistema::arreglarPatinetesEstacion()
{
    std::string idaux;
    cin >> idaux;
    Estacion *s = buscarEstacion(idaux);
    
    if(s == nullptr)
        cout << "No se encontró una estación con ese id\n";
    else
        while(s->getNumAveriadas() > 0){
            s->arreglarPatinete();
        }
}

void Sistema::cerrarSistema()
{
    ListaDPI <Usuario *> *lUsuarios;
    int cont;
    std::ofstream fEnt;
    fEnt.open("usuarios.csv");
    if(fEnt.is_open()){
        fEnt << "NOMBRE COMPLETO;DNI;CORREO;TELÉFONO;EDAD;N.CUENTA;SALDO" << endl;
        
        for(int i = 0; i < this->usuarios->numElementos(); i++){
            
        }
        
        fEnt.close();
    }else
        std::cerr << "No se pudo abrir \"usuarios.csv\"\n";
}

void Sistema::alquilarDevolverPatinetes(){
    std::string in[3];
    std::ifstream fEnt;
    fEnt.open("alquilerPatinetes.csv");
    if(fEnt.is_open()){
        if(!fEnt.eof())
            getline(fEnt, in[0]);//saltamos la primera línea
        while(!fEnt.eof()){
            getline(fEnt, in[0], ';');
            if(in[0] != ""){
                getline(fEnt, in[1], ';');
                getline(fEnt, in[2]);
                alquilarDevolverUnPatinete(in[0], in[1], in[2]);
            }
        }
        fEnt.close();
    }else
        std::cerr << "No se pudo abrir \"alquilerPatinetes.csv\"\n";
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
