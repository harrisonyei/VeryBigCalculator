// Integer 帶正負號的整數

#pragma once
#include <vector>
#include <iostream>
#include "NumberObject.h"


class Integer : NumberObject {
private:
	std::vector<unsigned int> nums;
	// [NEED IMPLEMENT] String to integer.
	void StoInt(std::string s);
	void ItoS(std::vector<unsigned int>&);


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

	friend bool operator ==(Integer& a,Integer& b);
	friend bool operator >(Integer& a,Integer& b);
	friend bool operator <(Integer& a,Integer& b);
	friend bool operator >=(Integer& a,Integer& b);
	friend bool operator <=(Integer& a,Integer& b);

	friend std::ostream& operator <<(std::ostream& out,Integer& b);
	friend std::istream& operator >>(std::istream& a,Integer& b);

};