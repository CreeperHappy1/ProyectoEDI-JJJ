#include "PruebaGestorUsuarios.h"
#include "../gestorusuarios.h"

///Define la flag de precompilación ARBOLYPUBLICADOS para activar las pruebas de los métodos privados de GestorUsuarios (Si usas CMake sólo es descomentar una línea)
#ifdef ARBOLYPUBLICADOS
#ifndef LISTA
///Módulos privados
void pruebaCopiarArbol(){
    cout << "Iniciando pruebas de copiarArbol()...\n";
    BSTree<KeyValue<string, Usuario*>>* original = new BSTree<KeyValue<string, Usuario*>>();
    GestorUsuarios* g1 = new GestorUsuarios();
    Usuario* usuarios[4];
    for(int i = 0; i < 4; i++){
        string aux = to_string(i);
        usuarios[0] = new Usuario("nombre" + aux, "telefono" + aux, i, "cuenta" + aux, -i, "DNI" + aux, "email" + aux);
        original->insertar(KeyValue<string,Usuario*>(usuarios[i]->getDNI(), usuarios[i]));
    }
    
    g1->copiarArbol(original);//esto llevará a un estado inválido realmente, por eso el método es privado xd
    cout << "Se deberían mostrar 4 usuarios\n";
    g1->mostrar();
    
    Usuario* aux;
    for(Usuario* U : usuarios){
        aux = g1->buscar(U->getDNI());
        if(aux == nullptr)
            cerr << "ERROR: No se encontró el usuario copiado" << aux->getDNI() <<"!\n";
        if(aux == U)
            cerr << "ERROR: La copia apunta a la misma dirección que el original!\n";
        if(aux->getNombre() != U->getNombre())
            cerr << "ERROR: se encontró el usuario copiado pero su nombre no coincide! Es \"" << aux->getNombre() << "\" en vez de \"" << U->getNombre() << "\"\n"; 
        if(aux->getTelefono() != U->getTelefono())
            cerr << "ERROR: se encontró el usuario copiado pero su telefono no coincide! Es \"" << aux->getTelefono() << "\" en vez de \""<< U->getTelefono() << "\"\n"; 
        if(aux->getEdad() != U->getEdad())
            cerr << "ERROR: se encontró el usuario copiado pero su edad no coincide! Es " << aux->getEdad() << " en vez de " << U->getEdad() << endl; 
        if(aux->getNumeroCuenta() != U->getNumeroCuenta())
            cerr << "ERROR: se encontró el usuario copiado pero su número de cuenta no coincide! Es \"" << aux->getNumeroCuenta() << "\" en vez de \"" << U->getNumeroCuenta() << "\"\n"; 
        if(aux->getSaldo() != U->getSaldo())
            cerr << "ERROR: se encontró el usuario copiado pero su saldo no coincide! Es " << aux->getSaldo() << " en vez de " << U->getSaldo() << "\n"; 
        if(aux->getDNI() != U->getDNI())
            cerr << "ERROR: se encontró el usuario copiado pero su DNI no coincide! Es \"" << aux->getDNI() << "\" en vez de \"" << U->getDNI() << "\"\n"; 
        if(aux->getEmail() != U->getEmail())
            cerr << "ERROR: se encontró el usuario copiado pero su email no coincide! Es \"" << aux->getEmail() << "\" en vez de \"" << U->getEmail() << "\"\n"; 
    }
    
    for(Usuario* U : usuarios)
        delete U;
    delete original;
    delete g1;
    cout << "Pruebas de copiarArbol() finalizadas\n";
}

