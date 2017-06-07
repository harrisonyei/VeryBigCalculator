#include "library\Complex.h"

// Constructors.
Integer::Integer():NumberObject(){
	StoInt(NumberObject::StrNums());
	ItoS(nums);
}
Integer::Integer(std::string s) : NumberObject(s){
	StoInt(NumberObject::StrNums());
	ItoS(nums);
}
Integer::Integer(Decimal d){
	// [NOTFINISHED] 應該要回傳 -->(nume / deno) . nums;
	nums = (d.Nume()/d.Deno()).Nums();
	ItoS(nums);
}
Integer::Integer(Complex c){
	// [NOTFINISHED] 應該要回傳 -->(nume / deno) . nums;
	nums = ((c.Real()).Nume()/(c.Real()).Deno()).Nums();
	ItoS(nums);
}

// Constructors.
Decimal::Decimal():NumberObject(){
	StoD(NumberObject::StrNums());
	nume = Integer(strNume);
	deno = Integer(strDeno);
	DtoS(nume,deno);
}
Decimal::Decimal(std::string s) : NumberObject(s){
	StoD(NumberObject::StrNums());
	nume = Integer(strNume);
	deno = Integer(strDeno);
	DtoS(nume,deno);
}
Decimal::Decimal(Integer& i){
	nume = i;
	deno = (Integer)"1";
	DtoS(nume,deno);
}
Decimal::Decimal(Complex& c){
	nume = (c.Real()).Nume();
	deno = (c.Real()).Deno();
	DtoS(nume,deno);
}

// Constructors.
Complex::Complex():NumberObject(){
	StoC(NumberObject::StrNums());
	real = Decimal(strReal);
	imag = Decimal(strImag);
	CtoS(real,imag);
}
Complex::Complex(std::string s) : NumberObject(s){
	StoC(NumberObject::StrNums());
	real = Decimal(strReal);
	imag = Decimal(strImag);
	CtoS(real,imag);
}
Complex::Complex(Integer& i){
	real = (Decimal)i;
	imag = (Decimal)"0";
	CtoS(real,imag);
}
Complex::Complex(Decimal& d){
	real = d;
	imag = (Decimal)"0";
	CtoS(real,imag);
}
Complex::Complex(NumberObject& n){
	StoC(n.StrNums());
	real = Decimal(strReal);
	imag = Decimal(strImag);
	CtoS(real,imag);
}