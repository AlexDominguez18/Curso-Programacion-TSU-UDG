#include <stdio.h>

#define NOMBRE_ARCHIVO "../../1 - Escribiendo en archivo txt/C/ejemplo.txt"
#define MAX 100

int main()
{
    int tamanioArchivo;
    // Buffer para almacenar el contenido del archivo.
    char buffer[MAX];
    FILE* archivo = fopen("ejemplo.txt", "r");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo\n");
        return 1;
    }
    
    // fseek se usa para mover el puntero de lectura/escritura al fin del archivo.
    fseek(archivo, 0, SEEK_END);
    // ftell devuelve la posicion del puntero de lectura/escritura.
    tamanioArchivo = ftell(archivo);
    // fseek se usa para mover el puntero de lectura/escritura al inicio del archivo.
    fseek(archivo, 0, SEEK_SET); 


    printf("Tamanio del archivo: %d bytes\n", tamanioArchivo);
    // fread lee el contenido del archivo y lo almacena en el buffer.
    fread(buffer, sizeof(char), tamanioArchivo, archivo);
    printf("Contenido del archivo: %s\n", buffer);

    fclose(archivo);

    return 0;
}