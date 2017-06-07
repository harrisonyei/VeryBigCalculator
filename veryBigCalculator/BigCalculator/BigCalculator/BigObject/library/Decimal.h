// Decimal 是帶正負號的浮點數
#pragma once
#include "Integer.h"

const int DECIMAL_POINT_SIZE = 100;

class Decimal:public NumberObject{
private:
	Integer nume; //分子
	Integer deno; //分母
	std::string strNume;
	std::string strDeno;
	void StoD(std::string s);
	void DtoS(Integer& nume,Integer& deno);

public:
	// Constructors.
	Decimal();
	Decimal(std::string s);
	Decimal(Integer& i);
	Decimal(Complex& c);
	// Getter
	Integer& Nume(){ return nume; }
	Integer& Deno(){ return deno; }

	friend Decimal operator +(Decimal& a,Decimal b);
	friend Decimal operator -(Decimal& a,Decimal b);
	friend Decimal operator *(Decimal& a,Decimal b);
	friend Decimal operator /(Decimal& a,Decimal b);
	friend Decimal operator ^(Decimal& a,Decimal b);

	std::string toComplexPrec();
	Decimal Sqrt();
	virtual bool IsPositive(){
		return (nume.IsPositive() ^ deno.IsPositive());
	}

	friend bool operator ==(Decimal& a,Decimal& b);
	friend bool operator >(Decimal& a,Decimal& b);
	friend bool operator <(Decimal& a,Decimal& b);
	friend bool operator >=(Decimal& a,Decimal& b);
	friend bool operator <=(Decimal& a,Decimal& b);
	friend bool operator !=(Decimal& a,Decimal& b);

	friend std::ostream& operator <<(std::ostream& out,Decimal& b);
	friend std::istream& operator >> (std::istream& a,Decimal& b);

};
