#ifndef vector_H_
#define vector_H_

#include "pair.h"
#include <cstddef>
#include <stdexcept>

template <typename T>
class vector {
private:
    T* v;
    size_t capacity_;
    size_t size_;

public:
    vector();
    vector(const size_t n);
    vector(const size_t n, const T& default_value);
    vector(const vector<T>& other);
    vector<T>& operator=(const vector<T>& other);
    ~vector();

    void reallocate(size_t new_capacity);

public:
    T& vector<T>::operator[](size_t index)const;
    void push_back(const T& value);
    void pop_back();
    T& back() const;
    bool IsEmpty() const { return size_ == 0; }
    size_t size() const { return size_; }
};

template <typename T>
vector<T>::vector() : capacity_(1), size_(0) {
	v = new T[capacity_];
}

template <typename T>
vector<T>::vector(const size_t n) : vector(n,T()){}

template <typename T>
vector<T>::vector(size_t n, const T& value) {
    capacity_ = 2 * n;
    size_ = n;
    v = new T[capacity_];
    for (size_t i = 0; i < size_; ++i) {
        v[i] = value;
    }
}

template <typename T>
vector<T>::vector(const vector<T>& other) {
    size_ = other.size_;
    capacity_ = other.capacity_;
    v = new T[capacity_];

    for (size_t i = 0; i < size_; ++i) {
        v[i] = other.v[i];
    }
}

template <typename T>
vector<T>& vector<T>::operator=(const vector<T>& other) {
    if (this == &other) {
        return *this;
    }
    delete[] v;

    size_ = other.size_;
    capacity_ = other.capacity_;
    v = new T[capacity_];
    for (size_t i = 0; i < size_; ++i) {
        v[i] = other.v[i];
    }

    return *this;
}

template <typename T>
vector<T>::~vector() {
    delete[] v;
}

template <typename T>
void vector<T>::reallocate(size_t new_capacity) {
    if (new_capacity < capacity_) {
        return;
    }
    T* new_v = new T[new_capacity];
    std::copy(v, v + size_, new_v);
    delete[] v;
    v = new_v;
    capacity_ = new_capacity;
}

template <typename T>
void vector<T>::push_back(const T& value) {
    if (size_ == capacity_) {
        size_t new_capacity = (capacity_ == 0) ? 1 : capacity_ * 2;

        reallocate(new_capacity);
    }
    v[size_] = value;
    size_++;
}

template <typename T>
T& vector<T>::operator[](size_t index) const{
    if (index >= size_) {
        throw std::out_of_range("Index out of bounds");
    }
    return v[index];
}

template <typename T>
void vector<T>::pop_back() {
    if (size_ > 0) {
        size_--;
	}
	else {
		throw std::out_of_range("vector is empty.");
	}
}

template <typename T>
T& vector<T>::back() const {
    if (size_ > 0) {
        return v[size_ - 1];
    }
    throw std::out_of_range("vector is empty.");
}


#endif // vector_H_
