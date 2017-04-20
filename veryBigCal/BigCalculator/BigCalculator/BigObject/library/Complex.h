// Complex 是帶正負號的浮點數
#pragma once
#include "Decimal.h"

const int COMPLEX_POINT_SIZE = 10;

class Complex :public NumberObject {
private:
	Decimal real; //實部
	Decimal imag; //虛部
	std::string strReal;
	std::string strImag;
	// [NEED IMPLEMENT] String to Complex.
	void StoC(std::string s);

public:
	// Constructors.
	Complex();
	Complex(std::string s);
	Complex(Integer& i);
	Complex(Decimal& d);
	// Getter
	Decimal& Real(){ return real; }
	Decimal& Imag(){ return imag; }

	friend Complex operator +(Complex& a,Complex& b);
	friend Complex operator -(Complex& a,Complex& b);
	friend Complex operator *(Complex& a,Complex& b);
	friend Complex operator /(Complex& a,Complex& b);

};