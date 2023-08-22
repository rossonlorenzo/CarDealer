#include "linkedlist.h"
#include "car.h"


namespace products{

template <class T>
List<T>::Node::Node(const T& o, Node* s): data(o), next(s) {};

template <class T>
List<T>::List(): first(nullptr){};

template <class T>
bool List<T>::empty() const {
    return first==nullptr;
}

template <class T>
typename List<T>::Node *List<T>::copy(Node* p) {
    if(!p) return nullptr;
    else
        return new Node(p->data, copy(p->next));
}

template <class T>
List<T>& List<T>::operator=(const List<T>& l){
    if(this != &l){
        destroy(first);
        first= copy(l.first);
    }
    return *this;
}

template <class T>
List<T>::List(const List<T>& l): first(copy(l.first)) {};


template <class T>
void List<T>::destroy(Node* p) {
    if (p){
        destroy(p->next);
        delete p;
    }
}
//delete the object after removed from the list

template <class T>
List<T>::Node::~Node() {
    delete data;
}

template <class T>
List<T>::~List() {
    destroy(first);
}

template <class T>
void List<T>::add(const T& o) {
    first=new Node(o,first);
}
//remove and delete the node

template <class T>
void List<T>::remove(const T& o) {
    Node* p = first, *prec = nullptr;
    while (p && !(p->data == o)) {
        prec = p;
        p = p->next;
    }
    if(p) {
        if (!prec)
            first = p->next;
        else
            prec->next = p->next;
        delete p;
    }
}

template <class T>
void List<T>::clear(){
    destroy(first);
}

template <class T>
bool List<T>::const_Iterator::operator==(const const_Iterator& i) const {
    return punt == i.punt;
}

template <class T>
bool List<T>::const_Iterator::operator!=(const const_Iterator& i) const {
    return punt != i.punt;
}

template <class T>
typename List<T>::const_Iterator& List<T>::const_Iterator::operator++() {
    if(punt) punt = punt->next;
    return *this;
}

template <class T>
typename List<T>::const_Iterator List<T>::const_Iterator::operator++(int) {
    const_Iterator aux =*this;
    if(punt) punt = punt->next;
    return aux;
}

template <class T>
typename List<T>::const_Iterator List<T>::begin() const {
    const_Iterator aux;
    aux.punt = first;
    return aux;
}

template <class T>
typename List<T>::const_Iterator List<T>::end() const {
    const_Iterator aux;
    aux.punt = nullptr;
    return aux;
}
template <class T>
const T& List<T>::getItemfromId(const unsigned int& n){
        for(List<T>::const_Iterator it=this->begin(); it!=this->end(); it++){
                if((*it)->getId() == n){
                    return *it;
                }
        }
        throw std::string("no item found");
}

template class List<const Car*>;

}
