#include "vector.h"
//
//// ����������� �� ���������
//Vector::Vector() : capacity(1), currentSize(0) {
//    data = new Pair[capacity];
//}
//
//// ����������
//Vector::~Vector() {
//    delete[] data;
//}
//
//// ����������� �����������
//Vector::Vector(const Vector& other) : capacity(other.capacity), currentSize(other.currentSize) {
//    data = new Pair[capacity];
//    for (size_t i = 0; i < currentSize; ++i) {
//        data[i] = other.data[i];
//    }
//}
//
//// ����� ��� ���������� ������� �������
//void Vector::resize() {
//    capacity *= 2;
//    Pair* new_data = new Pair[capacity];
//    for (size_t i = 0; i < currentSize; ++i) {
//        new_data[i] = data[i];
//    }
//    delete[] data;
//    data = new_data;
//}
//
//// ����� ���������� �������� � �����
//void Vector::push_back(const Pair& elem) {
//    if (currentSize == capacity) {
//        resize();
//    }
//    data[currentSize++] = elem;
//}
//
//// ����� �������� ���������� ��������
//void Vector::pop_back() {
//    if (currentSize > 0) {
//        --currentSize;
//    }
//}
//
//// ��������� ������� ������� �������
//size_t Vector::getCapacity() const {
//    return capacity;
//}
//
//// ��������� �������� ������� �������
//size_t Vector::getSize() const {
//    return currentSize;
//}
//
//// ������� �������
//void Vector::Clear() {
//    currentSize = 0;
//}
//
//// �������� �� �������
//bool Vector::isEmpty() const {
//    return currentSize == 0;
//}
//
//// ������ � �������� �� ������� � ��������� ������
//Pair& Vector::at(size_t index) {
//    if (index >= currentSize) {
//        throw std::out_of_range("Index out of bounds");
//    }
//    return data[index];
//}
//
//// ���������� ��������� ������� �� �������
//Pair& Vector::operator[](size_t index) {
//    return data[index];
//}
//
//// �������� ������������
//Vector& Vector::operator=(const Vector& other) {
//    if (this != &other) {
//        delete[] data;
//        capacity = other.capacity;
//        currentSize = other.currentSize;
//        data = new Pair[capacity];
//        for (size_t i = 0; i < currentSize; ++i) {
//            data[i] = other.data[i];
//        }
//    }
//    return *this;
//}
