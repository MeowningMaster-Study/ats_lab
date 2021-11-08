#pragma once
#include "complex.hpp"
#include <vector>

using mtx_t = std::vector<std::vector<Complex>>;

namespace chabaniuk_m {

	/*
	* ����� ��������� ������� ������� ��������;
	* ��� ������� - vector<vector<Complex>>;
	* epsilon - �������� ��������� ������� (����� - �������, ��� �����),
	* ������ ��������������� ���������� �������� 0.001
	* ���� ������� � �� ������, �������
	* ����� ������� ( vector<vector<Complex>>() ) ��
	* ���� ����������� � �������
	*/ 
	mtx_t inverse(const mtx_t A, double epsilon);


	namespace auxiliary {

		bool is_valid(const mtx_t& A);							// �� ��������� & n >= 1

		mtx_t mult(const mtx_t& A, Complex val);				// �������� ������� �� �����

		Complex to_number(const mtx_t& E);						// ���������� ������� "�������" �� �����

		mtx_t get_unit_mtx(int n);								// ������ �������� ������� ��������� n

		mtx_t get_hermitian_transpose_mtx(const mtx_t& A);		// ����� ������� �������� �������

		Complex max_row_sum(const mtx_t& A);					// ���� ���� ������� ����� ����� ��� �����

		Complex max_column_sum(const mtx_t& A);					// ���� ���� ������� �������� ����� ��� ��������
	}
}

