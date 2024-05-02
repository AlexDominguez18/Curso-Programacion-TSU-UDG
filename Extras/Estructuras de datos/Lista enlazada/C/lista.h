#ifndef LISTA_H
#define LISTA_H

#include <stdlib.h>

#include "nodo.h"

typedef short int bool;

typedef struct {
    Nodo *primero;
    Nodo *ultimo;
    int longitud;
} Lista;

/**
 * Inicializa una lista.
 * 
 * @param lista La lista a inicializar.
*/
void inicializar(Lista *lista)
{
    lista->primero = NULL;
    lista->ultimo = NULL;
    lista->longitud = 0;
}

/**
 * Retorna la longitud de la lista.
 * 
 * @param lista La lista de la que se quiere conocer la longitud.
 * @return La longitud de la lista.
*/
int longitud(Lista *lista)
{
    return lista->longitud;
}

/**
 * Verifica si la lista está vacía.
 * 
 * @param lista La lista a verificar.
 * 
 * @return 1 si la lista está vacía, 0 en caso contrario.
*/
bool estaVacia(Lista *lista)
{
    return lista->longitud == 0;
}

/**
 * Agrega un elemento al final de la lista.
 * 
 * @param lista La lista a la que se le agregará el elemento.
 * @param elemento El elemento a agregar.
*/
void agregar(Lista *lista, Dato dato)
{
    Nodo *nuevoElemento = (Nodo*)malloc(sizeof(Nodo));
    
    nuevoElemento->dato = dato;
    nuevoElemento->siguiente = NULL;

    if (estaVacia(lista)) {
        lista->primero = lista->ultimo = nuevoElemento;
    }
    else {
        lista->ultimo->siguiente = nuevoElemento;
        lista->ultimo = nuevoElemento;
    }

    lista->longitud++;
}

/**
 * Obtiene el elemento en la posición indicada.
 * 
 * @param lista La lista de la que se quiere obtener el elemento.
 * @param posicion La posición del elemento a obtener.
 * 
 * @return El elemento en la posición indicada.
*/
Nodo* obtener(Lista *lista, int posicion)
{
    if (posicion < 0 || posicion >= lista->longitud) return NULL;

    Nodo *actual = lista->primero;
    for (int i = 0; i < posicion; i++) actual = actual->siguiente;

    return actual;
}

/**
 * Imprime los elementos de la lista.
 * 
 * @param lista La lista a imprimir.
*/
void imprimir(Lista *lista)
{
    Nodo *actual = lista->primero;

    while(actual != NULL) {
        if (actual->siguiente == NULL) printf("%d\n", actual->dato);
        else printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
}

#endif // LISTA_H