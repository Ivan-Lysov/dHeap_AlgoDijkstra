#ifndef _pair_
#define _pair_
#include <iostream>

template <typename T>
T min(const T& a, const T& b) {
    return (a < b) ? a : b;
}

template <typename T>
T max(const T& a, const T& b) {
    return (a > b) ? a : b;
}

template <typename T1, typename T2>
class pair {
public:
    T1 first;
    T2 second;

public:
    pair();
    pair(const T1& a, const T2& b);
    pair& operator=(const pair& other) {
        if (this != &other) {
            first = other.first;
            second = other.second;
        }
        return *this;
    }
};

template <typename T1, typename T2>
pair<T1, T2>::pair() : first(T1()), second(T2()) {}

template <typename T1, typename T2>
pair<T1, T2>::pair(const T1& a, const T2& b) : first(a), second(b) {}

#endif // _pair_