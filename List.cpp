//
// Created by crism on 9/05/2023.
//

#include "List.h"
#include <iostream>

using namespace std;

template<typename T>

List<T>::List(): begin(0), count(0) {}

template<typename T>

List<T>::~List(){
        Node<T>* del = begin;

        while(begin->next!=0){
            begin = begin->next;
            delete del;
            del = begin;
        }
}

template<typename T>

Node<T>* List<T>::makeNode(const T &value) {
    Node<T>* newNode = new Node<T>;

    newNode->data = value;
    newNode->next = 0;

    return newNode;

}

template <typename T>

void List<T>::insert(int pos, const T &value) {
    Node<T>* add = makeNode(value);

    if(pos>count || pos<0){
        cout << "POSICION INCORRECTA" << endl;
        return;
    }
    if(pos==0){
        add->next = begin;
        begin = add;
    }
    else{
        Node<T>* cur = begin;
        for(unsigned i = 0; i<(pos-1); i++){
            cur = cur->next;
        }
        add->next = cur->next;
        cur->next = add;
    }
    count ++;
}

template <typename T>

void List<T>::erase(const int pos) {

    if(pos<0 || pos>(count-1)){
        cout << "POSICION INCORRECTA" << endl;

        return;
    }
    if(pos==0){
        Node<T>* del = begin;
        begin = begin->next;
        delete del;
    }
    else{
        Node<T>* del;
        Node<T>* cur = begin;
        for(unsigned i=0; i< (pos-1);i++){
            cur = cur->next;
        }
        del = cur->next;
        cur->next = cur->next->next;
        delete del;
    }
    count --;
}

template <typename T>

void List<T>::print(int pos) const {

    if(pos<0 || pos>(count-1)){
        cout << "POSICION INCORRECTA" << endl;
        return;
    }
    Node<T>* cur = begin;

    for(unsigned i=0; i<pos;i++){
        cur = cur->next;
    }

    cout << "DATO: " << cur->data << endl;

}
template<typename T>

int List<T>:: size() const{
    return count;
}

template<typename T>

T& List<T>:: get(int pos)const{
    Node<T>* cur = begin;
    for(unsigned i=0; i<pos; i++){
        cur = cur->next;
    }
    return cur->data;
}
