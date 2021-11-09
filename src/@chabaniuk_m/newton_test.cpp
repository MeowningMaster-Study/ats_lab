#include "C:\Users\Admin\source\repos\MeowningMaster\ats_lab\src\@chabaniuk_m\newton.hpp"
#include "C:\Users\Admin\source\repos\MeowningMaster\ats_lab\src\@chabaniuk_m\util.hpp"
#include <iostream>

void test() {

	double epsilon = 0.001;

	std::cout << " *** Unit tests ***\n\n";
	std::cout << " Test #1\n epsilon = " << epsilon << "\n\n";

    std::vector<std::vector<Complex>> A{
        std::vector<Complex>{Complex(1), Complex(5), Complex(0)},
        std::vector<Complex>{Complex(7), Complex(1), Complex(7)},
        std::vector<Complex>{Complex(4), Complex(1), Complex(1)}
    };

    auto res = chabaniuk_m::inverse(A, epsilon);

    Complex::set_precision(2);

    std::cout << " Matrix A:\n";
    show(A);

    std::cout << " Inversed A:\n";
    show(res);

    std::cin.get();
    std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";

    A = std::vector<std::vector<Complex>> {
        std::vector<Complex>{Complex(1, 1), Complex(5), Complex(0)},
        std::vector<Complex>{Complex(3), Complex(1), Complex(2)},
        std::vector<Complex>{Complex(4), Complex(1), Complex(0)}
    };

    std::cout << "\n Test #2\n epsilon = " << epsilon << "\n\n";

    res = chabaniuk_m::inverse(A, epsilon);

    Complex::set_precision(3);

    std::cout << " Matrix A:\n";
    show(A);

    std::cout << " Inversed A:\n";
    show(res);

    std::cin.get();
    std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";

    A = std::vector<std::vector<Complex>>{
        std::vector<Complex>{Complex(2, 3), Complex(0, -5)},
        std::vector<Complex>{Complex(14), Complex(0, 2.8)}
    };

    epsilon = 0.1;

    std::cout << "\n Test #3\n epsilon = " << epsilon << "\n\n";

    res = chabaniuk_m::inverse(A, epsilon);

    Complex::set_precision(4);

    std::cout << " Matrix A:\n";
    show(A);

    std::cout << " Inversed A:\n";
    show(res);

    std::cin.get();
    std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";

    A = std::vector<std::vector<Complex>>{
        std::vector<Complex>{Complex(18,13), Complex(0.3,8.7), Complex(1,-9.3), Complex(-9.3,-5)},
        std::vector<Complex>{Complex(-7,3.44), Complex(189), Complex(0,15), Complex(0.1,-2.34)},
        std::vector<Complex>{Complex(-91), Complex(0,-102), Complex(0.34,0.91), Complex(1,1)},
        std::vector<Complex>{Complex(71), Complex(56), Complex(0,56.87), Complex(3,13.95)}
    };

    epsilon = 0.0001;

    std::cout << "\n Test #4\n epsilon = " << epsilon << "\n\n";

    res = chabaniuk_m::inverse(A, epsilon);

    Complex::set_precision(3);

    std::cout << " Matrix A:\n";
    show(A);

    std::cout << " Inversed A:\n";
    show(res);

    std::cin.get();
}