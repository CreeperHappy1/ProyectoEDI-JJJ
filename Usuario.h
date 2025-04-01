//~ = alt gr + 4
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
    Usuario();
    Usuario(const std::string &apellidoNombre, const std::string &telefono, int edad, const std::string numeroCuenta, const float saldo, const std::string DNI, const std::string email);
    Usuario(const Usuario &original);
    ~Usuario();
    
    //Métodos selectores
    std::string getNombre() const;
    void getNombre(std::string &apellidoNombre);
    std::string getTelefono() const;
    void getTelefono(std::string &telefono);
    int getEdad() const;
    void getEdad(int &edad);
    std::string getDNI();
    void getDNI(std::string &DNI);
    std::string getEmail();
    void getEmail(std::string &email);
    
    //Métodos modificadores
    void setNombre(std::string apellidoNombre);
    void setTelefono(std::string telefono);
    void setEdad(const int edad);
    void setCuentaBancaria(const std::string numeroCuenta, const float saldo);
    void setDNI(const std::string newDNI);
    void setEmail(const std::string newEmail);
    
    //otros
    std::string pasarACadena();
    void mostrar();
    
    //métodos de cuenta bancaria
        std::string getNumeroCuenta() const;
        void getNumeroCuenta(std::string &num);
        float getSaldo() const;
        void getSaldo(float &saldo);
        //setters
        void setNumeroCuenta(const std::string newNumeroCuenta);
        void setSaldo(float newSaldo);
        //otros
        void mostrarCuenta();
        void ingresar(const float dS);//no voy a hacer un sacarDinero cuando puedes sin más dS < 0
};

#endif // USUARIO_H
