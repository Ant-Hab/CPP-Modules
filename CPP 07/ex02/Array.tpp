#pragma once

// Default constructor
template <typename T>
Array<T>::Array() : _elements(nullptr), _size(0) {}

// Parameterized constructor
template <typename T>
Array<T>::Array(unsigned int n) : _elements(new T[n]()), _size(n) {}

// Copy constructor
template <typename T>
Array<T>::Array(const Array& other) : _elements(nullptr), _size(0) {
    if (other._size > 0) {
        _elements = new T[other._size]();
        _size = other._size;
        for (unsigned int i = 0; i < _size; ++i) {
            _elements[i] = other._elements[i];
        }
    }
}

// Assignment operator
template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        delete[] _elements;
        _size = other._size;
        if (_size > 0) {
            _elements = new T[_size]();
            for (unsigned int i = 0; i < _size; ++i) {
                _elements[i] = other._elements[i];
            }
        } else {
            _elements = nullptr;
        }
    }
    return *this;
}

// Destructor
template <typename T>
Array<T>::~Array() {
    delete[] _elements;
}

// Subscript operator (non-const)
template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= _size) {
        throw OutOfBoundsException();
    }
    return _elements[index];
}

// Subscript operator (const)
template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= _size) {
        throw OutOfBoundsException();
    }
    return _elements[index];
}

// Size getter
template <typename T>
unsigned int Array<T>::size() const {
    return _size;
}

// Exception what()
template <typename T>
const char* Array<T>::OutOfBoundsException::what() const noexcept {
    return "Error: Index out of bounds";
}