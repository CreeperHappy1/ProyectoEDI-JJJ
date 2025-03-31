#include "pruebas/pruebas.h"
#include "pruebas/pruebasEstacion.h"
#include <iostream>
#include <fstream>
#include "Usuario.h"

const int TAM = 255;
typedef Usuario* TVector[TAM]; //Why the hell would you do this

void leerFichero1(){
    std::string linea;
    std::ifstream fEnt;
    fEnt.open("usuarios.csv");
    if(fEnt.is_open()){
        if(!fEnt.eof())
            getline(fEnt, linea);
        for(int i = 1; !fEnt.eof(); i++){
            getline(fEnt, linea);
            std::cout << i << ": " << linea << std::endl;
        }
        //std::cout << "closing line\n";
        //std::flush(std::cout);
        fEnt.close();
    }else
        std::cerr << "No se pudo abrir \"usuarios.csv\"\n";
}

void leerFichero2(TVector & v){
    std::string in[7];
    std::ifstream fEnt;
    fEnt.open("usuarios.csv");
    if(fEnt.is_open()){
        if(!fEnt.eof())
            getline(fEnt, in[0]);
        int cont = 0;
        while(!fEnt.eof()){
            cont++;
            for(int i = 0; i < 6; i++)
                getline(fEnt, in[i], ';');//NOTE: aquí seguirá leyendo aunque la línea sea inválida
            if(in[0] != ""){
                getline(fEnt, in[6]);
                v[cont-1] = new Usuario(in[0], in[3], std::stoi(in[4]), in[5], std::stof(in[6]), in[1], in[2]);
            }
        }
        //std::cout << "closing line\n";
        //std::flush(std::cout);
        fEnt.close();
    }else
        std::cerr << "No se pudo abrir \"usuarios.csv\"\n";
}

void mostrarTVector(TVector const& v){
    for(int i = 0; i < TAM; i++)
        if(v[i] != nullptr){
            std::cout << i+1 << ": ";
            v[i]->mostrar();
        }
}

void crearFichero(TVector const& v, std::string const& outputName){//se recomienda que outputName acabe en ".csv"
    std::ofstream out;
    /*if(!outputName.ends_with(".csv"))//ends_with is only included from C++20 onwards
        outputName.append(".csv");*/
    out.open(outputName, std::ios::trunc);
    if(out.is_open()){
        out << "NOMBRE COMPLETO;DNI;CORREO;TELÉFONO;EDAD;N.CUENTA;SALDO\n";
        for(int i = 0; i < TAM; i++)
            if(v[i] != nullptr)
                out << v[i]->getNombre() << ';' << v[i]->getDNI() << ';' << v[i]->getEmail() << ';' << v[i]->getTelefono() << ';' << v[i]->getEdad() << ';' << v[i]->getNumeroCuenta() << ';' << v[i]->getSaldo() << std::endl;
        out.close();
    }else
        std::cerr << "Failed to create \"" << outputName << "\"\n";
}

void crearFicheroFiltrado(TVector const& v, std::string const& outputName, const int edad){//se recomienda que outputName acabe en ".csv"
    std::ofstream out;
    /*if(!outputName.ends_with(".csv"))//ends_with is only included from C++20 onwards
        outputName.append(".csv");*/
    out.open(outputName, std::ios::trunc);
    if(out.is_open()){
        out << "NOMBRE COMPLETO;DNI;CORREO;TELÉFONO;EDAD;N.CUENTA;SALDO\n";
        for(int i = 0; i < TAM; i++)
            if(v[i] != nullptr && v[i]->getEdad() >= edad)
                out << v[i]->getNombre() << ';' << v[i]->getDNI() << ';' << v[i]->getEmail() << ';' << v[i]->getTelefono() << ';' << v[i]->getEdad() << ';' << v[i]->getNumeroCuenta() << ';' << v[i]->getSaldo() << std::endl;
        out.close();
    }else
        std::cerr << "Failed to create \"" << outputName << "\"\n";
}

//Actually only works if the number of lines is less than TAM
void mostrarFicheroInverso(std::string const& inName){//Not gonna be using recursive functions, like wth
    //ojala haber dado las listas para poner aquí una lista, ya que no necesitamos random access en absoluto, de hecho con una reverse_list bastaría
    //bastante molesto no poder usar cosas no dadas, aunque seguro
    std::string buffer[TAM];
    int occ = 0;
    std::ifstream in;
    in.open(inName);
    if(in.is_open()){
        for(; occ < TAM && !in.eof(); occ++)
            getline(in, buffer[occ]);
        for(int i = 0; i < occ; i++)
            std::cout << occ-i << ": " << buffer[occ-i-1] << std::endl;
        in.close();
    }else
        std::cerr << "Error opening \"" << inName << "\"\n";
}

void mfiRint(std::ifstream &instream){
    if(instream.eof())
        return;
    else{
        std::string h;
        getline(instream, h);
        mfiRint(instream);
        std::cout << h << std::endl;
    }
}

void mostrarFicheroInversoR(std::string const& inName){
    std::ifstream in;
    in.open(inName);
    if(in.is_open()){
        mfiRint(in);
        in.close();
    }else
        std::cerr << "Error opening \"" << inName << "\"\n";
}

/*void checkV(){//Soo, apparently I have C++17 installed, wild tbh
    if (__cplusplus == 202101L) std::cout << "C++23";
    else if (__cplusplus == 202002L) std::cout << "C++20";
    else if (__cplusplus == 201703L) std::cout << "C++17";
    else if (__cplusplus == 201402L) std::cout << "C++14";
    else if (__cplusplus == 201103L) std::cout << "C++11";
    else if (__cplusplus == 199711L) std::cout << "C++98";
    else std::cout << "pre-standard C++." << __cplusplus;
    std::cout << "\n";
}*/



int main()
{
    /*//checkV();
    //pruebas();
    //leerFichero1();
    TVector v;
    for(int i = 0; i < TAM; i++)
        v[i] = nullptr;
    
    leerFichero2(v);
    //mostrarTVector(v);
    //crearFichero(v, "out.csv");
    crearFicheroFiltrado(v, "out.csv", 20);
    //mostrarFicheroInverso("usuarios.csv");
    //mostrarFicheroInversoR("usuarios.csv");
    
    for(int i = 0; i < TAM; i++)
        if(v[i] != nullptr)
            delete v[i];*/
    //pruebasEstacion();
    pruebaPatinete();
    return 0;
}
