#include <stdio.h>

int main()
{
    // Declaramos una bandera para continuar con la repetición
    int continuarRepeticion = 1;

    // Mientras la bandera sea verdadera, se ejecutará el ciclo
    /**
     * La estructura de control repetitiva while se compone de dos partes:
     * 1. La condición de continuación del ciclo
     * 2. El bloque de código que se ejecutará mientras la condición sea verdadera
    */
    while (continuarRepeticion) {
        char respuesta;
        printf("Desea continuar con la repeticion? (s/n): ");
        scanf("%c", &continuarRepeticion);
        getchar(); // Limpiamos el buffer del teclado

        if (continuarRepeticion == 'n') {
            continuarRepeticion = 0;
        } // else no es necesario, ya que la bandera ya es verdadera
    }

    /**
     * El ciclo while se ejecutará hasta que la condición sea falsa
     * La condicion del while esta determinado por como manipulemos el valor
     * de la variable continuarRepeticion y no por un contador como en el ciclo for
    */
    printf("Fin del ciclo while\n");

    return 0;
}