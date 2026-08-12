#include<iostream>

double kelvinToFahrenheit(double kelvin) {
    double celsius = kelvin - 273.15;
    double fahrenheit = celsius * 9.0 / 5.0 + 32.0;
    return fahrenheit;
}

int main() {
    double kelvin;

    std::cout << "Enter kelvin: ";
    std::cin >> kelvin;

    if (kelvin < 0) {
        std::cout << "Invalid input: cannot be zero (0 K).\n";
        return 1;
    }

    double fahrenheit = kelvinToFahrenheit(kelvin);
    std::cout << kelvin << " K: " << fahrenheit << " F\n";
}