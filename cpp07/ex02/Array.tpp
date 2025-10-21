#ifndef ARRAY_TPP
#define ARRAY_TPP

template <typename T>
Array<T>::Array() : data(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : data(new T[n]()), _size(n) {}

template <typename T>
Array<T>::~Array() {
    delete[] data;
}

template <typename T>
Array<T>::Array(const Array &other) : data(NULL), _size(0) {
    *this = other;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &other) {
    if (this != &other) {
        delete[] data;
        _size = other._size;
        data = new T[_size];
        for (unsigned int i = 0; i < _size; ++i)
            data[i] = other.data[i];
    }
    return *this;
}

template <typename T>
unsigned int Array<T>::size() const {
    return _size;
}

template <typename T>
T& Array<T>::operator[](int index) {
    if (index < 0 || index >= static_cast<int>(_size))
        throw OutOfBoundException();
    return data[index];
}

template <typename T>
const T& Array<T>::operator[](int index) const {
    if (index < 0 || index >= static_cast<int>(_size))
        throw OutOfBoundException();
    return data[index];
}

template <typename T>
const char* Array<T>::OutOfBoundException::what() const throw() {
    return "Index out of bounds";
}

#endif
