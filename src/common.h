#include <iostream>
#include <cmath>
#include <map>
#include <string>
#include <vector>

using namespace std;

double getDist(const vector<double>& vector1, const vector<double>& vector2) {
    double sum = 0.0;
    
    auto it1 = vector1.begin();
    auto it2 = vector2.begin();

    for (; it1 != vector1.end() && it2 != vector2.end(); ++it1, ++it2) {
        sum = sum + pow(*it1 - *it2, 2);
    }
    
    return pow(sum, 0.5);
}


double getScalarMult(const vector<double>& vector1, const vector<double>& vector2) {
    double sum = 0.0;
    
    auto it1 = vector1.begin();
    auto it2 = vector2.begin();

    for (; it1 != vector1.end() && it2 != vector2.end(); ++it1, ++it2) {
        sum = sum + *it1 * *it2;
    }
    return sum;
}


double getAngle(const vector<double>& vector1,
                const vector<double>& vector2,
                const vector<double>& vector3) {
    double P_21 = getDist(vector2, vector1);
    double P_23 = getDist(vector2, vector3);
    double P_13 = getDist(vector1, vector3);
    return acos((pow(P_21, 2)+ pow(P_23, 2)-pow(P_13, 2))/(2*P_21*P_23))*180/M_PI;
}


vector<double> cross(const vector<double>& vector1,
                     const vector<double>& vector2) {
    return vector<double> {vector1[1]*vector2[2] - vector1[2]*vector2[1],
                           -vector1[0]*vector2[2] - vector1[2]*vector2[0],
                           vector1[0]*vector2[1] - vector1[1]*vector2[0]};
                     }

vector<double> vecMinmus(const vector<double>& vector1,
                         const vector<double>& vector2) {
    return vector<double> {vector1[0] - vector2[0],
                           vector1[1] - vector2[1],
                           vector1[2] - vector2[2]};
                     }


double getDihedralAngle(const vector<double>& vector1,
                        const vector<double>& vector2,
                        const vector<double>& vector3,
                        const vector<double>& vector4) {
    vector<double> b1 = vecMinmus(vector1, vector2);
    vector<double> b2 = vecMinmus(vector2, vector3);
    vector<double> b3 = vecMinmus(vector3, vector4);
    vector<double> n1 = cross(b1, b2);
    vector<double> n2 = cross(b2, b3);
    vector<double> M1 = cross(n1, b2);
    double b2s = pow(getScalarMult(b2, b2), 0.5);
    vector<double> m1 = {M1[0]/b2s, M1[1]/b2s, M1[2]/b2s};
    double x = getScalarMult(n1, n2);
    double y = getScalarMult(m1, n2);
    double result =  atan2(x, y);
    return result*180/M_PI;
    }


map<string, int> XyzToZamt(const map<string, int>& inputDict) {
    map<string, int> resultDict;

    for (const auto& pair : inputDict) {
        resultDict[pair.first] = pair.second;
    }

    return resultDict;
}
