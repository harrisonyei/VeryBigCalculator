
// Problem statement: This C++ program separate complex into real part and imaginary part.

#include <string>

#include "../Operation/TestCore.h"
#include "library\Complex.h"

void Complex::StoC(std::string s) {

	//clear white character
	TestCore::ClearWhite(s);

	int operatorPos = 0;
	char sign = 0;
	std::string realprt;
	std::string imaginaryprt;

	//find position of operator
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == '+' || s[i] == '-') {
			sign = s[i];
			operatorPos = i;
			break;
		}
	}
	//get substring from begin to position of operator
	realprt = s.substr(0, operatorPos);

	//get substring from next position of operator to the end
	imaginaryprt = s.substr(operatorPos + 1);

	//delete 'i' from imaginary part
	imaginaryprt.erase(imaginaryprt.begin() + imaginaryprt.size() - 1);

	//a - -bi = a + bi, a - bi = a + -bi
	if (sign == '-') {

		if (imaginaryprt[0] == '-') {
			imaginaryprt.erase(imaginaryprt.begin() + 0);
		}
		else {
			imaginaryprt.insert(0, "-");
		}
	}

	strReal = realprt;
	strImag = imaginaryprt;
}


Complex operator +(Complex& a,Complex& b){
	Complex c;
	c.real = a.real + b.real;
	c.imag = a.imag + b.imag;
	return c;
}
Complex operator -(Complex& a,Complex& b){
	Complex c;
	c.real = a.real - b.real;
	c.imag = a.imag - b.imag;
	return c;
}
Complex operator *(Complex& a,Complex& b){
	Complex c;
	c.real = (a.real * b.real) - (a.imag * b.imag);
	c.imag = (a.real * b.imag) + (a.imag * b.real);
	return c;
}
Complex operator /(Complex& a,Complex& b){
	// [NOT FINISHED]
	return a;
}