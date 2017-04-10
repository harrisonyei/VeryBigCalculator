#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<stack>
#define NUMBER -1

class TestCore{
private:
	static void Simplify(std::string& s,std::vector<double>& nums,std::vector<char>& ops);
	static void Push(std::stack<char>& op_stack,std::vector<char>& ops,char op);
	static double Calculate(std::string& s);
	static int Priority(char op);
public:
	static void ClearWhite(std::string& s);
	static double CalQ(std::string input){
		return Calculate(input);
	}

};