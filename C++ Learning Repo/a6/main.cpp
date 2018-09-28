#include <iostream>
#include "Vector.hpp"

using namespace std;
template<typename T>
void printVector(Vector<T> v) {
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << ", ";
    }
    cout << endl;
}
int main() {
    Vector<int> v1;
    v1.pushBack(4);
    v1.pushBack(5);
    v1.pushBack(6);
    v1.pushBack(7);
    v1.pushBack(8);
    cout << v1[0] << ", " << v1[3] << endl;
    printVector(v1);
    Vector<int> v2 = v1;
    v2.at(3)=2;
    printVector(v2);
    printVector(v1);
    v1.erase(v1.begin()+1);
    auto it = v1.erase(v1.begin()+3);
    cout << (it == v1.end()) << endl;
    printVector(v1);
    v2.clear();
    cout << v2.empty() << endl;
    Vector<float> v3;
    v3.reserve(56);
    cout << v3.capacity() << endl;
    v3.pushBack(5.4);
    return 0;
}