#include <chrono>
#include <cassert>
#include <iostream>

#include "../@chabaniuk_m/complex.hpp"
#include "../@theblacl1ght/basic_matrix.hpp"
#include "../@meowning_master/matrix.hpp"

using namespace std;
using namespace std::chrono;

template<class T>
bool cmp_matrixes(Matrix<T> a, Matrix<T> b) {
    if (a.size() != b.size()) {
        return false;
    }
    int n = a.size();
    for (int i = 0; i < n; i += 1) {
        for (int k = 0; k < n; k += 1) {
            if (a[i][k] != b[i][k]) {
                return false;
            }
        }
    }
    return true;
}

void test_sub_matrix() {
    Matrix<int> m = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
    };
    Matrix<int> r = matrix::sub_matrix(m, 2, 2);
    Matrix<int> c = {
        {1, 2, 4},
        {5, 6, 8},
        {13, 14, 16},
    };
    assert(cmp_matrixes(r, c));
}

void test_determinant() {
    Matrix<Complex> m1 = {
        {{1, 0}, {2, 0}},
        {{3, 0}, {4, 0}}
    };
    Complex d1 = matrix::determinant(m1);
    assert(d1 == Complex(-2, 0));

    Matrix<Complex> m2 = {
        {{5, -2}, {0, 0}, {-5, 0}},
        {{0, 0}, {0, -2}, {0, -4}},
        {{-5, 0}, {0, -4}, {5, -2}}
    };
    Complex d2 = matrix::determinant(m2);
    assert(d2 == Complex(40, -24));
}

void test_transpose() {
    Matrix<int> m = {
        {1, 2},
        {3, 4}
    };
    auto r = matrix::transpose(m);
    Matrix<int> c = {
        {1, 3},
        {2, 4}
    };
    assert(cmp_matrixes(r, c));
}

void test_inverse_by_minors() {
    Matrix<Complex> m = {
        {{5, -2}, {0, 0}, {-5, 0}},
        {{0, 0}, {0, -2}, {0, -4}},
        {{-5, 0}, {0, -4}, {5, -2}}
    };
    auto start = high_resolution_clock::now();
    Matrix<Complex> r = matrix::inverse_by_minors(m);
    auto stop = high_resolution_clock::now();
    Matrix<Complex> c = {
        {{0.330882, 0.0514706}, {0.220588, 0.367647}, {0.110294, 0.183824}},
        {{0.220588, 0.367647}, {0.147059, 0.411765}, {0.0735294, 0.455882}},
        {{0.110294, 0.183824}, {0.0735294, 0.455882}, {0.0367647, 0.227941}}
    };
    assert(cmp_matrixes(r, c));
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Inverse by minors nanoseconds elapsed: " << duration.count() << '\n';
}