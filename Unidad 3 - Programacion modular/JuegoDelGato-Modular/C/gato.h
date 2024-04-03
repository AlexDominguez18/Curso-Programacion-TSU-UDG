#ifndef GATO_H
#define GATO_H

#include <stdio.h>

#include "util.h"

#define FILAS 3
#define COLUMNAS 3
#define JUGADOR_X 'X'
#define JUGADOR_O 'O'
#define VACIO ' '

void imprimirTablero(char tablero[FILAS][COLUMNAS]);
int leerMovimiento(char* mensaje);
booleano movimientoValido(char tablero[FILAS][COLUMNAS], int fila, int columna);
booleano verificarGanador(char tablero[FILAS][COLUMNAS], char jugador);
booleano verificarGatoEncerrado(char tablero[FILAS][COLUMNAS]);
void cambiarJugador(char* jugadorActual);
void mostrarResultado(char tablero[FILAS][COLUMNAS], char jugadorActual);

void imprimirTablero(char tablero[FILAS][COLUMNAS])
{
    printf("Juego del Gato\n\n");
    printf("  1 2 3\n");
    for (int i = 0; i < FILAS; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%c", tablero[i][j]);
            if (j < COLUMNAS - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < FILAS - 1) {
            printf("  -----\n");
        }
    }
}

int leerMovimiento(char* mensaje)
{
    int movimiento;
    printf("Ingrese la %s: ", mensaje);
    scanf("%d", &movimiento);
    return movimiento - 1;
}

booleano movimientoValido(char tablero[FILAS][COLUMNAS], int fila, int columna)
{
    return fila >= 0 && fila < FILAS && columna >= 0 && columna < COLUMNAS && tablero[fila][columna] == VACIO;
}

booleano verificarGanador(char tablero[FILAS][COLUMNAS], char jugador)
{   
    // Verificar si el jugador ha ganado en alguna fila
    for (int i = 0; i < FILAS; i++) {
        if (tablero[i][0] == jugador && tablero[i][1] == jugador && tablero[i][2] == jugador) {
            return VERDADERO;
        }
    }
    // Verificar si el jugador ha ganado en alguna columna
    for (int j = 0; j < COLUMNAS; j++) {
        if (tablero[0][j] == jugador && tablero[1][j] == jugador && tablero[2][j] == jugador) {
            return VERDADERO;
        }
    }
    // Verificar si el jugador ha ganado en alguna diagonal
    if (tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador) {
        return VERDADERO;
    }
    else if (tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador) {
        return VERDADERO;
    }

    return FALSO;
}

booleano verificarGatoEncerrado(char tablero[FILAS][COLUMNAS])
{
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (tablero[i][j] == VACIO) {
                return FALSO;
            }
        }
    }
    return VERDADERO;
}

void cambiarJugador(char* jugadorActual)
{
    *jugadorActual = (*jugadorActual == JUGADOR_X) 
        ? JUGADOR_O
        : JUGADOR_X;
}

void mostrarResultado(char tablero[FILAS][COLUMNAS], char jugadorActual)
{
    limpiarPantalla();
    imprimirTablero(tablero);
    if (jugadorActual == VACIO) {
        printf("Gato encerrado!\n");
    } else {
        printf("Ganador: %c\n", jugadorActual);
    }
}

#endif // GATO_H