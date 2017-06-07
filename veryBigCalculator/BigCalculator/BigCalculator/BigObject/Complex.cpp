
// Problem statement: This C++ program separate complex into real part and imaginary part.

#include <string>

#include "../Operation/TestCore.h"
#include "library\Complex.h"

void Complex::StoC(std::string s){

	//clear white character
	TestCore::ClearWhite(s);

	int operatorPos = 0;
	char sign = 0;
	std::string realprt;
	std::string imaginaryprt;

	//find position of operator
	int i;
	for(i = 1; i < s.size(); i++){
		if(s[i] == '+' || s[i] == '-'){
			sign = s[i];
			operatorPos = i;
			break;
		}
	}

	//there is only real part or imaginary part
	if(i == s.size()){
		//real part
		if(s.find("i") == std::string::npos){
			strReal = s;
			strImag = "0";
		} else{
			//imaginary part
			//no digit before i -> 1i
			if(s.size() == 1){
				s.insert(s.size() - 1,"1");
			} else if(s[s.size() - 2] > 57 || s[s.size() - 2] < 48){
				s.insert(s.size() - 1,"1");
			}
			strReal = "0";
			s.erase(s.begin() + s.size() - 1);
			strImag = s;
		}
		return;
	}
	//no digit before i -> 1i
	if(s.size() == 1){
		s.insert(s.size() - 1,"1");
	} else if(s[s.size() - 2] > 57 || s[s.size() - 2] < 48){
		s.insert(s.size() - 1,"1");
	}
	//get substring from begin to position of operator
	realprt = s.substr(0,operatorPos);

	//get substring from next position of operator to the end
	imaginaryprt = s.substr(operatorPos + 1);

	//delete 'i' from imaginary part
	imaginaryprt.erase(imaginaryprt.begin() + imaginaryprt.size() - 1);

	//a - -bi = a + bi, a - bi = a + -bi
	if(sign == '-'){

		if(imaginaryprt[0] == '-'){
			imaginaryprt.erase(imaginaryprt.begin() + 0);
		} else{
			imaginaryprt.insert(0,"-");
		}
	}

	strReal = realprt;
	strImag = imaginaryprt;
}

void Complex::CtoS(Decimal& r,Decimal& i){
	strReal = r.toComplexPrec();
	strImag = i.toComplexPrec();
	this->StrNums() = strReal + "+" + strImag + "i";
	ShowStrNums() = this->StrNums();
}

Complex operator +(Complex& a,Complex b){
	Complex c;
	c.real = a.real + b.real;
	c.imag = a.imag + b.imag;
	c.CtoS(c.real,c.imag);
	return c;
}
Complex operator -(Complex& a,Complex b){
	Complex c;
	c.real = a.real - b.real;
	c.imag = a.imag - b.imag;
	c.CtoS(c.real,c.imag);
	return c;
}
Complex operator *(Complex& a,Complex b){
	Complex c;
	c.real = (a.real * b.real) - (a.imag * b.imag);
	c.imag = (a.real * b.imag) + (a.imag * b.real);
	c.CtoS(c.real,c.imag);
	return c;
}
Complex operator /(Complex& a,Complex b){
	Complex c;
	c.real = (a.real*b.real + a.imag*b.imag) / (b.real*b.real + b.imag*b.imag);
	c.imag = (a.imag*b.real - a.real*b.imag) / (b.real*b.real + b.imag*b.imag);
	c.CtoS(c.real,c.imag);
	return c;
}

bool operator ==(Complex& a,Complex& b){
	return (a.real == b.real) && (a.imag == b.imag);
}
bool operator !=(Complex& a,Complex& b){
	return (a.real != b.real) || (a.imag != b.imag);
}

std::ostream& operator <<(std::ostream& out,Complex& b){
	return out << b.StrNums();
}
std::istream& operator >> (std::istream& in,Complex& b){
	in >> b.StrNums();
	b.StoC(b.StrNums());
	b.CtoS(b.real,b.imag);
	return in;
}

Complex operator ^(Complex& a,Integer b){
	Complex c = "1";
	Integer One = "1";
	Integer pow = b.AbsStrNums();
	bool isNeg = false;
	if(b.StrNums()[0] == '-'){
		isNeg = true;
	}
	for(Integer i = "0";i < pow;i += One){
		if(isNeg){
			c = c / a;
		} else{
			c = c * a;
		}

	}
	c.CtoS(c.real,c.imag);
	return c;
}