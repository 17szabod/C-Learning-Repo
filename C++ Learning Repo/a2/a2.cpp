////////////////////////////////////////////////////////////////////////////////
// File Name:      a2.cpp
//
// Author:         Daniel Szabo
// CS email:       szabo@cs.wisc.edu
//
// Description:    Prints the intersection of two wonderful files, also some stuff
//                  like the size of the union and such
//
// Sources:        C++ API Documentation for set_intersection and sort and set_union
//
// URL(s) of sources:
//                      http://www.cplusplus.com/reference/
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief Prompts the user for a file name and populates a given vector with the contents
 * @param writeTo - The vector to populate
 * @param iteration - An integer representing if this is the first or second time running the method
 * @return The name of the file given
 */
string makeVector(vector<string> &writeTo, int iteration) {
    string fileName;
    bool correct = false;
    while (!correct) {
        correct = true;
        string iter;
        if (iteration == 1) {
            iter = "first";
        }
        else if (iteration == 2) {
            iter = "second";
        }
        cout << "Enter the name of the " << iter << " file: ";
        cin >> fileName;
        ifstream fileStream1(fileName);  // "../" makes it search as a relative path
        if (!fileStream1.is_open()) {
            fileStream1.open(fileName + ".txt");
            // tries to open with the .txt (won't work the other
            // way around, if the file had an unnecessary .txt)
            if (!fileStream1.is_open()) {
                cout << "Input file " << fileName << " is NOT found. Please try again." << endl;
                correct = false;
                continue;
            }
        }
        while (true) {
            string line;
            getline(fileStream1, line);
            if (fileStream1.fail()) break;
            writeTo.push_back(line);
        }
    }
    return fileName;
}

/**
 * @brief Reads 2 files and returns the union and intersection
 * @return 0 for success
 */
int main() {
    vector<string> file1, file2;
    string fileName1 = makeVector(file1, 1);
    string fileName2 = makeVector(file2, 2);
    cout << endl;

    sort(file1.begin(), file1.end());
    sort(file2.begin(), file2.end());
    cout << "Number of recipes in " << fileName1 << " = " << file1.size() << endl;
    cout << "Number of recipes in " << fileName2 << " = " << file2.size() << endl;
    vector<string> inters;
    set_intersection(file1.begin(), file1.end(), file2.begin(), file2.end(), back_inserter(inters));
    cout << "Number of recipes that are present in BOTH " << fileName1 << " AND " << fileName2 << " = " << inters.size()
         << endl;
    vector<string> uni;
    set_union(file1.begin(), file1.end(), file2.begin(), file2.end(), back_inserter(uni));
    cout << "Number of recipes that are in EITHER " << fileName1 << " OR " << fileName2 << " = " << uni.size()
         << endl;

    sort(inters.begin(), inters.end());
    sort(uni.begin(), uni.end());
    if (!inters.empty()) {
        cout << endl;
        cout << "List of recipes that are present in BOTH " << fileName1 << " AND " << fileName2 << ":" << endl;
        for (auto const &it: inters) {
            cout << it << endl;
        }
    }
    cout << endl;

    string andName = "intersection.txt";
    string orName = "union.txt";
    ofstream outAnd(andName);
    ofstream outOr(orName);
    for (auto const &it: inters) {
        outAnd << it << endl;
    }
    if (outAnd.is_open()) {
        cout << "The set intersection of the two files was written to a file named " << andName << endl;
    }
    for (auto const &it: uni) {
        outOr << it << endl;
    }
    if (outOr.is_open()) {
        cout << "The set union of the two files was written to a file named " << orName << endl;
    }
    return 0;
}