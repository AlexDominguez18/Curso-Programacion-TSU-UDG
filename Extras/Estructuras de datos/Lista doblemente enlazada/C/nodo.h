#ifndef NODO_H
#define NODO_H

typedef int Dato;

typedef short int bool;

struct Nodo {
    Dato dato;
    struct Nodo *siguiente;
    struct Nodo *anterior;
};

typedef struct Nodo Nodo;

#endif // NODO_H