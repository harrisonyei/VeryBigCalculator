
#include<algorithm>

#include "../Operation/TestCore.h"
#include "library\Integer.h"

#define N 10
#define MAXDIG 8

void add(std::vector<unsigned int>&,std::vector<unsigned int>&,std::vector<unsigned int>&);
void subtract(std::vector<unsigned int>&,std::vector<unsigned int>&,std::vector<unsigned int>&);
void multiply(std::vector<unsigned int>&,std::vector<unsigned int>&,std::vector<unsigned int>&);
void divide(std::vector<unsigned int>&,std::vector<unsigned int>&,std::vector<unsigned int>&);
void toComp(std::vector<unsigned int>&);  // 轉補數
std::vector<unsigned int> absv(std::vector<unsigned int>&);    // 轉絕對值
void print(std::vector<unsigned int>&);   // 顯示大整數


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
		if((s.length() - i) % MAXDIG == 0 || i== 0 ){
			index = N - 1 - (s.length()-1-i) / MAXDIG;
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

void add(std::vector<unsigned int>& a,std::vector<unsigned int>& b,std::vector<unsigned int>& c){
	if(b[0] == 99999999){
		toComp(b);
		subtract(a,b,c);
	} else{
		int i,carry = 0;
		for(i = N - 1; i >= 0; i--){
			c[i] = a[i] + b[i] + carry;
			if(c[i] < 100000000){
				carry = 0;
			} else{ // 進位 
				c[i] = c[i] - 100000000;
				carry = 1;
			}
		}
	}
}

void subtract(std::vector<unsigned int>& a,std::vector<unsigned int>& b,std::vector<unsigned int>& c){
	if(b[0] == 99999999){
		toComp(b);
		add(a,b,c);
	} else{
		int i,borrow = 0;
		for(i = N - 1; i >= 0; i--){
			c[i] = a[i] - b[i] - borrow;
			if(c[i] >= 0){
				borrow = 0;
			} else{ // 借位 
				c[i] = c[i] + 100000000;
				borrow = 1;
			}
		}
	}
}

void multiply(std::vector<unsigned int>& a,std::vector<unsigned int>& b,std::vector<unsigned int>& c){ // b 為乘數
	std::vector<unsigned int> tempA = absv(a);
	std::vector<unsigned int> tempB = absv(b);
	/*Call ADD()*/

	if((a[0] == 99999999 && b[0] == 0) || (a[0] == 0 && b[0] == 99999999)){
		toComp(c);
	}
}

void divide(std::vector<unsigned int>& a,std::vector<unsigned int>& b,std::vector<unsigned int>& c){  // b 為除數 
	std::vector<unsigned int> tempA = absv(a);
	std::vector<unsigned int> tempB = absv(b);

	/*Call SUB*/

	if((a[0] == 99999999 && b[0] == 0) || (a[0] == 0 && b[0] == 99999999)){
		toComp(c);
	}
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

