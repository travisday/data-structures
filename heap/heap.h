//
// Created by Travis on 4/24/18.
//
#ifndef HEAPARRAY_HEAP_H
#define HEAPARRAY_HEAP_H
#include <fstream>
#include <cstdlib>
#include <bitset>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
//#include "node.h"
using namespace std;
enum HEAP_ERRORS {HEAP_EMPTY, HEAP_FULL, HEAP_BAD_SIZE};
enum TYPE {MAX, MIN};
//template<typename T>
//typedef bool (*fptr)(const node<T> &x, const node<T> &y);

template<typename T>
class heap
{
public:
    heap() = default;
    ~heap() = default;
    heap(const heap<T> &other) = default;
    heap<T>& operator=(const heap<T>& other) = default;

    void push(const T &data);
    T extract();
    T peek();
    bool hasParent(int x);
    bool hasLeft(int x);
    bool hasRight(int x);
    int getLeftChild(int x);
    int getRightChild(int x);
    int getParent(int x);
    bool empty() const;
    bool full() const;
    size_t size() const;
    const T& peek() const;
    void print();

private:
    vector<T> pile;
    TYPE type = MAX;

    void swap(T &x, T &y);
    void shuffleUp();
    void shuffleDown();
    bool compare(T x, T y);
};


template<typename T>
void heap<T>::push(const T &data){
    if (full()){
        throw HEAP_FULL;
    }
    pile.push_back(data);
    shuffleUp();
}

template<typename T>
T heap<T>::extract(){
    if (empty()){
        throw HEAP_EMPTY;
    }
    T data = pile[0];
    pile[0] = pile[pile.size()-1];
    pile.pop_back();
    shuffleDown();
    return data;
}

template<typename T>
T heap<T>::peek(){
    if (empty())
        throw HEAP_EMPTY;
    return pile[0];
}

template<typename T>
bool heap<T>::hasParent(int x){
    return ((x-1)/2)>=0;
}

template<typename T>
bool heap<T>::hasLeft(int x){
    return (2*x+1)<pile.size();
}

template<typename T>
bool heap<T>::hasRight(int x){
    return (2*x+2)<pile.size();
}

template<typename T>
int heap<T>::getLeftChild(int x){
    return 2*x+1;
}

template<typename T>
int heap<T>::getRightChild(int x){
    return 2*x+2;
}

template<typename T>
int heap<T>::getParent(int x){
    return (x-1)/2;
}

template<typename T>
bool heap<T>::empty() const{
    return !pile.size();
}

template<typename T>
bool heap<T>::full() const{
    return false;
}

template<typename T>
size_t heap<T>::size() const{
    return pile.size();
}

template<typename T>
void heap<T>::shuffleUp(){
    int current = pile.size()-1;
    int parent;
    while (hasParent(current) && compare(pile[parent = getParent(current)],pile[current])){
        swap(pile[parent], pile[current]);
        current = parent;
    }
}

template<typename T>
void heap<T>::shuffleDown(){
    int current = 0;
    int child;
    while (hasLeft(current) && compare(pile[child = getLeftChild(current)],current)){
        if (hasRight(current) && compare(getRightChild(current), child))
            child = getRightChild(current);
        swap(pile[child], pile[current]);
        current = child;
    }
}

template<typename T>
bool heap<T>::compare(T x, T y){
    return type ?  x>y : x<y;
}

template<typename T>
void heap<T>::swap(T &x, T &y){
    T data = x;
    x = y;
    y = data;
}

template<typename T>
void heap<T>::print(){
    for(int i = 0; i < pile.size(); i++){
        cout<<pile[i]<<endl;
    }
}

#endif //HEAPARRAY_HEAP_H
