#include <stdio.h>

#define MAX_REPETICIONES 10

int main()
{
    // Declaramos nuestra variable contador
    int contador;
    /**
     * El ciclo for se compone de tres partes:
     * 1. Inicialización de la variable de control
     * 2. Condición de continuacion del ciclo
     * 3. Incremento o decremento de la variable de control
     * Cada parte se separa por un punto y coma ';'
    */
    for (contador = 0; contador < MAX_REPETICIONES; contador++){
        // Esta linea se imprime hasta que el valor del contador sea igual a 10
        // El valor del contador va cambiando en cada iteración
        // El 'contador++' es el incremento de la variable contador en una unidad
        printf("Contador igual a %d\n", contador);
    }

    printf("Fin del ciclo for\n");
    // El valor de la variable contador es 10
    printf("Valor final del contador: %d\n", contador);

    return 0;
}