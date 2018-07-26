#ifndef MYMAP_H
#define MYMAP_H
#include <iomanip>
#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
namespace x
{
    enum MAP_ERRORS {KEY_NOT_FOUND};
    template<typename sKey, typename sValue>
    struct pair
    {
        sKey first;
        sValue second;
        pair<sKey, sValue> *next;

        pair()
        {
            first = sKey();
            second = sValue();
            next = NULL;
        }
        //TODO ask why only first needs explicit initialization
        pair(const sKey &k, const sValue &v):first(k)
        {
            //first = k;
            second = v;
            next = NULL;
        }

        pair(const pair<sKey,sValue> &other):first(other.first)
        {
            //first = other.first;
            second = other.second;
            next = NULL;
        }
    };

    template<typename Key, typename Value>
    class myMap
    {
    public:

        class iterator
        {
        public:
            iterator( pair<Key, Value> *thePair)
            {
                start = thePair;
            }

            ~iterator()
            {

            }
            bool operator!=(const iterator &x){
                return x.start != start;
            }
            bool operator==(const iterator &x){
                return !(this!=x);
            }

            pair<Key,Value> operator*()
            {
                return *start;
            }

            pair<Key, Value>* operator->()
            {
                return start;
            }

            iterator(const iterator &other)
            {
                start = other.start;
            }

            iterator& operator=(const iterator &other)
            {
                if(this != &other)
                    start = other.start;
                return *this;
            }

            iterator operator++()
            {
                start=start->next;
                return *this;
            }
            iterator operator--()
            {
                start=start->next;
                return *this;
            }

            iterator operator++(int)
            {
                start=start->next;
                return *this;
            }


        private:
            pair<Key, Value> *start;
        };

        myMap();
        ~myMap();
        myMap(const myMap<Key, Value> &other);
        myMap<Key, Value>& operator=(const myMap<Key, Value> &other);
        Value& operator[] (const Key& k);
        Value& at (const Key& k);
        const Value& at (const Key& k) const;
        iterator find(Key k);
        size_t count(const Key &k);
        iterator begin();
        iterator end();
        bool empty();
        size_t size();
        size_t max_size();
        pair<iterator,bool> insert (const pair<Key,Value>& val);
        void erase (iterator position);
        size_t erase (const Key& k);
        void erase (iterator first, iterator last);
        void swap (myMap<Key, Value>& x);
        void clear();

    private:
        pair<Key, Value> anchor;
        unsigned int mySize, maxSize;

        void copy(const myMap<Key, Value>& other);
        void nukem();
    };


    template<typename Key, typename Value>
    myMap<Key, Value>::myMap()
    {
        mySize = 0;
        maxSize = 32767;
    }

    template<typename Key, typename Value>
    myMap<Key, Value>::~myMap()
    {
        nukem();
    }

    template<typename Key, typename Value>
    myMap<Key, Value>::myMap(const myMap<Key, Value> &other)
    {
        copy(other);
    }

    template<typename Key, typename Value>
    myMap<Key, Value>& myMap<Key, Value>::operator=(const myMap<Key, Value> &other)
    {
        if(this != &other)
        {
            clear();
            copy(other);
        }
        return *this;
    }

    template<typename Key, typename Value>
    Value& myMap<Key, Value>::operator[] (const Key& k)
    {
        iterator it = find(k);
        if(it != end())
            return it->second;
        else
            return insert(pair<Key,Value>(k, Value())).first->second;
    }

    template<typename Key, typename Value>
    Value& myMap<Key, Value>::at(const Key& k)
    {
        if (k)
            return (*this)[k];
        else
            throw KEY_NOT_FOUND;
    }

    template<typename Key, typename Value>
    const Value& myMap<Key, Value>::at(const Key& k) const
    {
        return (*this).at(k);
    }

    template<typename Key, typename Value>
    typename myMap<Key,Value>::iterator myMap<Key, Value>::find(Key k)
    {
        iterator it = begin();
        for(; it != end() && it->first != k; it++);
        return it;
    }

    template<typename Key, typename Value>
    size_t myMap<Key, Value>::count(const Key &k)
    {
        iterator it = begin();
        for(; it != end() && it->first != k; it++);
        return it != end() ? 1 : 0;
    }

    template<typename Key, typename Value>
    bool myMap<Key, Value>::empty()
    {
        return !mySize;
    }

    template<typename Key, typename Value>
    size_t myMap<Key, Value>::size()
    {
        return mySize;
    }

    template<typename Key, typename Value>
    size_t myMap<Key, Value>::max_size()
    {
        return maxSize;
    }

    template<typename Key, typename Value>
    pair<typename myMap<Key, Value>::iterator,bool> myMap<Key, Value>::insert(const pair<Key, Value> &who)
    {
        pair<Key, Value> *ptr = &anchor, *newPair = new pair<Key,Value>(who);
        while(ptr->next && ptr->next->first <= who.first) {
            if (ptr->next->first == who.first)
                return pair<iterator, bool>(ptr->next, false);
            ptr=ptr->next;
        }
        newPair->next = ptr->next;
        ptr->next = newPair;
        return pair<iterator,bool>(ptr->next,true);

    }



    template<typename Key, typename Value>
    typename myMap<Key,Value>::iterator myMap<Key,Value>::begin()
    {
        return iterator(anchor.next);
    }

    template<typename Key, typename Value>
    typename myMap<Key,Value>::iterator myMap<Key,Value>::end()
    {
        return iterator(NULL);
    }

    template<typename Key, typename Value>
    void myMap<Key, Value>::erase (iterator position)
    {
        this->erase(position->first);
    }

    template<typename Key, typename Value>
    size_t myMap<Key, Value>::erase (const Key& k)
    {
        pair<Key,Value> *ptr = &anchor;
        for(;ptr->next && ptr->next->first != k; ptr = ptr->next) ;
        if (ptr->next->first==k) {
            pair<Key, Value> *x = ptr->next;
            //ptr->next = ptr->next->next;
            ptr->next = x->next;
            delete x;
        }
        return ptr->next ? 1 : 0;
    }

    template<typename Key, typename Value>
    void myMap<Key, Value>::erase (iterator first, iterator last)
    {
        for (; first != last; first = first->next){
            if (first->first)
                erase(first->first);
        }

    }

    template<typename Key, typename Value>
    void myMap<Key, Value>::swap(myMap<Key, Value>& other)
    {
        pair<Key, Value> *temp = anchor.next;
        anchor.next = other.anchor.next;
        other.anchor.next = temp;
    }

    template<typename Key, typename Value>
    void myMap<Key, Value>::clear()
    {
        mySize = 0;
        nukem();
    }

    template<typename Key, typename Value>
    void myMap<Key, Value>::copy(const myMap<Key, Value>& other)
    {
        ;
        for( pair<Key, Value> *me = &anchor, *you = other.anchor.next;
             you; you++)
        {
            me->next = new pair<Key,Value>(*you);
            me = me->next;
        }
    }

    template<typename Key, typename Value>
    void myMap<Key, Value>::nukem()
    {
        pair<Key,Value> *goodBye;
        while(anchor.next)
        {
            goodBye = anchor.next;
            anchor.next = goodBye->next;
            delete goodBye;
        }
        mySize = 0;
    }

    template<typename X, typename Y>
    bool operator!=(const typename myMap<X,Y>::iterator &x, const typename myMap<X,Y>::iterator &y)
    {
        return x.start != y.start;
    }

}
#endif // MYMAP_H