void pruebaBuscarR(){
    cout << "Iniciando pruebas de buscarR()...\n";
    
    GestorUsuarios *g1 = new GestorUsuarios();
    BSTree<KeyValue<string, Usuario*>>* arbol = new BSTree<KeyValue<string, Usuario*>>();
    BSTree<KeyValue<string, Usuario*>>* aux;//lo usaremos para el segundo argumento de buscarR
    Usuario* H;//lo utilizaremos como un auxiliar hold para guardar temporalmente usuarios encontrados
    Usuario* usuarios[4];
    for(int i = 0; i < 4; i++){
        string aux = to_string(i);
        usuarios[0] = new Usuario("nombre" + aux, "telefono" + aux, i, "cuenta" + aux, -i, "DNI" + aux, "email" + aux);
        arbol->insertar(KeyValue<string,Usuario*>(usuarios[i]->getDNI(), usuarios[i]));
    }
    
    //Caso 1: se busca cualquier usuario en el gestor vacío
    aux = arbol;
    if(g1->buscarR("", aux) != nullptr)
        cerr << "ERROR: buscar() no devuelve nullptr a pesar de que el gestor debería estar vacío!\n";
    
    arbol->insertar(KeyValue<string,Usuario*>(usuarios[0]->getDNI(),usuarios[0]));
    
    //Caso 2: se busca un usuario siendo este el único
    aux = arbol;
    H = g1->buscarR(usuarios[0]->getDNI(), aux);
    if(H == nullptr)
        cerr << "ERROR: se buscó un usuario añadido pero no se encontró! (1 usuario en el gestor)\n";
    if(H->getNombre() != usuarios[0]->getNombre())
        cerr << "ERROR: se encontró el único usuario pero su nombre no coincide! Es \"" << H->getNombre() << "\" en vez de \"" << usuarios[0]->getNombre() << "\"\n"; 
    if(H->getTelefono() != usuarios[0]->getTelefono())
        cerr << "ERROR: se encontró el único usuario pero su telefono no coincide! Es \"" << H->getTelefono() << "\" en vez de \"" << usuarios[0]->getTelefono() << "\"\n"; 
    if(H->getEdad() != usuarios[0]->getEdad())
        cerr << "ERROR: se encontró el único usuario pero su edad no coincide! Es " << H->getEdad() << " en vez de " << usuarios[0]->getEdad() << "\n"; 
    if(H->getNumeroCuenta() != usuarios[0]->getNumeroCuenta())
        cerr << "ERROR: se encontró el único usuario pero su número de cuenta no coincide! Es \"" << H->getNumeroCuenta() << "\" en vez de \"" << usuarios[0]->getNumeroCuenta() << "\"\n"; 
    if(H->getSaldo() != usuarios[0]->getSaldo())
        cerr << "ERROR: se encontró el único usuario pero su saldo no coincide! Es " << H->getSaldo() << " en vez de " << usuarios[0]->getSaldo() << "\n"; 
    if(H->getDNI() != usuarios[0]->getDNI())
        cerr << "ERROR: se encontró el único usuario pero su DNI no coincide! Es \"" << H->getDNI() << "\" en vez de \"" << usuarios[0]->getDNI() << "\"\n"; 
    if(H->getEmail() != usuarios[0]->getEmail())
        cerr << "ERROR: se encontró el único usuario pero su email no coincide! Es \"" << H->getEmail() << "\" en vez de \"" << usuarios[0]->getEmail() << "\"\n";
    
    //Caso 3: se busca un usuario de en medio habiendo 4
    arbol->insertar(KeyValue<string,Usuario*>(usuarios[1]->getDNI(),usuarios[1]));
    arbol->insertar(KeyValue<string,Usuario*>(usuarios[2]->getDNI(),usuarios[2]));
    arbol->insertar(KeyValue<string,Usuario*>(usuarios[3]->getDNI(),usuarios[3]));
    
    aux = arbol;
    H = g1->buscarR(usuarios[1]->getDNI(), aux);
    if(H == nullptr)
        cerr << "ERROR: se buscó un usuario añadido pero no se encontró! (4 usuario en el gestor)\n";
    if(H->getNombre() != usuarios[1]->getNombre())
        cerr << "ERROR: se encontró el segundo usuario pero su nombre no coincide! Es \"" << H->getNombre() << "\" en vez de \"" << usuarios[1]->getNombre() << "\"\n"; 
    if(H->getTelefono() != usuarios[1]->getTelefono())
        cerr << "ERROR: se encontró el segundo usuario pero su telefono no coincide! Es \"" << H->getTelefono() << "\" en vez de \"" << usuarios[1]->getTelefono() << "\"\n"; 
    if(H->getEdad() != usuarios[1]->getEdad())
        cerr << "ERROR: se encontró el segundo usuario pero su edad no coincide! Es " << H->getEdad() << " en vez de " << usuarios[1]->getEdad() << "\n"; 
    if(H->getNumeroCuenta() != usuarios[1]->getNumeroCuenta())
        cerr << "ERROR: se encontró el segundo usuario pero su número de cuenta no coincide! Es \"" << H->getNumeroCuenta() << "\" en vez de \"" << usuarios[1]->getNumeroCuenta() << "\"\n"; 
    if(H->getSaldo() != usuarios[1]->getSaldo())
        cerr << "ERROR: se encontró el segundo usuario pero su saldo no coincide! Es " << H->getSaldo() << " en vez de " << usuarios[1]->getSaldo() << "\n"; 
    if(H->getDNI() != usuarios[1]->getDNI())
        cerr << "ERROR: se encontró el segundo usuario pero su DNI no coincide! Es \"" << H->getDNI() << "\" en vez de \"" << usuarios[1]->getDNI() << "\"\n"; 
    if(H->getEmail() != usuarios[1]->getEmail())
        cerr << "ERROR: se encontró el segundo usuario pero su email no coincide! Es \"" << H->getEmail() << "\" en vez de \"" << usuarios[1]->getEmail() << "\"\n";
    
    //Caso 4: se busca el último usuario
    aux = arbol;
    H = g1->buscarR(usuarios[3]->getDNI(), aux);
    if(H == nullptr)
        cerr << "ERROR: se buscó el último usuario añadido pero no se encontró! (4 usuarios en el gestor)\n";
    if(H->getNombre() != usuarios[3]->getNombre())
        cerr << "ERROR: se encontró el último usuario pero su nombre no coincide! Es \"" << H->getNombre() << "\" en vez de \"" << usuarios[3]->getNombre() << "\"\n"; 
    if(H->getTelefono() != usuarios[3]->getTelefono())
        cerr << "ERROR: se encontró el último usuario pero su telefono no coincide! Es \"" << H->getTelefono() << "\" en vez de \"" << usuarios[3]->getTelefono() << "\"\n"; 
    if(H->getEdad() != usuarios[3]->getEdad())
        cerr << "ERROR: se encontró el último usuario pero su edad no coincide! Es " << H->getEdad() << " en vez de " << usuarios[3]->getEdad() << "\n"; 
    if(H->getNumeroCuenta() != usuarios[3]->getNumeroCuenta())
        cerr << "ERROR: se encontró el último usuario pero su número de cuenta no coincide! Es \"" << H->getNumeroCuenta() << "\" en vez de \"" << usuarios[3]->getNumeroCuenta() << "\"\n"; 
    if(H->getSaldo() != usuarios[3]->getSaldo())
        cerr << "ERROR: se encontró el último usuario pero su saldo no coincide! Es " << H->getSaldo() << " en vez de " << usuarios[3]->getSaldo() << "\n"; 
    if(H->getDNI() != usuarios[3]->getDNI())
        cerr << "ERROR: se encontró el último usuario pero su DNI no coincide! Es \"" << H->getDNI() << "\" en vez de \"" << usuarios[3]->getDNI() << "\"\n"; 
    if(H->getEmail() != usuarios[3]->getEmail())
        cerr << "ERROR: se encontró el último usuario pero su email no coincide! Es \"" << H->getEmail() << "\" en vez de \"" << usuarios[3]->getEmail() << "\"\n";
    
    //Caso 5: se busca un usuario que no está en el gestor
    aux = arbol;
    H = g1->buscarR("NOTADNI", aux);
    if(H != nullptr){
        cerr << "ERROR: se buscó un usuario que no existe pero se encontró! (4 usuarios en el gestor) Usuario encontrado:\n";
        H->mostrar();
    }
    
    for(Usuario* U : usuarios)
        delete U;    
    delete arbol;
    delete g1;
    
    cout << "Pruebas de buscarR() finalizadas\n";
    
}

