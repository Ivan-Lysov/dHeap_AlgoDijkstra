#ifndef VECTOR_H
#define VECTOR_H

#include "pair.h"
#include <cstddef>
#include <stdexcept>

template <typename T>
class vector {
private:
    T* vector_;
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
	vector_ = new T[capacity_];
}

template <typename T>
vector<T>::vector(const size_t n) : vector(n,T()){}

template <typename T>
vector<T>::vector(size_t n, const T& value) {
    capacity_ = 2 * n;
    size_ = n;
    vector_ = new T[capacity_];
    for (size_t i = 0; i < size_; ++i) {
        vector_[i] = value;
    }
}

template <typename T>
vector<T>::vector(const vector<T>& other) {
    size_ = other.size_;
    capacity_ = other.capacity_;
    vector_ = new T[capacity_];

    for (size_t i = 0; i < size_; ++i) {
        vector_[i] = other.vector_[i];
    }
}

template <typename T>
vector<T>& vector<T>::operator=(const vector<T>& other) {
    if (this == &other) {
        return *this;
    }
    delete[] vector_;

    size_ = other.size_;
    capacity_ = other.capacity_;
    vector_ = new T[capacity_];
    for (size_t i = 0; i < size_; ++i) {
        vector_[i] = other.vector_[i];
    }

    return *this;
}

template <typename T>
vector<T>::~vector() {
    delete[] vector_;
}

template <typename T>
void vector<T>::reallocate(size_t new_capacity) {
    if (new_capacity < capacity_) {
        return;
    }
    T* new_v = new T[new_capacity];
    std::copy(vector_, vector_ + size_, new_v);
    delete[] vector_;
    vector_ = new_v;
    capacity_ = new_capacity;
}

template <typename T>
void vector<T>::push_back(const T& value) {
    if (size_ == capacity_) {
        size_t new_capacity = (capacity_ == 0) ? 1 : capacity_ * 2;

        reallocate(new_capacity);
    }
    vector_[size_] = value;
    size_++;
}

template <typename T>
T& vector<T>::operator[](size_t index) const{
    if (index >= size_) {
        throw std::out_of_range("Index out of bounds");
    }
    return vector_[index];  // убираем const
}

template <typename T>
void vector<T>::pop_back() {
    if (size_ > 0) {
        size_--;
    }
}

template <typename T>
T& vector<T>::back() const {
    if (size_ > 0) {
        return vector_[size_ - 1];
    }
    throw std::out_of_range("vector is empty.");
}


#endif // VECTOR_H
