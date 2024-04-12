#ifndef OPERACIONES_H
#define OPERACIONES_H

#include <iostream>

enum Operaciones {
    SUMA = 1,
    RESTA,
    MULTIPLICACION,
    DIVISION,
    RESIDUO,
    FACTORIAL,
    SALIR
};

// Prototipos de funciones
int suma(int a, int b);
int resta(int a, int b);
int multiplicacion(int a, int b);
int division(int a, int b);
int residuo(int a, int b);
int factorial(int n);

// Implementacion de funciones
int suma(int a, int b)
{
    return a + b;
}

int resta(int a, int b)
{
    return a - b;
}

int multiplicacion(int a, int b)
{
    return a * b;
}

int division(int a, int b)
{
    if (b == 0) {
        std::cout << "No se puede dividir entre cero" << std::endl;
        return 0;
    }
    return a / b;
}

int residuo(int a, int b)
{
    if (b == 0) {
        std::cout << "No se puede dividir entre cero" << std::endl;
        return 0;
    }
    return a % b;
}

int factorial(int n)
{
    if (n == 0) return 1;
    
    return n * factorial(n - 1);
}

#endif // OPERACIONES_H