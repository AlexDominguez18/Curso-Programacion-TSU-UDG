#include <stdio.h>


/**
 * Ejemplo de un programa en C para leer un dato del usuario
 * y guardarlo en una variable.
*/

int main()
{
    int numero;

    printf("Ingresa un numero: ");
    scanf("%d", &numero);

    printf("El numero ingresado es: %d", numero);

    return 0;
}
