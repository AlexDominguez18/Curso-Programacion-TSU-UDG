#ifndef GATO_H
#define GATO_H

#include <iostream>
#include "util.h"

#define FILAS 3
#define COLUMNAS 3
#define JUGADOR_X 'X'
#define JUGADOR_O 'O'
#define VACIO ' '

// Prototipos de funciones
void imprimirTablero(char tablero[FILAS][COLUMNAS]);
int leerMovimiento(const char* mensaje);
bool movimientoValido(char tablero[FILAS][COLUMNAS], int fila, int columna);
bool verificarGanador(char tablero[FILAS][COLUMNAS], char jugador);
bool verificarGatoEncerrado(char tablero[FILAS][COLUMNAS]);
void cambiarJugador(char* jugadorActual);
void mostrarResultado(char tablero[FILAS][COLUMNAS], char jugadorActual);

// Implementacion de las funciones

void imprimirTablero(char tablero[FILAS][COLUMNAS])
{
    std::cout << "Juego del Gato" << std::endl << std::endl;
    std::cout << "  1 2 3" << std::endl;
    for (int i = 0; i < FILAS; i++) {
        std::cout << i + 1 << " ";
        for (int j = 0; j < COLUMNAS; j++) {
            std::cout << tablero[i][j];
            if (j < COLUMNAS - 1) {
                std::cout << "|";
            }
        }
        std::cout << std::endl;
        if (i < FILAS - 1) {
            std::cout << "  -----" << std::endl;
        }
    }
}

int leerMovimiento(const char* mensaje)
{
    int movimiento;
    std::cout << "Ingrese la " << mensaje << ": ";
    std::cin >> movimiento;
    return movimiento - 1;
}

bool movimientoValido(char tablero[FILAS][COLUMNAS], int fila, int columna)
{
    return fila >= 0 && fila < FILAS && columna >= 0 && columna < COLUMNAS && tablero[fila][columna] == VACIO;
}

bool verificarGanador(char tablero[FILAS][COLUMNAS], char jugador)
{   
    // Verificar si el jugador ha ganado en alguna fila
    for (int i = 0; i < FILAS; i++) {
        if (tablero[i][0] == jugador && tablero[i][1] == jugador && tablero[i][2] == jugador) {
            return true;
        }
    }
    // Verificar si el jugador ha ganado en alguna columna
    for (int j = 0; j < COLUMNAS; j++) {
        if (tablero[0][j] == jugador && tablero[1][j] == jugador && tablero[2][j] == jugador) {
            return true;
        }
    }
    // Verificar si el jugador ha ganado en alguna diagonal
    if (tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador) {
        return true;
    }
    else if (tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador) {
        return true;
    }

    return false;
}

bool verificarGatoEncerrado(char tablero[FILAS][COLUMNAS])
{
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (tablero[i][j] == VACIO) {
                return false;
            }
        }
    }
    return true;
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
        std::cout << "Gato encerrado!" << std::endl;
    } else {
        std::cout << "Ganador: " << jugadorActual << std::endl;
    }
}

#endif // GATO_H