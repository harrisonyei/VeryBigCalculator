
// Name: 黃浩禎 
// Student ID: B10515007
// Date: April 7, 2017 
// Last Update: Date: April 7, 2017
// Problem statement: This C++ program separated into numerator and denominator.
#include "library\Decimal.h"
#include <string>

// [NEED IMPLEMENT] String to decimal.
void Decimal::StoD(std::string s) {	
	std::string numerator; 
	std::string denominator = "1";

	int negtiveFlag = 0;
	int dotPos      = 0;

	//if number is negtive,negtiveFlag equal to 1,delet '-' from the string
	if (s[0] == '-') {
		negtiveFlag = 1;
		s.erase(s.begin() + 0);
	}

	//make sure dot position
	for (int i = 0; i < s.size(); i++)
		if (s[i] == '.') {
			dotPos = i;
			s.erase(s.begin() + i);
			numerator = s;
			negtiveFlag == 1 ? numerator.insert(0, "-") : numerator = s;
		}

	//have no dot
	if (dotPos == 0) {
		numerator = s;
		negtiveFlag == 1 ? numerator.insert(0, "-") : numerator = s;
		denominator = "1";
	}
	else {
		for (int i = 0; i < s.size() - dotPos; i++)
			denominator += '0';
	}

	//erase 0,-001230 -> -1230
	for (int i = 0; i < numerator.size(); i++) {
		if (numerator == "0"){ break; }

		if (numerator[i] != '0' && numerator[i] != '-'){ break; }
			
		if (numerator[i] == '0') {
			numerator.erase(numerator.begin() + i);
			i--;
		}
	}
	strNume = numerator;
	strDeno = denominator;

}

Decimal operator +(Decimal& a,Decimal& b){
	Decimal c;
	Integer tempa_nume;
	Integer tempb_nume;	
	tempa_nume = a.nume * b.deno;
	tempb_nume = b.nume * a.deno;	
	//[請先通分]
	c.nume = tempa_nume + tempb_nume;
	c.deno = a.deno * b.deno;
	return c;
}
Decimal operator -(Decimal& a,Decimal& b){
	Decimal c;
	Integer tempa_nume;
	Integer tempb_nume;
	tempa_nume = a.nume * b.deno;
	tempb_nume = b.nume * a.deno;
	//[請先通分]
	c.nume = tempa_nume - tempb_nume;
	c.deno = a.deno * b.deno;
	return c;
}
Decimal operator *(Decimal& a,Decimal& b){
	Decimal c;
	c.nume = a.nume * b.nume;
	c.deno = a.deno * b.deno;
	c.DtoS();
	return c;
}
Decimal operator /(Decimal& a,Decimal& b){
	Decimal c;
	c.nume = a.nume * b.deno;
	c.deno = a.deno * b.nume;
	c.DtoS();
	return c;
}

void Decimal::DtoS() {
	//0/x -> "0"
	if (nume.StrNums() == "0") {
		dotExpress = "0"; 
		return;
	}
	int dotPos = (nume/deno).NumberObject::StrNums().size();	
	int addzero = nume > deno ? (nume / deno).NumberObject::StrNums().size() : (deno / nume).NumberObject::StrNums().size();
	

	std::string result;
	Integer temp = nume;

	//add 0
	for (int i = 0; i < 100; i++) {
		nume.StrNums() += "0";
	}	
	//nume = Integer(nume.StrNums());	
	result = (nume / deno).StrNums();
	
	//0."00000"1
	if (temp < deno) {
		for (int i = 0; i < addzero; i++) {
			result.insert(0, "0");
		}
	}
				
	result.insert(dotPos, ".");
	dotExpress = result;
}

