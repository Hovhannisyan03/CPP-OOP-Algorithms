#ifndef UNORDERED_SET_H
#define UNORDERED_SET_H
#include "LinkedList.h"
#include <initializer_list>

class unordered_set
{
    public:
        unordered_set();
        void insert(int key);
        void remove(int key);
        bool search(int key);
        float load_factor();
        void print();
        int size();
    private:
        int m_size;
        LinkedList *m_arr;
        int hash_function(int key);
        int quadratie_probing(int i);
        void reHash();
        bool isPrime(int num);
        int nextPrime(int num);
};
#endif