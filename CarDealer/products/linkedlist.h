#ifndef LIST_H
#define LIST_H
#include "car.h"

namespace products{

template <class T>
class List{
private:                                                            //campi private della lista
    class Node{                                                 // classe nodo
    public:
        Node(const T& o,Node* p);
        T data;
        Node* next;
        ~Node();
    };
    Node* first;                                                     //puntatore al primo nodo
    static Node* copy(Node* p);
    static void destroy(Node*);
public:
    class const_Iterator{
        friend class List<T>;                                                       //classe iteratore
    private:
        const Node* punt;                                                  //puntatore a nodo
    public:
        bool operator==(const const_Iterator&) const;                            //metodi di iteratore
        bool operator!=(const const_Iterator&) const;
        const_Iterator& operator++();
        const_Iterator operator++(int);

        // not sure check
        const T* operator->() const {return &(punt->data);};
        const T& operator*() const {return punt->data;};
    };
    List();
    ~List();
    List(const List&);
    List& operator=(const List&);
    bool empty() const;
    void add(const T& o);
    void remove(const T& o);
    void clear();
    const T& getItemfromId(const unsigned int&);
    const_Iterator begin() const;
    const_Iterator end() const;
};

}

#endif
