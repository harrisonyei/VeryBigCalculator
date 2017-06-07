#include<regex>
#include "TestCore.h"

#define NUMBER -1
using namespace std;

NumberType TypeIs(NumberObject& NumObj){
	regex intRegex("");
	regex decRegex("");
	regex comRegex("");

	if(regex_match(NumObj.StrNums(),intRegex)){
		return INT;
	} else if(regex_match(NumObj.StrNums(),decRegex)){
		return DEC;
	} else if(regex_match(NumObj.StrNums(),comRegex)){
		return COM;
	}
	return NUL;
}
void TestCore::Simplify(string& s,vector<Complex>& nums,vector<char>& ops)throw(...){
	ClearWhite(s);
	//std::cout << s << std::endl;
	bool is_operator = true;
	bool is_num = false;
	char op = 0;
	string num;
	stack<char> op_stack;
	int brackets = 0;


	for(int i = 0; i < s.length(); i++){
		if((s[i] <= '9'&&s[i] >= '0') || s[i] == '.' || s[i] == 'i'){
			is_operator = false;
			is_num = true;
			num.push_back(s[i]);
		}// is number
		else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '!' || s[i] == '^'){
			if(is_num){
				nums.push_back(Complex(num));
				ops.push_back(NUMBER);
				num.clear();
				is_num = false;
			}
			if(is_operator && (s[i] != '!') && (s[i] == '+' || s[i] == '-')){
				if(s[i] == '-'){
					nums.push_back(Complex("-1"));
				} else if(s[i] == '+'){
					nums.push_back(Complex("1"));
				}
				ops.push_back(NUMBER);
				Push(op_stack,ops,'@');
			} else{
				op = s[i];
				Push(op_stack,ops,s[i]);
			}
			is_operator = (s[i] != '!');
		}//is operator
		else if(s[i] == '('){
			op_stack.push('(');
		} else if(s[i] == ')'){
			if(num.size()){
				nums.push_back(Complex(num));
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
		nums.push_back(Complex(num));
		ops.push_back(NUMBER);
	}
	for(int i = op_stack.size() - 1; i >= 0; i--){
		ops.push_back(op_stack.top());
		op_stack.pop();
	}


}//simplify

void TestCore::ClearWhite(string& s){
	string temp;
	for(int i = 0; i < s.length(); i++)
		if(s[i] != ' ')
			temp.push_back(s[i]);
	s = temp;
}
void TestCore::Operate(Complex& answer,vector<Complex>& nums,vector<char>& ops)throw(int){
	stack<Complex> num_stack;
	Complex Zero("0");
	Complex Point5("0.5");
	for(char &i : ops){
		if(i == NUMBER){
			if(nums.size() == 0){
				throw(0);
			}
			num_stack.push(nums[0]);
			nums.erase(nums.begin());
		} else{
			if(num_stack.size() == 0){
				throw(0);
			}
			Complex ans;
			Complex A;
			Complex B = num_stack.top();
			num_stack.pop();
			if(i != '!'){
				if(num_stack.size() == 0){
					throw(0);
				}
				A = num_stack.top();
				num_stack.pop();
			}
			switch(i){
				case'+':
				ans = A + B;
				num_stack.push(ans);
				//std::cout << A.StrNums() << "," << B.StrNums() << ", + ," << ans.StrNums() << std::endl;
				break;
				case'-':

				ans = A - B;
				num_stack.push(ans);
				//std::cout << A.StrNums() << "," << B.StrNums() << ", - ," << ans.StrNums() << std::endl;
				break;
				case'*':case'@':
				ans = A * B;
				num_stack.push(ans);
				//std::cout << A.StrNums() << "," << B.StrNums() << ", * ," << ans.StrNums() << std::endl;

				break;
				case'/':
				if(B == Zero){
					throw("不能除以零喔白癡");
				}
				ans = A / B;
				num_stack.push(ans);
				//std::cout << A.StrNums() << "," << B.StrNums() << ", / ," << ans.StrNums() << std::endl;

				break;
				case'^':
				if(B.AbsStrNums() == Point5.AbsStrNums()){
					if(A.StrNums()[0] == '-'){
						throw("根號沒在跟你負的");
					} else if(B.StrNums()[0] == '-'){
						ans = (Decimal)"1"/A.Real().Sqrt();
					} else{
						ans = A.Real().Sqrt();
					}
				} else{
					ans = A ^ B;
				}
				num_stack.push(ans);
				//std::cout << A.StrNums() << "," << B.StrNums() << ", ^ ," << ans.StrNums() << std::endl;

				break;
				case'!':
				if(B.StrNums()[0] == '-'){
					throw("階層沒負的啦");
				}
				ans = !((Integer)B.StrNums());
				num_stack.push(ans);
				//std::cout << B.StrNums() << ", ! ," << ans.StrNums() << std::endl;
				break;
			}
		}
	}
	if(num_stack.size() > 0){
		answer = num_stack.top();
	};

}
std::pair<NumberType,Complex> TestCore::Calculate(NumberType nt,string& s)throw(int,const char*){
	vector<Complex> nums;
	vector<char> ops;
	std::pair<NumberType,Complex> answer(nt,Complex());
	std::string result;
	Simplify(s,nums,ops);
	Operate(answer.second,nums,ops);
	return answer;
}

int TestCore::Priority(char op){
	switch(op){
		case '+': case '-': return 1;
		case '*': case '/': return 2;
		case '^': return 3;
		case '!': return 4;
		case '@': return 5;
		default:            return 0;
	}
}


void TestCore::Push(stack<char>& op_stack,vector<char>& ops,char op){
	if(op_stack.size())
		while(Priority(op_stack.top()) >= Priority(op)){
			ops.push_back(op_stack.top());
			op_stack.pop();
			if(op_stack.size() == 0)
				break;
		}
	op_stack.push(op);
}