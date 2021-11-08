#pragma once

#include <vector>
#include <stdexcept>

template<typename T>
using Matrix = std::vector<std::vector<T>>;

namespace matrix {
	template<typename T>
	bool is_correct_multiply_sizes(const Matrix<T>& first, const Matrix<T>& second);
	template<typename T>
	bool is_correct_addition_sizes(const Matrix<T>& first, const Matrix<T>& second);
	template<typename T>
	void to_square_matrix(Matrix<T>& matrix, const size_t& size);

	template<typename T>
	Matrix<T> classic_multiply(const Matrix<T>& lhs, const Matrix<T>& rhs);
	template<typename T>
	Matrix<T> add_matrix(Matrix<T> lhs, const Matrix<T>& rhs);
	template<typename T>
	Matrix<T> sub_matrix(Matrix<T> lhs, const Matrix<T>& rhs);
	size_t to_degrees_two(const size_t& number);
}
