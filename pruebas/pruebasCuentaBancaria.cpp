#include "pruebas.h"
#include "iostream"
#include "../cuentabancaria.h"
using namespace std;

void pruebaCuentaBancaria(){
    cout << "INICIO PRUEBAS CUENTA BANCARIA" << endl;
    
    //Pruebas de constructores
    
    //Caso 1 constructor por defecto
    
    CuentaBancaria *cB1;
    cB1 = new CuentaBancaria();
    cB1->ingresar(100);
    cB1->mostrar();
    
    //Caso 2 constructor parametrizado
    
    CuentaBancaria *cB2;
    cB2 = new CuentaBancaria("ES3222", 120);
    cB2->mostrar();
    
    //Caso 3 constructo copia
    CuentaBancaria *cB3;
    cB3 = new CuentaBancaria(*cB2);
    cB3->mostrar();
    
    //Pruebas de getters
    
    //Caso 1 getNumeroCuenta
    
    cout << "El número de cuenta es: ES3222, y sale: " << cB2->getNumeroCuenta() << endl;
    
    string numeroCuenta = cB2->getNumeroCuenta();
    cout << "El número de cuenta es: ES3222, y sale: " << numeroCuenta << endl;
    
    //Caso 2 getSaldo
    
    cout << "El saldo de la cuenta es: 120, y es: " << cB2->getSaldo() << endl;
    
    int saldo = cB2->getSaldo();
    cout << "El saldo de la cuenta es: 120, y sale: " << saldo << endl;
    
    
    //Pruebas de setters
    
    //Caso 1 setNumeroCuenta
    
    cout << "El número de cuenta es: " << cB1->getNumeroCuenta() << endl;
    
    cB1->setNumeroCuenta("HY4555");
    
    cout << "El nuevo número de cuenta es: " << cB1->getNumeroCuenta() << endl;
    
    //Caso 2 setSaldo
    
    cout << "El saldo de la cuenta es: " << cB2->getSaldo() << endl;
    
    cB2->setSaldo(200);
    
    cout << "El saldo de la cuenta es: 200, y sale: " << cB2->getSaldo() << endl;
    
    //Caso 3 ingresar
    
    cout << "El saldo de la cuenta es: " << cB2->getSaldo() << endl;
    
    cB2->ingresar(100);
    
    cout << "El saldo de la cuenta es: 300, y sale: " << cB2->getSaldo() << endl;
    
    //Caso 4 retirar
    
    cout << "El saldo de la cuenta es: " << cB2->getSaldo() << endl;
    
    cB2->ingresar(-100);
    
    cout << "El saldo de la cuenta es: 200, y sale: " << cB2->getSaldo() << endl;
    
    //Mostrar
    
    cout << " El saldo de la cuenta es: " << cB2->getSaldo() << "El número de la cuenta es: " << cB2->getNumeroCuenta() << endl;
    
    cB2->mostrar();
    
    
    delete cB1;
    delete cB2;
    delete cB3;
    
    cout << "FIN PRUEBAS CUENTA BANCARIA" << endl;
}
