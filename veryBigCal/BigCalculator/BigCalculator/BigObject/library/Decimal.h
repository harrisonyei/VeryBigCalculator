// Decimal �O�a���t�����B�I��
#pragma once
#include "Integer.h"

const int DECIMAL_POINT_SIZE = 100;

class Decimal:NumberObject{
private:
	Integer nume; //���l
	Integer deno; //����
	std::string strNume;
	std::string strDeno;	
	// [NEED IMPLEMENT] String to decimal.
	void StoD(std::string s);
	void DtoS();

public:
	// Constructors.
	Decimal();
	Decimal(std::string s);
	Decimal(Integer& i);
	Decimal(Complex& c);
	// Getter
	Integer& Nume(){ return nume; }
	Integer& Deno(){ return deno; }
	
	std::string dotExpress;

	friend Decimal operator +(Decimal& a,Decimal& b);
	friend Decimal operator -(Decimal& a,Decimal& b);
	friend Decimal operator *(Decimal& a,Decimal& b);
	friend Decimal operator /(Decimal& a,Decimal& b);

};
