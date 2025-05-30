#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include "cuentabancaria.h"

class Usuario{
private:
    std::string apellidoNombre;
    std::string telefono;
    int edad;
    CuentaBancaria *cuentaB;
    std::string DNI;
    std::string email;
public:
    
    //PRE: No hay
    //DESC: Inicia los valores de los string apellidoNombre, telefono, DNI y email a "", el int edad a -1 y se inicia la cuenta bancaria
    //Complejidad: O(1)
    Usuario();
    
    //PRE: Parámetros de entrada string apellidoNombre, telefono, DNI, email y el número de cuenta, el int edad, el float saldo y la cuenta bancaria
    //DESC: Asigna los valores de los parámetros de entrada a este usuario
    //Complejidad: O(1)
    Usuario(const std::string &apellidoNombre, const std::string &telefono, int edad, const std::string numeroCuenta, const float saldo, const std::string DNI, const std::string email);
    
    //PRE: Parámetro de entrada y salida de tipo Usuario llamado original
    //DESC: Asigna los valores del usuario pasado por parámetro a este
    //Complejidad: O(1)
    Usuario(const Usuario &original);
    
    //PRE: No hay
    //DESC: Destruye la cuenta bancaria y el usuario
    //Complejidad: O(1)
    ~Usuario();
    
    
    //Métodos selectores
    
    //PRE: No hay
    //DESC: Devuelve el nombre del usuario
    //Complejidad: O(1)
    std::string getNombre() const;
    
    //PRE: Parámetro de entrada y salida apellidoNombre
    //DESC: Devuelve el nombre del usuario mediante el parámetro de entrada y salida
    //Complejidad: O(1)
    void getNombre(std::string &apellidoNombre);
    
    //PRE: No hay
    //DESC: Devuelve el teléfono del usuario
    //Complejidad: O(1)
    std::string getTelefono() const;
    
    //PRE: Parámetro de entrada y salida telefono
    //DESC: Devuelve el teléfono del usuario mediante el parámetro de entrada y salida
    //Complejidad: O(1)
    void getTelefono(std::string &telefono);
    
    //PRE: No hay
    //DESC: Devuelve la edad del usuario
    //Complejidad: O(1)
    int getEdad() const;
    
    //PRE: Parámetro de entrada y salida tipo int de la edad
    //DESC: Devuelve la edad del usuario mediante el parámetro de entrada y salida
    //Complejidad: O(1)
    void getEdad(int &edad);
    
    //PRE: No hay
    //DESC: Devuelve el string dni del usuario
    //Complejidad: O(1)
    std::string getDNI();
    
    //PRE: Parámetro de entrada y salida de tipo string DNI
    //DESC: Devuelve el DNI del usuario mediante el parámetro de entrada y salida
    //Complejidad: O(1)
    void getDNI(std::string &DNI);
    
    //PRE: No hay
    //DESC: Devuelve el email del usuario
    //Complejidad: O(1)
    std::string getEmail();
    
    //PRE: Parámetro de entrada y salida de tipo string
    //DESC: Devuelve el email del usuario mediante el parámetro de entrada y salida
    //Complejidad: O(1)
    void getEmail(std::string &email);
    
    
    //Métodos modificadores
    
    //PRE: Parámetro de entrada de tipo string apellidoNombre
    //DESC: Cambia el nombre del usuario según el parámetro de entrada
    //Complejidad: O(1)
    void setNombre(std::string apellidoNombre);
    
    //PRE: Parámetro de entrada de tipo string telefono
    //DESC: Cambia el teléfono del usuario según el parámetro de entrada
    //Complejidad: O(1)
    void setTelefono(std::string telefono);
    
    //PRE: Parámetro de entrada de tipo string edad
    //DESC: Cambia la edad del usuario según el parámetro de entrada
    //Complejidad: O(1)
    void setEdad(const int edad);
    
    //PRE: Parámetro de entrada de tipo string numeroCuenta y de tipo float saldo
    //DESC: Cambia el numero de cuenta y el saldo del usuario según los parámetros de entrada
    //Complejidad: O(1)
    void setCuentaBancaria(const std::string numeroCuenta, const float saldo);
    
    //PRE: Parámetro de entrada de tipo string newDNI
    //DESC: Cambia el DNI del usuario según el parámetro de entrada
    //Complejidad: O(1)
    void setDNI(const std::string newDNI);
    
    //PRE: Parámetro de entrada de tipo string newEmail
    //DESC: Cambia el email del usuario según el parámetro de entrada
    //Complejidad: O(1)
    void setEmail(const std::string newEmail);
    
    
    //otros
    
    //PRE: No hay
    //DESC: Pasa a una cadena de texto todos los parámetros del usuario y la devuelve
    //Complejidad: O(1)
    std::string pasarACadena();
    
    //PRE: No hay
    //DESC: Muestra los atributos del usuario en pantalla
    //Complejidad: O(1)
    void mostrar();
    
    
    //métodos de cuenta bancaria
    
    //PRE: No hay
    //DESC: Devuelve el número de cuenta de la cuenta bancaria en forma de string
    //Complejidad: O(1)
    std::string getNumeroCuenta() const;
    
    //PRE: Parámetro de entrada y salida de tipo string
    //DESC: Devuelve el número de cuenta mediante el parámetro de entrada y salida
    //Complejidad: O(1)
    void getNumeroCuenta(std::string &num);
    
    //PRE: No hay
    //DESC: Devuelve el saldo de la cuenta bancaria en forma de float
    //Complejidad: O(1)
    float getSaldo() const;
    
    //PRE: Parámetro de entrada y salida de tipo float
    //DESC: Devuelve el saldo de la cuenta bancaria mediante el parámetro de entrada y salida
    //Complejidad:
    void getSaldo(float &saldo);
    //setters
    
    //PRE: Parámetro de entrada de tipo string
    //DESC: Cambia el número de la cuenta bancaria mediante el parámetro de entrada
    //Complejidad: O(1)
    void setNumeroCuenta(const std::string newNumeroCuenta);
    
    //PRE: Parámetro de entrada de tipo float
    //DESC: Cambia el saldo de la cuenta bancaria mediante el parámetro de entrada
    //Complejidad: O(1)
    void setSaldo(const float newSaldo);
    //otros
    
    //PRE: No hay
    //DESC: Muestra los valores de la cuenta bancaria
    //Complejidad: O(1)
    void mostrarCuenta();
    
    
    //PRE: Parámetro de entrada de tipo float
    //DESC: Aumenta el saldo de la cuenta bancaria según el parámetro de entrada
    //Complejidad: O(1)
    void ingresar(const float dS);//no voy a hacer un sacarDinero cuando puedes sin más dS < 0
};

#endif // USUARIO_H
