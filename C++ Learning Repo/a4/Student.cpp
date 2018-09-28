///////////////////////////////////////////////////////////////////////////////
// File Name:      Student.cpp
//
// Author:         Daniel Szabo
// CS email:       dszabo2@cs.wisc.edu
//
// Description:    A student class, has some properties
//
// Sources:        lecture notes and files
//
// URL(s) of sources:
//                 canvas.wisc.edu
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Student.hpp"

int Student::numStudents = -1; //To fix an off-by-one error

Student::Student(std::string name, std::vector<double> &assignmentsScore, double projectScore)
        : name(name), assignmentsScore(assignmentsScore), projectScore(projectScore)  {
    numStudents++;
    id = numStudents; //could have fixed said error by switching these
}

int Student::getId() {
    return id;
}

std::string Student::getName() {
    return name;
}

std::vector<double>& Student::getAssignmentsScore() {
    return assignmentsScore;
}

double Student::getProjectScore() {
    return projectScore;
}

int Student::getNumStudents() {
    return numStudents;
}

void Student::printVector(std::vector<double> toPrint) {
    std::cout << "[";
    for (auto it = toPrint.begin(); it != --toPrint.end(); it++) {
        std::cout << *it << ", ";
    }
    std::cout << *--toPrint.end() << "]"; //makes the last input look good
}

void Student::printDetails() {
    std::cout << "STUDENT DETAILS:" << std::endl;
    std::cout << "id = " << id << std::endl;
    std::cout << "Name = " << name << std::endl;
    std::cout << "Assignments = ";
    printVector(assignmentsScore);
    std::cout << std::endl << "Project = " << projectScore << std::endl;
    std::cout << "Total = " << getTotal() << std::endl;
    std::cout << "Grade = " << getGrade() << std::endl;
}

