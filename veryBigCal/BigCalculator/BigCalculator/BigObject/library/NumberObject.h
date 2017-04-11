// NumberObject 是所有大數型別的基本類別
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