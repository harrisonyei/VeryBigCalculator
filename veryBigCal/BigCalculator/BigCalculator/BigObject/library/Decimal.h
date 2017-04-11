// Decimal 是帶正負號的浮點數
#pragma once
#include "Integer.h"

const int DECIMAL_POINT_SIZE = 100;

class Decimal:NumberObject{
private:
	Integer nume; //分母
	Integer deno; //分子
	std::string strNume;
	std::string strDeno;
	// [NEED IMPLEMENT] String to decimal.
	void StoD(std::string s);

public:
	// Constructors.
	Decimal();
	Decimal(std::string s);
	Decimal(Integer& i);
	Decimal(Complex& c);
	// Getter
	Integer& Nume(){ return nume; }
	Integer& Deno(){ return deno; }

};
