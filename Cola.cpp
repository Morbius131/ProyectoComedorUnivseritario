//
// Created by crism on 9/05/2023.
//

#include "Cola.h"

template<typename T>

void Cola<T>::push( T &value) {
    lista.insert(lista.size(), value);
}

template<typename T>

void Cola<T>::pop() {
    lista.erase(0);
}

template<typename T>

T& Cola<T>::front()const {
    return lista.get(0);
}

template<typename T>

T& Cola<T>::back()const {
    return lista.get(lista.size()-1);
}

template<typename T>

int Cola<T>::size()const {
    return lista.size();
}

