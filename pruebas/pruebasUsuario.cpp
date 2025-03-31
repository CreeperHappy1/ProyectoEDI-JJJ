#include "pruebas.h"
#include "../Usuario.h"
#include <iostream>
using namespace std;

void pruebaUsuario(){
    
    cout << "INICIO PRUEBAS USUARIO" << endl;
    
    Usuario user;
    
    //Pruebas apellidosNombre
    string cad1;
    
    user.setNombre("Sánchez Gil, Jorge");
    
    //prueba supervisada
    
    cout << user.getNombre() << endl;
    
    //prueba automatica
    
    if(user.getNombre() != "Sánchez Gil, Jorge"){
        cerr << "Error en la prueba de poner apellido" << endl;
    }
    
    user.getNombre(cad1);
    cout << cad1 << endl;
    
    //Pruebas telefono
    
    string cad2;
    
    user.setTelefono("902 45 86 47");
    
    //prueba supervisada
    
    cout << user.getTelefono() << endl;
    
    //prueba automatica
    
    if(user.getTelefono() != "902 45 86 47"){
        cerr << "Error en la prueba de poner telefono" << endl;
    }
    
    user.getTelefono(cad2);
    cout << cad2 << endl;
    
    //Pruebas edad
    
    int num;
    
    user.setEdad(30);
    
    //prueba supervisada
    
    cout << user.getEdad() << endl;
    
    //prueba automatica
    
    if(user.getEdad() != 30){
        cerr << "Error en la prueba de poner edad" << endl;
    }
    
    user.getEdad(num);
    cout << num << endl;
    
    //Pruebas mostrar
    
    user.mostrar();
    
    //Pruebas pasarACadena
    
    string cad3;
    
    cad3 = user.pasarACadena();
    
    cout << cad3 << endl;
    
    //PRUEBAS CUENTA BANCARIA
    
    //Pruebas de constructores
    
    //Caso 1 constructor por defecto
    
    user.setCuentaBancaria("ES3222", 100);
    
    //Pruebas de getters
    
    //Caso 1 getNumeroCuenta
    
    cout << "El número de cuenta es: ES3222, y sale: " << user.getNumeroCuenta() << endl;
    
    //Caso 2 getSaldo
    
    cout << "El saldo de la cuenta es: 100, y es: " << user.getSaldo() << endl;
    
    //Pruebas de setters
    
    //Caso 1 setNumeroCuenta
    
    cout << "El número de cuenta es: " << user.getNumeroCuenta() << endl;
    
    user.setCuentaBancaria("HY4555", 55);
    
    cout << "El nuevo número de cuenta es, HY4555, y debería ser: " << user.getNumeroCuenta() << endl;
    
    //Caso 2 setSaldo
    
    cout << "El saldo de la cuenta es: " << user.getSaldo() << endl;
    
    user.setSaldo(200);
    
    cout << "El saldo de la cuenta es: 200, y sale: " << user.getSaldo() << endl;
    
    //Caso 3 ingresar
    
    cout << "El saldo de la cuenta es: " << user.getSaldo() << endl;
    
    user.ingresar(100);
    
    cout << "El saldo de la cuenta es: 300, y sale: " << user.getSaldo() << endl;
    
    //Caso 4 retirar
    
    cout << "El saldo de la cuenta es: " << user.getSaldo() << endl;
    
    user.ingresar(100);
    
    cout << "El saldo de la cuenta es: 200, y sale: " << user.getSaldo() << endl;
    
    //Mostrar
    
    cout << " El saldo de la cuenta es: " << user.getSaldo() << " El número de la cuenta es: " << user.getNumeroCuenta() << endl;
    
    user.mostrarCuenta();
    
    cout << "FIN PRUEBAS USUARIO" << endl;
}
