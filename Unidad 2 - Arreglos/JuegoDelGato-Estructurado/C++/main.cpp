#include <iostream>

#define FILAS 3
#define COLUMNAS 3
#define JUGADOR_X 'X'
#define JUGADOR_O 'O'
#define VACIO ' '

using namespace std;

int main()
{
    // Variables para controlar el juego
    char jugadorActual = JUGADOR_X;
    int fila, columna;
    int i, j;
    // Banderas para controlar el juego
    bool hayGanador = false;
    bool hayGatoEncerrado = true;
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
        cout << "Juego del Gato" << endl << endl;
        cout << "  1 2 3" << endl;
        for (i = 0; i < FILAS; i++) {
            cout << i + 1 << " "; // Mostramos el numero de fila
            for (j = 0; j < COLUMNAS; j++) {
                cout << tablero[i][j];
                // Si no es la ultima columna, imprimimos una barra
                if (j < COLUMNAS - 1) {
                    cout << "|";
                }
            }
            cout << endl;
            // Si no es la ultima fila, imprimimos una linea
            if (i < FILAS - 1) {
                cout << "  -----" << endl;
            }
        }
        
        cout << "Turno del jugador " << jugadorActual << endl;
        // Leemos la fila y columna donde el jugador quiere colocar su ficha
        cout << "Ingrese la fila: ";
        cin >> fila;
        cout << "Ingrese la columna: ";
        cin >> columna;
        
        // Decrementamos la fila y columna para que el usuario ingrese valores de 1 a 3
        fila--;
        columna--;

        // Verificamos que la fila y columna ingresada este dentro del rango
        if (fila < 0 || fila > FILAS - 1 || columna < 0 || columna > COLUMNAS - 1) {
            cout << "Fila o columna invalida" << endl;
            cin.get();
            cout << "Presione enter para continuar...";
            cin.get();
            // Si la fila o columna es invalida, no cambiamos el jugador actual
            continue;
        }

        // Verificamos que la casilla este vacia
        if (tablero[fila][columna] == VACIO) {
            tablero[fila][columna] = jugadorActual;
        } else {
            cout << "La casilla ya esta ocupada" << endl;
            cin.get();
            cout << "Presione enter para continuar...";
            cin.get();
            // Si la casilla ya esta ocupada, no cambiamos el jugador actual
            continue;
        }

        // Verificamos si hay un ganador en las filas
        for (i = 0; i < FILAS; i++) {
            if (tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2] && tablero[i][0] != VACIO) {
                cout << "Ganador: " << tablero[i][0] << endl;
                hayGanador = true;
                break;
            }
        }
        // Verificamos si hay un ganador en las columnas
        for (i = 0; i < COLUMNAS; i++) {
            if (tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i] && tablero[0][i] != VACIO) {
                hayGanador = true;
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
            hayGanador = true;
        }
        /**
         * Diagonal 2 ejemplo:
         *   O |   | X
         *     | X | O
         *   X |   | O
        */
        else if (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0] && tablero[0][2] != VACIO) {
            hayGanador = true;
        }

        // Si no hay ganador verificamos si el tablero esta lleno
        if (!hayGanador) {
            hayGatoEncerrado = true;
            for (i = 0; i < FILAS; i++) {
                for (j = 0; j < COLUMNAS; j++) {
                    // Si hay una casilla vacia, continuamos el juego
                    if (tablero[i][j] == VACIO) {
                        hayGatoEncerrado = false;
                        break;
                    } 
                }
                // Si ya encontramos una casilla vacia, salimos del ciclo
                if (!hayGatoEncerrado) {
                    break;
                }
            }
        }
        
        // Si hay un ganador o el tablero esta lleno, mostramos el tablero final
        if (hayGatoEncerrado || hayGanador) {
            system("clear || cls");
            for (i = 0; i < FILAS; i++) {
                for (j = 0; j < COLUMNAS; j++) {
                    cout << tablero[i][j];
                    if (j < COLUMNAS - 1) {
                        cout << "|";
                    }
                }
                cout << endl;
                if (i < FILAS - 1) {
                    cout << "-----" << endl;
                }
            }
        }

        if (hayGanador) {
            cout << "Ganador: " << jugadorActual << endl;
        } else if (hayGatoEncerrado) {
            cout << "Gato encerrado" << endl;
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

        cin.ignore();
        cout << "Presione enter para continuar...";
        cin.get();

    } while (!hayGanador && !hayGatoEncerrado);

    return 0;
}