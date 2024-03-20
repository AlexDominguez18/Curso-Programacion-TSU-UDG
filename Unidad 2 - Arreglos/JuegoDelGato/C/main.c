#include <stdio.h>
#include <stdlib.h>

#define FILAS 3
#define COLUMNAS 3
#define JUGADOR_X 'X'
#define JUGADOR_O 'O'
#define VACIO ' '

// Enumeracion para representar valores booleanos
enum { FALSO, VERDADERO };

int main()
{
    char jugadorActual = JUGADOR_X;
    int fila, columna;
    int i, j;
    short int hayGanador = FALSO;
    short int hayGatoEncerrado = VERDADERO;
    // Declaracion de una matriz de 3x3 de tipo char, simula el tablero del juego del gato
    char tablero[FILAS][COLUMNAS] = {
        {VACIO, VACIO, VACIO},
        {VACIO, VACIO, VACIO},
        {VACIO, VACIO, VACIO}
    };

    do {
        // Limpiamos la pantalla
        system("clear || cls");
        // Imprimimos el tablero
        printf("Juego del Gato\n\n");
        printf("  1 2 3\n");
        for (i = 0; i < FILAS; i++) {
            printf("%d ", i + 1); // Mostramos el numero de fila
            for (j = 0; j < COLUMNAS; j++) {
                printf("%c", tablero[i][j]);
                // Si no es la ultima columna, imprimimos una barra
                if (j < COLUMNAS - 1) {
                    printf("|");
                }
            }
            printf("\n");
            // Si no es la ultima fila, imprimimos una linea
            if (i < FILAS - 1) {
                printf("  -----\n");
            }
        }
        
        printf("Turno del jugador %c\n", jugadorActual);
        // Leemos la fila y columna donde el jugador quiere colocar su ficha
        printf("Ingrese la fila: ");
        scanf("%d", &fila);
        printf("Ingrese la columna: ");
        scanf("%d", &columna);
        
        // Decrementamos la fila y columna para que el usuario ingrese valores de 1 a 3
        fila--;
        columna--;

        // Verificamos que la fila y columna ingresada este dentro del rango
        if (fila < 0 || fila > FILAS - 1 || columna < 0 || columna > COLUMNAS - 1) {
            printf("Fila o columna invalida\n");
            getchar();
            printf("Presione enter para continuar...");
            getchar();
            // Si la fila o columna es invalida, no cambiamos el jugador actual
            continue;
        }

        // Verificamos que la casilla este vacia
        if (tablero[fila][columna] == VACIO) {
            tablero[fila][columna] = jugadorActual;
        } else {
            printf("La casilla ya esta ocupada\n");
            getchar();
            printf("Presione enter para continuar...");
            getchar();
            // Si la casilla ya esta ocupada, no cambiamos el jugador actual
            continue;
        }

        // Verificamos si hay un ganador en las filas
        for (i = 0; i < FILAS; i++) {
            if (tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2] && tablero[i][0] != VACIO) {
                printf("Ganador: %c\n", tablero[i][0]);
                hayGanador = VERDADERO;
                break;
            }
        }
        // Verificamos si hay un ganador en las columnas
        for (i = 0; i < COLUMNAS; i++) {
            if (tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i] && tablero[0][i] != VACIO) {
                hayGanador = VERDADERO;
                break;
            }
        }
        // Verificamos si hay un ganador en las diagonales
        /**
         * Diagonal 1 ejemplo:
         *    X |   | O
         *      | X | O
         *    O |   | X
        */
        if (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2] && tablero[0][0] != VACIO) {
            hayGanador = VERDADERO;
        }
        /**
         * Diagonal 2 ejemplo:
         *   O |   | X
         *     | X | O
         *   X |   | O
        */
        else if (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0] && tablero[0][2] != VACIO) {
            hayGanador = VERDADERO;
        }

        // Verificamos si el tablero esta lleno
        for (i = 0; i < FILAS; i++) {
            for (j = 0; j < COLUMNAS; j++) {
                // Si hay una casilla vacia, continuamos el juego
                if (tablero[i][j] == VACIO) {
                    hayGatoEncerrado = FALSO;
                    break;
                } 
            }
        }

        // Si hay un ganador o el tablero esta lleno, mostramos el tablero final
        if (hayGatoEncerrado || hayGanador) {
            system("clear || cls");
            for (i = 0; i < FILAS; i++) {
                for (j = 0; j < COLUMNAS; j++) {
                    printf("%c", tablero[i][j]);
                    if (j < COLUMNAS - 1) {
                        printf("|");
                    }
                }
                printf("\n");
                if (i < FILAS - 1) {
                    printf("-----\n");
                }
            }
        }

        if (hayGanador) {
            printf("Ganador: %c\n", jugadorActual);
        } else if (hayGatoEncerrado) {
            printf("Gato encerrado\n");
        } else {
            /**
             * Si no hay ganador y el tablero no esta lleno, cambiamos el jugador actual
             * para que el otro jugador pueda jugar.
             * 
             * Usamos un operador ternario para cambiar el jugador actual.
             * Los operadores ternarios tienen la siguiente forma:
             *    condicion ? valor_si_verdadero : valor_si_falso
            */
            jugadorActual = (jugadorActual == JUGADOR_X) ? JUGADOR_O : JUGADOR_X;
        }

        getchar();
        printf("Presione enter para continuar...");
        getchar();

    } while (!hayGanador);

    return 0;
}