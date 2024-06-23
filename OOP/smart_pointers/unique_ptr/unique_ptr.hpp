#ifndef UNIQUE_PTR_HPP
#define UNIQUE_PTR_HPP

template <typename T>
class unique_ptr
{
    public:
        explicit unique_ptr(T* ptr = nullptr) : m_ptr{ptr} {}
        ~unique_ptr()
        {
            delete m_ptr;
        }
        unique_ptr(const unique_ptr& rhv) = delete;
        unique_ptr(unique_ptr&& rhv) noexcept : m_ptr{rhv.m_ptr}
        {
            rhv.m_ptr = nullptr; 
        }

    public:
        unique_ptr& operator=(const unique_ptr& rhv) = delete;
        unique_ptr& operator=(unique_ptr&& rhv) noexcept
        {
            if(this != &rhv)
            {
                delete m_ptr;
                m_ptr = rhv.m_ptr;
                rhv.m_ptr = nullptr;
            }
            return *this;
        }

    public:
        T* operator->()
        {
            return m_ptr;
        }
        T& operator*()
        {
            return *m_ptr;
        }
        T* get()const
        {
            return m_ptr;
        }
        void reset(T* ptr = nullptr)
        {
            if(m_ptr != nullptr)
            {
                delete m_ptr;
                m_ptr = ptr;
            }
        }
        T* release()
        {
            T* temp = m_ptr;
            m_ptr = nullptr;
            return temp;
        }
        void swap(unique_ptr& rhv)
        {
            T* temp = m_ptr;
            m_ptr = rhv.m_ptr;
            rhv.m_ptr = m_ptr;
        }
    private:
        T* m_ptr;
};

#endif