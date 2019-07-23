#ifndef INFO_STACK_STACK_HPP
#define INFO_STACK_STACK_HPP

#include <cstddef>
#include <iostream>

using namespace std;

template<typename T>
class Stack {
private:
    template<typename TT>
    class Object {
    public:
        TT data;
        Object<TT> *next;
    };

public:
    Stack();
    ~Stack();
    Stack(const Stack& s);
    bool push(T);
    T pop();
    bool empty();
    T* top();
    void clear();

private:
    Object<T> *front;
};

template<typename T>
Stack<T>::Stack() : front(nullptr) {}

template<typename T>
Stack<T>::~Stack() {
    clear();
}

template<typename T>
Stack<T>::Stack(const Stack &s) {
    front = new Object<T>();
    front->data = s.front->data;
    front->next = s.front->next;
}

template<typename T>
bool Stack<T>::push(T p_data) {
    Object<T> *obj = new Object<T>();
    obj->data = p_data;
    obj->next = front;
    front = obj;
}

template<typename T>
T Stack<T>::pop() {
    if (empty()) {
        cout << "ERROR" << endl;
        exit(1);
    }
    else {
        Object<T> *old_front = front;
        front = front->next;
        T data = old_front->data;
        //delete old_front;
        return data;
    }
}

template<typename T>
T* Stack<T>::top() {
    if(empty()) {
        cout << "ERROR" << endl;
        exit(1);
    }
    else {
        return &(front->data);
    }
}

template<typename T>
void Stack<T>::clear() {
    while(!empty()) {
        pop();
    }
}

template<typename T>
bool Stack<T>::empty() {
    return front == nullptr;
}

#endif //INFO_STACK_STACK_HPP