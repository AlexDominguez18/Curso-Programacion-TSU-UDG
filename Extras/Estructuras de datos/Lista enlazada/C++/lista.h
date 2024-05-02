#ifndef LISTA_H
#define LISTA_H

#include <iostream>

#include "nodo.h"

template<typename T>
class Lista {
public:
    Nodo<T> *primero;
    Nodo<T> *ultimo;
    int longitud;
    Lista();
    bool estaVacia();
    int obtenerLongitud();
    void agregar(T dato);
    void eliminar(int posicion);
    T operator[] (int posicion);
};

template<typename T>
Lista<T>::Lista() {
    this->primero = nullptr;
    this->ultimo = nullptr;
    this->longitud = 0;
}

template<typename T>
bool Lista<T>::estaVacia() {
    return this->longitud == 0;
}

template<typename T>
int Lista<T>::obtenerLongitud()  {
    return this->longitud;
}

template<typename T>
void Lista<T>::agregar(T dato) {
    Nodo<T> *nuevoElemento = new Nodo<T>(dato);

    if (this->estaVacia()) {
        this->primero = this->ultimo = nuevoElemento;
    } else {
        this->ultimo->siguiente = nuevoElemento;
        this->ultimo = nuevoElemento;
    }

    this->longitud++;
}

template<typename T>
void Lista<T>::eliminar(int posicion) {
    if (posicion < 0 || posicion >= this->longitud) return;

    Nodo<T> *actual = this->primero;

    if (posicion == 0) {
        this->primero = this->primero->siguiente;
        delete actual;
    } else {
        for (int i = 0; i < posicion - 1; i++)
            actual = actual->siguiente;
        
        Nodo<T> *temp = actual->siguiente;
        actual->siguiente = temp->siguiente;
        delete temp;
    }

    this->longitud--;
}

template<typename T>
T Lista<T>::operator[](int posicion) {
    if (posicion < 0 || posicion >= this->longitud) return T();

    Nodo<T> *actual = this->primero;

    for (int i = 0; i < posicion; i++)
        actual = actual->siguiente;
    
    return actual->dato;
}

template<typename T>
std::ostream& operator<<(std::ostream &os, const Lista<T> &lista) {
    Nodo<T> *actual = lista.primero;

    while (actual != nullptr) {
        if (actual->siguiente == nullptr) os << actual->dato;
        else os << actual->dato << " -> ";
        actual = actual->siguiente;
    }

    return os;
}

#endif // LISTA_H