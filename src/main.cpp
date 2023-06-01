#include <iostream>
#include <map>
#include <list>
#include "common.h"

void printMap(const std::map<std::string, int>& map) {
    for (const auto& pair : map) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}

int main() {
    const std::map<std::string, int> myMap = {
        {"apple", 5},
        {"banana", 7},
        {"orange", 3}
    };

    std::map<std::string, int> output = XyzToZamt(myMap);

    std::cout << "Printing a map:" << std::endl;
    printMap(output);

    std::vector<double> v1 = {1.0, 2.0, 3.0};
    std::vector<double> v2 = {3.4, 1.1, 3.14};
    std::cout << "Printing the distance between the points:" << getDist(v1, v2) << std::endl;

    return 0;
}
