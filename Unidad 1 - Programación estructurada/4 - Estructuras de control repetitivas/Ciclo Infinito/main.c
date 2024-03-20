#include <stdio.h>

/**
 * Los enums son una forma de definir constantes que empiezan
 * en 0 y se incrementan en 1.
 * 
 * En el siguiente caso, FALSO es 0 y VERDADERO es 1.
*/

enum { FALSO, VERDADERO };

int main()
{
    int continuarCiclo = VERDADERO;

    // Se ejecuta siempre y cuando continuarCiclo sea verdadero
    while (continuarCiclo) {
        // Si no modificamos continuarCiclo, el ciclo se ejecutará de manera infinita
        printf("Ciclo infinito\n");
    }

    // Esto nunca se ejecutará
    printf("Salida del ciclo\n");

    return 0;
}