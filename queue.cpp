#include "queue.h"
using namespace std;

template <class T>
queue::Queue<T>::Queue() {
    this->elems = NULL;
    this->no_elems = 0;
}

template <class T>
queue::Queue<T>::Queue(T* elems, int no_elems) {
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
queue::Queue<T>::Queue(const Queue& ref_queue) {
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
queue::Queue<T>::~Queue() {
    if (this->elems)
        delete[] this->elems;
}

template <class T>
void queue::Queue<T>::push(T elem) {
    if (this->elems) {
        // exista cel putin 1 element, elems e alocat
        T* aux_elems = new T[this->no_elems];
        for (auto i = 0; i < this->no_elems; ++i)
            aux_elems[i] = this->elems[i];
        delete[] this->elems;
        this->elems = new T[++this->no_elems];
        for (auto i = 0; i < this->no_elems - 1; ++i)
            this->elems[i] = aux_elems[i];
        delete[] aux_elems;
        this->elems[this->no_elems - 1] = elem;
    } else {
        // nu exista niciun element, elems e null
        this->elems = new T[++this->no_elems];
        this->elems[0] = elem;
    }
}

template <class T>
T queue::Queue<T>::pop() {
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
    // nu exista niciun element, elems e null 
    return top;
}

template <class T>
void queue::Queue<T>::print(ostream& out_stream) {
    out_stream << "Size of queue: " << this->no_elems << endl;
    out_stream << "HEAD-> ";
    if (this->elems) {
        for (auto i = 0; i < this->no_elems; ++i)
            out_stream << this->elems[i] << " ";
    }
    out_stream << " <-TAIL" << endl;
}

template <typename T>
ostream& queue::operator<<(ostream& out_stream, Queue<T>& queue) {
    queue.print(out_stream);
    return out_stream;
}

template <class T>
T* queue::Queue<T>::get_elems() {
    T* elems = new T[this->no_elems];
    for (auto i = 0; i < this->no_elems; ++i)
        elems[i] = this->elems[i];
    return elems;
}

template <class T>
int queue::Queue<T>::get_no_elems() {
    return this->no_elems;
}