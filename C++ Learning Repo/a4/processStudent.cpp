///////////////////////////////////////////////////////////////////////////////
// File Name:      processStudent.cpp
//
// Author:         Daniel Szabo
// CS email:       dszabo2@cs.wisc.edu
//
// Description:    Methods to perform some processing on student objects.
//
// Sources:        lecture notes and files
//
// URL(s) of sources:
//                 canvas.wisc.edu
///////////////////////////////////////////////////////////////////////////////

#include "processStudent.hpp"
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

void fillStudents(std::istream &inFile,
                  std::vector<std::shared_ptr<Student>> &gstudentPtrs,
                  std::vector<std::shared_ptr<Student>> &ugstudentPtrs) {
    string line;
    while (getline(inFile, line)) {
        istringstream strStr;
        strStr.str(line);
        char type[1];
        strStr.getline(type, 256, ',');
        char name[256];
        strStr.getline(name, 256, ',');
        char num[256];
        vector<double> assignments;
        for (int i = 0; i < 6; ++i) {
            strStr.getline(num, 4, ',');
            assignments.push_back(stod(num));
        }
        char projectStr[256];
        strStr.getline(projectStr, 4, ',');
        double project = stod(projectStr);
        if (type[0] == 'G') {
            char area[256], adv[256];
            strStr.getline(area, 256, ',');
            strStr.getline(adv, 256, ',');
            shared_ptr<Student> gstud(new GradStudent(name, assignments, project, area, adv));
            gstudentPtrs.push_back(gstud);
        } else {
            char resHall[256], year[256];
            strStr.getline(resHall, 256, ',');
            strStr.getline(year, 256, ',');
            shared_ptr<Student> uStud(new UndergradStudent(name, assignments, project, resHall, year));
            ugstudentPtrs.push_back(uStud);
        }
    }

}

void printStudents(std::vector<std::shared_ptr<Student>> &students) {
    for (auto const &it : students) {
        it->printDetails();
    }
}

void computeStatistics(std::vector<std::shared_ptr<Student>> &students) {
    double total = 0;
    // display the number of students (undergrad or grad)
    cout << "Number of students = " << students.size() << endl;
    // compute the mean of the total score.
    for (auto const &it : students) {
        total += it->getTotal();
    }
    cout << "The mean of the total score = " << total / students.size() << endl;
    // sort and print the students based on their total.
    cout << "The sorted list of students (id, name, total, grade) in descending order of total: " << endl;
    sort(students.begin(), students.end(),
         [](shared_ptr<Student> me, shared_ptr<Student> other) { return me->getTotal() > other->getTotal(); });
    for (auto const &it : students) {
        cout << it->getId() << ", " << it->getName() << ", " << it->getTotal() << ", " << it->getGrade() << endl;
    }
}