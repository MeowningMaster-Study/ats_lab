#include "newton.hpp"
#include "..\@theblacl1ght\basic_matrix.hpp"
#include "..\@meowning_master\matrix.hpp"
#include "..\util.hpp"

// MAIN METHOD
mtx_t chabaniuk_m::inverse(const mtx_t A, double epsilon) {		// add epsilon

	using namespace auxiliary;

	if (!is_valid(A)) return vector<vector<Complex>>();
	
	mtx_t AH = get_hermitian_transpose_mtx(A);										// ерм≥това спр€жена матриц€

	Complex t_magnitude = Complex(1) / (max_row_sum(A) * max_column_sum(A));		// магн≥туда

	mtx_t B = mult(AH, t_magnitude);			

	mtx_t I = get_unit_mtx(A.size());												// одинична матриц€

	mtx_t E;																		

	do {

		E = matrix::sub_matrix(I, matrix::classic_multiply(B, A));					// k-та матриц€ в≥дхиленн€

		B = matrix::classic_multiply(matrix::add_matrix(I, E), B);					// результат при k-му в≥дхиленн≥

	} while (to_number(E).to_rational() > epsilon);

	return B;
}


// *** auxiliary methods ***


bool chabaniuk_m::auxiliary::is_valid(const mtx_t& A)
{
	if (A.size() == 0) {

		std::cout << "@chabaniuk_m\nERROR: invalid matrix A: has no elements\n";

		return false;
	}
	else if (!is_square(A)) {

		std::cout << "@chabaniuk_m\nERROR: invalid matrix A: is not a square matrix\n";

		return false;
	}

	return true;
}

mtx_t chabaniuk_m::auxiliary::mult(const mtx_t& A, Complex val) {

	mtx_t res = mtx_t(A);

	for (size_t i = 0; i < A.size(); i++)
		for (size_t j = 0; j < A.at(0).size(); j++)

			res[i][j] = A[i][j] * val;

	return res;
}

Complex chabaniuk_m::auxiliary::to_number(const mtx_t& E) {

	return E.at(0).at(0);
}

mtx_t chabaniuk_m::auxiliary::get_unit_mtx(int n) {
	
	mtx_t I = mtx_t(n, vector<Complex>(n, Complex()));

	for (size_t i = 0; i < n; i++)
	
		I[i][i] = Complex(1);

	return I;
}

mtx_t chabaniuk_m::auxiliary::get_hermitian_transpose_mtx(const mtx_t& A) {

	mtx_t At = matrix::transpose(A);			// транспонована матриц€

	mtx_t AH = mtx_t(At);						// ≈рм≥тово-спр€жена матриц€

	for (size_t i = 0; i < AH.size(); i++)
		for (size_t j = 0; j < AH.at(i).size(); j++)

			AH[i][j] = AH[i][j].getComplement();

	return AH;
}

Complex chabaniuk_m::auxiliary::max_row_sum(const mtx_t& A) {

	Complex max = Complex(DBL_MIN, DBL_MIN);

	for (size_t i = 0; i < A.size(); i++) {

		Complex sum = 0;

		for (size_t j = 0; j < A.at(i).size(); j++)

			sum += A[i][j];

		if (max.to_rational() < sum.to_rational()) max = sum;
	}

	return max;
}

Complex chabaniuk_m::auxiliary::max_column_sum(const mtx_t& A) {

	if (A.size() < 1) {

		cout << "Error: Matrix is empty [0x0]";
		return 0;
	}

	Complex max = Complex(DBL_MIN, DBL_MIN);

	for (size_t j = 0; j < A.at(0).size(); j++) {

		Complex sum = 0;

		for (size_t i = 0; i < A.size(); i++)

			sum += A[i][j];

		if (max.to_rational() < sum.to_rational()) max = sum;
	}

	return max;
}