void pruebaDestructorR(){
    cout << "Iniciando pruebas de destructorR()...\n";
    
    BSTree<KeyValue<string, Usuario*>>* arbol = new BSTree<KeyValue<string, Usuario*>>();
    GestorUsuarios* g1 = new GestorUsuarios();
    for(int i = 0; i < 4; i++){
        string aux = to_string(i);
        arbol->insertar(KeyValue<string,Usuario*>("DNI" + aux, new Usuario("nombre" + aux, "telefono" + aux, i, "cuenta" + aux, -i, "DNI" + aux, "email" + aux)));
    }
    
    g1->destructorR(arbol);
    if(!arbol->estaVacio())
        cerr << "ERROR: Tras llamar destructorR() el árbol no está vacío!\n";
    
    //no hace falta borrar los usuarios o el árbol ya que destructorR() ya debería haberlos borrado
    delete g1;
}

#endif //-LISTA
#endif //ARBOLYPUBLICADOS

void pruebasConstructores()
{
    cout << "Iniciando pruebas de los constructores...\n";
    
    GestorUsuarios *g1 = new GestorUsuarios();
    
    g1->insertar("SanchezGilJorge", "809", 37, "52", -3, "909087A", "SanchezGilJorge@alumnos.unex.es");
    
    GestorUsuarios *g2 = new GestorUsuarios(*g1);
    //añadimos otro a la copia para comprobar que se haya inicializado propiamente y que no comparta datos con el original (composición)
    g2->insertar("Nombre2", "404", 17, "90", 122.314, "DNINUMERO2", "nombre@dominio.terminación");
    
    cout << "\tSe debería mostrar un usuario en el gestor con los datos \"SanchezGilJorge - 809 - 37 - C(52, -3) - 909087A - SanchezGilJorge@alumnos.unex.es\"\n";
    g1->mostrar();
    
    cout << "\tSe debería mostrar junto al usuario anterior el usuario \"Nombre2 - 404 - 17 - C(90, 122.314) - DNINUMERO2 - nombre@dominio.terminación\"\n";
    g2->mostrar();
    
    delete g1;
    delete g2;
    
    cout << "Pruebas de constructores finalizadas\n";
}

