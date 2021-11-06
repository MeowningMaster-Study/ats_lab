#pragma once
#include "../@theblacl1ght/basic_matrix.hpp"
using namespace std;

namespace matrix {
    template<class T>
    Matrix<T> sub_matrix(const Matrix<T>& m, int p, int q) {
        int i = 0, j = 0, n = m.size();
        Matrix<T> tmp(n - 1, vector<T>(n - 1));
        for (int row = 0; row < n; row += 1) {
            for (int col = 0; col < n; col += 1) {
                if (row != p && col != q) {
                    tmp[i][j] = m[row][col];
                    j += 1;
                    if (j == n - 1) {
                    j = 0;
                    i += 1;
                    }
                }
            }
        }
        return tmp;
    }

    template<class T>
    T determinant(const Matrix<T>& m) {
        int n = m.size();
        T d;

        if (n == 1) {
            return m[0][0];
        }

        if (n == 2) {
            return (m[0][0] * m[1][1]) - (m[0][1] * m[1][0]);
        }

        double sign = 1;
        for (int i = 0; i < n; i += 1) {
            Matrix<T> tmp = sub_matrix(m, 0, i);
            auto elem = m[0][i] * determinant(tmp); 
            if (i == 0) {
                d = elem;
            } else {
                d += elem * sign;
            }
            sign = -sign;
        }

        return d;
    }

    template<class T>
    Matrix<T> transpose(const Matrix<T>& m) {
        int n = m.size();
        Matrix<T> r(n, vector<T>(n));
        for (int i = 0; i < n; i += 1) {
            for (int k = 0; k < n; k += 1) {
                r[i][k] = m[k][i];
            }
        }
        return r;
    }

    template<class T>
    Matrix<T> inverse_by_minors(const Matrix<T>& m) {
        int n = m.size();
        T d = determinant(m); 
        Matrix<T> r(n, vector<T>(n));
        for (int i = 0; i < n; i += 1) {
            for (int k = 0; k < n; k += 1) {
                Matrix<T> tmp = sub_matrix(m, i, k);
                double sign = (i + k) & 1 ? -1 : 1;
                r[i][k] = determinant(tmp) / d * sign;
            }
        }
        return transpose(r);
    }
}