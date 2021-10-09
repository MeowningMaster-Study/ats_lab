#include <vector>
#include "complex.hpp"
#include "@theblacl1ght/strassen.hpp"

namespace dmiron{

    struct DecomposedMatrix{
        vector<vector<Complex>> L, U;
    };

    vector<Complex> addedVectors(vector<Complex> v1, vector<Complex> v2){
        for(int i=0; i<v1.size(); i++){ v1[i] += v2[i]; }
        return v1;
    }

    vector<Complex> multipliedVector(vector<Complex> v1, Complex c){
        for(auto & i : v1){ i *= c; }
        return v1;
    }

    void displayMatrix(vector<vector<Complex>> matrix){
        for(vector<Complex> line : matrix){
            for(int i=0; i < line.size(); i++){
                std::cout << line[i] << " ";
            }
            std::cout << std::endl;
        }
    }

    vector<vector<Complex>> identityMatrix(int n, int c=1){
        vector<vector<Complex>> res;
        for (int i = 0; i < n; ++i) {
            vector<Complex> line;
            for (int j = 0; j < n; ++j) {
                if(i == j) line.emplace_back(c,0);
                else line.emplace_back(0,0);
            }
            res.push_back(line);
        }
        return res;
    }

    vector<vector<Complex>> inverseUpperMatrix(vector<vector<Complex>> matrix){
        vector<vector<Complex>> res = identityMatrix((int) matrix.size());

        for (long long i = (signed) matrix.size()-1; i >= 0; --i) {
            Complex c = matrix[i][i];
            if(c == Complex(0, 0)) throw std::invalid_argument("Inverse matrix does not exist!");
            matrix[i] = multipliedVector(matrix[i], Complex(1)/c);
            res[i] = multipliedVector(   res[i], Complex(1)/c);
            for (long long j = 0; j < i; ++j) {
                c = matrix[j][i];
                matrix[j] = addedVectors(matrix[j], multipliedVector(matrix[i], c * -1));
                res[j] = addedVectors(   res[j], multipliedVector(   res[i], c * -1));
            }
        }
        return res;
    }

    vector<vector<Complex>> inverseLeftMatrix(vector<vector<Complex>> matrix){
        vector<vector<Complex>> res = identityMatrix((int) matrix.size());

        for (unsigned long long i = 0; i < matrix.size(); ++i) {
            Complex c = matrix[i][i];
            if(c == Complex(0, 0)) throw std::invalid_argument("Inverse matrix does not exist!");
            matrix[i] = multipliedVector(matrix[i], Complex(1)/c);
            res[i] = multipliedVector(   res[i], Complex(1)/c);
            for (long long j = (signed) matrix.size()-1; j > i; --j) {
                c = matrix[j][i];
                matrix[j] = addedVectors(matrix[j], multipliedVector(matrix[i], c * -1));
                res[j] = addedVectors(   res[j], multipliedVector(   res[i], c * -1));
            }
        }
        return res;
    }

    DecomposedMatrix decomposeMatrix(vector<vector<Complex>> matrix){
        vector<vector<Complex>> L = identityMatrix(matrix.size());
        vector<vector<Complex>> U = identityMatrix(matrix.size(), 0);

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix.size(); ++j) {
                if(i <= j){
                    Complex sum = 0;
                    for (int k = 0; k < i; ++k) sum += L[i][k] * U[k][j];
                    U[i][j] = matrix[i][j] - sum;
                } else {
                    Complex sum = 0;
                    for (int k = 0; k < j; ++k) sum += L[i][k] * U[k][j];
                    L[i][j] = (matrix[i][j] - sum)/U[j][j];
                }
            }
        }
        return DecomposedMatrix{L, U};
    }

    vector<vector<Complex>> inverseMatrix(vector<vector<Complex>> matrix){
        DecomposedMatrix dm = decomposeMatrix(matrix);
        return strassen_multiply(inverseUpperMatrix(dm.U), inverseLeftMatrix(dm.L));
    }

}

