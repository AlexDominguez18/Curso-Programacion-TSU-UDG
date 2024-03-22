#include <stdio.h>
#include <stdlib.h>

// Incluimos nuestras librerias
#include "util.h"
#include "gato.h"

int main()
{
    // Banderas para el control del juegosp
    booleano hayGanador;
    booleano hayGatoEncerrado;
    // Variables para el control del juego
    char jugadorActual = JUGADOR_X;
    int fila, columna;
    // Declaracion del tablero del juego
    char tablero[FILAS][COLUMNAS] = {
        { VACIO, VACIO, VACIO },
        { VACIO, VACIO, VACIO },
        { VACIO, VACIO, VACIO }
    };

    do {
        limpiarPantalla();
        imprimirTablero(tablero);
        printf("Turno del jugador %c\n", jugadorActual);

        fila = leerMovimiento("fila");
        columna = leerMovimiento("columna");

        if (!movimientoValido(tablero, fila, columna)) {
            printf("Movimiento no valido, intente de nuevo\n");
            pausa("Presione ENTER para continuar...");
            continue;
        }

        tablero[fila][columna] = jugadorActual;

        hayGanador = verificarGanador(tablero, jugadorActual);
        if (hayGanador) {
            mostrarResultado(tablero, jugadorActual);
        } 
        
        hayGatoEncerrado = verificarGatoEncerrado(tablero);
        if (!hayGanador && hayGatoEncerrado) {
            mostrarResultado(tablero, VACIO);
        }

        if (!hayGanador && !hayGatoEncerrado) {
            cambiarJugador(&jugadorActual);
        }
        
        pausa("Presione ENTER para continuar...");
    } while(!hayGanador && !hayGatoEncerrado);

    return 0;
}