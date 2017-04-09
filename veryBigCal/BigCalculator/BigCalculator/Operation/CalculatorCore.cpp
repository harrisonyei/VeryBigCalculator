#include<iostream>
#include<string>
#include<vector>
#include<stack>

#include "../BigObject/library/BigNum.h"
/*
#define NUMBER -1
using namespace std;

class OperationCore{
private:
	static void Simplify(string& s,vector<BigNum>& nums,vector<char>& ops);
	static void Push(stack<char>& op_stack,vector<char>& ops,char op);
	static void ClearWhite(string& s);
	static int Priority(char op);
	static BigNum Calculate(string& s);

public:

};

void Simplify(string& s,vector<BigNum>& nums,vector<char>& ops);
void Push(stack<char>& op_stack,vector<char>& ops,char op);
void ClearWhite(string& s);
BigNum Calculate(string& s);
int Priority(char op);
int a(){
	int n;
	string input;
	while(cin >> n)
		for(getline(cin,input); n--;){
			getline(cin,input);
			cout << Calculate(input) << endl;
		}
	return 0;
}

void Simplify(string& s,vector<BigNum>& nums,vector<char>& ops){
	ClearWhite(s);
	bool is_operator = true;
	bool is_num = false;
	char op = 0;
	string num;
	stack<char> op_stack;
	int brackets = 0;


	for(int i = 0; i < s.length(); i++){
		if((s[i] <= '9'&&s[i] >= '0') || s[i] == '.'){
			is_operator = false;
			is_num = true;
			num.push_back(s[i]);
		}// is number
		else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^' || s[i] == '!'){
			if(is_num){
				nums.push_back(stod(num));
				ops.push_back(NUMBER);
				num.clear();
				is_num = false;
			}
			if(is_operator){
				nums.push_back(-1.0);
				ops.push_back(NUMBER);
				if(op == '/')
					Push(op_stack,ops,'/');
				else
					Push(op_stack,ops,'*');
			} else{
				op = s[i];
				Push(op_stack,ops,s[i]);
			}
			is_operator = true;
		}//is operator
		else if(s[i] == '('){
			op_stack.push('(');
		} else if(s[i] == ')'){
			if(num.size()){
				nums.push_back(stod(num));
				ops.push_back(NUMBER);
				num.clear();
				is_num = false;
			}
			for(char data = op_stack.top(); data != '('; data = op_stack.top()){
				ops.push_back(data);
				op_stack.pop();
			}
			op_stack.pop();
		}
	}//for loop
	if(num.size()){
		nums.push_back(stod(num));
		ops.push_back(NUMBER);
	}
	for(int i = op_stack.size() - 1; i >= 0; i--){
		ops.push_back(op_stack.top());
		op_stack.pop();
	}


}//simplify

void ClearWhite(string& s){
	string temp;
	for(int i = 0; i < s.length(); i++)
		if(s[i] != ' ')
			temp.push_back(s[i]);
	s = temp;
}

BigNum Calculate(string& s){
	vector<BigNum> nums;
	vector<char> ops;
	stack<BigNum> num_stack;
	BigNum answer = 0;

	Simplify(s,nums,ops);

	for(char &i : ops){
		if(i == NUMBER){
			num_stack.push(nums[0]);
			nums.erase(nums.begin());
		} else{
			BigNum A,B,ans;
			B = num_stack.top();
			num_stack.pop();
			A = num_stack.top();
			num_stack.pop();
			if(i == '+')
				ans = A + B;
			else if(i == '-')
				ans = A - B;
			else if(i == '*')
				ans = A * B;
			else if(i == '/')
				ans = A / B;

			num_stack.push(ans);
		}
	}
	answer = num_stack.top();

	return answer;
}

int Priority(char op){
	switch(op){
		case '+': case '-': return 1;
		case '*': case '/': return 2;
		case '^': case '!': return 3;
		default:            return 0;
	}
}


void Push(stack<char>& op_stack,vector<char>& ops,char op){
	if(op_stack.size())
		while(Priority(op_stack.top()) >= Priority(op)){
			ops.push_back(op_stack.top());
			op_stack.pop();
			if(op_stack.size() == 0)
				break;
		}
	op_stack.push(op);
}*/