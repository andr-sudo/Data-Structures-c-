#include "stack.h"

template <class T>
stack::Stack<T>::Stack() {
    this->elems = NULL;
    this->no_elems = 0;
}

template <class T>
stack::Stack<T>::Stack(T* elems, int no_elems) {
    this->no_elems = 0;
    this->elems = NULL;
    if (no_elems > 0) {
        this->no_elems = no_elems;
        this->elems = new T[no_elems];
        for (auto i = 0; i < this->no_elems; ++i)
            this->elems[i] = elems[i];
    }
}

template <class T>
stack::Stack<T>::Stack(const Stack& ref_queue) {
    this->no_elems = 0;
    this->elems = NULL;
    if (ref_queue.no_elems > 0) {
        this->no_elems = ref_queue.no_elems;
        this->elems = new T[ref_queue.no_elems];
        for (auto i = 0; i < ref_queue.no_elems; ++i)
            this->elems[i] = ref_queue.elems[i];
    }

}

template <class T>
stack::Stack<T>::~Stack() {
    if (this->elems)
        delete[] this->elems;
}

template <class T>
void stack::Stack<T>::push(T elem) {
    if (this->elems) {
        // exista cel putin 1 element, elems e alocat
        T* aux_elems = new T[this->no_elems];
        for (auto i = 0; i < this->no_elems; ++i)
            aux_elems[i] = this->elems[i];
        delete[] this->elems;
        this->elems = new T[++this->no_elems];
        for (auto i = 0; i < this->no_elems - 1; ++i)
            this->elems[i + 1] = aux_elems[i];
        delete[] aux_elems;
        this->elems[0] = elem;
    } else {
        // nu exista niciun element, elems e null
        this->elems = new T[++this->no_elems];
        this->elems[0] = elem;
    }
}

template <class T>
T stack::Stack<T>::pop() {
    T top;
    if (this->no_elems && this->elems) {
        // exista cel putin 1 element, elems e alocat
        top = this->elems[0];
        T* aux_elems = new T[--this->no_elems];
        for (auto i = 0; i < this->no_elems; ++i)
            aux_elems[i] = this->elems[i + 1];
        delete[] this->elems;
        this->elems = new T[this->no_elems];
        for (auto i = 0; i < this->no_elems; ++i)
            this->elems[i] = aux_elems[i];
    } 
    return top;
}

template <class T>
void stack::Stack<T>::print(ostream& out_stream) {
    out_stream << "Size of stack: " << this->no_elems << endl;
    out_stream << "HEAD-> ";
    if (this->elems) {
        for (auto i = 0; i < this->no_elems; ++i)
            out_stream << this->elems[i] << " ";
    }
    out_stream << " <-TAIL" << endl;
}

template <class T>
T* stack::Stack<T>::get_elems() {
    T* elems = new T[this->no_elems];
    for (auto i = 0; i < this->no_elems; ++i)
        elems[i] = this->elems[i];
    return elems;
}

template <class T>
int stack::Stack<T>::get_no_elems() {
    return this->no_elems;
}

template <typename T>
ostream& stack::operator<<(ostream& out_stream, Stack<T>& stack) {
    stack.print(out_stream);
    return out_stream;
}