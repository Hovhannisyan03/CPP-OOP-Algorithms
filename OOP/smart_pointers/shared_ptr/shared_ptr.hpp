#ifndef SHARED_PTR_HPP
#define SHARED_PTR_HPP
#include <iostream>

template <typename T>
class shared_ptr
{   
    public:
        explicit shared_ptr(T* ptr = nullptr) : m_ptr{ptr}, m_count{new size_t(1)}{}
        ~shared_ptr()
        {
            release();
        }
        shared_ptr(const shared_ptr& rhv) : m_ptr{rhv.m_ptr}, m_count{rhv.m_count}
        {
            ++(*m_count);
        }
        shared_ptr(shared_ptr&& rhv) : m_ptr{rhv.m_ptr}, m_count{rhv.m_count}
        {
            rhv.m_ptr = nullptr;
            rhv.m_count = nullptr;
        }

    public:
        shared_ptr& operator=(const shared_ptr& rhv) 
        {
            if(this != &rhv)
            {
                release();
                m_ptr = rhv.m_ptr;
                m_count= rhv.m_count;
                ++(m_count);
            }
            return *this;
        }

        shared_ptr& operator=(shared_ptr&& rhv) 
        {
            if(this != &rhv)
            {
                release();
                m_ptr = rhv.m_ptr;
                m_count= rhv.m_count;

                rhv.m_ptr = nullptr;
                rhv.m_count = nullptr;
            }
            return *this;
        }

    public:
        T& operator*()
        {
            return *m_ptr;
        }

        T* operator->()
        {
            return m_ptr;
        }

        T* get()const
        {
            return m_ptr;
        }

        size_t use_count() const
        {
            return *m_count;
        }

        void reset(T* p = nullptr)
        {
            release();
            m_ptr = p;
            m_count = new size_t(1);
        }

        bool unique()const
        {
            return *m_count == 1;
        }

        void swap(shared_ptr& rhv)
        {
            T* temp_ptr = m_ptr;
            m_ptr = rhv.m_ptr;
            rhv.m_ptr = temp_ptr;

            size_t* temp_count = m_count;
            m_count = rhv.m_count;
            rhv.m_count = temp_count;
        }

        bool owner_before(const shared_ptr& rhv)
        {
            return m_count < rhv.m_count;
        }

    private:
        void release()
        {
            if(m_count)
            {
                (*m_count)--;
                if(*m_count == 0)
                {
                    delete m_ptr;
                    delete m_count;
                }
                m_ptr = nullptr;
                m_count = nullptr;
            }
        }

    private:
        T* m_ptr;
        size_t* m_count;
};
#endif