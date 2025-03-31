#ifndef CUENTABANCARIA_H
#define CUENTABANCARIA_H

#include <string>

class CuentaBancaria//clic derecho > refactor > create definitions for member functions (qtcreator está bastante on top lol)
{
private:
    std::string numeroCuenta;
    float saldo;
public:
    //Constructores
    CuentaBancaria();//default
    CuentaBancaria(const CuentaBancaria &original);//de copia
    CuentaBancaria(const std::string numeroCuenta, const float saldo);//parametrizado
    //getters
    std::string getNumeroCuenta() const;
    void getNumeroCuenta(std::string &num);
    float getSaldo() const;
    void getSaldo(float &saldo);
    //setters
    void setNumeroCuenta(const std::string newNumeroCuenta);
    void setSaldo(float newSaldo);
    //otros
    void mostrar();
    void ingresar(const float dS);//no voy a hacer un sacarDinero cuando puedes sin más dS < 0
    //destructor
    ~CuentaBancaria();
};

#endif // CUENTABANCARIA_H
