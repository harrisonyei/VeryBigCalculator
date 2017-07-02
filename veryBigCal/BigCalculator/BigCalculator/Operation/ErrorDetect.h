// try.cpp : 定義主控台應用程式的進入點。
//
/*
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	string input;
	while (cin >> input) {
		string s1, s2;
		char oper = '\0';

		for (int i = 0; i < input.length(); i++) {
			if (input[i] == '!' || input[i] == '^' || input[i] == '/') {
				oper = input[i];
			}
			else {
				if (oper == '\0')
					s1.push_back(input[i]);
				else
					s2.push_back(input[i]);
			}
		}

		cout << s1 << " " << oper << " " << s2 << endl;

		if (oper != '!') {

			switch (oper) {
			case '/':
				if (s2 == "0") {
					cout << "Division Error" << endl;
					break;
				}
			case'^':
				if (s2 == "0.5") {
					if (s1[0] == '-') {
						cout << "Power Error" << endl;
						break;
					}
				}
				if (s1 == "0") {
					if (s2[0] == '-') {
						cout << "Power Error" << endl;
						break;
					}
				}
			default:
				break;
			}
		}

		// 階乘
		else if (oper == '!') {
			for (int i = 0; i < s1.length(); i++) {
				if (s1[i] == '.' || s1[i] == 'i') {
					cout << "Factorial Error" << endl;
					break;
				}
				if (s1[0] == '-')
				{
					cout << "Factorial Error" << endl;
					break;
				}
			}
		}

	}
	return 0;
}
*/
