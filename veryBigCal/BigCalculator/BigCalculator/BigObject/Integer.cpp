
#include<algorithm>

#include "../Operation/TestCore.h"
#include "library\Integer.h"

#define N 2500
#define MAXDIG 8

Integer add(std::vector<unsigned int>&,std::vector<unsigned int>&);
Integer subtract(std::vector<unsigned int>&,std::vector<unsigned int>&);
Integer multiply(std::vector<unsigned int>&,std::vector<unsigned int>&);
Integer divide(std::vector<unsigned int>&,std::vector<unsigned int>&);
void toComp(std::vector<unsigned int>&);  // 轉補數
std::vector<unsigned int> absv(std::vector<unsigned int>&);    // 轉絕對值
void print(std::vector<unsigned int>&);   // 顯示大整數


Integer operator +(Integer& a,Integer& b){
	return add(a.nums,b.nums);
}
Integer operator -(Integer& a,Integer& b){
	return subtract(a.nums,b.nums);
}
Integer operator *(Integer& a,Integer& b){
	return a;
}
Integer operator /(Integer& a,Integer& b){
	return a;
}
Integer operator ^(Integer& a,Integer& b){
	return a;
}
Integer operator !(Integer& a){
	return a;
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

Integer add(std::vector<unsigned int>& a,std::vector<unsigned int>& b){
	Integer c = "0";
	if(b[0] == 99999999){
		toComp(b);
		subtract(a,b);
		toComp(b);
	} else{
		int i,carry = 0;
		for(i = N - 1; i >= 0; i--){
			c.Nums()[i] = a[i] + b[i] + carry;
			if(c.Nums()[i] < 100000000){
				carry = 0;
			} else{ // 進位 
				c.Nums()[i] = c.Nums()[i] - 100000000;
				carry = 1;
			}
		}
	}
	return c;
}

Integer subtract(std::vector<unsigned int>& a,std::vector<unsigned int>& b){
	Integer c = "0";
	if(b[0] == 99999999){
		toComp(b);
		add(a,b);
		toComp(b);
	} else{
		int i,borrow = 0;
		for(i = N - 1; i >= 0; i--){
			c.Nums()[i] = a[i] - b[i] - borrow;
			if(c.Nums()[i] >= 0){
				borrow = 0;
			} else{ // 借位 
				c.Nums()[i] = c.Nums()[i] + 100000000;
				borrow = 1;
			}
		}
	}
	return c;
}

Integer multiply(std::vector<unsigned int>& a,std::vector<unsigned int>& b){ // b 為乘數
	std::vector<unsigned int> tempA = absv(a);
	std::vector<unsigned int> tempB = absv(b);
	/*Call ADD()*/

	if((a[0] == 99999999 && b[0] == 0) || (a[0] == 0 && b[0] == 99999999)){
		//toComp();
	}
	return (Integer)"0";
}

Integer divide(std::vector<unsigned int>& a,std::vector<unsigned int>& b){  // b 為除數 
	std::vector<unsigned int> tempA = absv(a);
	std::vector<unsigned int> tempB = absv(b);

	/*Call SUB*/

	if((a[0] == 99999999 && b[0] == 0) || (a[0] == 0 && b[0] == 99999999)){
		//toComp();
	}
	return (Integer)"0";
}

void toComp(std::vector<unsigned int>& src){
	int j;
	for(j = 0; j < N; j++){
		src[j] = 99999999 - src[j];
	}
	src[N - 1] += 1;
}

std::vector<unsigned int> absv(std::vector<unsigned int>& src){
	std::vector<unsigned int> temp;
	temp = src;
	if(temp[0] == 99999999){
		toComp(temp);
	}
	return temp;
}

