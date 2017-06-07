#pragma once

#include"TestCore.h"
#include"../BigObject/library/Complex.h"
#include<iostream>
#include<vector>
#include<sstream>
#include <map>
#include<unordered_set>
#include<string>
#include<regex>

class CalculatorUI{
public:
	static void Run();
	static std::map<std::string,std::pair<NumberType,Complex>> BigNums;
	static std::unordered_set<std::string> Commands;

	static std::stringstream InStream;
	static std::string Command;
	static std::string Expression;
	static void ReadInput();
	static void ProcessInput(std::string& s);

};