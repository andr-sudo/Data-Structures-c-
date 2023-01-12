#ifndef _STACK_H_
#define _STACK_H_
using namespace std;
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>


namespace stack {

    template <class T>
    class Stack {
        private:
            T* elems;
            int no_elems;
        public:
            Stack();
            Stack(T* elems, int no_elems);
            Stack(const Stack& ref_stack);
            ~Stack();
            void push(T elem);
            T pop();
            void print(ostream& out_stream);
            T* get_elems();
            int get_no_elems();
    };
    template <class T>
    ostream& operator<<(ostream& out_stream, const Stack<T>& stack);
}
#endif