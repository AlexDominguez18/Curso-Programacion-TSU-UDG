#include <stdio.h>

// Prototipo de la funcion
// El * indica que es un puntero al array de caracteres
void saludar(char* nombre);

int main()
{
    // Llamada a la funcion
    saludar("Juan");
    saludar("Maria");
    return 0;
}

// Definicion de la funcion
void saludar(char* nombre)
{
    printf("Hola %s!\n", nombre);
}