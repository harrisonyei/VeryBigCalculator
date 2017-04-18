
#include<algorithm>

#include "../Operation/TestCore.h"
#include "library\Integer.h"

#define N 300
#define MAXDIG 8

void toComp(std::vector<long long>&);
std::vector<long long> Mult(std::vector<long long>&,int);
void CarryOn(std::vector<long long>&);
std::vector<long long> absv(std::vector<long long>&);
std::string Divi(std::string& a,std::string& b);

Integer operator +=(Integer& a,Integer& b){
	a = a + b;
	a.ItoS(a.nums);
	return a;
}
Integer operator -=(Integer& a,Integer& b){
	a = a - b;
	a.ItoS(a.nums);
	return a;
}
Integer operator +(Integer& a,Integer& b){
	Integer c = "0";
	int i,carry = 0;
	if(b.nums[0] == 99999999){
		toComp(b.nums);
		c = a + b;
		toComp(b.nums);
	} else{
		for(i = N - 1; i >= 0; i--){
			c.nums[i] = a.nums[i] + b.nums[i] + carry;
			if(c.nums[i] < 100000000){
				carry = 0;
			} else{ // �i�� 
				c.nums[i] = c.nums[i] - 100000000;
				carry = 1;
			}
		}
	}
	c.ItoS(c.nums);
	return c;
}
Integer operator -(Integer& a,Integer& b){
	Integer c = "0";
	int i,borrow = 0;
	if(b.nums[0] == 99999999){
		toComp(b.nums);
		c = a + b;
		toComp(b.nums);
	} else{
		for(i = N - 1; i >= 0; i--){
			c.nums[i] = a.nums[i] - b.nums[i] - borrow;
			if(c.nums[i] >= 0){
				borrow = 0;
			} else{ // �ɦ� 
				c.nums[i] = c.nums[i] + 100000000;
				borrow = 1;
			}
		}
	}
	c.ItoS(c.nums);
	return c;
}
Integer operator *(Integer& a,Integer& b){
	int i;
	std::vector<long long> tempA = absv(a.nums);
	std::vector<long long> tempB = absv(b.nums);
	std::string bAbsStr = b.StrAbs();
	Integer temp;
	Integer Result;

	/*Call ADD()*/
	for(i = 1;i <= (bAbsStr.length() / MAXDIG + 1);i++){
		temp.ItoS(Mult(tempA,tempB[N - i]));
		for(int j = 0;j < (i - 1);j++){
			temp.NumberObject::StrNums() += "00000000";
		}
		temp.StoInt(temp.NumberObject::StrNums());
		Result += temp;
	}

	if((a.nums[0] == 99999999 && b.nums[0] == 0) || (a.nums[0] == 0 && b.nums[0] == 99999999)){
		toComp(Result.nums);
	}
	Result.ItoS(Result.nums);
	return Result;
}
Integer operator /(Integer& a,Integer& b){
	Integer tempA = Integer(a.StrAbs());
	Integer tempB = Integer(b.StrAbs());
	Integer temp;
	Integer Result;
	
	int lenA = tempA.StrNums().length();
	int lenB = tempB.StrNums().length();
	int maxSize = (lenA / lenB);
	int tempLen;

	/*Call Division*/
	if(tempA < tempB){
		Result = Integer("0");
	} else if(tempA == tempB){
		Result = Integer("1");
	} else{
		for(int i = 1;i <= maxSize;i++){
			temp = Integer(Divi(tempA.StrNums().substr(0,lenB+1),tempB.StrNums()));
			lenA = tempA.StrNums().length();
			for(int j = 0;j < (lenA-lenB-1);j++){
				temp.NumberObject::StrNums() += "0";
			}
			temp.StoInt(temp.NumberObject::StrNums());
			Result += temp;
			tempA  -= (temp*tempB);
		}
	}

	if((a.nums[0] == 99999999 && b.nums[0] == 0) || (a.nums[0] == 0 && b.nums[0] == 99999999)){
		toComp(Result.nums);
	}
	Result.ItoS(Result.nums);
	return Result;
}
Integer operator ^(Integer& a,Integer& b){
	return a;
}
Integer operator !(Integer& a){
	return a;
}

