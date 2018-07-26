#ifndef MYSTACK_H
#define MYSTACK_H
#include <cstdlib>

enum STACK_ERRORS {STACK_EMPTY, STACK_FULL};

namespace x {
    template<typename T>
    class myStack {
    public:
        myStack();

        myStack(size_t cap);

        ~myStack();

        myStack(const myStack &x);

        myStack &operator=(const myStack &x);

        bool empty();

        bool full();

        void clear();

        T peek();

        T pop();

        void push(const T &data);

    private:
        size_t mySize, myCapacity;
        int tos;
        void **stack;

        void nukem();

        void copy(const myStack &x);
    };

    template<typename T>
    myStack<T>::myStack() {
        stack = new void *[myCapacity = 5];
        tos = -1;
        mySize = 0;
    }

    template<typename T>
    myStack<T>::myStack(size_t cap) {
        stack = new void *[myCapacity = cap];
        tos = -1;
        mySize = 0;
    }

    template<typename T>
    myStack<T>::~myStack() {
        nukem();
    }

    template<typename T>
    myStack<T> &myStack<T>::operator=(const myStack &other) {
        if (this != &other) {
            nukem();
            copy(other);
        }
        return *this;
    }

    template<typename T>
    bool myStack<T>::empty() {
        return tos < 0;
    }

    template<typename T>
    bool myStack<T>::full() {
        return tos + 1 >= myCapacity;
    }

    template<typename T>
    void myStack<T>::clear() {
        tos = -1;
    }

    template<typename T>
    T myStack<T>::peek() {
        if (empty())
            throw STACK_EMPTY;
        return stack[tos];
    }

    template<typename T>
    myStack<T>::myStack(const myStack &other) {
        copy(other);
    }


    template<typename T>
    T myStack<T>::pop() {
        if (empty())
            throw STACK_EMPTY;
        T *data = (T *) stack[tos--];
        return *data;
    }

    template<typename T>
    void myStack<T>::push(const T &data) {
        if (full())
            throw STACK_FULL;
        stack[++tos] = new T(data);
    }

    template<typename T>
    void myStack<T>::copy(const myStack &x) {
        for (size_t i = 0; i <= tos; ++i)
            stack[i] = new T(x.stack[i]);
    }


    template<typename T>
    void myStack<T>::nukem() {
        for (size_t i = 0; i < myCapacity; ++i)
            delete stack[i];
        delete[] stack;
    }
}

#endif // MYSTACK_H