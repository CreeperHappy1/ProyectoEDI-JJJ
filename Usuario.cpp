#include "Usuario.h"
#include <iostream>

Usuario::Usuario()
{
    apellidoNombre = "";
    telefono = "";
    edad = -1;
    cuentaB = new CuentaBancaria();
    DNI = "";
    email = "";
}

Usuario::~Usuario()
{
    delete cuentaB;
}

std::string Usuario::getNombre() const
{
    return this->apellidoNombre;
}

void Usuario::getNombre(std::string &apellidoNombre)
{
    apellidoNombre
        = this->apellidoNombre; //también podemos nombrar los atributos con un _ para distinguirlos, pero está desfasado
}

std::string Usuario::getTelefono() const
{
    return this->telefono;
}

void Usuario::getTelefono(std::string &telefono)
{
    telefono = this->telefono;
}

int Usuario::getEdad() const
{
    return this->edad;
}

void Usuario::getEdad(int &edad)
{
    edad = this->edad;
}

std::string Usuario::getDNI()
{
    return DNI;
}

void Usuario::getDNI(std::string &DNI)
{
    DNI = this->DNI;
}

std::string Usuario::getEmail()
{
    return email;
}

void Usuario::getEmail(std::string &email)
{
    email = this->email;
}

void Usuario::setNombre(std::string apellidoNombre)
{
    this->apellidoNombre = apellidoNombre;
}

void Usuario::setTelefono(std::string telefono)
{
    this->telefono = telefono;
}

void Usuario::setEdad(int edad)
{
    this->edad = edad;
}

void Usuario::setCuentaBancaria(const std::string numeroCuenta, const float saldo)
{
    cuentaB->setNumeroCuenta(numeroCuenta);
    cuentaB->setSaldo(saldo);
}

void Usuario::setDNI(const std::string newDNI)
{
    this->DNI = newDNI;
}

void Usuario::setEmail(const std::string newEmail)
{
    this->email = newEmail;
}

std::string Usuario::pasarACadena()
{
    return apellidoNombre + " - " + telefono + " - " + std::to_string(edad) + " - C("
           + cuentaB->getNumeroCuenta() + ", " + std::to_string(cuentaB->getSaldo()) + ") - " + DNI
           + " - " + email;
}

void Usuario::mostrar()
{
    std::cout << this->pasarACadena() << std::endl;
}

std::string Usuario::getNumeroCuenta() const
{
    return cuentaB->getNumeroCuenta();
}

void Usuario::getNumeroCuenta(std::string &num)
{
    cuentaB->getNumeroCuenta(num);
}

float Usuario::getSaldo() const
{
    return cuentaB->getSaldo();
}

void Usuario::getSaldo(float &saldo)
{
    cuentaB->getSaldo(saldo);
}

void Usuario::setNumeroCuenta(const std::string newNumeroCuenta)
{
    cuentaB->setNumeroCuenta(newNumeroCuenta);
}

void Usuario::setSaldo(float newSaldo)
{
    cuentaB->setSaldo(newSaldo);
}

void Usuario::mostrarCuenta()
{
    cuentaB->mostrar();
}

void Usuario::ingresar(const float dS)
{
    cuentaB->ingresar(dS);
}

//lo de usar lo de los dos puntos fue idea de qtcreator, tampoco me parece mal aunque es un poco raro
Usuario::Usuario(const std::string &apellidoNombre,
                 const std::string &telefono,
                 int edad,
                 const std::string numeroCuenta,
                 const float saldo,
                 const std::string DNI,
                 const std::string email)
    : apellidoNombre(apellidoNombre)
    , telefono(telefono)
    , edad(edad)
    , DNI(DNI)
    , email(email)
{
    cuentaB = new CuentaBancaria(numeroCuenta, saldo);
}

Usuario::Usuario(const Usuario &original)
{
    this->apellidoNombre = original.apellidoNombre;
    this->telefono = original.telefono;
    this->edad = original.edad;
    cuentaB = new CuentaBancaria(*original.cuentaB);
    this->DNI = original.DNI;
    this->email = original.email;
}
