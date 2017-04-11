// Integer ±a¥¿­t¸¹ªº¾ã¼Æ

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

	friend Integer operator +(Integer& a,Integer& b);
	friend Integer operator -(Integer& a,Integer& b);
	friend Integer operator *(Integer& a,Integer& b);
	friend Integer operator /(Integer& a,Integer& b);
	friend Integer operator ^(Integer& a,Integer& b);
	friend Integer operator !(Integer& a);
  
};