#ifndef UNORDERED_MAP_H
#define UNORDERED_MAP_H

#include<iostream>
#include "LinkedList.h"

class unordered_map
{
    public:
        unordered_map();
        void insert(std::string key, int value);
        void remove(int key);
        // bool search(int key);
        float load_factor();
        void print();
        int size();
    private:
        LinkedList *m_map;
        std::string m_key;
        int m_val;
        int m_size;
        unsigned long long hash_function(const std::string& key);
        void reHash();
        bool isPrime(int num);
        int nextPrime(int num);
};

#endif