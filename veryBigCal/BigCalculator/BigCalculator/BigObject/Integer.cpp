
#include<algorithm>

#include "../Operation/TestCore.h"
#include "library\Integer.h"

#define N 300
#define MAXDIG 8

void toComp(std::vector<unsigned int>&);
std::vector<unsigned int> absv(std::vector<unsigned int>&);


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
			} else{ // ¶i¦ì 
				c.nums[i] = c.nums[i] - 100000000;
				carry = 1;
			}
		}
	}
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
			} else{ // ­É¦ì 
				c.nums[i] = c.nums[i] + 100000000;
				borrow = 1;
			}
		}
	}
	return c;
}
Integer operator *(Integer& a,Integer& b){
	std::vector<unsigned int> tempA = absv(a.nums);
	std::vector<unsigned int> tempB = absv(b.nums);
	/*Call ADD()*/

	if((a.nums[0] == 99999999 && b.nums[0] == 0) || (a.nums[0] == 0 && b.nums[0] == 99999999)){
		//toComp();
	}
	return (Integer)"0";
}
Integer operator /(Integer& a,Integer& b){
	std::vector<unsigned int> tempA = absv(a.nums);
	std::vector<unsigned int> tempB = absv(b.nums);

	/*Call SUB*/

	if((a.nums[0] == 99999999 && b.nums[0] == 0) || (a.nums[0] == 0 && b.nums[0] == 99999999)){
		//toComp();
	}
	return (Integer)"0";
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
	return true;
}
bool operator <=(Integer& a,Integer& b){
	return true;
}

std::ostream& operator <<(std::ostream& out,Integer& b){
	return out;
}
std::istream& operator >> (std::istream& in,Integer& b){
	return in;
}

void Integer::StoInt(std::string s){
	std::vector<unsigned int> Nums(N,0);

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
void Integer::ItoS(std::vector<unsigned int>& Nums){
	std::vector<unsigned int> temp = absv(Nums);
	NumberObject::StrNums().clear();
	if(Nums[0] == 99999999){
		NumberObject::StrNums().push_back('-');
	}
	for(unsigned int& i : temp){
		NumberObject::StrNums() += std::to_string((double)i);
	}
}

void toComp(std::vector<unsigned int>& Nums){
	for(unsigned int& i : Nums){
		i = (unsigned int)99999999 - i;
	}
	Nums[N - 1] += 1;
}

std::vector<unsigned int> absv(std::vector<unsigned int>& Nums){
	std::vector<unsigned int> temp = Nums;
	if(temp[0] == 99999999){
		toComp(temp);
	}
	return temp;
}

