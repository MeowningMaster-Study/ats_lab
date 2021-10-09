#include <iostream>
using namespace std;

#include "@chabaniuk_m/complex.hpp"
#include "@dmiron.hpp"

int main() {
//    // complex test
//    Complex a(2, 0), b(2, 0);
//    cout << (a == b) << '\n';
//    cout << a * b << '\n';
//    cout << a / b;

    vector<vector<Complex>> matrix{
        vector<Complex>{Complex(1), Complex(5), Complex(0)},
        vector<Complex>{Complex(7), Complex(1), Complex(7)},
        vector<Complex>{Complex(4), Complex(1), Complex(1)}
    };

    dmiron::displayMatrix(dmiron::inverseMatrix(matrix));

}