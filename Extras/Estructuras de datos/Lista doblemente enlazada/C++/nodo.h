#ifndef NODO_H
#define NODO_H

template<typename T>
class Nodo {
    T dato;
    Nodo<T>* siguiente;
    Nodo<T>* anterior;
public:
    // Constructores
    Nodo();
    Nodo(T dato);
    Nodo(T dato, Nodo<T>* siguiente, Nodo<T>* anterior);

    // Getters
    T getDato();
    Nodo<T>* getSiguiente();
    Nodo<T>* getAnterior();

    // Setters
    void setDato(T dato);
    void setSiguiente(Nodo<T>* siguiente);
    void setAnterior(Nodo<T>* anterior);
};

template<typename T>
Nodo<T>::Nodo() {
    this->dato = NULL;
    this->siguiente = nullptr;
    this->anterior = nullptr;
}

template<typename T>
Nodo<T>::Nodo(T dato) {
    this->dato = dato;
    this->siguiente = nullptr;
    this->anterior = nullptr;
}

template<typename T>
Nodo<T>::Nodo(T dato, Nodo<T>* siguiente, Nodo<T>* anterior) {
    this->dato = dato;
    this->siguiente = siguiente;
    this->anterior = anterior;
}

template<typename T>
T Nodo<T>::getDato() {
    return this->dato;
}

template<typename T>
Nodo<T>* Nodo<T>::getSiguiente() {
    return this->siguiente;
}

template<typename T>
Nodo<T>* Nodo<T>::getAnterior() {
    return this->anterior;
}

template<typename T>
void Nodo<T>::setDato(T dato) {
    this->dato = dato;
}

template<typename T>
void Nodo<T>::setSiguiente(Nodo<T>* siguiente) {
    this->siguiente = siguiente;
}

template<typename T>
void Nodo<T>::setAnterior(Nodo<T>* anterior) {
    this->anterior = anterior;
}

#endif // NODO_H