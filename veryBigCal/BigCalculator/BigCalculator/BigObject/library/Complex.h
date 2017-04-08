// Complex 是帶正負號的浮點數
#pragma once
#include "Decimal.h"

const int COMPLEX_POINT_SIZE = 10;

class Complex :NumberObject {
private:
	Decimal real; //實部
	Decimal imag; //虛部
	std::string strReal;
	std::string strImag;
	// [NEED IMPLEMENT] String to Complex.
	void StoC(std::string s);

public:
	// Constructors.
	Complex():NumberObject(){
		StoC(NumberObject::StrNums());
		real = Integer(strReal);
		imag = Integer(strImag);
	}
	Complex(std::string s):NumberObject(s){
		StoC(NumberObject::StrNums());
		real = Integer(strReal);
		imag = Integer(strImag);
	}
	Complex(Integer& i) {
		real = (Decimal)i;
		imag = (Decimal)"0";
	}
	Complex(Decimal& d){
		real = d;
		imag = (Decimal)"0";
	}
	// Getter
	Decimal& Real(){ return real; }
	Decimal& Imag(){ return imag; }

};