void pruebaInsertar()
{
    cout << "Iniciando pruebas de insertar()...\n";
    
    GestorUsuarios *g1 = new GestorUsuarios();
    
    g1->insertar("SanchezGilJorge", "809", 37, "52", -3, "909087A", "SanchezGilJorge@alumnos.unex.es");
    
    cout << "\tSe debería mostrar un usuario en el gestor con los datos \"SanchezGilJorge - 809 - 37 - C(52, -3) - 909087A - SanchezGilJorge@alumnos.unex.es\"\n";
    g1->mostrar();
    
    g1->insertar("", "", 0, "", 0, "909087A", "");//insertar no debería insertar si existe un usuario con el mismo DNI
    cout << "\tSólo se debería mostrar el mismo usuario anterior (y no otro vacío salvo por el mismo DNI)\n";
    g1->mostrar();
    
    g1->insertar("Nombre2", "404", 17, "90", 122.314, "DNINUMERO2", "nombre@dominio.terminación");
    cout << "\tSe debería mostrar junto al usuario anterior el usuario \"Nombre2 - 404 - 17 - C(90, 122.314) - DNINUMERO2 - nombre@dominio.terminación\"\n";
    g1->mostrar();
    
    delete g1;
    
    cout << "Pruebas de insertar() finalizadas\n";
}

void pruebaEliminarUsuario(){
    cout << "Iniciando pruebas de eliminarUsuario()...\n";
    
    GestorUsuarios *g1 = new GestorUsuarios();
    
    //caso 1: borrar con sólo un elemento
    g1->insertar("SanchezGilJorge", "809", 37, "52", -3, "909087A", "SanchezGilJorge@alumnos.unex.es");
    g1->eliminarUsuario("909087A");
    
    cout << "\tNo se debería mostrar ningún usuario dentro del gestor:\n";
    g1->mostrar();
    
    //caso 2: probamos a eliminar uno de tres usuarios
    g1->insertar("SanchezGilJorge", "809", 37, "52", -3, "909087A", "SanchezGilJorge@alumnos.unex.es");
    g1->insertar("Nombre2", "404", 17, "90", 122.314, "DNINUMERO2", "nombre@dominio.terminación");
    g1->insertar("Nombre3", "403", 13, "93", 122.313, "DNINUMERO3", "nombre@dominio.terminació3");
    g1->eliminarUsuario("DNINUMERO3");
    
    cout << "\tSe deberían mostrar dos usuarios, uno con datos \"Nombre2 - 404 - 17 - C(90, 122.314) - DNINUMERO2 - nombre@dominio.terminación\" y otro con datos \"SanchezGilJorge - 809 - 37 - C(52, -3) - 909087A - SanchezGilJorge@alumnos.unex.es\"\n";
    g1->mostrar();
    
    delete g1;
    
    cout << "Pruebas de eliminarUsuario() finalizadas\n";
}

