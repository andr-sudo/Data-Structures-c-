#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;


namespace queue {
    
    template <class T>
    class Queue {
        private:
            T* elems;
            int no_elems;
        public:
            Queue();
            Queue(T* elems, int no_elems);
            Queue(const Queue& ref_queue);
            ~Queue();
            void push(T elem);
            T pop();
            void print(ostream& out_stream);
            T* get_elems();
            int get_no_elems();
    };

    template <class T>
    ostream& operator<<(ostream& out_stream, const Queue<T>& queue);
}
#endif