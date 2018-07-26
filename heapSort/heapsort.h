//
// Created by Travis on 4/30/18.
//

#ifndef HEAPSORT_HEAPSORT_H
#define HEAPSORT_HEAPSORT_H
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <memory.h>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
enum HEAPSORTERRORS {NULL_POINTER};
enum TYPE{MIN_HEAP,MAX_HEAP};

template<typename T>
class heapSort
{
public:
    void itemsToSort(const vector<T>& x);
    //void sortedList(T* &ans, size_t &s);
    void sort();
    void clear();
    void print();

private:

    vector<T> list;
    TYPE type = MAX_HEAP;
    size_t size, lastEntered;

    void shuffleUp(int where);
    void shuffleDown(int where);
    void swap(T &x, T &y);
    bool compare(const T &x, const T &y);
};

template<typename T>
void heapSort<T>::itemsToSort(const vector<T>& x)
{
    list = x;
    size = x.size();
}

template<typename T>
void heapSort<T>::clear()
{
    list.clear();
}

template<typename T>
void heapSort<T>::sort()
{
    int n = size;
    for(int i = n/2-1; i < size; ++i)
        shuffleUp(i);
    for(int i = n-1; i > 0; --i)
    {
        swap(list[0], list[i]);
        shuffleDown(i-1);
    }
}

template<typename T>
void heapSort<T>::swap(T &x, T &y)
{
    T temp = x;
    x = y;
    y = temp;
}

template<typename T>
bool heapSort<T>::compare(const T &x, const T &y)
{
    return type == MAX_HEAP?x>y:x<y;
}

template<typename T>
void heapSort<T>::shuffleUp(int where)
{
    int child = where, parent = (where-1)/2;
    bool cont = true;
    while(cont && child != parent)
        if(list[child] > list[parent])
        {
            swap(list[child], list[parent]);
            child = parent;
            parent = (child-1)/2;
        }
        else
            cont = false;
}

template<typename T>
void heapSort<T>::shuffleDown(int where)
{
    int parent = 0, left = 1, right = 2, toSwap;
    bool cont = true;
    while(cont && left <= where)
    {
        toSwap = right > where ? left : list[left] > list[right] ? left : right;
        if(list[parent] < list[toSwap])
        {
            swap(list[parent], list[toSwap]);
            parent = toSwap;
            left = parent*2 + 1;
            right = parent*2 + 2;
        }
        else
            cont = false;
    }
}

template<typename T>
void heapSort<T>::print()
{
    for(int i = 0; i<size;i++)
        cout<<list[i]<<' ';
    cout<<endl;
}

#endif //HEAPSORT_HEAPSORT_H
