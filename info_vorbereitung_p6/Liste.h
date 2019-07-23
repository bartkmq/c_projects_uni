//
// Created by marco on 18.01.17.
//

#ifndef INFO_VORBEREITUNG_P6_LISTE_H
#define INFO_VORBEREITUNG_P6_LISTE_H

#include <cstddef>

template <typename T>
class Element {
public:
    Element();
    Element(Element<T> *prev, T data, Element<T> *next);

    Element *get_prev() const { return prev; }
    void set_prev(Element *prev) { Element::prev = prev; }

    T get_data() const { return data; }
    void set_data(T data) { Element::data = data; }

    Element *get_next() const { return next; }
    void set_next(Element *next) { Element::next = next; }

private:
    Element<T> *prev;
    T data;
    Element<T> *next;
};

template <class T>
class Liste {
public:
    Liste();

    Liste(T *, size_t len);

    void add_front(T, size_t pos = 0);
    void add_back(T, size_t = 0);

    T remove_front(size_t pos);
    T remove_back(size_t pos);

    T get(size_t pos);

    T next(size_t pos);
    T prev(size_t pos);

    void fill_array(T*, size_t len);

    size_t get_length();

private:
    void init();

    Element<T> *first;
    Element<T> *last;
    size_t length = 0;
};

template <class T>
Liste::Liste() {}

template <class T>
Liste::Liste(T *, size_t len) {

}

template <class T>
void Liste::add_front(T new_element, size_t pos) {
    if (!length) {
        init();
        first->set_data(new_element);
    }
    else {

    }
}

template <class T>
void Liste::add_back(T, size_t) {

}

template <class T>
T Liste::remove_front(size_t pos) {
    return nullptr;
}

template <class T>
T Liste::remove_back(size_t pos) {
    return nullptr;
}

template <class T>
T Liste::get(size_t pos) {
    return nullptr;
}

template <class T>
T Liste::next(size_t pos) {
    return nullptr;
}

template <class T>
T Liste::prev(size_t pos) {
    return nullptr;
}

template <class T>
void Liste::fill_array(T *, size_t len) {

}

template <class T>
size_t Liste::get_length() {
    return 0;
}

template <class T>
void Liste::init() {
    first = new Element();
    last = first;
}

#endif //INFO_VORBEREITUNG_P6_LISTE_H
