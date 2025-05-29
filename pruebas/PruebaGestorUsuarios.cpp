#include "PruebaGestorUsuarios.h"
#include "../gestorusuarios.h"

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

void pruebaBuscar()
{
    cout << "Iniciando pruebas de buscar()...\n";
    
    GestorUsuarios *g1 = new GestorUsuarios();
    Usuario* aux;//lo utilizaremos como un auxiliar hold para guardar temporalmente usuarios encontrados
    
    //Caso 1: se busca cualquier usuario en el gestor vacío
    if(g1->buscar("") != nullptr)
        cerr << "ERROR: buscar() no devuelve nullptr a pesar de que el gestor debería estar vacío!\n";
    
    g1->insertar("SanchezGilJorge", "809", 37, "52", -3, "909087A", "SanchezGilJorge@alumnos.unex.es");
    
    //Caso 2: se busca un usuario siendo esté el único
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
        cerr << "ERROR: se encontró el segundo usuario pero su nombre no coincide! Es \"" << aux->getNombre() << "\" en vez de \"Nombr44\"\n"; 
    if(aux->getTelefono() != "444")
        cerr << "ERROR: se encontró el segundo usuario pero su telefono no coincide! Es \"" << aux->getTelefono() << "\" en vez de \"444\"\n"; 
    if(aux->getEdad() != 44)
        cerr << "ERROR: se encontró el segundo usuario pero su edad no coincide! Es " << aux->getEdad() << " en vez de 44\n"; 
    if(aux->getNumeroCuenta() != "44")
        cerr << "ERROR: se encontró el segundo usuario pero su número de cuenta no coincide! Es \"" << aux->getNumeroCuenta() << "\" en vez de \"44\"\n";
    if(aux->getSaldo() != (float)122.344)
        cerr << "ERROR: se encontró el segundo usuario pero su saldo no coincide! Es " << aux->getSaldo() << " en vez de 122.344\n"; 
    if(aux->getDNI() != "DNINUMER44")
        cerr << "ERROR: se encontró el segundo usuario pero su DNI no coincide! Es \"" << aux->getDNI() << "\" en vez de \"DNINUMER44\"\n"; 
    if(aux->getEmail() != "nombre@dominio.terminaci44")
        cerr << "ERROR: se encontró el único usuario pero su email no coincide! Es \"" << aux->getEmail() << "\" en vez de \"nombre@dominio.terminaci44\"\n";
    
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
    
    //Aquí faltaría el caso de eliminar, que no está implementado todavía en esta rama :/ //TODO
    
    delete g1;
    
    cout << "Pruebas de numElementos() finalizadas\n";
}

void pruebasGestorUsuarios()
{
    cout << "Inicio de pruebas de GestorUsuarios (algunas supervisadas)" << endl;
    
    pruebasConstructores();
    pruebaInsertar();
    pruebaBuscar();
    pruebaNumElementos();
    
    cout << "Fin pruebas de GestorUsuarios" << endl;
}
