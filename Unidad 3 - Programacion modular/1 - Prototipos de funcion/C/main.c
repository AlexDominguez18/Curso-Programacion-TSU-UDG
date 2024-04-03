#include <stdio.h>

// Prototipo de la funcion
// Si una funcion no retorna nada, se pone void (significa vacio)
void saludar();

int main()
{
    // Llamada a la funcion
    saludar();
    return 0;
}

// Definicion de la funcion
void saludar()
{
    printf("Hola!\n");
}