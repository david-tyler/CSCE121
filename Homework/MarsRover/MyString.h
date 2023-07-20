// TODO: Implement this header file
#ifndef _MyString_H
#define _MyString_H

#include <iostream>
#include <fstream>
#include <tuple>
#include <limits>
#include <stdexcept>

class MyString{
private:
    size_t capacity_var;
    size_t size_var;
    char* str;
public:
    MyString();
    MyString(const MyString& src);//Copy constructor
    ~MyString();//Destructor
    MyString(const char* s);//Copies the null-terminated character sequence (C-string) pointed by s
    void resize(size_t n);
    size_t capacity() const;
    size_t size() const;
    size_t length() const; //exact same as size
    const char* data() const; //This function returns the internal character array’s reference 
    //because it is actually a c-string on the inside, so remember the null terminator
    bool empty() const; //Returns whether the string is empty (i.e. whether its length is 0)
    const char& front() const; //Returns a reference to the first character of the string.
    const char& at(size_t pos) const; //Remember to do bounds checking and throw the exception if out of bounds
    void clear(); //Erases the contents of the string, which becomes an empty string (with a length of 0 characters).
    friend std::ostream& operator<< (std::ostream& os, const MyString& src);
    MyString& operator+= (const MyString& src);
    MyString& operator= (const MyString& src);
    size_t find (const MyString& src, size_t pos = 0) const;
    friend bool operator== (const MyString& first, const MyString& second);
    friend MyString operator+ (const MyString& first, const MyString& second);


};







#endif