// Complex �O�a���t�����B�I��
#pragma once
#include "Decimal.h"

const int COMPLEX_POINT_SIZE = 10;

class Complex :public NumberObject {
private:
	Decimal real; //�곡
	Decimal imag; //�곡
	std::string strReal;
	std::string strImag;
	// [NEED IMPLEMENT] String to Complex.
	void StoC(std::string s);
	void CtoS(Decimal& r,Decimal& i);

public:
	// Constructors.
	Complex();
	Complex(NumberObject& n);
	Complex(std::string s);
	Complex(Integer& i);
	Complex(Decimal& d);
	// Getter
	Decimal& Real(){ return real; }
	Decimal& Imag(){ return imag; }

	friend Complex operator +(Complex& a,Complex b);
	friend Complex operator -(Complex& a,Complex b);
	friend Complex operator *(Complex& a,Complex b);
	friend Complex operator /(Complex& a,Complex b);
	friend Complex operator ^(Complex& a,Integer b);

	virtual bool IsPositive(){
		return real.IsPositive();
	}

	friend bool operator ==(Complex& a,Complex& b);
	friend bool operator !=(Complex& a,Complex& b);

	friend std::ostream& operator <<(std::ostream& out,Complex& b);
	friend std::istream& operator >> (std::istream& a,Complex& b);

};