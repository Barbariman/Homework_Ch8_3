#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imaginary;

public:
    // Constructors
    Complex(double realPart, double imaginaryPart) : real(realPart), imaginary(imaginaryPart) {}
    Complex(double realPart) : real(realPart), imaginary(0) {}
    Complex() : real(0), imaginary(0) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imaginary * other.imaginary,
                       real * other.imaginary + imaginary * other.real);
    }

};

// Test program
int main() {
    // Test constructors
    Complex c1;
    Complex c2(3);
    Complex c3(3, 4);
    
    // Test operator overloading   
    cout << "c2 + c3: " << c4 << endl;  // Should be 6 + 4*i
    cout << "c3 - c2: " << c5 << endl;  // Should be 0 + 4*i
    cout << "c3 * c3: " << c6 << endl;  // Should be -7 + 24*i
    
    return 0;
}
