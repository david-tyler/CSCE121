// TODO: Implement this source file
#include "MyString.h"
#include <iostream>
#include <fstream>
#include <tuple>
#include <limits>
#include <stdexcept>

using std::cout;
using std::endl;
using std::ostream;

MyString::MyString() : capacity_var(0),  size_var(0), str(nullptr)
{
    str = new char[1];
    str[0] = '\0';
    capacity_var = 1;
}
MyString::MyString(const MyString& src) : capacity_var(src.capacity_var), size_var(src.size_var), str(nullptr)//copy constructor
{
    str = new char[capacity_var];
    for(int i = 0; src.str[i] != '\0'; i++)
    {
        str[i] = src.str[i];
    }
    str[size_var] = '\0';
}
MyString::~MyString()//destructor
{
    delete[] str;
    str = nullptr;
    size_var = 0;
    capacity_var = 0;
}
MyString::MyString(const char* s) : capacity_var(0), size_var(0), str(nullptr)//Copies the null-terminated character sequence (C-string) pointed by s
{
    if(s == nullptr || s[0] == '\0')
    {
        str = new char[1];
        str[0] = '\0';
    }
    else
    {
        size_var = 0;
        capacity_var = 0;
        for(int i = 0; s[i] != '\0'; i++)
        {
            size_var++;
        }
        capacity_var = size_var + 1;
        str = new char[capacity_var];
        //strcpy(str, s);
        for(int i = 0; s[i] != '\0'; i++)
        {
            str[i] = s[i];
        }
        str[size_var] = '\0';
    }
    
}
void MyString::resize(size_t n)
{
    if(n < size_var)
    {
        size_var = n;
        capacity_var = size_var + 1;
        char * ary = new char[n];
        for(size_t i = 0; i < n; i++)
        {
            ary[i] = str[i];
        }
        delete []str;
        str = ary;
        str[n] = '\0';
    }
    else if (n > size_var)
    {
        size_var = n;
        capacity_var = size_var + 1;
        char * ary = new char[n];
        for(int i = 0; str[i] != '\0'; i++)
        {
            ary[i] = str[i];
        }
        delete []str;
        str = ary;
        str[n] = '\0';
    }
}
size_t MyString::capacity() const
{
    return capacity_var;
}
size_t MyString::size() const
{
    return size_var;
}
size_t MyString::length() const
{
    return size_var;
}
const char* MyString::data() const
{
    return str;
}
bool MyString::empty() const
{
    if(str[0] == '\0' || str == nullptr)
        return true;
    return false;
}
const char& MyString::front() const
{
    return str[0];
}
const char& MyString::at(size_t pos) const
{
    if(str == nullptr || str[0] == '\0')
    {
        throw std::out_of_range("Out of range");
    }
    if(pos >= size_var)
    {
        throw std::out_of_range("Out of range");
    }
    return str[pos];
}
void MyString::clear()
{
    delete []str;
    str = nullptr;
    str = new char[1];
    str[0] = '\0';
    size_var = 0;
    capacity_var = 1;
}
std::ostream& operator<<(std::ostream& os, const MyString& src)
{
    for(int i = 0; src.str[i] != '\0'; i++)
    {
        os << src.str[i];
        if(os.fail())
        {
            throw std::invalid_argument("ERROR FOUND");
        }
    }

    return os;
}
MyString& MyString::operator+=(const MyString& src)
{
    if(this != &src)
    {
        capacity_var = src.capacity_var + capacity_var;
        char *ary = new char[capacity_var];
        for(int i = 0; str[i] != '\0'; i++)
        {
            ary[i] = str[i];
        }
        for(int i = 0; src.str[i] != '\0'; i ++)
        {
            ary[i+size_var] = src.str[i];//
        }
        size_var += src.size_var;
        ary[size_var] = '\0';
        delete[] str;
        str = ary;
        
    }
    return *this;
}
MyString& MyString::operator=(const MyString& src)
{
    if(this != &src)
    {
        delete []str;
        size_var = src.size_var;
        capacity_var = src.capacity_var;
        str = new char[capacity_var];
        for(int i = 0; src.str[i] != '\0'; i++)
        {
            str[i] = src.str[i];
        }
        str[size_var] = '\0';
    }
    return *this;
}
size_t MyString::find (const MyString& src, size_t pos) const
{
    size_t index = -1;
    if(pos < size_var)
    {
        for(int i = pos; str[i] != '\0'; i++)
        {
            if(str[i] == src.str[0])
            {
                index = i;
                for(int j = 0; src.str[j] != '\0'; j++)
                {
                    if(str[i+j] != src.str[j])
                    {
                        index = -1;
                        continue;
                    }
                }
            }
        }
        return index;
    }
    return -1;
}
bool operator== (const MyString& first, const MyString& second)
{
    if(first.size() == second.size() && first.capacity() == second.capacity())
    {
        for(size_t i = 0; i<first.size(); i++)
        {
            if(first.at(i) != second.at(i))
                return false;
        }
        return true;
    }
    return false;
}
MyString operator+ (const MyString& first, const MyString& second)
{
    MyString result;
    result = first;
    result += second;
    return result;
}