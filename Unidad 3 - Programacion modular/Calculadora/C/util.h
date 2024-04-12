#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <stdlib.h>

// Prototipos de funciones
void pausar(char* mensaje);
void limpiarPantalla();
void limpiarBuffer();

// Definiciones de funciones
void pausar(char* mensaje)
{
    if (mensaje != NULL) {
        printf("%s", mensaje);
    } else {
        printf("Presione una tecla para continuar...");
    }
    getchar();
}

void limpiarPantalla()
{
    system("cls || clear");
}

void limpiarBuffer()
{
    while (getchar() != '\n');
}

#endif // UTIL_H