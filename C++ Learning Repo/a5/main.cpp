#include "SmartInteger.hpp"

#include <iostream>
#include <climits>

int main() {
    std::cout << "Constructing n1 and n2..." << std::endl;
    SmartInteger n1(3);
    SmartInteger n2;
    std::cout << "n1.getValue() should be 3: " << n1.getValue() << std::endl;
    std::cout << "n2.getValue() should be 0: " << n2.getValue() << std::endl;
    std::cout << std::endl;

    // No need to implement custom copy assignment operator - this should just work
    std::cout << "Changing value of n2..." << std::endl;
    n2 = 3;
    std::cout << "n2.getValue() should be 3: " << n2.getValue() << std::endl;
    std::cout << std::endl;

    // No need to implement custom copy constructor - this should just work
    std::cout << "Constructing n3..." << std::endl;
    SmartInteger n3(n2);
    std::cout << "n3.getValue() should be 3: " << n3.getValue() << std::endl;

    // Add more code here to test SmartInteger here!
    std::cout << "Let's fuck shit up!" << std::endl;

    std::cout << n2.getValue() << " + " << n3.getValue() << " = " << (n2+n3).getValue() << std::endl;
    std::cout << n2.getValue() << " - " << n3.getValue() << " = " << (n2-n3).getValue() << std::endl;
    std::cout << n2.getValue() << " * " << n3.getValue() << " = " << (n2*n3).getValue() << std::endl;

    SmartInteger big1(INT_MAX - 1);
    SmartInteger big2(INT_MIN + 1);

    std::cout << big1 + big2 << std::endl;
    try {
        big1-big2;
    }
    catch (const std::exception& e) {
        std::cout << "Caught a-b" << std::endl;
    }
    ++big1;

    try {
        ++big1;
    }
    catch (const std::exception& e) {
        std::cout << "Caught ++a" << std::endl;
    }

    std::cout << "- " << n1 << " = " << -n1 << std::endl;

    std::cout << n2 << "(3), ";
    std::cout << (n2 += n1) << "(6), " << n2 << "(6), ";
    std::cout << ++n2 << "(7), ";
    std::cout << --n2 << "(6), ";
    std::cout << n2++ << "(6), ";
    std::cout << n2-- << "(7)" << std::endl;

    std::cout << (big1 *= SmartInteger(1)) << std::endl;

    try {
        std::cout << (big1 *= SmartInteger(2)) << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Caught a*=2" << std::endl;
    }
    try {
        std::cout << (big2 *= SmartInteger(-2)) << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Caught b*=-2" << std::endl;
    }

    std::cout << big2 - SmartInteger(-15) << std::endl;
    std::cout << big2 + SmartInteger(150) << std::endl;
    std::cout << big1 + SmartInteger(-1124124) << std::endl;
    std::cout << big1 - SmartInteger(1234235) << std::endl;

    (n1 + n2) + n3;
    ++(++n2);
    n2++++ + n3;
    std::cout << big1 << ", "  << n2 << std::endl;
    std::cout << (SmartInteger(INT_MIN/2+1)).getValue() << std::endl;
    std::cout << ((SmartInteger(2))*SmartInteger(INT_MIN/2+1)).getValue() << std::endl;
    std::cout << -SmartInteger(1) - -SmartInteger(INT_MIN + 1) << std::endl;
    std::cout << -SmartInteger(1) * SmartInteger(1) << std::endl;
    std::cout << -SmartInteger(1) * -SmartInteger(1) << std::endl;
    std::cout << SmartInteger(-1).getValue() << std::endl;
    std::cout << "hi" << std::endl;
    std::cout << SmartInteger(1) * SmartInteger(1) << std::endl;
    std::cout << SmartInteger(10) * SmartInteger(-10) << std::endl << std::endl;
    std::cout << (((n2++)++)++)++ << " vs " << ++++++++n2 << std::endl;



    return 0;
}