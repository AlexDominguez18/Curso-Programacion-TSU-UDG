#include <stdio.h>

#define TAMANIO_ARREGLO 5

int main()
{
    // Declaracion del arreglo
    int arreglo[TAMANIO_ARREGLO];

    /**
     * Si declaramos un arreglo y no lo inicializamos, el contenido del arreglo
     * es indefinido. Por lo tanto, es importante inicializar el arreglo antes
     * de usarlo. Ya sea a la hora de declararlo o en un ciclo.
     * A continuacion, inicializamos el arreglo con un ciclo.
    */
    for (int i = 0; i < TAMANIO_ARREGLO; i++) {
        /* 
         * Guardamos el valor 2 * i en la posicion i del arreglo
         * El nombre del arreglo mas el indice entre corchetes es la forma de
         * acceder a un elemento del arreglo.
        */
        arreglo[i] = i * 2;
    }

    // Imprimimos el arreglo
    printf("Indice:\tValor:\n");
    for (int i = 0; i < TAMANIO_ARREGLO; i++) {
        printf("%d\t%d\n", i, arreglo[i]);
    }

    printf("Presione ENTER para continuar...\n");
    getchar();
    
    return 0;
}