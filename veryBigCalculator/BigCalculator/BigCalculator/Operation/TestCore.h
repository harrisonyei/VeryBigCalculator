#pragma once
#include"../BigObject/library/BigNum.h"
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#define NUMBER -1

class TestCore{
private:
	static void Simplify(std::string& s,std::vector<Complex>& nums,std::vector<char>& ops)throw(...);
	static void Push(std::stack<char>& op_stack,std::vector<char>& ops,char op);
	static int Priority(char op);
public:
	static void ClearWhite(std::string& s);
	static void Operate(Complex& answer,std::vector<Complex>& nums,std::vector<char>& ops)throw(int);
	static std::pair<NumberType,Complex> Calculate(NumberType nt,std::string& s)throw(int,const char*);

};