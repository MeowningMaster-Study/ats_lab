#pragma once

#include <vector>
#include "@chabaniuk_m/complex.hpp"

namespace dzhedzhalyk {
    vector<vector<Complex>> augmentedMatrix (vector<vector<Complex>> matrix) {
        vector<vector<Complex>> augmented = matrix;
        int n = matrix.size();
        for (int i=0; i<n; i++) {
            augmented[i].resize(n*2);
            for (int j=0; j<n; j++) {
                if (i==j)
                    augmented[i][j+n] = 1;
                else
                    augmented[i][j+n] = 0;
            }
        }
        return augmented;
    }

    void displayMatrix(vector<vector<Complex>> matrix){
        for(vector<Complex> line : matrix){
            for(int i=0; i < line.size(); i++){
                std::cout << line[i] << " ";
            }
            std::cout << std::endl;
        }
    }

    vector<vector<Complex>> inverseMatrix(vector<vector<Complex>> matrix) {
        vector<vector<Complex>> augmented = augmentedMatrix(matrix);
        int n = matrix.size();
        Complex ratio;
        for(int i=0; i<n; i++) {
            if(augmented[i][i] == 0.0)
                throw std::invalid_argument("Inverse matrix does not exist!");
            for(int j=0; j<n; j++) {
                if(i != j) {
                    ratio = augmented[j][i] / augmented[i][i];
                    for(int k=0; k<2*n; k++)
                        augmented[j][k] -= ratio*augmented[i][k];
                }
            }
        }
        for(int i=0; i<n; i++)
            for(int j=n; j<2*n; j++)
                augmented[i][j] /= augmented[i][i];

        vector<vector<Complex>> inverse(n, vector <Complex>(n));

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                inverse[i][j] = augmented[i][j+n];

        return inverse;
    }

}
