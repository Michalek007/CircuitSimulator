//
// Created by Michał on 14.11.2022.
//

#include "Complex.h"

void Complex::print() const{
    std::string real = std::to_string(get_real());
    std::string imag = std::to_string(get_imag());
    std::cout << "Real: " + real + " Imag: " + imag <<std::endl;
}

Complex Complex::conjugate() const{
    Complex conjugate {get_real(), -get_imag()};
    return conjugate;
}

float Complex::modulus() const{
    auto module = (float)(pow(pow(get_real(), 2)+pow(get_imag(), 2), 0.5));
    return module;
}

Complex Complex::add(Complex& other) const{
    Complex add {get_real() + other.get_real(), get_imag() + other.get_imag()};
    return add;
}

Complex Complex::subtract(Complex& other) const{
    Complex subtract {get_real() - other.get_real(), get_imag() - other.get_imag()};
    return subtract;
}

Complex Complex::multiply(Complex& other) const{
    float real = get_real() * other.get_real() - get_imag() * other.get_imag();
    float imag = get_real() * other.get_imag() + get_imag() * other.get_real();
    Complex multiply {real, imag};
    return multiply;
}

Complex Complex::divide(Complex& other) const{
    auto denominator = (float)(pow(get_real(), 2) + pow(get_imag(), 2));
    float real = (get_real() * other.get_real() + get_imag() * other.get_imag()) / denominator;
    float imag = (get_real() * other.get_imag() - get_imag() * other.get_real()) / denominator;
    Complex divide {real, imag};
    return divide;
}