bool operator ==(Integer& a,Integer& b){
	int i;
	for(i = 0;i < N;i++){
		if(a.nums[i] != b.nums[i]){
			return false;
		}
	}
	return true;
}
bool operator >(Integer& a,Integer& b){
	int i;
	if(a.nums[0] == 99999999 && b.nums[0] == 0){
		return false;
	} else if(a.nums[0] == 0 && b.nums[0] == 99999999){
		return true;
	} else if(a.nums[0] == 0 && b.nums[0] == 0){
		if(a.NumberObject::StrNums().length() == b.NumberObject::StrNums().length()){
			return (a.NumberObject::StrNums().compare(b.NumberObject::StrNums()) > 0);
		} else{
			return (a.NumberObject::StrNums().length()>b.NumberObject::StrNums().length());
		}
	} else{
		if(a.NumberObject::StrNums().length() == b.NumberObject::StrNums().length()){
			return (a.NumberObject::StrNums().compare(b.NumberObject::StrNums()) < 0);
		} else{
			return (a.NumberObject::StrNums().length()<b.NumberObject::StrNums().length());
		}
	}

	return false;
}
bool operator <(Integer& a,Integer& b){
	int i;
	if(a.nums[0] == 99999999 && b.nums[0] == 0){
		return true;
	} else if(a.nums[0] == 0 && b.nums[0] == 99999999){
		return false;
	} else if(a.nums[0] == 0 && b.nums[0] == 0){
		if(a.NumberObject::StrNums().length() == b.NumberObject::StrNums().length()){
			return (b.NumberObject::StrNums().compare(a.NumberObject::StrNums())>0);
		} else{
			return (a.NumberObject::StrNums().length()<b.NumberObject::StrNums().length());
		}
	} else{
		if(a.NumberObject::StrNums().length() == b.NumberObject::StrNums().length()){
			return (b.NumberObject::StrNums().compare(a.NumberObject::StrNums())<0);
		} else{
			return (a.NumberObject::StrNums().length()>b.NumberObject::StrNums().length());
		}
	}

	return false;
}
bool operator >=(Integer& a,Integer& b){
	int i;
	if(a.nums[0] == 99999999 && b.nums[0] == 0){
		return false;
	} else if(a.nums[0] == 0 && b.nums[0] == 99999999){
		return true;
	} else if(a.nums[0] == 0 && b.nums[0] == 0){
		if(a.NumberObject::StrNums().length() == b.NumberObject::StrNums().length()){
			return (a.NumberObject::StrNums().compare(b.NumberObject::StrNums()) >= 0);
		} else{
			return (a.NumberObject::StrNums().length()>b.NumberObject::StrNums().length());
		}
	} else{
		if(a.NumberObject::StrNums().length() == b.NumberObject::StrNums().length()){
			return (a.NumberObject::StrNums().compare(b.NumberObject::StrNums()) <= 0);
		} else{
			return (a.NumberObject::StrNums().length()<b.NumberObject::StrNums().length());
		}
	}

	return false;
}
bool operator <=(Integer& a,Integer& b){
	int i;
	if(a.nums[0] == 99999999 && b.nums[0] == 0){
		return true;
	} else if(a.nums[0] == 0 && b.nums[0] == 99999999){
		return false;
	} else if(a.nums[0] == 0 && b.nums[0] == 0){
		if(a.NumberObject::StrNums().length() == b.NumberObject::StrNums().length()){
			return (b.NumberObject::StrNums().compare(a.NumberObject::StrNums()) >= 0);
		} else{
			return (a.NumberObject::StrNums().length()<b.NumberObject::StrNums().length());
		}
	} else{
		if(a.NumberObject::StrNums().length() == b.NumberObject::StrNums().length()){
			return (b.NumberObject::StrNums().compare(a.NumberObject::StrNums()) <= 0);
		} else{
			return (a.NumberObject::StrNums().length()>b.NumberObject::StrNums().length());
		}
	}
}

std::ostream& operator <<(std::ostream& out,Integer& b){
	return out;
}
std::istream& operator >> (std::istream& in,Integer& b){
	return in;
}

void Integer::StoInt(std::string s){
	std::vector<long long> Nums(N,0);

	bool isPos;
	int index;
	std::string num;
	TestCore::ClearWhite(s);

	if(s[0] == '-'){
		if(s != "-0")
			isPos = false;
		s.erase(s.begin());
	} else{
		isPos = true;
	}
	num.clear();
	for(int i = s.length() - 1; i >= 0; i--){
		num.push_back(s[i]);
		if((s.length() - i) % MAXDIG == 0 || i == 0){
			index = N - 1 - (s.length() - 1 - i) / MAXDIG;
			std::reverse(num.begin(),num.end());
			Nums[index] = atoi(num.c_str());
			num.clear();
		}
	}
	if(!isPos){
		toComp(Nums);
	}
	nums = Nums;
}
void Integer::ItoS(std::vector<long long>& Nums){
	std::vector<long long> temp = absv(Nums);
	std::string tempStr;
	bool firstNonZero = false;
	NumberObject::StrNums().clear();
	for(long long& i : temp){
		if(!firstNonZero&&i > 0){ firstNonZero = true; } else if(!firstNonZero){ continue; }
		tempStr = std::to_string(i + (long long)100000000);
		tempStr.erase(tempStr.begin());
		NumberObject::StrNums() += tempStr;
	}
	if(NumberObject::StrNums().length() == 0){ NumberObject::StrNums() = "0"; };
	while(NumberObject::StrNums()[0] == '0'&&NumberObject::StrNums().length()>1){
		NumberObject::StrNums().erase(NumberObject::StrNums().begin());
	};
	if(Nums[0] == 99999999){ NumberObject::StrNums() = "-" + NumberObject::StrNums(); }
}

void toComp(std::vector<long long>& Nums){
	for(long long& i : Nums){
		i = (long long)99999999 - i;
	}
	Nums[N - 1] += 1;
}
void CarryOn(std::vector<long long>& Nums){
	// Nums most be positive BigNum;
	std::vector<long long> temp = Nums;
	int i,carry = 0;
	for(i = N - 1; i >= 0; i--){
		temp[i] += carry;
		if(temp[i] < 100000000){
			carry = 0;
		} else{ // �i�� 
			carry = temp[i] / 100000000;
			temp[i] = temp[i] % 100000000;
		}
	}
	Nums = temp;
}
std::vector<long long> Mult(std::vector<long long>& Nums,int mult){
	std::vector<long long> temp = Nums;
	for(long long& i : temp){
		i *= mult;
	}
	CarryOn(temp);
	return temp;
}

std::vector<long long> absv(std::vector<long long>& Nums){
	std::vector<long long> temp = Nums;
	if(temp[0] == 99999999){
		toComp(temp);
	}
	return temp;
}

std::string Divi(std::string& strA,std::string& strB){
	Integer a = Integer(strA);
	Integer b = Integer(strB);
	Integer temp;
	int l=0,r=99999999,mid=0;
	int result;
	while(l <= r){
		mid = (l + r) / 2;
		temp = b * Integer(std::to_string(mid));
		if(temp < a){
			l = mid + 1,result = mid;
		}
		else if(temp > a){
			r = mid - 1;
		}
		else{ 
			result = mid;
			break; 
		}
	}
	return std::to_string(result);
}

