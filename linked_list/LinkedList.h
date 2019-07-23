#ifndef LINKED_LIST_LINKEDLIST_H
#define LINKED_LIST_LINKEDLIST_H

#include <cstddef>

template <typename T>
class Element {
public:
    Element(T *p_data) : data(p_data) {};
    Element *prev;
    T *data;
    Element *next;
};

template <typename T>
class LinkedList {
public:
    LinkedList(const T *arr, const size_t len) {

    }

    LinkedList() {

    }

    void add_front(size_t index, T *d) {
        Element *e = new Element(d);
        if (front == nullptr) {
            front = e;
            back = e;
        }
        else {
            front->prev = e;
            e->next = front;
            front = e;
        }
    }

    void add_back(size_t index, T *d) {
        Element *e = new Element(d);
        if (back == nullptr) {
            front = e;
            back = e;
        }
        else {
            back->next = e;
            e->prev = back;
            back = e;
        }

    }

    size_t remove_front(size_t index) {

    }

    size_t remove_back(size_t index) {

    }

    size_t contains(T *d) {

    }

    T* get(size_t index) {

    }

    // caller is responsible for freeing returned array
    T* to_array() {

    }

    ~LinkedList() {
        Element *e = back;
        while (e != NULL) {
            Element *e_old = e;
            e = e->prev;
            delete e_old;
        }
    }

private:
    Element<T> *front;
    Element<T> *back;
};


#endif //LINKED_LIST_LINKEDLIST_H
