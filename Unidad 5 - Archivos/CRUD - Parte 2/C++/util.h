#ifndef UTIL_H
#define UTIL_H

#include <iostream>

// Prototypes of functions
void pausar(char* mensaje);
void limpiarPantalla();
void limpiarBuffer();
void imprimirLinea(char caracter, int longitud);

// Definitions of functions
void pausar(const char* mensaje)
{
    if (mensaje != nullptr) {
        std::cout << mensaje;
    } else {
        std::cout << "Presione una tecla para continuar...";
    }
    std::cin.ignore();
}

void limpiarPantalla()
{
    system("cls || clear");
}

void limpiarBuffer()
{
    while (std::cin.get() != '\n');
}

void imprimirLinea(char caracter, int longitud)
{
    for (int i = 0; i < longitud; i++) {
        std::cout << caracter;
    }
    std::cout << std::endl;
}

#endif // UTIL_H