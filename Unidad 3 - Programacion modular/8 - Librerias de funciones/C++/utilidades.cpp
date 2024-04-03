#include <iostream>

#include "utilidades.h"

// Implementación de las funciones

void limpiarPantalla()
{
    system("cls || clear");
}

void limpiarBuffer()
{
    while (std::cin.get() != '\n');
}

void pausar(const char* mensaje = "Presione Enter para continuar...")
{
    std::cout << mensaje;
    std::cin.get();
}