// Decimal �O�a���t�����B�I��
#pragma once
#include "Integer.h"

const int DECIMAL_POINT_SIZE = 100;

class Decimal:NumberObject{
private:
	Integer nume; //����
	Integer deno; //���l
	std::string strNume;
	std::string strDeno;
	// [NEED IMPLEMENT] String to decimal.
	void StoD(std::string s);

public:
	// Constructors.
	Decimal():NumberObject(){
		StoD(NumberObject::StrNums());
		nume = Integer(strNume);
		deno = Integer(strDeno);
	}
	Decimal(std::string s):NumberObject(s){
		StoD(NumberObject::StrNums());
		nume = Integer(strNume);
		deno = Integer(strDeno);
	}
	Decimal(Integer& i){
		nume = i;
		deno = (Integer)"1";
	}
	/*Decimal(Complex& c){
		nume = (c.Real()).Nume();
		deno = (c.Real()).Deno();
	}*/
	// Getter
	Integer& Nume(){ return nume; }
	Integer& Deno(){ return deno; }

};
