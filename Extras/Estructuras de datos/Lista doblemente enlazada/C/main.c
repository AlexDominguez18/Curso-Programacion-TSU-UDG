#include <stdio.h>
#include <time.h>

#include "lista.h"

int main()
{
    Lista lista;
    inicializar(&lista);

    srand(time(NULL));
    for (int i = 0; i < 1000; i++) {
        int numero = rand();
        insertar(&lista, numero);
    }
    
    imprimir(&lista);

    return 0;
}