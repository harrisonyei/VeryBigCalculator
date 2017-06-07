
// Name: ¶À¯EºÕ 
// Student ID: B10515007
// Date: April 7, 2017 
// Last Update: Date: April 7, 2017
// Problem statement: This C++ program separated into numerator and denominator.
#include "library\Decimal.h"
#include <string>

void toGCD(Integer& nume,Integer& deno);

std::string Decimal::toComplexPrec(){
	// Find '.'
	int dotPos = 0;
	for(int i = 0; i < this->StrNums().length(); i++)
		if(this->StrNums()[i] == '.'){
			dotPos = i;
		}
	return this->StrNums().substr(0,dotPos + 10);

}

void Decimal::StoD(std::string s){
	std::string legalChar = "0123456789.";
	std::string newS;
	for(char&c : s){
		if(legalChar.find(c) == std::string::npos){
			break;
		} else{
			newS += c;
		}
	}
	s = newS;
	std::string numerator;
	std::string denominator = "1";

	int dotPos = -1;
	int addzero = 0;
	int count = 0;
	for(char&c : s){
		if(c == '.'){
			count++;
			if(count > 1){
				throw (0);//
			}
		}
	}
	//make sure dot position
	for(int i = 0; i < s.size(); i++)
		if(s[i] == '.'){
			dotPos = i;
			s.erase(s.begin() + i);
			if((s.size() - dotPos) > 110){
				s.erase(s.begin() + dotPos + 110,s.end());
				addzero = 110;
			}
			numerator = s;
		}

	//have no dot
	if(dotPos == -1){
		numerator = s;
		denominator = "1";
	} else{
		if(!addzero){
			addzero = s.size() - dotPos;
		}
		for(int i = 0; i < addzero; i++)
			denominator += '0';
	}

	//erase 0,-001230 -> -1230
	for(int i = 0; i < numerator.size(); i++){
		if(numerator == "0"){ break; }

		if(numerator[i] != '0' && numerator[i] != '-'){ break; }

		if(numerator[i] == '0'){
			numerator.erase(numerator.begin() + i);
			i--;
		}
	}
	strNume = numerator;
	strDeno = denominator;

}
void Decimal::DtoS(Integer& nume,Integer& deno){
	std::string result = nume.StrAbs();
	// Step.1 add 100 "0" at end.
	result += "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
	// Step.2 Divi
	Integer quotient = (Integer)result / (Integer)deno.StrAbs();
	// Step.3 backtrack point pos.
	result = quotient.StrNums();
	int strLen = result.length();
	for(int i = 105 - strLen;i >=0 ;i--){
		result = "0" + result;
		strLen++;
	}

	result.insert(strLen - 105,".");
	
	if((nume.IsPositive() ^ deno.IsPositive())){
		result = "-" + result;
	}
	this->StrNums() = result;

	int pos = this->StrNums().find('.');
	ShowStrNums() = this->StrNums().substr(0,pos + 101);
}

Decimal operator +(Decimal& a,Decimal b){
	Decimal c;
	Integer tempa_nume;
	Integer tempb_nume;
	tempa_nume = a.nume * b.deno;
	tempb_nume = b.nume * a.deno;

	c.nume = tempa_nume + tempb_nume;
	c.deno = a.deno * b.deno;
	//toGCD(c.nume,c.deno);
	c.DtoS(c.nume,c.deno);
	return c;
}
Decimal operator -(Decimal& a,Decimal b){
	Decimal c;
	Integer tempa_nume;
	Integer tempb_nume;
	tempa_nume = a.nume * b.deno;
	tempb_nume = b.nume * a.deno;

	c.nume = tempa_nume - tempb_nume;
	c.deno = a.deno * b.deno;
	//toGCD(c.nume,c.deno);
	c.DtoS(c.nume,c.deno);
	return c;
}
Decimal operator *(Decimal& a,Decimal b){
	Decimal c;
	c.nume = a.nume * b.nume;
	c.deno = a.deno * b.deno;
	//toGCD(c.nume,c.deno);
	c.DtoS(c.nume,c.deno);
	return c;
}
Decimal operator /(Decimal& a,Decimal b){
	Decimal c;
	c.nume = a.nume * b.deno;
	c.deno = a.deno * b.nume;
	//toGCD(c.nume,c.deno);
	c.DtoS(c.nume,c.deno);
	return c;
}
Decimal operator ^(Decimal& a,Decimal b){
	Decimal c = "1";
	Integer One = "1";
	Integer pow = b.AbsStrNums();
	bool isNeg = false;
	if(b.StrNums()[0]=='-'){
		isNeg = true;
	}
	for(Integer i = "0";i < pow;i += One){
		if(isNeg){
			c = c / a;
		} else{
			c = c * a;
		}
		
	}
	c.DtoS(c.nume,c.deno);
	return c;
}

void toGCD(Integer& nume,Integer& deno){
	Integer n = (Integer)nume.StrAbs();
	Integer m = (Integer)deno.StrAbs();
	Integer Zero = "0";
	Integer r;
	if(m > n){
		std::swap(n,m);
	}
	while(m > Zero){
		r = n % m;
		n = m;
		m = r;
	}

	nume = nume / n;
	deno = deno / n;
}

Decimal Decimal::Sqrt(){
	// Step.1 add 200 "0" at deno and nume.
	nume = nume.StrAbs() + "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\
00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
	deno = deno.StrAbs() + "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\
00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
	// Sqrt them.
	nume.Sqrt();
	deno.Sqrt();
	// Divi them.
	return ((Decimal)nume / (Decimal)deno)+(Decimal)"0.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001";
}

bool operator ==(Decimal& a,Decimal& b){
	return (a.StrNums() == b.StrNums());
}
bool operator >(Decimal& a,Decimal& b){
	return ((a.nume*b.deno)>(b.nume*a.deno));
}
bool operator <(Decimal& a,Decimal& b){
	return ((a.nume*b.deno)<(b.nume*a.deno));
}
bool operator >=(Decimal& a,Decimal& b){
	return ((a.nume*b.deno)>=(b.nume*a.deno));
}
bool operator <=(Decimal& a,Decimal& b){
	return ((a.nume*b.deno)<=(b.nume*a.deno));
}
bool operator !=(Decimal& a,Decimal& b){
	return (a.StrNums() != b.StrNums());
}

std::ostream& operator <<(std::ostream& out,Decimal& b){
	int pos = b.StrNums().find('.');
	return out << b.StrNums().substr(0,pos+101);
}
std::istream& operator >> (std::istream& in,Decimal& b){
	in >> b.StrNums();
	b.StoD(b.StrNums());
	b.DtoS(b.nume,b.deno);
	return in;
}



