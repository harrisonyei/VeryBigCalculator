// Integer 帶正負號的整數

#pragma once
#include <vector>

#include "NumberObject.h"

class Integer : NumberObject {
private:
	std::vector<int> nums;
	// [NEED IMPLEMENT] String to integer.
	void StoInt(std::string s);

public:
	// Constructors.
	Integer():NumberObject(){
		StoInt(NumberObject::StrNums());
	}
	Integer(std::string s):NumberObject(s){
		StoInt(NumberObject::StrNums());
	}
	/*Integer(Decimal d){
		// [NOTFINISHED] 應該要回傳 -->(nume / deno) . nums;
		nums = (d.Nume()).Nums();
	}
	Integer(Complex c){
		// [NOTFINISHED] 應該要回傳 -->(nume / deno) . nums;
		nums = ((c.Real()).Nume()).Nums();
	}*/
	// Getter
	std::vector<int>& Nums(){ return nums; }

};