void pruebaBuscar()
{
    cout << "Iniciando pruebas de buscar()...\n";
    
    GestorUsuarios *g1 = new GestorUsuarios();
    Usuario* aux;//lo utilizaremos como un auxiliar hold para guardar temporalmente usuarios encontrados
    
    //Caso 1: se busca cualquier usuario en el gestor vacío
    if(g1->buscar("") != nullptr)
        cerr << "ERROR: buscar() no devuelve nullptr a pesar de que el gestor debería estar vacío!\n";
    
    g1->insertar("SanchezGilJorge", "809", 37, "52", -3, "909087A", "SanchezGilJorge@alumnos.unex.es");
    
    //Caso 2: se busca un usuario siendo este el único
    aux = g1->buscar("909087A");
    if(aux == nullptr)
        cerr << "ERROR: se buscó un usuario añadido pero no se encontró! (1 usuario en el gestor)\n";
    if(aux->getNombre() != "SanchezGilJorge")
        cerr << "ERROR: se encontró el único usuario pero su nombre no coincide! Es \"" << aux->getNombre() << "\" en vez de \"SanchezGilJorge\"\n"; 
    if(aux->getTelefono() != "809")
        cerr << "ERROR: se encontró el único usuario pero su telefono no coincide! Es \"" << aux->getTelefono() << "\" en vez de \"809\"\n"; 
    if(aux->getEdad() != 37)
        cerr << "ERROR: se encontró el único usuario pero su edad no coincide! Es " << aux->getEdad() << " en vez de 37\n"; 
    if(aux->getNumeroCuenta() != "52")
        cerr << "ERROR: se encontró el único usuario pero su número de cuenta no coincide! Es \"" << aux->getNumeroCuenta() << "\" en vez de \"52\"\n"; 
    if(aux->getSaldo() != -3)
        cerr << "ERROR: se encontró el único usuario pero su saldo no coincide! Es " << aux->getSaldo() << " en vez de -3\n"; 
    if(aux->getDNI() != "909087A")
        cerr << "ERROR: se encontró el único usuario pero su DNI no coincide! Es \"" << aux->getDNI() << "\" en vez de \"909087A\"\n"; 
    if(aux->getEmail() != "SanchezGilJorge@alumnos.unex.es")
        cerr << "ERROR: se encontró el único usuario pero su email no coincide! Es \"" << aux->getEmail() << "\" en vez de \"SanchezGilJorge@alumnos.unex.es\"\n";
    
    //Caso 3: se busca un usuario de en medio habiendo 4
    g1->insertar("Nombre2", "404", 17, "90", 122.314, "DNINUMERO2", "nombre@dominio.terminación");
    g1->insertar("Nombre3", "403", 13, "93", 122.313, "DNINUMERO3", "nombre@dominio.terminació3");
    g1->insertar("Nombr44", "444", 44, "44", 122.344, "DNINUMER44", "nombre@dominio.terminaci44");
    aux = g1->buscar("DNINUMERO2");
    if(aux == nullptr)
        cerr << "ERROR: se buscó un usuario añadido pero no se encontró! (4 usuarios en el gestor)\n";
    if(aux->getNombre() != "Nombre2")
        cerr << "ERROR: se encontró el segundo usuario pero su nombre no coincide! Es \"" << aux->getNombre() << "\" en vez de \"Nombre2\"\n"; 
    if(aux->getTelefono() != "404")
        cerr << "ERROR: se encontró el segundo usuario pero su telefono no coincide! Es \"" << aux->getTelefono() << "\" en vez de \"404\"\n"; 
    if(aux->getEdad() != 17)
        cerr << "ERROR: se encontró el segundo usuario pero su edad no coincide! Es " << aux->getEdad() << " en vez de 17\n"; 
    if(aux->getNumeroCuenta() != "90")
        cerr << "ERROR: se encontró el segundo usuario pero su número de cuenta no coincide! Es \"" << aux->getNumeroCuenta() << "\" en vez de \"90\"\n";
    if(aux->getSaldo() != (float)122.314)
        cerr << "ERROR: se encontró el segundo usuario pero su saldo no coincide! Es " << aux->getSaldo() << " en vez de 122.314\n"; 
    if(aux->getDNI() != "DNINUMERO2")
        cerr << "ERROR: se encontró el segundo usuario pero su DNI no coincide! Es \"" << aux->getDNI() << "\" en vez de \"DNINUMERO2\"\n"; 
    if(aux->getEmail() != "nombre@dominio.terminación")
        cerr << "ERROR: se encontró el único usuario pero su email no coincide! Es \"" << aux->getEmail() << "\" en vez de \"nombre@dominio.terminación\"\n";
    
    //Caso 4: se busca el último usuario
    aux = g1->buscar("DNINUMER44");
    if(aux == nullptr)
        cerr << "ERROR: se buscó el último usuario añadido pero no se encontró! (4 usuarios en el gestor)\n";
    if(aux->getNombre() != "Nombr44")
        cerr << "ERROR: se encontró el último usuario pero su nombre no coincide! Es \"" << aux->getNombre() << "\" en vez de \"Nombr44\"\n"; 
    if(aux->getTelefono() != "444")
        cerr << "ERROR: se encontró el último usuario pero su telefono no coincide! Es \"" << aux->getTelefono() << "\" en vez de \"444\"\n"; 
    if(aux->getEdad() != 44)
        cerr << "ERROR: se encontró el último usuario pero su edad no coincide! Es " << aux->getEdad() << " en vez de 44\n"; 
    if(aux->getNumeroCuenta() != "44")
        cerr << "ERROR: se encontró el último usuario pero su número de cuenta no coincide! Es \"" << aux->getNumeroCuenta() << "\" en vez de \"44\"\n";
    if(aux->getSaldo() != (float)122.344)
        cerr << "ERROR: se encontró el último usuario pero su saldo no coincide! Es " << aux->getSaldo() << " en vez de 122.344\n"; 
    if(aux->getDNI() != "DNINUMER44")
        cerr << "ERROR: se encontró el último usuario pero su DNI no coincide! Es \"" << aux->getDNI() << "\" en vez de \"DNINUMER44\"\n"; 
    if(aux->getEmail() != "nombre@dominio.terminaci44")
        cerr << "ERROR: se encontró el único usuario pero su email no coincide! Es \"" << aux->getEmail() << "\" en vez de \"nombre@dominio.terminaci44\"\n";
    
    //Caso 5: se busca un usuario que no está en el gestor
    aux = g1->buscar("NOTADNI");
    if(aux != nullptr){
        cerr << "ERROR: se buscó un usuario que no existe pero se encontró! (4 usuarios en el gestor) Usuario encontrado:\n";
        aux->mostrar();
    }
    
    delete g1;
    
    cout << "Pruebas de buscar() finalizadas\n";
}

