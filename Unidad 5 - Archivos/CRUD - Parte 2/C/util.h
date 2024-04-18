#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <stdlib.h>

typedef enum {
    false,
    true
} booleano;

// Prototipos de funciones
void pausar(char* mensaje);
void limpiarPantalla();
void limpiarBuffer();
void imprimirLinea(char caracter, int longitud);

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

void imprimirLinea(char caracter, int longitud)
{
    for (int i = 0; i < longitud; i++) {
        printf("%c", caracter);
    }
    printf("\n");
}

#endif // UTIL_H