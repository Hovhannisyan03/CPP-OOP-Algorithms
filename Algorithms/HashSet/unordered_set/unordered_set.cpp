#include "unordered_set.h"

unordered_set::unordered_set() : m_size{0},m_arr{nullptr}{}


int unordered_set::hash_function(int key) 
{
    int prime = 31;
    int hash_value = 0;
    while (key != 0) 
    {
        hash_value = (prime * hash_value + key % 10) % m_size;
        key /= 10;
    }
    return hash_value;
}

int unordered_set::quadratie_probing(int i)
{
    return (i * i + i) / 2;
}

void unordered_set::insert(int key)
{
    if(load_factor() > 0.7)
    {
        reHash();
    }
    int index = hash_function(key);
    
    if(m_arr[index].empty())
    {
        m_arr[index].push_back(key);
        return;
    } 
    else if(m_arr[index].front() == key)
    {
        return;
    }

    int i = 0;
    int another_index = (index + quadratie_probing(i)) % m_size;
    while(!m_arr[another_index].empty() && m_arr[another_index].front() != key && i < m_size)
    {
        ++i;
        another_index = (index + quadratie_probing(i)) % m_size;
    }
    
    if(m_arr[another_index].empty())
    {
        m_arr[another_index].push_back(key);
    }
}

void unordered_set::remove(int key)
{
    if(m_size == 0)
    {
        return;
    }

    int index = hash_function(key);
    if(!m_arr[index].empty() && m_arr[index].front() == key)
    {
        m_arr[index].clear();
        return;
    }
    int i = 0;
    int another_index = (index + quadratie_probing(i)) % m_size;
    while(!m_arr[another_index].empty() && m_arr[another_index].front() != key && i < m_size)
    {
        ++i;
        another_index = (index + quadratie_probing(i)) % m_size;
    }

    if(!m_arr[another_index].empty())
    {
        m_arr[another_index].clear();
    }
}

bool unordered_set::search(int key)
{
    if(m_size == 0)
    {
        return false;
    }
    int index = hash_function(key);
    if(!m_arr[index].empty() && m_arr[index].front() == key)
    {
        return true;
    }
    
    int i = 0;
    int another_index = (index + quadratie_probing(i)) % m_size;
    while(!m_arr[another_index].empty() && m_arr[another_index].front() != key && i < m_size)
    {
        ++i;
        another_index = (index + quadratie_probing(index)) % m_size;
    }
    if(!m_arr[another_index].empty() && m_arr[another_index].front() == key)
    {
        return true;
    }
    return false;
}

float unordered_set::load_factor()
{  
    if(m_size == 0)
    {
        return 1;
    }
    return static_cast<float>(size())/static_cast<float>(m_size);
}

void unordered_set::print()
{
    for(int i = 0; i < m_size; ++i)
    {
        if(!m_arr[i].empty())
        {
            std::cout << m_arr[i].front() << std::endl;
        }
    }
}

void unordered_set::reHash()
{
    int old_size = m_size;
    m_size = nextPrime(m_size*2);
    LinkedList *newArr = new LinkedList[m_size];
    
    for (int i = 0; i < old_size; ++i) 
    {
        for (auto it = m_arr[i].begin(); it != m_arr[i].end(); ++it) 
        {
            int index = hash_function(*it);
            if(newArr[index].empty())
            {
                newArr[index].push_back(*it);
                continue;
            }
            int j = 0;
            int another_index = (index + quadratie_probing(j)) % m_size;
            while(!newArr[another_index].empty() && newArr[another_index].front() != *it && j < m_size)
            {
                ++j;
                another_index = (index + quadratie_probing(j)) % m_size;
            }
            
            if(newArr[another_index].empty())
            {
                newArr[another_index].push_back(*it);
            }
        }
        m_arr[i].clear();
    }
    delete[] m_arr;
    m_arr = newArr;   
}


int unordered_set::size()
{
    int count_of_numbers = 0;
    for(int i = 0; i < m_size; ++i)
    {
        if(!m_arr[i].empty())
        {
            ++count_of_numbers;
        }
    } 
    return count_of_numbers;
}

bool unordered_set::isPrime(int num) 
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
 

int unordered_set::nextPrime(int num)
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
