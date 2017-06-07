// NumberObject 是所有大數型別的基本類別
#pragma once
#include<string>

enum NumberType{
	INT,
	DEC,
	COM,
	NUL
};
class Integer;
class Decimal;
class Complex;


class NumberObject {
private:
	std::string strNums;
	std::string showStrNums;
public:
	// Constructors.
	NumberObject(){
		strNums = "0";
	}
	NumberObject(std::string& s){
		strNums = s;
	}
	virtual bool IsPositive() = 0;
	// Getter
	std::string& StrNums(){
		return strNums;
	}
	std::string& ShowStrNums(){
		return showStrNums;
	}
	std::string AbsStrNums(){
		return (strNums[0]!='-')?strNums: strNums.substr(1);
	}
	friend std::ostream& operator <<(std::ostream& out,NumberObject& b){
		return out << b.ShowStrNums();
	}
	friend std::istream& operator >> (std::istream& in,NumberObject& b){
		in >> b.StrNums();
		return in;
	}
};