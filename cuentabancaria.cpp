#include "cuentabancaria.h"
#include <iostream>

CuentaBancaria::CuentaBancaria()
{
    numeroCuenta = "NULL";
    saldo = 0;
}

CuentaBancaria::CuentaBancaria(const CuentaBancaria &original)
{
    this->numeroCuenta = original.numeroCuenta;
    this->saldo = original.saldo;
}

CuentaBancaria::CuentaBancaria(const std::string numeroCuenta, const float saldo)
{
    this->numeroCuenta = numeroCuenta;
    this->saldo = saldo;
}

std::string CuentaBancaria::getNumeroCuenta() const
{
    return numeroCuenta;
}

void CuentaBancaria::getNumeroCuenta(std::string &num)
{
    num = numeroCuenta;
}

float CuentaBancaria::getSaldo() const
{
    return saldo;
}

void CuentaBancaria::getSaldo(float &saldo)
{
    saldo = this->saldo;
}

void CuentaBancaria::setNumeroCuenta(const std::string newNumeroCuenta)
{
    numeroCuenta = newNumeroCuenta;
}

void CuentaBancaria::setSaldo(float newSaldo)
{
    saldo = newSaldo;
}

void CuentaBancaria::mostrar()
{
    std::cout << "Número de cuenta: " << numeroCuenta << std::endl;
    std::cout << "Saldo: " << saldo << std::endl;
}

void CuentaBancaria::ingresar(const float dS)
{
    saldo += dS;
    if (saldo < 0)
        std::cout << "ajjaj lol estás en deuda por bobo\nAhora me debes dinero juajajau\n";
}

CuentaBancaria::~CuentaBancaria() {}