void pruebaNumElementos()
{
    cout << "Iniciando pruebas numElementos()...\n";
    
    GestorUsuarios *g1 = new GestorUsuarios();
    if(g1->numElementos() != 0)
        cerr << "ERROR: devuelve " << g1->numElementos() << " cuando debería devolver 0\n";
    
    g1->insertar("SanchezGilJorge", "809", 37, "52", -3, "909087A", "SanchezGilJorge@alumnos.unex.es");
    if(g1->numElementos() != 1)
        cerr << "ERROR: devuelve " << g1->numElementos() << " cuando debería devolver 1\n";
    
    g1->insertar("AzpeitiaDelPozoJorgeJuan", "546", 54, "37", 45, "850379J", "AzpeitiaDelPozoJorgeJuan@alumnos.unex.es");
    if(g1->numElementos() != 2)
        cerr << "ERROR: devuelve " << g1->numElementos() << " cuando debería devolver 2\n";
    
    g1->eliminarUsuario("850379J");
    if(g1->numElementos() != 1)
        cerr << "ERROR: devuelve " << g1->numElementos() << " tras eliminar un usuario cuando debería devolver 1\n";
    
    delete g1;
    
    cout << "Pruebas de numElementos() finalizadas\n";
}

void pruebasGestorUsuarios()
{
    cout << "Inicio de pruebas de GestorUsuarios (algunas supervisadas)" << endl;

#ifdef ARBOLYPUBLICADOS
#ifndef LISTA
    pruebaCopiarArbol();
    pruebaBuscarR();
    pruebaDestructorR();
#endif //-LISTA
#endif //ARBOLYPUBLICADOS
    pruebasConstructores();
    pruebaInsertar();
    pruebaBuscar();
    pruebaNumElementos();
    
    cout << "Fin pruebas de GestorUsuarios" << endl;
}
