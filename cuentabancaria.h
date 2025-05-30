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
    
    //PRE: No hay
    //DESC: Inicia el saldo a 0 y el número de cuenta a NULL
    //Complejidad: O(1)
    CuentaBancaria();//default
    
    //PRE: Una cuenta bancaria inicializada como parámetro de entrada por referencia constante
    //DESC: Inicia el saldo y el número de cuenta iguales a los de la cuenta bancaria que hay como parámetro en el módulo
    //Complejidad: O(1)
    CuentaBancaria(const CuentaBancaria &original);//de copia
    
    //PRE: Parámetros de entrada por valor (constante en la función) de un número de cuenta como string y un saldo como float
    //DESC: Inicia el saldo y el número de la cuenta como sus respectivos parámetros de entrada
    //Complejidad: O(1)
    CuentaBancaria(const std::string numeroCuenta, const float saldo);//parametrizado
    //getters
    
    //PRE: No hay
    //DESC: Devuelve el número de cuenta de la cuenta bancaria en forma de string
    //Complejidad: O(1)
    std::string getNumeroCuenta() const;
    
    //PRE: Parámetro de entrada por referencia de tipo string
    //DESC: Devuelve el número de cuenta mediante el parámetro de entrada y salida
    //Complejidad: O(1)
    void getNumeroCuenta(std::string &num);
    
    //PRE: No hay
    //DESC: Devuelve el saldo de la cuenta bancaria en forma de float
    //Complejidad: O(1)
    float getSaldo() const;
    
    //PRE: Parámetro de entrada por referencia de tipo float
    //DESC: Devuelve el saldo de la cuenta bancaria mediante el parámetro de entrada y salida
    //Complejidad:
    void getSaldo(float &saldo);
    //setters
    
    //PRE: Parámetro de entrada por valor (constante en la función) de tipo string
    //DESC: Cambia el número de la cuenta bancaria mediante el parámetro de entrada
    //Complejidad: O(1)
    void setNumeroCuenta(const std::string newNumeroCuenta);
    
    //PRE: Parámetro de entrada por valor (constante en la función) de tipo float
    //DESC: Cambia el saldo de la cuenta bancaria mediante el parámetro de entrada
    //Complejidad: O(1)
    void setSaldo(const float newSaldo);
    //otros
    
    //PRE: No hay
    //DESC: Muestra los valores de la cuenta bancaria
    //Complejidad: O(1)
    void mostrar();
    
    //PRE: Parámetro de entrada por valor (constante en la función) de tipo float
    //DESC: Aumenta el saldo de la cuenta bancaria según el parámetro de entrada
    //Complejidad: O(1)
    void ingresar(const float dS);//no voy a hacer un sacarDinero cuando puedes sin más dS < 0
    //destructor
    
    //PRE: No hay
    //DESC: Destruye los atributos de cuenta bancaria
    //Complejidad: O(1)
    ~CuentaBancaria();
};

#endif // CUENTABANCARIA_H
