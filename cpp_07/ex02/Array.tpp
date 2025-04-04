#include "Array.hpp"

template <typename T>
Array<T>::Array() : arr(NULL), len(0) {
    std::cout<< "Default constructor is called !\n";
}

//????
template <typename T>
Array<T>::Array(unsigned int n) {
    if (n == 0)
        arr= NULL;
    else{
        arr = new T[n];
        len = n;
		for (size_t i = 0; i < len; i++)
			arr[i] = T();
    }
}

template <typename T>
Array<T>::Array(const Array& original) { //why Array& but not Array<T>&
    if (original.len == 0)
        arr = NULL;
    else {
        arr = new T[original.len];
        this->len = original.len;
        for (size_t i = 0; i < len; i++)
        {
            arr[i] = original[i];
        }
    }
}
template <typename T>
const T& Array<T>::operator[](size_t index) const {
    if (index >= len)
        throw std::out_of_range("Index is out of range");
    return arr[index];
}
template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& original) {
    if (original.len == 0)
        arr = NULL;
    
    if (this != &original) {
        delete[] arr;
        //len = original.len;
        arr = new T[original.len];
        this->len = original.len;
        if (len > 0) {
            for (size_t i = 0; i < len; i++)
            {
                arr[i] = original[i];
            }
        }
    }
    return (*this);
}

template <typename T>
T&	Array<T>::operator[](size_t index) {
    if (index >= len)
        throw std::out_of_range("Index is out of range");
    return arr[index];
}
//whyyyyyy?


template <typename T>
size_t Array<T>::size() {
    if (!arr)
        len = 0;
    return (len);
}

template <typename T>
Array<T>::~Array() {
    if (len == 0)
        arr = NULL;
    else {
        delete[] arr;
        arr = NULL;
        this->len = 0;
    }
}

