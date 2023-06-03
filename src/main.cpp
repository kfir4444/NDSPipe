#include <iostream>
#include <map>
#include <list>
#include "common.h"

using namespace std;

void printMap(const map<string, int>& map) {
    for (const auto& pair : map) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

int main() {
    const map<string, int> myMap = {
        {"apple", 5},
        {"banana", 7},
        {"orange", 3}
    };

    map<string, int> output = XyzToZamt(myMap);

    cout << "Printing a map:" << endl;
    printMap(output);

    vector<double> v1 = {0, 1, 0};
    vector<double> v2 = {0, 0, 0};
    cout << "Printing the distance between the points:" << getDist(v1, v2) << endl;
    vector<double> v3 = {1, 0, 0};
    cout << "Printing the angle between the points:" << getAngle(v1, v2, v3) << endl;
    
    return 0;
}
