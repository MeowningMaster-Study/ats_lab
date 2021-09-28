#include <iostream>
using namespace std;

#include "complex.hpp"

int main() {
    // complex test
    Complex a(1, 5), b(4, 8);
    cout << a + b << '\n';
    cout << a * b << '\n';
    cout << a / b;
}