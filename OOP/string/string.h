    #include <iostream>
#ifndef STRING_H
#define STRING_H

class String 
{   
    public:
        String();
        String(const char* str);
        String(const String& obj);
        String(String&& obj)noexcept;
        ~String(){ delete[]m_arr;}
    public:
        String& operator=(const String& obj);
        String& operator=(String&& obj) noexcept;
        String operator+(const String& obj);
        String operator+(const char* str); 
        String operator+=(const String& obj);
        String operator+=(const char* str);
        friend std::ostream& operator<<(std::ostream& stream, const String& obj)
        {
            stream << obj.m_arr;
            return stream; 
        } 
        friend std::istream& operator>>(std::istream& stream, String& obj)
        {
            stream >> obj.m_arr;
            obj.m_size = obj.len(obj.m_arr);
            return stream; 
        }
    public:
        explicit operator const char*();
        explicit operator int();
        bool operator==(const String& rhs);
        bool operator==(const char* rhs);
        String& append(const String& obj);
        String& append(const char* str);
        size_t size();
        char* c_str();
        char& at(size_t pos);
        char& back();
        char& front();
        void clear();
        bool empty() const noexcept;
        void display();
    private:
        void allocate();
        size_t len(const char *arr);
        size_t m_size;
        char *m_arr;

};
#endif