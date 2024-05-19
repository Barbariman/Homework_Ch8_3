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

    // Overloaded operators
    bool operator==(const Complex& other) const {
        return (real == other.real) && (imaginary == other.imaginary);
    }

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

    // Friend functions for input and output
    friend ostream& operator<<(ostream& out, const Complex& c){
        out << c.real << " + " << c.imaginary << "i";
        return out;
    }
    friend istream& operator>>(istream& in, Complex& c){
        in >> c.real >> c.imaginary;
        return in;
    }
};

// Defined constant i
const Complex i(0, 1);

// Test program
int main() {
    // Test constructors
    Complex c1;
    Complex c2(3);
    Complex c3(3, 4);
    
    // Output initialized values
    cout << "c1: " << c1 << endl;  // Should be 0 + 0*i
    cout << "c2: " << c2 << endl;  // Should be 3 + 0*i
    cout << "c3: " << c3 << endl;  // Should be 3 + 4*i
    
    // Test operator overloading
    Complex c4 = c2 + c3;
    Complex c5 = c3 - c2;
    Complex c6 = c3 * c3;
    
    cout << "c2 + c3: " << c4 << endl;  // Should be 6 + 4*i
    cout << "c3 - c2: " << c5 << endl;  // Should be 0 + 4*i
    cout << "c3 * c3: " << c6 << endl;  // Should be -7 + 24*i
    
    // Test == operator
    cout << "c1 == c2: " << (c1 == c2) << endl;  // Should be 0 (F)
    cout << "c2 == c2: " << (c2 == c2) << endl;  // Should be 1 (T)
    
    // Test input
    Complex c7;
    cout << "Enter a complex number (format: real imaginary): ";
    cin >> c7;
    cout << "You entered: " << c7 << endl;

    return 0;
}
