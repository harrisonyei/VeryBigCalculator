// BigNum 是萬用數，在計算機使用
#pragma once
#include "Complex.h"

enum NumberType{
	INT,
	DEC,
	COM,
	NUM
};

union NumberUnion{
	NumberObject numObj;
	Integer numInt;
	Decimal numDec;
	Complex numCmp;
};

class BigNum {  
private:
	NumberUnion num;
	std::string name;
	NumberType type;
	
public:
	BigNum();
	
	void SetType(NumberType t){
		type = t;
	}
};