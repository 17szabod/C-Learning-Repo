////////////////////////////////////////////////////////////////////////////////
// File Name:      a1.cpp
//
// Author:         Daniel Szabo
// CS email:       dszabo2@cs.wisc.edu
//
// Description:    A program that outputs information about myself
//                 and repeats a string.
//
// Sources:        Element14 reading user input in C++
//
// URL(s) of sources:
//                 https://www.element14.com/community/community/code_exchange/blog/2013/01/09/c-tutorial--reading-user-input
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

/**
 * @brief A main method that prints out personal information and a string a number of times
 * @return 0 for success, 1 for failure
 */
int main() {
    std::string info = "-+-+-+-+-+-+-+-+-+-+-+-+-\n"
            "Name: Daniel Szabo\n"
            "Major: Computer Science and Mathematics\n"
            "Year: Freshman\n"
            "Reason I am taking this class: C++ is an interesting and useful new language to learn!\n"
            "-+-+-+-+-+-+-+-+-+-+-+-+-";
    std::cout << info << std::endl;
    int num;
    std::cout << std::endl;
    std::cout << "Number of times to loop: ";
    std::cin >> num;
    if (num < 0) {
        // Do not allow a negative number
        std::cerr << "Input \"" << num << "\" cannot be negative" << std::endl;
        return 1;
    }
    for (int x = 0; x < num; x++) {
        std::cout << "-=-";
    }
    std::cout << std::endl;
    return 0;
}