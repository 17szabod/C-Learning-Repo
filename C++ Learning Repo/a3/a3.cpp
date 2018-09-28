////////////////////////////////////////////////////////////////////////////////
// File Name:      a3.cpp
//
// Author:         Gerald, Isaac, Varun, Daniel Szabo
// CS email:       gerald@cs.wisc.edu
//                 cisung@wisc.edu
//                 vnaik@cs.wisc.edu
//                 szabo@cs.wisc.edu
//
// Description:    The source file for a3.
//
// IMPORTANT NOTE: THIS IS THE ONLY FILE THAT YOU SHOULD MODIFY FOR A3.
//                 You SHOULD NOT MODIFY any of the following:
//                   1. Name of the functions.
//                   2. The number and type of parameters of the functions.
//                   3. Return type of the functions.
//                   4. Import statements.
//
// Sources:        Stack Overflow and cppreference during bugfixing
//
// URL(s) of sources:
//                 en.cppreference.com
//                 stackoverflow.com
////////////////////////////////////////////////////////////////////////////////

#include "a3.hpp"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void cleanData(istream &inFile, ostream &outFile,
               unordered_set<string> &commonWords) {
    string line;
    while (getline(inFile, line)) { //loop until getline fails
        vector<string> theseWords;
        splitLine(line, theseWords);
        removeCommonWords(theseWords, commonWords);
        for_each(theseWords.begin(), theseWords.end(), // go through each element of the vector and add it to outFile
                 [&outFile] (string it) { outFile << it << " "; }); //Note: will have a space at the end of each line
        outFile << endl; //Note: will have an extra newline at the end of the file
    }
}

void fillDictionary(istream &newInFile,
                    unordered_map<string, pair<long, long>> &dict) {
    string line;
    while (getline(newInFile, line)) { //loop until getline fails
        vector<string> theseWords;
        splitLine(line, theseWords);
        long rating = stoi(*theseWords.begin()); //essentially parses the first word of each line, which is the rating
        for(auto it = ++theseWords.begin(); it != theseWords.end(); ++it) { //Starts at ++theseWords.begin(), which is
                                                                            //the second word
            auto newIt = dict.emplace(*it,make_pair(0,0)).first; //we can ignore whether emplacement succeeded or not,
                                                                 //because it returns the right pair if the call fails
                                                                 //and creates the right pair if the call succeeds
            long total_rating = newIt->second.first;
            long total_count = newIt->second.second;
            total_rating += rating;
            total_count++;
            dict[*it] = make_pair(total_rating, total_count); //can't directly modify the elements of the pair, so we
                                                              //create a new pair with the appropriate information
        }
    }
}

void fillCommonWords(istream &inFile,
                     unordered_set<string> &commonWords) {
    string line;
    while (getline(inFile, line)) { //loop until getline fails
        commonWords.insert(line);
    }
}

void rateReviews(istream &testFile,
                 unordered_map<string, pair<long, long>> &dict,
                 ostream &ratingsFile) {
    string line;
    while (getline(testFile, line)) { //loop until getline fails
        vector<string> words;
        splitLine(line, words);
        double lineTotal = 0;
        for_each(words.begin(), words.end(),
                 [dict, &lineTotal](string it){ //maybe ended up being a little long for a lambda
                     if (dict.find(it) == dict.end()) { //if dict does not contain it
                        lineTotal += NEUTRAL_RATING;
                     }
                     else {
                         lineTotal += (double)dict.at(it).first/(double)dict.at(it).second; //calculates the value for
                                                                                            //the word
                     }});
        ratingsFile << setprecision(2) << fixed //sets the precision to show the values at
                    << lineTotal/((double)words.size()) //concatenates the average word rating
                    << endl; //Note: will have an extra line at the end
    }

}

void removeCommonWords(vector<string> &tokens,
                       unordered_set<string> &commonWords) {
    tokens.erase(remove_if(tokens.begin(), tokens.end(),
                        [&commonWords](string word){ return 0 < commonWords.count(word); }),
                 tokens.end()); //removes each element from token if the element appears at least once in commonWords
}

void splitLine(string &line, vector<string> &words) {
    // This code is provided for you and is correct.
    // You should NOT make any changes to this function!
    stringstream ss;
    ss.str(line);
    string token;
    while (getline(ss, token, ' ')) {
        if (token.length() != 0) {
            words.push_back(token);
        }
    }
}