#include "complex.hpp"
#include <vector>

using mtx_t = std::vector<std::vector<Complex>>;

namespace chabaniuk_m {

	/*
	* Пошук оберененої матриці методом Ньоютона;
	* Тип матриці - vector<vector<Complex>>;
	* epsilon - точність обрахунку матриці (менше - точніше, але довше),
	* бажано використовувати оптимальне значення 0.001
	* Якщо матриця А не валідна, повертає
	* пусту матрицю ( vector<vector<Complex>>() ) та
	* видає повідомлення в консоль
	*/ 
	mtx_t inverse(const mtx_t A, double epsilon);


	namespace auxiliary {

		bool is_valid(const mtx_t& A);							// чи квадратна & n >= 1

		mtx_t mult(const mtx_t& A, Complex val);				// множення матриці на число

		Complex to_number(const mtx_t& E);						// наближення матриці "похибки" до числа

		mtx_t get_unit_mtx(int n);								// генерує одиничну матрицю розмірності n

		mtx_t get_hermitian_transpose_mtx(const mtx_t& A);		// пошук ермітово спряженої матриці

		Complex max_row_sum(const mtx_t& A);					// макс сума елеметів рядка серед всіх рядків

		Complex max_column_sum(const mtx_t& A);					// макс сума елеметів стовпців серед всіх стовпців
	}
}

