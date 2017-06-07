// Integer ±a¥¿­t¸¹ªº¾ã¼Æ

#pragma once
#include <vector>
#include <iostream>
#include "NumberObject.h"


class Integer : public NumberObject {
private:
	std::vector<long long> nums;
	void StoInt(std::string s);
	void ItoS(std::vector<long long>&);


public:
	// Constructors.
	Integer();
	Integer(std::string s);
	Integer(Decimal d);
	Integer(Complex c);
	// Getter
	std::vector<long long>& Nums(){ return nums; }
	std::string StrAbs(){
		if(NumberObject::StrNums()[0] == '-'){
			return NumberObject::StrNums().substr(1);
		}
		return NumberObject::StrNums();
	}

	friend Integer operator +(Integer& a,Integer b);
	friend Integer operator -(Integer& a,Integer b);
	friend Integer operator *(Integer& a,Integer b);
	friend Integer operator /(Integer& a,Integer b);
	friend Integer operator %(Integer& a,Integer b);
	friend Integer operator ^(Integer& a,Integer b);
	friend Integer operator +=(Integer& a,Integer b);
	friend Integer operator -=(Integer& a,Integer b);
	friend Integer operator !(Integer& a);

	void Sqrt();
	virtual bool IsPositive(){
		return (nums[0] != 99999999);
	}
	

	friend bool operator ==(Integer& a,Integer& b);
	friend bool operator >(Integer& a,Integer& b);
	friend bool operator <(Integer& a,Integer& b);
	friend bool operator >=(Integer& a,Integer& b);
	friend bool operator <=(Integer& a,Integer& b);
	friend bool operator !=(Integer& a,Integer& b);

	friend std::ostream& operator <<(std::ostream& out,Integer& b);
	friend std::istream& operator >>(std::istream& a,Integer& b);
};

