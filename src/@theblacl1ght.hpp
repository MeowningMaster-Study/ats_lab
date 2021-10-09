#pragma once

#include <vector>
#include <utility>
#include <algorithm>
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

    template<typename T>
	Matrix<T> strassen(Matrix<T> lhs, Matrix<T> rhs, size_t n);
	template<typename T>
	void split_matrix(Matrix<T>& a,
		Matrix<T>& a1, Matrix<T>& a2, Matrix<T>& a3, Matrix<T>& a4);
	size_t to_degrees_two(const size_t& number);
	template<typename T>
	void collect_matrix(Matrix<T>& a,
		Matrix<T>& a1, Matrix<T>& a2, Matrix<T>& a3, Matrix<T>& a4);
	size_t to_degrees_two(const size_t& number);
}


template<typename T>
bool matrix::is_correct_multiply_sizes(
	const Matrix<T>& first, const Matrix<T>& second)
{
	if (first[0].size() != second.size()) {
		return false;
	}
	return true;
}

template<typename T>
bool matrix::is_correct_addition_sizes(
	const Matrix<T>& first, const Matrix<T>& second) 
{
	if (first.size() != second.size() || first[0].size() != second[0].size()) {
		false;
	}
	return true;
}

template<typename T>
void matrix::to_square_matrix(
	Matrix<T>& matrix, const size_t& size)
{
	matrix.resize(size);
	for (auto& r : matrix) {
		r.resize(size, 0);
	}
}


template<typename T>
Matrix<T> matrix::classic_multiply(
	const Matrix<T>& lhs, const Matrix<T>& rhs)
{
	if (!is_correct_multiply_sizes(lhs, rhs)) {
		throw std::runtime_error("");
	}

	Matrix<T> result(lhs.size());
	for (size_t i = 0; i < lhs.size(); ++i) {
		result[i].resize(rhs[0].size());
		for (size_t j = 0; j < rhs[0].size(); ++j) {
			for (size_t k = 0; k < lhs[0].size(); ++k) {
				result[i][j] += lhs[i][k] * rhs[k][j];
			}
		}
	}
	return result;
}

template<typename T>
Matrix<T> matrix::add_matrix(
	Matrix<T> lhs, const Matrix<T>& rhs)
{
	if (!is_correct_addition_sizes(lhs, rhs)) {
		throw std::runtime_error("");
	}

	for (size_t i = 0; i < lhs.size(); ++i) {
		for (size_t j = 0; j < lhs[0].size(); ++j) {
			lhs[i][j] += rhs[i][j];
		}
	}
	return lhs;
}

template<typename T>
Matrix<T> matrix::sub_matrix(
	Matrix<T> lhs, const Matrix<T>& rhs)
{
	if (!is_correct_addition_sizes(lhs, rhs)) {
		throw std::runtime_error("");
	}

	for (size_t i = 0; i < lhs.size(); ++i) {
		for (size_t j = 0; j < lhs[0].size(); ++j) {
			lhs[i][j] -= rhs[i][j];
		}
	}
	return lhs;
}

template<typename T>
Matrix<T> strassen_multiply(Matrix<T> lhs, Matrix<T> rhs);

template<typename T>
Matrix<T> strassen_multiply(Matrix<T> lhs, Matrix<T> rhs) {
	if (!matrix::is_correct_multiply_sizes(lhs, rhs)) {
		throw std::runtime_error("");
	}

	size_t n_rows = lhs.size(), n_columns = rhs[0].size();
	size_t new_size = matrix::to_degrees_two(
		std::max(std::max(n_rows, lhs[0].size()),
			std::max(lhs.size(), n_columns))
	);
	if (lhs.size() != new_size || lhs[0].size() != new_size) {
		matrix::to_square_matrix(lhs, new_size);
		matrix::to_square_matrix(rhs, new_size);
	}

	Matrix<T> result = matrix::strassen(lhs, rhs, new_size);

	if (n_rows != new_size) {
		result.resize(n_rows);
	}
	if (n_columns != new_size) {
		for (auto& r : result) { r.resize(n_columns); }
	}

	return result;
}

template<typename T>
Matrix<T> matrix::strassen(
	Matrix<T> lhs, Matrix<T> rhs, size_t n)
{
	if (n == 2) {
		return classic_multiply(lhs, rhs);
	}
	n = n >> 1;

	Matrix<T> a11(n), a12(n), a21(n), a22(n);
	Matrix<T> b11(n), b12(n), b21(n), b22(n);
	split_matrix(lhs, a11, a12, a21, a22);
	split_matrix(rhs, b11, b12, b21, b22);

	Matrix<T> p1 = strassen(add_matrix(a11, a22), add_matrix(b11, b22), n);
	Matrix<T> p2 = strassen(add_matrix(a21, a22), b11,					n);
	Matrix<T> p3 = strassen(a11,				  sub_matrix(b12, b22), n);
	Matrix<T> p4 = strassen(a22,			      sub_matrix(b21, b11), n);
	Matrix<T> p5 = strassen(add_matrix(a11, a12), b22,					n);
	Matrix<T> p6 = strassen(sub_matrix(a21, a11), add_matrix(b11, b12), n);
	Matrix<T> p7 = strassen(sub_matrix(a12, a22), add_matrix(b21, b22), n);

	Matrix<T> c11 = add_matrix(add_matrix(p1, p4), sub_matrix(p7, p5));
	Matrix<T> c12 = add_matrix(p3, p5);
	Matrix<T> c21 = add_matrix(p2, p4);
	Matrix<T> c22 = add_matrix(sub_matrix(p1, p2), add_matrix(p3, p6));

	Matrix<T> result(2 * n);
	for (auto& r : result) {
		r.resize(2 * n);
	}
	collect_matrix(result, c11, c12, c21, c22);

	return result;
}

template<typename T>
void matrix::split_matrix(Matrix<T>& a,
	Matrix<T>& a1, Matrix<T>& a2, Matrix<T>& a3, Matrix<T>& a4)
{
	size_t n = a.size() / 2;
	for (size_t i = 0; i < n; ++i) {
		a1[i].resize(n);
		a2[i].resize(n);
		a3[i].resize(n);
		a4[i].resize(n);

		std::copy(begin(a[i]), begin(a[i]) + n, begin(a1[i]));
		std::copy(begin(a[i]) + n, end(a[i]), begin(a2[i]));
		std::copy(begin(a[i + n]), begin(a[i + n]) + n, begin(a3[i]));
		std::copy(begin(a[i + n]) + n, end(a[i + n]), begin(a4[i]));
	}
}

size_t matrix::to_degrees_two(const size_t& number) {
	size_t d_two = 2;
	while (number > d_two) { d_two = d_two << 1; }
	return d_two;
}

template<typename T>
void matrix::collect_matrix(Matrix<T>& a,
	Matrix<T>& a1, Matrix<T>& a2, Matrix<T>& a3, Matrix<T>& a4)
{
	size_t n = a.size() / 2;
	for (size_t i = 0; i < n; ++i) {
		std::copy(begin(a1[i]), end(a1[i]), begin(a[i]));
		std::copy(begin(a2[i]), end(a2[i]), begin(a[i]) + n);
		std::copy(begin(a3[i]), end(a3[i]), begin(a[i + n]));
		std::copy(begin(a4[i]), end(a4[i]), begin(a[i + n]) + n);
	}
}
