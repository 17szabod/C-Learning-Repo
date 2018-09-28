///////////////////////////////////////////////////////////////////////////////
// File Name:      UndergradStudent.cpp
//
// Author:         Daniel Szabo
// CS email:       dszabo2@cs.wisc.edu
//
// Description:    An undergraduate student, has some more information than a regular student
//
// Sources:        lecture notes and files
//
// URL(s) of sources:
//                 canvas.wisc.edu
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "UndergradStudent.hpp"

UndergradStudent::UndergradStudent(std::string name, std::vector<double> &assignmentsScore, double projectScore,
                                   std::string residenceHall, std::string yearInCollege)
        : Student::Student(name,assignmentsScore, projectScore), residenceHall(residenceHall), yearInCollege(yearInCollege) {}

double UndergradStudent::getTotal() {
    std::vector<double> assignments;
    assignments = getAssignmentsScore();
    double total = 0;
    for (auto it : assignments) {
        total += it;
    }
    return (total / assignments.size()) * 0.7 + getProjectScore() * 0.3;
}

std::string UndergradStudent::getGrade() {
    return getTotal() < 70 ? "N" : "CR";
}

void UndergradStudent::printDetails() {
    Student::printDetails();
    std::cout << "Type = " << "Undergraduate Student" << std::endl;
    std::cout << "Residence Hall = " << getResidenceHall() << std::endl;
    std::cout << "Year in College = " << getYearInCollege() << std::endl << std::endl;
}

std::string UndergradStudent::getResidenceHall() {
    return residenceHall;
}

std::string UndergradStudent::getYearInCollege() {
    return yearInCollege;
}