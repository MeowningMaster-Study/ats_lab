#include "util.hpp"
using namespace std;

void show(const mtx_t matrix) {

    cout << "\n";

    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix.at(i).size(); j++)
        {
            cout << " " << setw(16) << left << matrix[i][j];
        }

        cout << "\n\n";
    }
}

bool is_square(const mtx_t& matrix) {

    int n = matrix.size();

    for (size_t i = 0; i < n; i++)

        if (matrix[i].size() != n) return false;

    return true;
}
