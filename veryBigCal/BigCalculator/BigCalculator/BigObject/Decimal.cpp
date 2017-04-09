
// Name: ¶À¯EºÕ 
// Student ID: B10515007
// Date: April 7, 2017 
// Last Update: Date: April 7, 2017
// Problem statement: This C++ program separated into numerator and denominator.
#include "library\Decimal.h"
#include <iostream>
#include <string>
using namespace std;
// [NEED IMPLEMENT] String to decimal.
void StoD(std::string s) {	
	string numerator, denominator = "1";
	int negtiveFlag = 0, dotPos = 0;
	//if number is negtive,negtiveFlag equal to 1,delet '-' from the string
	if (s[0] == '-') {
		negtiveFlag = 1;
		s.erase(s.begin() + 0);
	}

	//make sure dot position
	for (int i = 0; i < s.size(); i++)
		if (s[i] == '.') {
			dotPos = i;
			s.erase(s.begin() + i);
			numerator = s;
			negtiveFlag == 1 ? numerator.insert(0, "-") : numerator = s;
		}

	//have no dot
	if (dotPos == 0) {
		numerator = s;
		negtiveFlag == 1 ? numerator.insert(0, "-") : numerator = s;
		denominator = "1";
	}
	else {
		for (int i = 0; i < s.size() - dotPos; i++)
			denominator += '0';
	}

	//erase 0,-001230 -> -1230
	for (int i = 0; i < numerator.size(); i++)
	{
		if (numerator == "0")break;
		if (numerator[i] != '0' && numerator[i] != '-')
			break;
		if (numerator[i] == '0') {
			numerator.erase(numerator.begin() + i);
			i--;
		}
	}



}

