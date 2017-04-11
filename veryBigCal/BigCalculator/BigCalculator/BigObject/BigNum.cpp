#include "library\Complex.h"

// Constructors.
Integer::Integer():NumberObject(){
	StoInt(NumberObject::StrNums());
}
Integer::Integer(std::string s) : NumberObject(s){
	StoInt(NumberObject::StrNums());
}
Integer::Integer(Decimal d){
	// [NOTFINISHED] 應該要回傳 -->(nume / deno) . nums;
	nums = (d.Nume()).Nums();
}
Integer::Integer(Complex c){
	// [NOTFINISHED] 應該要回傳 -->(nume / deno) . nums;
	nums = ((c.Real()).Nume()).Nums();
}

// Constructors.
Decimal::Decimal():NumberObject(){
	StoD(NumberObject::StrNums());
	nume = Integer(strNume);
	deno = Integer(strDeno);
}
Decimal::Decimal(std::string s) : NumberObject(s){
	StoD(NumberObject::StrNums());
	nume = Integer(strNume);
	deno = Integer(strDeno);
}
Decimal::Decimal(Integer& i){
	nume = i;
	deno = (Integer)"1";
}
Decimal::Decimal(Complex& c){
	nume = (c.Real()).Nume();
	deno = (c.Real()).Deno();
}

// Constructors.
Complex::Complex():NumberObject(){
	StoC(NumberObject::StrNums());
	real = Integer(strReal);
	imag = Integer(strImag);
}
Complex::Complex(std::string s) : NumberObject(s){
	StoC(NumberObject::StrNums());
	real = Integer(strReal);
	imag = Integer(strImag);
}
Complex::Complex(Integer& i){
	real = (Decimal)i;
	imag = (Decimal)"0";
}
Complex::Complex(Decimal& d){
	real = d;
	imag = (Decimal)"0";
}