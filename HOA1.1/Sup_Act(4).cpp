#include <iostream>
#include <cmath>

class Triangle {
private:
    double totalAngle, angleA, angleB, angleC;
    double sideA, sideB, sideC;
public:
    Triangle(double A, double B, double C);
    void getAngles(double A, double B, double C);
    void getSides(double a, double b, double c);
    const bool validateTriangle();
    double computeArea();
    double computePerimeter();
    std::string classifyTriangle();
};

Triangle::Triangle(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
    sideA = sideB = sideC = 0;
}

void Triangle::getAngles(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}

void Triangle::getSides(double a, double b, double c) {
    sideA = a;
    sideB = b;
    sideC = c;
}

const bool Triangle::validateTriangle() {
    return (std::abs(totalAngle - 180) < 1e-6);
}

double Triangle::computeArea() {
    double s = (sideA + sideB + sideC) / 2.0;
    return std::sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
}

double Triangle::computePerimeter() {
    return sideA + sideB + sideC;
}

std::string Triangle::classifyTriangle() {
    // find the largest angle without std::max
    double maxAngle = angleA;
    if (angleB > maxAngle) maxAngle = angleB;
    if (angleC > maxAngle) maxAngle = angleC;

    if (std::abs(maxAngle - 90) < 1e-6) return "Others (right-angled)";
    else if (maxAngle > 90) return "Obtuse-angled";
    else return "Acute-angled";
}

int main() {
    double a, b, c, s1, s2, s3;

    std::cout << "Enter angle A, B, C: ";
    std::cin >> a >> b >> c;

    Triangle set1(a, b, c);

    if (set1.validateTriangle()) {
        std::cout << "The shape is a valid Triangle" << std::endl;

        std::cout << "Enter side A, B, C: ";
        std::cin >> s1 >> s2 >> s3;
        set1.getSides(s1, s2, s3);

        std::cout << "Area: " << set1.computeArea() << std::endl;
        std::cout << "Perimeter: " << set1.computePerimeter() << std::endl;
        std::cout << "Classification: " << set1.classifyTriangle() << std::endl;
    }

    return 0;
}