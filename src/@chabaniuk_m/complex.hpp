#pragma once

#include <iostream>
#include <sstream>
#include <cmath>

class Complex
{
public:
	Complex();																										//tested
	Complex(double rationalPart);																					//tested
	Complex(double rationalPart, double imaginePart);																//tested

	Complex operator+(const Complex& other) const;
	Complex operator+(const double rational) const;
	Complex& operator+=(const Complex& other);
	Complex& operator+=(const double rational);	
	Complex operator-(const Complex& other) const;
	Complex operator-(const double rational) const;
	Complex& operator-=(const Complex& other);
	Complex& operator-=(const double rational);
	Complex operator*(const Complex& other) const;
	Complex operator*(const double rational) const;
	Complex& operator*=(const Complex& other);
	Complex& operator*=(const double rational);
	Complex operator/(const Complex& other) const;
	Complex operator/(const double rational) const;
	Complex& operator/=(const Complex& other);
	Complex& operator/=(const double rational);
	Complex operator-() const;

	bool operator==(const Complex& other) const;
	bool operator!=(const Complex& other) const;

	// IT IS NOT POSSIBLE TO COMPARE 2 COMPLEX NUMBERS https://www.cut-the-knot.org/do_you_know/complex_compare.shtml


	double getRationalPart() const;																					//tested
	double getImaginePart() const;																					//tested
	Complex getComplement() const;
	double to_rational() const;
	std::string toString() const;																					//tested
	//returns the number of chars used to output
	int length() const;																								//tested

	friend std::ostream& operator<< (std::ostream& out, const Complex& complex);									//tested

private:
	double r;			//rational part
	double i;			//imagine part

	double* mult(const Complex& c) const;
	double* div(const Complex& c) const;
	bool equals(double a, double b) const;
};

