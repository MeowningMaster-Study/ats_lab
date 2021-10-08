#include "strassen.h"

size_t matrix::to_degrees_two(const size_t& number) {
	size_t d_two = 1;
	while (number > d_two) { d_two = d_two << 1; }
	return d_two;
}