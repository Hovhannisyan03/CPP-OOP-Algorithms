#include "unordered_map.h"

unordered_map::unordered_map() : m_map{nullptr}, m_key{""}, m_val{0} {}

unsigned long long unordered_map::hash_function(const std::string& str) 
{
    unsigned long long hash_val = 0;
    for (size_t i = 0; i < str.length(); ++i) 
    {
        hash_val += static_cast<unsigned long long>(str[i]) * (i + 1);
    }
    return hash_val;
}

void unordered_map::insert(std::string key, int val)
{
    if(load_factor() < 0.7)
    {
        reHash();
    }
    int index = hash_function(key);
    m_map[index].push_front(val);
}

void unordered_map::remove(int key)
{
    if(m_size == 0)
    {
        return;
    }
    int index = hash_function(key);

}

void unordered_map::reHash()
{

}


void unordered_map::print()
{
    for(int i = 0; i < m_size; ++i)
    {
        if(!m_map[i].empty())
        {
            for(auto& elem : m_map[i])
            {
                std::cout << elem << " ";
            }
            std::cout << std::endl;
        }
    }
}

float unordered_map::load_factor()
{
    if(m_size == 0)
    {
        return 1;
    }
    return static_cast<float>(size()) / static_cast<float>(m_size);
}

int unordered_map::size()
{
    int size = 0;
    for(int i = 0; i < m_size; ++i)
    {
        if(!m_map[i].empty())
        {
            ++size;
        }
    }
    return size;
}

bool unordered_map::isPrime(int num) 
{ 
    if (num <= 1) 
    {   
        return false;
    } 
    if (num <= 3)  
    {
        return true; 
    }
   
    if (num%2 == 0 || num%3 == 0) 
    {
        return false; 
    }
   
    for (int i = 5; i * i <= num; i = i + 6) 
    {
        if (num % i == 0 || num % (i + 2) == 0) 
        {
           return false; 
        }
    }
    return true; 
} 
 

int unordered_map::nextPrime(int num)
{
 
    if (num <= 1)
    {
        return 2;
    }
    int prime = num;
    bool found = false;
 
    while (!found) 
    {
        prime++;
 
        if (isPrime(prime))
        {
            found = true;
        }
    }
 
    return prime;
}
