#include <stdio.h>

#define TAMANIO_TEXTO 20

int main()
{
    // Definimos un arreglo de caracteres para guardar el texto
    char texto[TAMANIO_TEXTO];
    char caracter;

    printf("Ingrese un texto: ");

    // Leemos el texto caracter por caracter y lo guardamos en el arreglo
    for (int i = 0; i < TAMANIO_TEXTO; i++) {
        scanf("%c", &caracter);
        if (caracter == '\n') {
            // Agregamos el caracter nulo al final del texto
            texto[i] = '\0';
            break;
        }
        texto[i] = caracter;
    }

    // Imprimimos el texto
    printf("El texto ingresado es: %s\n", texto);

    // Imprimimos el texto caracter por caracter
    for (int i = 0; i < TAMANIO_TEXTO; i++) {
        if (texto[i] == '\0') {
            break;
        }
        printf("El caracter %d es: %c\n", i, texto[i]);
    }

    printf("Presione enter para continuar...");
    getchar();
    
    return 0;
}