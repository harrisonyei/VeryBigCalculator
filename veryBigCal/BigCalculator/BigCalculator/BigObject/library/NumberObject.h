// NumberObject �O�Ҧ��j�ƫ��O�������O
#pragma once
#include<string>

class Integer;
class Decimal;
class Complex;


class NumberObject {
private:
	std::string strNums;

public:
	// Constructors.
	NumberObject(){
		strNums = "0";
	}
	NumberObject(std::string& s){
		strNums = s;
	}
	// Getter
	std::string& StrNums(){
		return strNums;
	}

};