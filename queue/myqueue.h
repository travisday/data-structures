#ifndef MYQUEUE_MYQUEUE_H
#define MYQUEUE_MYQUEUE_H
#ifndef MYQUEUE_H
#define MYQUEUE_H
#include <cstdlib>

namespace myqueue
{
    enum QUEUE_ERRORS {QUEUE_FULL, QUEUE_EMPTY};

    template<typename T>
    struct node
    {
        T data;
        node* next;

        node(const T& data)
        {
            this->data = data;
            next = NULL;
        }
    };

    template<typename T>
    class myQueue
    {
    public:
        myQueue(size_t cap = 10);
        ~myQueue();
        myQueue(const myQueue<T> &other);
        myQueue<T>& operator=(const myQueue<T> &other);

        myQueue<T>& operator<<(const T &data);
        myQueue<T>& operator>>(T &data);

        void enqueue(const T&data);
        T dequeue();
        T peek();
        bool full();
        bool empty();
        size_t size();
        void resize();
        void clear();

    private:
        node<T> *head, *tail;
        size_t mySize, myCapacity;

        void copy(const myQueue<T> &other);
        void nukem();
    };


    template<typename T>
    myQueue<T>::myQueue(size_t cap)
    {
        myCapacity = cap;
        mySize = 0;
        head = tail = NULL;
    }

    template<typename T>
    myQueue<T>::~myQueue()
    {
        nukem();
        mySize = myCapacity = 0;
    }

    template<typename T>
    myQueue<T>::myQueue(const myQueue<T> &other)
    {
        copy(other);
    }

    template<typename T>
    myQueue<T>& myQueue<T>::operator=(const myQueue<T> &other)
    {
        if(this != &other)
        {
            nukem();
            copy(other);
        }
        return *this;
    }


    template<typename T>
    myQueue<T>& myQueue<T>::operator<<(const T &data)
    {
        enqueue(data);
    }

    template<typename T>
    myQueue<T>& myQueue<T>::operator>>(T &data)
    {
        data = dequeue();
    }


    template<typename T>
    void myQueue<T>::enqueue(const T&data)
    {
        if(full())
            throw QUEUE_FULL;
        if(empty())
            head = tail = new node<T>(data);
        else
        {
            tail->next = new node<T>(data);
            tail = tail->next;
        }
        ++mySize;
    }

    template<typename T>
    T myQueue<T>::dequeue()
    {
        if(empty())
            throw QUEUE_EMPTY;
        node<T> *ptr = head;
        T data = head->data;
        head = head->next;
        delete ptr;
        --mySize;
        return data;
    }

    template<typename T>
    T myQueue<T>::peek()
    {
        if(empty())
            throw QUEUE_EMPTY;
        return head->data;
    }

    template<typename T>
    bool myQueue<T>::full()
    {
        return mySize == myCapacity;
    }

    template<typename T>
    bool myQueue<T>::empty()
    {
        return !mySize;
    }


    template<typename T>
    size_t myQueue<T>::size()
    {
        return mySize;
    }

    template<typename T>
    void myQueue<T>::resize()
    {

    }

    template<typename T>
    void myQueue<T>::clear()
    {
        nukem();
        head = tail = NULL;
        mySize = 0;
    }

    template<typename T>
    void copy(const myQueue<T> &other)
    {
        for(node<T> *ptr = other.head; ptr; ptr = ptr->next)
            enqueue(ptr->data);
    }

    template<typename T>
    void myQueue<T>::nukem()
    {
        while(head){
            dequeue();
        }
        head = tail = NULL;
    }

};
#endif // MYQUEUE_H
#endif //MYQUEUE_MYQUEUE_H
