#include <iostream>
#include <cstdlib>

// Include our libraries
#include "util.h"
#include "gato.h"

using namespace std;

int main()
{
    // Flags for game control
    bool hayGanador;
    bool hayGatoEncerrado;
    // Variables for game control
    char jugadorActual = JUGADOR_X;
    int fila, columna;
    // Declaration of the game board
    char tablero[FILAS][COLUMNAS] = {
        {VACIO, VACIO, VACIO},
        {VACIO, VACIO, VACIO},
        {VACIO, VACIO, VACIO}};

    do
    {
        limpiarPantalla();
        imprimirTablero(tablero);
        cout << "Turno del jugador " << jugadorActual << endl;

        fila = leerMovimiento("fila");
        columna = leerMovimiento("columna");

        if (!movimientoValido(tablero, fila, columna)) {
            cout << "Movimiento no valido, intente de nuevo" << endl;
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
    } while (!hayGanador && !hayGatoEncerrado);

    return 0;
}