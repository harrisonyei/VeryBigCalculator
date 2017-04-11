// Integer 帶正負號的整數

#pragma once
#include <vector>

#include "NumberObject.h"


class Integer : NumberObject {
private:
	std::vector<unsigned int> nums;
	// [NEED IMPLEMENT] String to integer.
	void StoInt(std::string s);


public:
	// Constructors.
	Integer();
	Integer(std::string s);
	Integer(Decimal d);
	Integer(Complex c);
	// Getter
	std::vector<unsigned int>& Nums(){ return nums; }

};