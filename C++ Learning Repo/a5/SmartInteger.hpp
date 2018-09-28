//
// Created by daniel on 11/15/17.
//

#include <ostream>

#ifndef A5_SMARTINTEGER_HPP
#define A5_SMARTINTEGER_HPP

#endif //A5_SMARTINTEGER_HPP

class SmartInteger {
private:
    int value;

public:

 /**
 * @brief default constructor, sets default value as 0
 */
    SmartInteger();

/**
 * @brief parameterized constructor
 *
 * @param num the number to set value to
 */
    SmartInteger(int num);

/**
 * @brief returns the value of this SmartInteger
 *
 * @return the value of this SmartInteger
 */
    const int getValue() const;

/**
 * @brief stream writing operator
 *
 * @param os the stream to write to
 * @param integer the SmartInteger to write to the stream
 * @return the stream that was written to
 */
    friend std::ostream &operator<<(std::ostream &os, const SmartInteger &integer);

/**
 * @brief less than comparator
 *
 * @param rhs the SmartInteger to compare to
 */
    bool operator<(const SmartInteger &rhs) const;

/**
 * @brief greater than comparator
 *
 * @param rhs the SmartInteger to compare to
 */
    bool operator>(const SmartInteger &rhs) const;

/**
 * @brief less than equal to comparator
 *
 * @param rhs the SmartInteger to compare to
 */
    bool operator<=(const SmartInteger &rhs) const;

/**
 * @brief greater than equal to comparator
 *
 * @param rhs the SmartInteger to compare to
 */
    bool operator>=(const SmartInteger &rhs) const;

/**
 * @brief equality comparator
 *
 * @param rhs the SmartInteger to compare to
 */
    bool operator==(const SmartInteger &rhs) const;

/**
 * @brief inequality comparator
 *
 * @param rhs the SmartInteger to compare to
 */
    bool operator!=(const SmartInteger &rhs) const;

/**
 * @brief addition operator
 *
 * @param rhs the SmartInteger to add
 */
    const SmartInteger operator+(const SmartInteger &rhs) const;

/**
 * @brief subtraction operator
 *
 * @param rhs the SmartInteger to subtract
 */
    const SmartInteger operator-(const SmartInteger &rhs) const;

/**
 * @brief multiplication operator
 *
 * @param rhs the SmartInteger to multiply
 */
    const SmartInteger operator*(const SmartInteger &rhs) const;

/**
 * @brief += operator
 *
 * @param rhs the SmartInteger to add
 */
    SmartInteger &operator+=(const SmartInteger &rhs);


/**
 * @brief -= operator
 *
 * @param rhs the SmartInteger to substract
 */
    SmartInteger &operator-=(const SmartInteger &rhs);

/**
 * @brief *= operator
 *
 * @param rhs the SmartInteger to multiply
 */
    SmartInteger &operator*=(const SmartInteger &rhs);

/**
 * @brief adds one to this SmartInteger (preincrement)
 */
    SmartInteger &operator++();

/**
 * @brief adds one to this SmartInteger (preincrement)
 */
    SmartInteger &operator--();

/**
 * @brief multiplies this SmartInteger by -1
 */
    SmartInteger operator-();

/**
 * @brief adds one to this SmartInteger (postincrement)
 */
    const SmartInteger operator++(int decoy);

/**
 * @brief adds one to this SmartInteger (postincrement)
 */
    const SmartInteger operator--(int decoy);


};