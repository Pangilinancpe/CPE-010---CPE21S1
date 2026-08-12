#include<iostream>

class Triangle {
private:
    double totalAngle, angleA, angleB, angleC;
public:
    Triangle(double A, double B, double C);
    void getAngles(double A, double B, double C);
    const bool validateTriangle();
};

int main() {

    Triangle set1(50,40,90);
    if (set1.validateTriangle()) {
        std::cout << "The shape is a valid Triangle" << std::endl;
    } else {
        std::cout << "The shape is not a valid Triangle. \n";
    }

    return 0;
}

Triangle::Triangle(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A+B+C;
}
void Triangle::getAngles(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A+B+C;
}
const bool Triangle::validateTriangle() {
    return (totalAngle <= 180);
}