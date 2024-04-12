#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <cstdlib>

// Prototipos de funciones
void pausar(char* mensaje);
void limpiarPantalla();
void limpiarBuffer();

// Definiciones de funciones
void pausar(const char* mensaje)
{
    if (mensaje != NULL) {
        std::cout << mensaje;
    } else {
        std::cout << "Presione una teclara para continuar...";
    }
    std::cin.get();
}

void limpiarPantalla()
{
    system("cls || clear");
}

void limpiarBuffer()
{
    while (std::cin.get() != '\n');
}

#endif // UTIL_H