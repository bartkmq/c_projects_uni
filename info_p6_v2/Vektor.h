#ifndef INFO_P6_V2_Vektor_H
#define INFO_P6_V2_Vektor_H

#include <iostream>
#include <cmath>

template <typename T>
class Vektor {
public:
    Vektor();
    Vektor(T x0, T y0, T z0);

    Vektor<T> operator+(const Vektor<T> &param);
    Vektor<T> operator-(const Vektor<T> &param);
    Vektor<T> operator*(const Vektor<T> &param);
    Vektor<T> operator+=(const Vektor<T> &param);
    Vektor<T> operator-=(const Vektor<T> &param);
    Vektor<T> operator*=(const Vektor<T> &param);

    T get_x();
    void set_x(const T param);

    T get_y();
    void set_y(const T param);

    T get_z();
    void set_z(const T param);

    T dot(const Vektor<T> &param);
    void print(int newline);
    Vektor<T> normalize();
    T get_length();
protected:
    T x, y, z;
};

template <typename T>
Vektor<T>::Vektor() {
    x = 0;
    y = 0;
    z = 0;
}

template <typename T>
Vektor<T>::Vektor(T x0, T y0, T z0) {
    x = x0;
    y = y0;
    z = z0;
}

template <typename T>
Vektor<T> Vektor<T>::operator+(const Vektor<T> &param) {
    return Vektor<T>(this->x + param.x, this->y + param.y, this->z + param.z);
}

template <typename T>
Vektor<T> Vektor<T>::operator-(const Vektor<T> &param) {
    return Vektor(this->x - param.x, this->y - param.y, this->z - param.z);
}

template <typename T>
Vektor<T> Vektor<T>::operator*(const Vektor<T> &param) {
    return Vektor<T>(y * param.z - z * param.y,
                     z * param.x - x * param.z,
                     x * param.y - y * param.x);
}

template <typename T>
Vektor<T> Vektor<T>::operator+=(const Vektor<T> &param) {
    return Vektor<T>(this->x + param.x, this->y + param.y, this->z + param.z);
}

template <typename T>
Vektor<T> Vektor<T>::operator-=(const Vektor<T> &param) {
    return Vektor<T>(this->x - param.x, this->y - param.y, this->z - param.z);
}

template <typename T>
Vektor<T> Vektor<T>::operator*=(const Vektor<T> &param) {
    return Vektor<T>(y * param.z - z * param.y,
                     z * param.x - x * param.z,
                     x * param.y - y * param.x);
}

template <typename T>
T Vektor<T>::get_x() {
    return x;
}

template <typename T>
void Vektor<T>::set_x(const T param) {
    x = param;
}

template <typename T>
T Vektor<T>::get_y() {
    return y;
}

template <typename T>
void Vektor<T>::set_y(const T param) {
    y = param;
}

template <typename T>
T Vektor<T>::get_z() {
    return z;
}

template <typename T>
void Vektor<T>::set_z(const T param) {
    z = param;
}

template <typename T>
T Vektor<T>::dot(const Vektor<T> &param) {
    return x * param.x + y * param.y + z * param.z;
}

template <typename T>
void Vektor<T>::print(int newline) {
    std::cout << "Vektor(" << x << ", " << y << ", " << z << ")";
    if (newline)
        std::cout << std::endl;
}

template <typename T>
Vektor<T> Vektor<T>::normalize() {
    T length = get_length();
    return Vektor(x / length, y / length, z / length);
}

template <typename T>
T Vektor<T>::get_length() {
    return sqrt(x * x + y * y + z * z);
}

#endif //INFO_P6_V2_Vektor_H