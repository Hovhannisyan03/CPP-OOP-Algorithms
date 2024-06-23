#ifndef AUTO_PTR_HPP
#define AUTO_PTR_HPP

template <typename T>
class auto_ptr
{
    public:
        explicit auto_ptr(T* ptr = nullptr) : m_ptr{ptr} {}
        ~auto_ptr()
        {
            delete m_ptr;
        }
        auto_ptr(const auto_ptr& rhv) = delete;
        auto_ptr(auto_ptr&& rhv) noexcept : m_ptr{rhv.m_ptr}
        {
            rhv.m_ptr = nullptr; 
        }

    public:
        auto_ptr& operator=(const auto_ptr& rhv) = delete;
        auto_ptr& operator=(auto_ptr&& rhv) noexcept
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
    private:
        T* m_ptr;
};

#endif