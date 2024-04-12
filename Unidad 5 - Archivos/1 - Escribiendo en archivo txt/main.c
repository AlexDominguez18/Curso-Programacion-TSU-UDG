#include <stdio.h>

int main()
{
    /*
     * FILE es un tipo de dato que representa un archivo.
     * fopen es una funcion que abre un archivo.
     * El primer parametro es el nombre del archivo.
     * El segundo parametro es el modo de apertura.
     * 
     * "w" es el modo de escritura.
     * 
     * fopen devuelve un puntero al archivo.
     * Si no se pudo abrir el archivo, devuelve NULL.
     * Si el archivo no existe, fopen lo crea.
    */
    FILE* archivo = fopen("ejemplo.txt", "w");

    // Verificar si se pudo abrir el archivo.
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo\n");
        return 1;
    }

    // fprintf es como printf, pero escribe en un archivo.
    fprintf(archivo, "Hola mundo desde archivo\n");

    // fclose cierra el archivo, se debe hacer despues de terminar de escribir.
    fclose(archivo);

    return 0;
}