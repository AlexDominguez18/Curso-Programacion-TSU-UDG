#ifndef UTIL_H
#define UTIL_H

#include <iostream>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

// Prototipos de funciones
void pausa(const char *text);
void limpiarPantalla();

// Implementacion de funciones

void pausa(const char *text)
{
    char c;
    while ((c = std::cin.get()) != '\n');
    std::cout << text;
    std::cin.get();
}

void limpiarPantalla()
{
    system(CLEAR);
}

#endif // UTIL_H