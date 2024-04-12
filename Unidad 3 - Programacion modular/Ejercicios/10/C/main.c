#include <stdio.h>
#include <stdlib.h> // Para usar malloc

int encontrarMenor(int* numeros, int cantidadNumeros);

int main()
{
    // Creamos un puntero a un arreglo de enteros
    int* numeros;
    int cantidadNumeros;
    int menor;

    printf("Ingrese la cantidad de numeros: ");
    scanf("%d", &cantidadNumeros);

    numeros = (int*) malloc(cantidadNumeros * sizeof(int));

    // Pedimos los numeros al usuario
    for (int i = 0; i < cantidadNumeros; i++) {
        printf("Ingrese el numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    for (int i = 0; i < cantidadNumeros; i++) {
        printf("Numero %d: %d\n", i + 1, numeros[i]);
    }

    // Llamamos a la funcion para encontrar el menor
    menor = encontrarMenor(numeros, cantidadNumeros);

    printf("El menor numero es: %d\n", menor);

    return 0;
}

int encontrarMenor(int* numeros, int cantidadNumeros)
{
    // Asumimos que el numero menor es el primer elemento del arreglo
    int menor = numeros[0];
   
    // Recorremos el arreglo para encontrar el numero menor
    for (int i = 1; i < cantidadNumeros; i++) {
        // Si el numero actual es menor que el menor actual, actualizamos el menor
        if (numeros[i] < menor){
            menor = numeros[i];
        }
    }

    return menor;
}