#pragma once

#include <exception>

template <typename T>
class Array {
private:
    T*              _elements;
    unsigned int    _size;

public:
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array();

    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;
    
    unsigned int size() const;

    class OutOfBoundsException : public std::exception {
    public:
        virtual const char* what() const noexcept override;
    };
};

// Include the template implementation file at the end
#include "Array.tpp"