#ifndef NODO_H
#define NODO_H

template<typename T>
class Nodo {
public:
    T dato;
    Nodo *siguiente;
    Nodo(T dato);
    Nodo(T dato, Nodo *siguiente);
    T obtenerDato();
    Nodo *obtenerSiguiente();
};

template<typename T>
Nodo<T>::Nodo(T dato) {
    this->dato = dato;
    this->siguiente = nullptr;
}

template<typename T>
Nodo<T>::Nodo(T dato, Nodo *siguiente) {
    this->dato = dato;
    this->siguiente = siguiente;
}

template<typename T>
T Nodo<T>::obtenerDato() {
    return dato;
}

template<typename T>
Nodo<T> *Nodo<T>::obtenerSiguiente() {
    return siguiente;
}

#endif // NODO_H