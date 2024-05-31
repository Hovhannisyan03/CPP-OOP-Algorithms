#include <iostream>
#include "string.h"

//Default
String::String() : m_size{1}, m_arr{nullptr}
{
    allocate();
    m_arr[0] = '\0';
    std::cout << "default" << std::endl;
}

// Parameter Ctor
String::String(const char *arr) : m_size{len(arr)}, m_arr{new char[m_size]}
{  
    std::cout << "parameter ctor" << std::endl;
    int i = 0;
    while(arr[i] != '\0')
    {
        m_arr[i] = arr[i];
        ++i;
    }
    m_arr[i] = '\0';
}

//Copy Ctor
String::String(const String& obj) : m_size{1}, m_arr{nullptr}
{
    std::cout << "copy ctor"<< std::endl;
    m_size = obj.m_size;
    allocate();
    int i = 0;
    while(obj.m_arr[i] != '\0')
    {
        m_arr[i] = obj.m_arr[i];
        ++i;
    }
    m_arr[i] = '\0';
}

// Copy Assignment Operator
String& String::operator=(const String& obj)
{
    std::cout << "copy assignment ctor" << std::endl;
    if(this == &obj)
    {
        return *this;
    }

    delete m_arr;
    m_arr = nullptr;

    m_size = obj.m_size;
    allocate();

    int i = 0;
    while(obj.m_arr[i] != '\0')
    {
        m_arr[i] = obj.m_arr[i];
        ++i;
    }
    m_arr[i] = '\0';

    return *this;
}

//Move ctor
String::String(String&& obj) noexcept
{   
    std::cout << "move ctor" << std::endl;
    m_size = obj.m_size;
    m_arr = obj.m_arr;

    obj.m_arr = nullptr;
    obj.m_size = 1;
}

// Move assignment operator
String& String::operator=(String&& obj) noexcept
{
    std::cout << "move assignment" << std::endl;
    if(this == &obj)
    {
        return *this;
    }
    delete m_arr;
    m_arr = nullptr;

    m_size = obj.m_size;
    m_arr = obj.m_arr;

    obj.m_arr = nullptr;
    obj.m_size = 1;
    
    return *this;
}

// operator +
String String::operator+(const String& obj)
{
    std::cout << "operator+" << std::endl;
    String str;
    str.m_size = m_size + obj.m_size;
    str.m_arr = new char[str.m_size];
    int i = 0;
    while(m_arr[i] != '\0')
    {
        str.m_arr[i] = m_arr[i];
        ++i;
    }
    str.m_arr[i] = ' ';
    ++i;
    int j = 0;
    while(obj.m_arr[j] != '\0')
    {
        str.m_arr[i] = obj.m_arr[j];
        ++i;
        ++j;
    }

    str.m_arr[i] = '\0';
    return str;
}

//operator +(char)
String String::operator+(const char* str)
{
    std::cout << "operator+(char)" << std::endl;
    String res;
    res.m_size = m_size + len(str);
    res.m_arr = new char[res.m_size];
    int i = 0;
    while(m_arr[i] != '\0')
    {
        res.m_arr[i] = m_arr[i];
        ++i;
    }
    res.m_arr[i] = ' ';
    ++i;
    int j = 0;
    while(str[j] != '\0')
    {
        res.m_arr[i] = str[j];
        ++i;
        ++j;
    }
    res.m_arr[i] = '\0';
    return res;
}

//operator +=
String String::operator+=(const String& obj)
{
    std::cout << "Operator+=" << std::endl;
    char *arr = m_arr;
    m_arr = nullptr;
    m_size += len(obj.m_arr) - 1;
    allocate();
    int i = 0;
    while(arr[i] != '\0')
    {
        m_arr[i] = arr[i];
        ++i;
    }
    int j = 0;
    while(obj.m_arr[j] != '\0')
    {
        m_arr[i] = obj.m_arr[j];
        ++j;
        ++i;
    }
    m_arr[i] = '\0';
    delete []arr;
    arr = nullptr;
    return *this;
}

//operator+= (char)
String String::operator+=(const char* str)
{
    std::cout << "operator+=(char)" << std::endl;
    char *arr = m_arr;
    m_arr = nullptr;
    m_size += len(str) - 1;
    allocate();
    int i = 0;
    while(arr[i] != '\0')
    {
        m_arr[i] = arr[i];
        ++i;
    }
    int j = 0;
    while(str[j] != '\0')
    {
        m_arr[i] = str[j];
        ++j;
        ++i;
    }
    m_arr[i] = '\0';
    delete []arr;
    arr = nullptr;
    return *this;
}

//operator==
bool String::operator==(const String& rhs)
{   
    std::cout << "operator==" << std::endl;
    if(m_size == rhs.m_size)
    {
        int count = 0;
        while((m_arr[count] == rhs.m_arr[count]) && (count != m_size))
        {
            ++count;
        }
        return count == m_size;
    }
    return false;
}

//operator==(char)
bool String::operator==(const char* rhs)
{   
    std::cout << "operator== (char)" << std::endl;
    if(m_size == len(rhs))
    {
        int count = 0;
        while((m_arr[count] == rhs[count]) && (count != m_size))
        {
            ++count;
        }
        return count == m_size;
    }
    return false;
}

//cast operator (string -> char)
String::operator const char*()
{
    return m_arr;
} 

//cast operator(string -> int)
String::operator int()
{
    return m_size;
}

String& String::append(const String& obj)
{   
    m_size = m_size + obj.m_size;
    char *arr = new char[m_size];
    int i = 0;

    while(m_arr[i] != '\0')
    {
        arr[i] = m_arr[i];
        ++i; 
    }
    arr[i] = ' ';
    ++i;
    int j = 0;
    while(obj.m_arr[j] != '\0')
    {
        arr[i] = obj.m_arr[j];
        ++i;
        ++j;
    }
    arr[i] = '\0';
    delete []m_arr;
    m_arr = arr;
    return *this;

}

String& String::append(const char* str)
{
    m_size = m_size + len(str);
    char *arr = new char[m_size];
    int i = 0;
    while(m_arr[i] != '\0')
    {
        arr[i] = m_arr[i];
        ++i; 
    }
    arr[i] = ' ';
    ++i;
    int j = 0;
    while(str[j] != '\0')
    {
        arr[i] = str[j];
        ++i;
        ++j;
    }
    arr[i] = '\0';
    delete []m_arr;
    m_arr = arr;

    return *this;
}

size_t String::size()
{
    return m_size - 1;
}

char* String::c_str()
{
    return m_arr;
}

char& String::at(size_t pos)
{
    if(pos < m_size - 1)
    {
        return m_arr[pos];
    }
    throw std::invalid_argument("Invalid index");
}

char& String::back()
{
    return m_arr[m_size - 2];
}
char& String::front()
{
    return m_arr[0];
}

void String::clear()
{
    delete []m_arr;
    m_arr = nullptr;

    m_size = 1;
    allocate();
    m_arr[0] = '\0';
}

bool String::empty() const noexcept
{
    if(m_size == 1)
    {
        return true;
    }
    return false;
}

//private
void String::allocate()
{   
    delete []m_arr;
    m_arr = new char[m_size];
}

size_t String::len(const char* arr)
{
    int len = 0;
    while(arr[len] != '\0')
    {
        ++len;
    }

    return len + 1;
}

void String::display()
{   
    std::cout << m_arr;
}
