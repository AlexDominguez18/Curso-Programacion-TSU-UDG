#ifndef LISTA_H
#define LISTA_H

#include <iostream>

#include "nodo.h"

template<typename T>
class Lista {
    Nodo<T>* primero;
    Nodo<T>* ultimo;
    int longitud;
public:
    // Constructor y destructor
    Lista();
    ~Lista();

    // Getters
    Nodo<T>* getPrimero();
    Nodo<T>* getUltimo();
    int getLongitud();

    // Setters
    void setPrimero(Nodo<T>* primero);
    void setUltimo(Nodo<T>* ultimo);
    void setLongitud(int longitud);
    
    bool estaVacia();
    void insertar(T dato);
    void eliminar(int posicion);
};

template<typename T>
Lista<T>::Lista() {
    this->primero = nullptr;
    this->ultimo = nullptr;
    this->longitud = 0;
}

template<typename T>
Lista<T>::~Lista() {
    while (!this->estaVacia()) {
        this->eliminar(0);
    }
    std::cout << "Lista eliminada" << std::endl;
}

template<typename T>
Nodo<T>* Lista<T>::getPrimero() {
    return this->primero;
}

template<typename T>
Nodo<T>* Lista<T>::getUltimo() {
    return this->ultimo;
}

template<typename T>
int Lista<T>::getLongitud() {
    return this->longitud;
}

template<typename T>
void Lista<T>::setPrimero(Nodo<T>* primero) {
    this->primero = primero;
}

template<typename T>
void Lista<T>::setUltimo(Nodo<T>* ultimo) {
    this->ultimo = ultimo;
}

template<typename T>
void Lista<T>::setLongitud(int longitud) {
    this->longitud = longitud;
}

template<typename T>
bool Lista<T>::estaVacia() {
    return this->longitud == 0;
}

template<typename T>
void Lista<T>::insertar(T dato) {
    Nodo<T>* nuevo = new Nodo<T>(dato);

    if (this->estaVacia()) {
        this->primero = nuevo;
        this->ultimo = nuevo;
    } else {
        Nodo<T>* aux = this->primero;
        Nodo<T>* anterior = nullptr;
        
        while (aux != nullptr && aux->getDato() < dato) {
            anterior = aux;
            aux = aux->getSiguiente();
        }

        if (anterior == nullptr) {
            nuevo->setSiguiente(this->primero);
            this->primero->setAnterior(nuevo);
            this->primero = nuevo;
        } else if (aux == nullptr) {
            this->ultimo->setSiguiente(nuevo);
            nuevo->setAnterior(this->ultimo);
            this->ultimo = nuevo;
        } else {
            anterior->setSiguiente(nuevo);
            nuevo->setAnterior(anterior);
            nuevo->setSiguiente(aux);
            aux->setAnterior(nuevo);
        }
    }

    this->longitud++;
}

template<typename T>
void Lista<T>::eliminar(int posicion) {
    if (this->estaVacia()) return;
    if (posicion < 0 || posicion >= this->longitud) return;

    Nodo<T>* actual = this->primero;

    for (int i = 0; i < posicion; i++) {
        actual = actual->getSiguiente();
    }

    if (actual->getAnterior() != nullptr)
        actual->getAnterior()->setSiguiente(actual->getSiguiente());
    if (actual->getSiguiente() != nullptr)
        actual->getSiguiente()->setAnterior(actual->getAnterior());
    if (posicion == 0)
        this->primero = actual->getSiguiente();

    delete actual;
    this->longitud--;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, Lista<T>& lista) {
    Nodo<T>* aux = lista.getPrimero();
    while (aux != nullptr) {
        if (aux->getSiguiente() == nullptr) {
            os << aux->getDato();
            break;
        }
        os << aux->getDato() << " -> ";
        aux = aux->getSiguiente();
    }
    return os;
}

#endif // LISTA_H