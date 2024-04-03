#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <stdio.h>
#include <stdlib.h>

// Prototipos de funciones
void limpiarPantalla();
void limpiarBuffer();
void pausar(const char *mensaje);

// Implementaciones
void limpiarPantalla()
{
    system("cls || clear");
}

void limpiarBuffer()
{
    while (getchar() != '\n');
}

void pausar(const char *mensaje)
{
    printf("%s\n", mensaje);
    getchar();
}

#endif