
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
	
	int dotPos  = 0;
	int addzero = 0;	

	//make sure dot position
	for (int i = 0; i < s.size(); i++)
		if (s[i] == '.') {
			dotPos = i;
			s.erase(s.begin() + i);
			if ((s.size() - dotPos) > 100) {
				s.erase(s.begin() + dotPos + 100, s.end());
				addzero = 100;
			}
			numerator = s;
		}

	//have no dot
	if (dotPos == 0) {
		numerator = s;
		denominator = "1";
	}
	else {
		if (!addzero) {
			addzero = s.size() - dotPos;
		}
		for (int i = 0; i < addzero; i++)
			denominator += '0';
	}

	//erase 0,-001230 -> -1230
	for (int i = 0; i < numerator.size(); i++) {
		if (numerator == "0") { break; }

		if (numerator[i] != '0' && numerator[i] != '-') { break; }

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
	//std::cout << b.nume.NumberObject::StrNums() << std::endl;
	//std::cout << b.deno.NumberObject::StrNums() << std::endl;	
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
	return c;
}
Decimal operator /(Decimal& a,Decimal& b){
	Decimal c;
	c.nume = a.nume * b.deno;
	c.deno = a.deno * b.nume;	
	return c;
}



