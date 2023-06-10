//
// Created by crism on 9/05/2023.
//

#ifndef COMEDOR_UNIVERSIARIO_LIST_H
#define COMEDOR_UNIVERSIARIO_LIST_H

template <typename T>

struct Node{
    T data;
    Node<T>* next;
};



template <typename T>

class List {
    int count;
    Node<T>* begin;
    Node<T>* makeNode(const T &value);

public:
    List();
    ~List();
    void insert(int pos, const T &value);
    void erase(const int pos);
    void print(int pos)const;
    T& get(int pos)const;
    int size() const;


};


#endif //COMEDOR_UNIVERSIARIO_LIST_H
