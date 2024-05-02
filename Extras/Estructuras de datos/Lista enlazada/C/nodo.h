#ifndef NODO_H
#define NODO_H

typedef int Dato;

struct Nodo {
    Dato dato;
    struct Nodo *siguiente;
};

typedef struct Nodo Nodo;

#endif // NODO_H