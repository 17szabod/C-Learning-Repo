//
// Created by daniel on 11/15/17.
//
#include "climits"
#include "SmartInteger.hpp"

SmartInteger::SmartInteger() : value(0) {}

SmartInteger::SmartInteger(int num) : value(num) {
    if (num > INT_MAX || num < INT_MIN) {
        throw std::exception();
    }
}

const int SmartInteger::getValue() const {
    return value;
}

std::ostream &operator<<(std::ostream &os, const SmartInteger &integer) {
    os << integer.getValue();
    return os;
}

bool SmartInteger::operator<(const SmartInteger &rhs) const {
    return value < rhs.getValue();
}

bool SmartInteger::operator>(const SmartInteger &rhs) const {
    return rhs < *this;
}

bool SmartInteger::operator<=(const SmartInteger &rhs) const {
    return !(rhs < *this);
}

bool SmartInteger::operator>=(const SmartInteger &rhs) const {
    return !(*this < rhs);
}

bool SmartInteger::operator==(const SmartInteger &rhs) const {
    return value == rhs.getValue();
}

bool SmartInteger::operator!=(const SmartInteger &rhs) const {
    return !(rhs == *this);
}

const SmartInteger SmartInteger::operator+(const SmartInteger &rhs) const {
    if (value > 0 && INT_MAX - value < rhs.getValue()
            || value < 0 && INT_MIN - value > rhs.getValue()) {
        throw std::exception();
    }
    return SmartInteger(value + rhs.getValue());
}

const SmartInteger SmartInteger::operator-(const SmartInteger &rhs) const {
    if (rhs.getValue() < 0 && INT_MAX + rhs.getValue() < value
        || rhs.getValue() > 0 && INT_MIN + rhs.getValue() > value) {
        throw std::exception();
    }
    return SmartInteger(value - rhs.getValue());
}

const SmartInteger SmartInteger::operator*(const SmartInteger &rhs) const {
    if (((rhs.getValue() > 0 && value > 0) && INT_MAX / rhs.getValue() < value)
            || ((rhs.getValue() < 0 && value < 0) && INT_MAX / rhs.getValue() > value)
            || ((value < 0 && rhs.getValue() > 0) && INT_MIN / rhs.getValue() > value)
            || ((value > 0 && rhs.getValue() < 0) && INT_MIN / rhs.getValue() < value)) {
        throw std::exception();
    }
    return SmartInteger(value * rhs.getValue());
}

SmartInteger &SmartInteger::operator+=(const SmartInteger &rhs) {
    *this = *this + rhs;
    return *this;
}

SmartInteger &SmartInteger::operator-=(const SmartInteger &rhs) {
    *this = *this - rhs;
    return *this;
}

SmartInteger &SmartInteger::operator*=(const SmartInteger &rhs) {
    *this = *this * rhs;
    return *this;
}

SmartInteger &SmartInteger::operator++() {
    *this += SmartInteger(1);
    return *this;
}

SmartInteger &SmartInteger::operator--() {
    *this -= SmartInteger(1);
    return *this;
}

SmartInteger SmartInteger::operator-() {
    return SmartInteger(0) - *this;
}

const SmartInteger SmartInteger::operator++(int decoy) {
    SmartInteger tmp(*this);
    ++*this;
    return tmp;
}

const SmartInteger SmartInteger::operator--(int decoy) {
    SmartInteger tmp(*this);
    --*this;
    return tmp;
}