#pragma once

#include <iostream>

template <typename T>
class Array {
    T* data = nullptr;
    size_t dim = 0;
    size_t cap = 1;

public:
    Array() = default;
    explicit Array(size_t inputSize);
    Array(const Array& other);
    Array(Array&& move) noexcept;
    ~Array();

    class Iterator {
        T* ptr;

    public:
        Iterator();
        explicit Iterator(T* inputPtr);

        T& operator*() { return *ptr; }

        Iterator& operator++();
        Iterator operator++([[maybe_unused]] int value);
        Iterator& operator--();
        Iterator operator--([[maybe_unused]] int value);
        Iterator& operator+=(size_t offset);
        Iterator& operator-=(size_t offset);

        friend Iterator operator+(const Iterator& itr, size_t offset) {
            return Iterator(itr.ptr + offset);
        };
        friend Iterator operator-(const Iterator& itr, size_t offset) {
            return Iterator(itr.ptr - offset);
        };
        friend ptrdiff_t operator-(const Iterator& lhs, const Iterator& rhs) {
            return lhs.ptr - rhs.ptr;
        }
        friend bool operator<(const Iterator& lhs, const Iterator& rhs) {
            return (lhs.ptr < rhs.ptr);
        }
        friend bool operator<=(const Iterator& lhs, const Iterator& rhs) {
            return (lhs.ptr <= rhs.ptr);
        }
        friend bool operator>(const Iterator& lhs, const Iterator& rhs) {
            return (lhs.ptr > rhs.ptr);
        }
        friend bool operator>=(const Iterator& lhs, const Iterator& rhs) {
            return (lhs.ptr >= rhs.ptr);
        }
        friend bool operator==(const Iterator& lhs, const Iterator& rhs) = default;

        friend bool operator!=(const Iterator& lhs, const Iterator& rhs) {
            return (lhs.ptr != rhs.ptr);
        }
    };

    Array& operator=(const Array& other);
    Array& operator=(Array&& move) noexcept;
    T& operator[](size_t index) { return data[index]; }
    T operator[](size_t index) const { return data[index]; }

    friend bool operator<(const Array& lhs, const Array& rhs) {
        return (lhs.dim < rhs.dim);
    }
    friend bool operator<=(const Array& lhs, const Array& rhs) {
        return (lhs.dim <= rhs.dim);
    }
    friend bool operator>(const Array& lhs, const Array& rhs) {
        return (lhs.dim > rhs.dim);
    }
    friend bool operator>=(const Array& lhs, const Array& rhs) {
        return (lhs.dim >= rhs.dim);
    }
    friend bool operator==(const Array& lhs, const Array& rhs) {
        if (lhs.dim != rhs.dim) {
            return false;
        }

        for (size_t i = 0; i < lhs.dim; i++) {
            if (lhs.data[i] != rhs.data[i]) {
                return false;
            }
        }

        return true;
    }
    friend bool operator!=(const Array& lhs, const Array& rhs) {
        return !(lhs == rhs);
    }

    void reserve(size_t newCap);
    bool empty() const;
    size_t size() const;
    size_t capacity() const;
    void swap(Array& other) noexcept;
    Iterator begin() const;
    Iterator end() const;
    Iterator insert(Iterator pos, const T& value);
    Iterator erase(Iterator pos);
    void clear();
    T& front();
    T& back();
    void push_back(const T& value);
    void push_front(const T& value);
    void pop_back();
    void pop_front();
};

template <typename T>
Array<T>::Array(const size_t inputSize) : dim(inputSize) {
    if (dim != 0) {
        cap = 2 * dim;
        data = new T[cap];
    }
}

template <typename T>
Array<T>::Array(const Array& other) : dim(other.dim), cap(other.cap) {
    data = new T[cap];

    for (size_t i = 0; i < dim; i++) {
        data[i] = other.data[i];
    }
}

template <typename T>
Array<T>::Array(Array&& move) noexcept
    : data(move.data), dim(move.dim), cap(move.cap) {
    move.data = nullptr;
}

template <typename T>
Array<T>::~Array() {
    delete[] data;
    data = nullptr;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this == &other) {
        return *this;
    }

    dim = other.dim;
    cap = other.cap;

    delete[] data;
    data = new T[cap];

    for (int i = 0; i < dim; i++) {
        data[i] = other.data[i];
    }

    return *this;
}

