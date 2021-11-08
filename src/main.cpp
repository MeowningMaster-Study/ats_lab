#include <iostream>
using namespace std;

#include "complex.hpp"
#include "@dmiron.hpp"

int main() {


    vector<vector<Complex>> matrix{
        vector<Complex>{Complex(1, 1), Complex(5), Complex(0)},
        vector<Complex>{Complex(3), Complex(1), Complex(2)},
        vector<Complex>{Complex(4), Complex(1), Complex(0)}
    };

    dmiron::displayMatrix(dmiron::inverseMatrix(matrix));

}