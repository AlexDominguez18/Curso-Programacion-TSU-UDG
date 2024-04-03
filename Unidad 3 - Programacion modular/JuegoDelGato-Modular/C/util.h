#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

// Enumeracion para valores booleanos
enum { FALSO, VERDADERO };

// En C no existe el tipo booleano, por lo que se define
typedef short int booleano;


// Prototipos de funciones
void pausa(const char* texto);
void limpiarPantalla();

// Implementacion de funciones

void pausa(const char* texto)
{
    char c;
    while ((c = getchar()) != '\n'); 
    printf(texto);
    getchar();
}

void limpiarPantalla()
{
    system(CLEAR);
}

#endif // UTIL_H