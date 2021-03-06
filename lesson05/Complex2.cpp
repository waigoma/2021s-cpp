#include "Complex2.h"
#include <cmath>
#include <sstream>

using namespace std;

Complex2::Complex2(double real, double imag):
        real(real), imag(imag) {}

Complex2::Complex2(const Complex2 &orig):
        real(orig.real), imag(orig.imag) {}

Complex2& Complex2::operator=(const Complex2 &arg) {
    real = arg.real;
    imag = arg.imag;

    return *this;
}

Complex2 Complex2::operator+(const Complex2 &arg) const {
    Complex2 temp(*this);

    return temp += arg;
}

Complex2 Complex2::operator-(const Complex2 &arg) const {
    Complex2 temp(*this);

    return temp -= arg;
}

Complex2 Complex2::operator*(const Complex2 &arg) const {
    Complex2 temp(*this);

    return temp *= arg;
}

Complex2 Complex2::operator/(const Complex2 &arg) const {
    Complex2 temp(*this);

    return temp /= arg;
}

Complex2 &Complex2::operator+=(const Complex2 &arg) {
    real += arg.real;
    imag += arg.imag;

    return *this;
}

Complex2 &Complex2::operator-=(const Complex2 &arg) {
    real -= arg.real;
    imag -= arg.imag;

    return *this;
}

Complex2 &Complex2::operator*=(const Complex2 &arg) {
    double real2 = (real * arg.real) - (arg.imag * imag);
    double imag2 = (imag * arg.real) + (real * arg.imag);

    real = real2;
    imag = imag2;

    return *this;
}

Complex2 &Complex2::operator/=(const Complex2 &arg) {
    double real2 = ((real * arg.real) + (imag * arg.imag)) / (pow(arg.real, 2) + pow(arg.imag, 2));
    double imag2 = ((imag * arg.real) - (real * arg.imag)) / (pow(arg.real, 2) + pow(arg.imag, 2));

    real = real2;
    imag = imag2;

    return *this;
}

bool Complex2::operator==(const Complex2 &arg) const {
    return (real == arg.real && imag == arg.imag);
}

bool Complex2::operator!=(const Complex2 &arg) const {
    return !(real == arg.real && imag == arg.imag);
}

double Complex2::getModulus() const {
    return sqrt((pow(real, 2) + pow(imag, 2)));
}

string Complex2::toString() const {
    stringstream ss;
    if (getImag() < 0) ss << getReal() << getImag() << "i";
    else ss << getReal() << "+" << getImag() << "i";

    return ss.str();
}


