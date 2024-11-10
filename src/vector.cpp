#include "vector.h"
//
//// Конструктор по умолчанию
//Vector::Vector() : capacity(1), currentSize(0) {
//    data = new Pair[capacity];
//}
//
//// Деструктор
//Vector::~Vector() {
//    delete[] data;
//}
//
//// Конструктор копирования
//Vector::Vector(const Vector& other) : capacity(other.capacity), currentSize(other.currentSize) {
//    data = new Pair[capacity];
//    for (size_t i = 0; i < currentSize; ++i) {
//        data[i] = other.data[i];
//    }
//}
//
//// Метод для увеличения емкости вектора
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
//// Метод добавления элемента в конец
//void Vector::push_back(const Pair& elem) {
//    if (currentSize == capacity) {
//        resize();
//    }
//    data[currentSize++] = elem;
//}
//
//// Метод удаления последнего элемента
//void Vector::pop_back() {
//    if (currentSize > 0) {
//        --currentSize;
//    }
//}
//
//// Получение текущей емкости вектора
//size_t Vector::getCapacity() const {
//    return capacity;
//}
//
//// Получение текущего размера вектора
//size_t Vector::getSize() const {
//    return currentSize;
//}
//
//// Очистка вектора
//void Vector::Clear() {
//    currentSize = 0;
//}
//
//// Проверка на пустоту
//bool Vector::isEmpty() const {
//    return currentSize == 0;
//}
//
//// Доступ к элементу по индексу с проверкой границ
//Pair& Vector::at(size_t index) {
//    if (index >= currentSize) {
//        throw std::out_of_range("Index out of bounds");
//    }
//    return data[index];
//}
//
//// Перегрузка оператора доступа по индексу
//Pair& Vector::operator[](size_t index) {
//    return data[index];
//}
//
//// Оператор присваивания
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
