#include <iostream>

Vector::Vector(size_type size)
{
    this->size = size;
    capacity = size;
    arr = new value_type[capacity];
}

Vector::Vector(const Vector& obj)
{
    size = obj.size;
    capacity = obj.capacity;
    arr = new value_type[size];
    for(int i = 0; i < size; ++i)
    {
        arr[i] = obj.arr[i];
    }
}
Vector::Vector(std::initializer_list<value_type> obj)
{
    size = obj.size();
    capacity = size;
    arr = new value_type[capacity];
    int i = 0;
    for(value_type elem : obj)
    {
        arr[i] = elem;
        ++i;
    }

}
Vector& Vector::operator=(const Vector& obj)
{
    if(this == &obj)
    {
        return *this;
    }
    delete []arr;
    size = obj.size;
    capacity = obj.capacity;
    arr = new value_type[size];
    
    for(int i = 0; i < size; ++i)
    {
        arr[i] = obj.arr[i];
    }
    return *this;
}

Vector::Vector(size_type size, value_type value)
{   
    this->size = size;
    capacity = size;
    arr = new value_type[capacity];
    for(int i = 0; i < size; ++i)
    {
        arr[i] = value;
    }
}
void Vector::assign(size_type size, const Vector& obj)
{
    if(this->size >= size)
    {   
        this->size = size;
        capacity = size;
        return;
    }
    resize();
    for(int i = 0; i < size; ++i)
    {
        arr[i] = obj.arr[i];
    }
    this->size = size;
    capacity = size;
}

Vector::pointer Vector::data()
{
    return arr; 
}

void Vector::clear()
{
    delete []arr;
    arr = nullptr;
    size = 0;
    capacity = 0;
}

Vector::pointer Vector::begin()
{
    return arr;
}

Vector::pointer Vector::end()
{
    return arr + size;
}

void Vector::p_front(int val)
{   
    int tmp = 0;
    ++size;
    for(int i = 0; i < size; ++i)
    {
        tmp = arr[i];
        arr[i] = val;
        val = tmp;
    }
}

void Vector::assign(std::initializer_list<value_type> obj)
{
    if(capacity < obj.size())
    {
        resize();
    }
    int i = 0;
    for(value_type elem : obj)
    {
        arr[i] = elem;
        ++i;
    }
    size = obj.size();
}

void Vector::insert(size_type index, value_type value)
{
    pointer newArr;
    capacity = capacity == 0 ? 1 : capacity;
    if((index <= size - 1) && (index >= 0))
    {
        if(size == capacity || size == 0)
        {
            resize();
        }
        ++size;
        value_type j = 0;
        newArr = new value_type[capacity];
        for(int i = 0; i < size; ++i)
        {   
            if(i == index)
            {
                newArr[i] = value;
            }
            else
            {
                newArr[i] = arr[j];
                ++j;
            }
        }
    }
    else 
    {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    delete []arr;
    arr = newArr;
    return;
}
Vector::value_type Vector::sizee()
{
    return size;
}

Vector::value_type Vector::capacityy()
{
    return capacity;
}

bool Vector::empty()
{
    if(size == 0)
    {
        return true;
    }
    return false;
}

Vector::value_type Vector::at(size_type index)
{
    if(index >= 0 && index <= size - 1)
    {
        return arr[index];
    }
    return 0;
}

Vector::reference Vector::operator[](size_type index)
{
    return arr[index];
}

void Vector::push_back(value_type value)
{   
    capacity = capacity == 0 ? 1 : capacity;
    if(size == capacity || size == 0)
    {
        resize();
    }
    arr[size] = value;
    ++size;
    return;
}

void Vector::pop_back()
{   
    if(size == 0)
    {
        std::cout << "Array is empty" << std::endl;
        return;
    }
    --size;
    return;
}

void Vector::resize()
{   
    capacity *= 2;
    pointer newArr = new value_type[capacity];
    for(int i = 0; i < size; ++i)
    {
        newArr[i] = arr[i];
    }
    delete []arr;
    arr = newArr;
}

void Vector::display_vec()
{    
    if(size == 0)
    {
        std::cout << "Vector is empty" << std::endl;
        return;
    }
    for(int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void Vector::shrinkToFit()
{
    pointer newArr = new value_type[size];
    for(int i = 0; i < size; ++i)
    {
        newArr[i] = arr[i];
    }
    delete[]arr;
    arr = newArr;
    capacity = size;
}

Vector::reference Vector::front()
{
    return arr[0];
}

Vector::reference Vector::back()
{
    return arr[size-1];
}

Vector::value_type Vector::find(value_type value)
{
    for(int i = 0; i < size; ++i)
    {
        if(arr[i] == value)
        {
            return i;
        }
    }
    return -1;
}

void Vector::unique()
{
    pointer newArr = new value_type[size];
    value_type size1 = 0;
    value_type count = 0;
    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size1; ++j)
        {
            if(arr[i] == newArr[j])
            {
                ++count;
            }
        }
        if(count == 0)
        {
            newArr[size1] = arr[i];
            ++size1;
        }
        count = 0;
    }
    delete []arr;
    arr = newArr;
    size = size1;
}

void Vector::reverse()
{   
    value_type j = 1;
    for(int i = 0; i < size/2; ++i)
    {
        value_type tmp = arr[i];
        arr[i] = arr[size - j];
        arr[size - j] = tmp;
        ++j;
    } 
}

void Vector::sort()
{
    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size; ++j)
        {
            if(arr[i] < arr[j])
            {
                value_type tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
        }
    }
}

void Vector::push_front(value_type value)
{
    capacity = capacity == 0 ? 1 : capacity;
    if(size == capacity || size == 0)
    {
        resize();
    }
    value_type tmp = 0;
    ++size;
    for(int i = 0; i < size; ++i)
    {   
        if(i == 0)
        {
            tmp = arr[i];
            arr[i] = value;
            continue;
        }
        else if(i == size - 1)
        {
            arr[i] = tmp;
        }
        value = arr[i];
        arr[i] = tmp;
        tmp = value;
    }
    return;
}


void Vector::pop_front()
{
    if(size == 0)
    {
        std::cout << "Array is empty" << std::endl;
        return;
    }
    for(int i = 0; i < size; ++i)
    {
        arr[i] = arr[i+1];
    }
    --size;
    return;
}

Vector::~Vector()
{
    empty();
}






