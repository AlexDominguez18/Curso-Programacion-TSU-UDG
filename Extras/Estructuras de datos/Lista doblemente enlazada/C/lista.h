#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

#include "nodo.h"

typedef struct {
    Nodo *primero;
    Nodo *ultimo;
    int longitud;
} Lista;

void inicializar(Lista *lista)
{
    lista->primero = NULL;
    lista->ultimo = NULL;
    lista->longitud = 0;
}

bool estaVacia(Lista *lista)
{
    return lista->longitud == 0;
}

void insertar(Lista *lista, Dato dato)
{
    Nodo *nuevoElemento = (Nodo*)malloc(sizeof(Nodo));
    
    if (nuevoElemento == NULL) {
        printf("Error: No se pudo reservar memoria para el nuevo elemento.\n");
        exit(1);
    }
    
    nuevoElemento->dato = dato;
    nuevoElemento->siguiente = NULL;

    if (estaVacia(lista)) {
        nuevoElemento->anterior = NULL;
        lista->primero = lista->ultimo = nuevoElemento;
    } else {
        // Insertar en orden
        Nodo *actual = lista->primero;
        Nodo *anterior = NULL;

        while (actual != NULL && actual->dato < dato) {
            anterior = actual;
            actual = actual->siguiente;
        }

        if (anterior == NULL) {
            nuevoElemento->siguiente = lista->primero;
            lista->primero->anterior = nuevoElemento;
            lista->primero = nuevoElemento;;
        } else if (actual == NULL) {
            nuevoElemento->anterior = lista->ultimo;
            lista->ultimo->siguiente = nuevoElemento;
            lista->ultimo = nuevoElemento;
        } else {
            nuevoElemento->siguiente = actual;
            nuevoElemento->anterior = anterior;
            anterior->siguiente = nuevoElemento;
            actual->anterior = nuevoElemento;
        }
    }

    lista->longitud++;
}

void eliminar(Lista *lista, int posicion)
{
    if (posicion < 0 || posicion >= lista->longitud) return;

    bool cercanoAlInicio = posicion < lista->longitud / 2;
    Nodo *actual = cercanoAlInicio ? lista->primero : lista->ultimo;

    for (int i = 0; i < posicion; i++)
        actual = cercanoAlInicio ? actual->siguiente : actual->anterior;
    
    if (actual->anterior != NULL) actual->anterior->siguiente = actual->siguiente;
    if (actual->siguiente != NULL) actual->siguiente->anterior = actual->anterior;
    if (posicion == 0) lista->primero = actual->siguiente;

    free(actual);
    lista->longitud--;
}

void imprimir(Lista *lista)
{
    Nodo *actual = lista->primero;
    
    while (actual != NULL) {
        if (actual->siguiente == NULL) printf("%d\n", actual->dato);
        else printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
}

void imprimirReversa(Lista *lista)
{
    Nodo *actual = lista->ultimo;

    while (actual != NULL) {
        if (actual->anterior == NULL) printf("%d\n", actual->dato);
        else printf("%d <- ", actual->dato);
        actual = actual->anterior;
    }
}

#endif // LISTA_H