#include <iostream>
#include <cmath>

struct Point {
    double x, y;
};

double distance(const Point& a, const Point& b) {
    double dx = b.x - a.x;
    double dy = b.y - a.y;
    return std::sqrt(dx * dx + dy * dy);
}

int main() {
    Point p1{0.0, 0.0};
    Point p2{7.0, 4.0};

    std::cout << "Distance: " << distance(p1, p2) << std::endl;

    return 0;
}