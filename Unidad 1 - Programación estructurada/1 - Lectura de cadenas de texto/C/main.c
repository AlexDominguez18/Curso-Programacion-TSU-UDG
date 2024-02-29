#include <stdio.h>

// Constante simbolica para el tamaño maximo del nombre
#define MAX_NOMBRE 50

int main()
{
    // Declaracon de la variable de 'tipo' string (arreglo de caracteres)
    char nombre[MAX_NOMBRE];
 
    // Lectura de la entrada del usuario
    printf("Ingresa tu nombre completo: ");
    scanf("%[^\n]", nombre);

    // Mostrar la cadena de texto leida
    printf("Hola %s!", nombre);

    return 0;
}