#include <stdio.h>

#define TAMANIO_ARREGLO 10

int main()
{
    // Definimos un arreglo de enteros
    int arreglo[TAMANIO_ARREGLO] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int numeroBuscado = 0;

    printf("Ingrese el numero a buscar: ");
    scanf("%d", &numeroBuscado);

    /**
     * Buscamos el numero en el arreglo recorriendolo
     * Las busquedas lineales son ineficientes, pero son utiles para entender el concepto
     * de busqueda en arreglos. Ya que a mayor cantidad de elementos en el arreglo, mayor
     * sera el tiempo de busqueda.
    */
    for (int i = 0; i < TAMANIO_ARREGLO; i++) {
        // Si encontramos el numero, imprimimos la posicion y terminamos el programa
        if (arreglo[i] == numeroBuscado) {
            printf("El numero %d se encuentra en la posicion %d del arreglo\n", numeroBuscado, i);
            return 0;
        }
    }

    // Si llegamos a esta linea, el numero no se encuentra en el arreglo
    printf("El numero %d no se encuentra en el arreglo\n", numeroBuscado);

    getchar();
    printf("Presione enter para continuar...");
    getchar();

    return 0;
}