///////////////////////////////////////////////////////////////////////////////
// File Name:      GradStudent.cpp
//
// Author:         Daniel Szabo
// CS email:       dszabo2@cs.wisc.edu
//
// Description:    A graduate student, vastly superior to an undergraduate student
//
// Sources:        lecture notes and files
//
// URL(s) of sources:
//                 canvas.wisc.edu
///////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include "GradStudent.hpp"

GradStudent::GradStudent(std::string name, std::vector<double> &assignmentsScore, double projectScore,
                         std::string researchArea, std::string advisor)
        : Student::Student(name, assignmentsScore, projectScore), researchArea(researchArea), advisor(advisor) {}

std::string GradStudent::getResearchArea() {
    return researchArea;
}

std::string GradStudent::getAdvisor() {
    return advisor;
}

double GradStudent::getTotal() {
    std::vector<double> assignments;
    assignments = getAssignmentsScore();
    double total = 0;
    for (auto it : assignments) {
        total += it;
    }
    return (total / assignments.size()) * 0.5 + getProjectScore() * 0.5;
}

std::string GradStudent::getGrade() {
    return getTotal() < 80 ? "N" : "CR";
}

void GradStudent::printDetails() {
    Student::printDetails();
    std::cout << "Type = " << "Graduate Student" << std::endl;
    std::cout << "Research Area = " << getResearchArea() << std::endl;
    std::cout << "Advisor = " << getAdvisor() << std::endl << std::endl;
}