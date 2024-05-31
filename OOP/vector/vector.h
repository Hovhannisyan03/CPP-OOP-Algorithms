#ifndef VECTOR_H
#define VECTOR_H

class Vector
{  
    public:
        using value_type = int;
        using size_type = size_t;
        using reference = int&;
        using pointer = int*;
        using const_ref = const int&;
        using const_pointer = int *const;

        Vector() : arr{nullptr}, size{0}, capacity{0}{}
        Vector(size_type size);
        Vector(std::initializer_list<value_type> obj);
        Vector(const Vector& obj);
        Vector& operator=(const Vector& obj); 
        Vector(size_type size, value_type value);
        void assign(size_type size, const Vector& obj);
        void assign(std::initializer_list<value_type> obj);
        pointer data();
        void clear();
        void insert(size_type index, value_type value);
        value_type sizee();
        value_type capacityy();
        bool empty();
        pointer begin();
        pointer end();
        reference operator[](size_type index);
        value_type at(size_type index);
        void push_back(value_type value);
        void push_front(value_type value);
        void pop_front();
        void pop_back();
        void display_vec();
        void shrinkToFit();
        reference front();
        reference back();
        value_type find(value_type value);
        void unique();
        void reverse();
        void sort();
        void p_front(int val);
        friend std::ostream& operator<<(std::ostream& out, const Vector& obj)
        {
            out << "Arr: ";
            for(size_t i = 0; i < obj.size; ++i)
            {
                out << obj.arr[i] << " ";
            }
            out << '\n';
            return out;
        } 

        friend std::istream& operator>>(std::istream& in, Vector& obj)
        {
            std::cout << "Enter size: ";
            in >> obj.size;
            std::cout << "Enter elements: ";
            for(size_t i = 0; i < obj.size; ++i)
            {
                in >> obj.arr[i];
            }
            return in;
        }
        ~Vector();
    private:
       void resize();
       value_type *arr;
       size_type size;
       size_type capacity;  
};
#endif