template <typename T>
Array<T>& Array<T>::operator=(Array&& move) noexcept {
    if (this == &move) {
        return *this;
    }

    dim = move.dim;
    cap = move.cap;
    data = move.data;

    move.data = nullptr;

    return *this;
}

template <typename T>
void Array<T>::reserve(size_t newCap) {
    if (newCap <= cap) return;

    auto* newData = new T[newCap];
    for (size_t i = 0; i < dim; ++i) {
        newData[i] = data[i];
    }

    delete[] data;
    data = newData;
    cap = newCap;
}

template <typename T>
bool Array<T>::empty() const {
    return dim == 0;
}

template <typename T>
size_t Array<T>::size() const {
    return dim;
}

template <typename T>
size_t Array<T>::capacity() const {
    return cap;
}

template <typename T>
void Array<T>::swap(Array& other) noexcept {
    Array tmp = *this;

    *this = other;
    other = tmp;
}

template <typename T>
Array<T>::Iterator::Iterator() : ptr(nullptr) {}

template <typename T>
Array<T>::Iterator::Iterator(T* inputPtr) : ptr(inputPtr) {}

template <typename T>
typename Array<T>::Iterator& Array<T>::Iterator::operator++() {
    ++ptr;

    return *this;
}

template <typename T>
typename Array<T>::Iterator Array<T>::Iterator::operator++(
    [[maybe_unused]] int value) {
    Array::Iterator tmp = *this;

    ptr++;

    return tmp;
}

template <typename T>
typename Array<T>::Iterator& Array<T>::Iterator::operator--() {
    --ptr;

    return *this;
}

template <typename T>
typename Array<T>::Iterator Array<T>::Iterator::operator--(
    [[maybe_unused]] int value) {
    Array::Iterator tmp = *this;

    ptr--;

    return tmp;
}

template <typename T>
typename Array<T>::Iterator& Array<T>::Iterator::operator+=(size_t offset) {
    ptr += offset;

    return *this;
}

template <typename T>
typename Array<T>::Iterator& Array<T>::Iterator::operator-=(size_t offset) {
    ptr -= offset;

    return *this;
}

template <typename T>
typename Array<T>::Iterator Array<T>::begin() const {
    return Array::Iterator(data);
}

template <typename T>
typename Array<T>::Iterator Array<T>::end() const {
    return Array::Iterator(data + dim);
}

template <typename T>
typename Array<T>::Iterator Array<T>::insert(Iterator pos, const T& value) {
    size_t ind = pos - begin();

    if (dim == cap) {
        reserve(cap * 2);
    }

    for (size_t i = dim; i > ind; i--) {
        data[i] = data[i - 1];
    }

    data[ind] = value;
    dim++;

    return Iterator(data + ind);
}

template <typename T>
typename Array<T>::Iterator Array<T>::erase(Iterator pos) {
    size_t ind = pos - begin();

    for (size_t i = ind; i < dim - 1; i++) {
        data[i] = data[i + 1];
    }

    dim--;

    return Iterator(data + ind);
}

template <typename T>
void Array<T>::clear() {
    dim = 0;
}

template <typename T>
T& Array<T>::front() {
    if (empty()) {
        throw std::out_of_range("Array is empty");
    }
    return data[0];
}

template <typename T>
T& Array<T>::back() {
    if (empty()) {
        throw std::out_of_range("Array is empty");
    }
    return data[dim - 1];
}

template <typename T>
void Array<T>::push_back(const T& value) {
    if (dim >= cap) {
        reserve(cap * 2);
    }

    data[dim] = value;

    dim++;
}

template <typename T>
void Array<T>::push_front(const T& value) {
    if (dim >= cap) {
        reserve(cap * 2);
    }

    for (size_t i = dim; i > 0; i--) {
        data[i] = data[i - 1];
    }

    data[0] = value;

    dim++;
}

template <typename T>
void Array<T>::pop_back() {
    if (empty()) {
        return;
    }
    dim--;
}

template <typename T>
void Array<T>::pop_front() {
    if (empty()) {
        return;
    }

    for (size_t i = 0; i < dim - 1; i++) {
        data[i] = data[i + 1];
    }

    dim--;
}
