#include <iostream>
#include <cmath>
#include <map>
#include <string>
#include <vector>


double getDist(const std::vector<double>& vector1, const std::vector<double>& vector2) {
    double sum = 0.0;
    
    auto it1 = vector1.begin();
    auto it2 = vector2.begin();

    for (; it1 != vector1.end() && it2 != vector2.end(); ++it1, ++it2) {
        sum = sum + std::pow(*it1 - *it2, 2);
    }
    
    return std::pow(sum, 0.5);
}


double getScalarMult(const std::vector<double>& vector1, const std::vector<double>& vector2) {
    double sum = 0.0;
    
    auto it1 = vector1.begin();
    auto it2 = vector2.begin();

    for (; it1 != vector1.end() && it2 != vector2.end(); ++it1, ++it2) {
        sum = sum + *it1 * *it2;
    }
    return sum;
}


// double getAngle(const std::vector<double>& vector1, const std::vector<double>& vector2, const std::vector<double>& vector3) {
//     double sum = 0.0;
    
//     auto it1 = vector1.begin();
//     auto it2 = vector2.begin();
//     auto it3 = vector3.begin();

//     double P_12 = getDist(vector1, vector2);
//     double P_13 = getDist(vector1, vector3);
//     double P_23 = getDist(vector2, vector3);

//     for (; it1 != vector1.end() && it2 != vector2.end(); ++it1, ++it2) {
//         sum = sum + std::pow(*it1 - *it2, 2);
//     }
    
//     return std::pow(sum, 0.5);
// }


std::map<std::string, int> XyzToZamt(const std::map<std::string, int>& inputDict) {
    std::map<std::string, int> resultDict;

    for (const auto& pair : inputDict) {
        resultDict[pair.first] = pair.second;
    }

    return resultDict;
}
