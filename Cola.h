//
// Created by crism on 9/05/2023.
//

#ifndef COMEDOR_UNIVERSIARIO_COLA_H
#define COMEDOR_UNIVERSIARIO_COLA_H

#include "List.h"

template<typename T>

class Cola{
    List<T> lista;

    public:

    void push( T &value);
    void pop();
    T& front()const;
    T& back()const;
    [[nodiscard]] int size()const;

};


#endif //COMEDOR_UNIVERSIARIO_COLA_H
