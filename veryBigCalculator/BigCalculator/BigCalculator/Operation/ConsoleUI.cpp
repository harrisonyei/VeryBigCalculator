#include"ConsoleUI.h"

std::stringstream CalculatorUI::InStream;
std::string CalculatorUI::Command;
std::string CalculatorUI::Expression;
std::map<std::string,std::pair<NumberType,Complex>> CalculatorUI::BigNums;
std::unordered_set<std::string> CalculatorUI::Commands = {
	"set", // set a new numberObject e.g. "set <type> <name>"
	"remove",// delete a numberObject e.g. "delete <name>"
	"integer",// type/cast e.g. "integer 1.0" 
	"decimal",// type/cast ...
	"complex",// type/cast ...
	"ls", // list all exist numberObject e.g. "ls"
	"exit", // "exit"
	"help",// "help"
	"print",
};

void expression(std::string,std::stringstream& InStream);
void SplitInput(std::string& part);

std::string getTypeName(NumberType nt){
	switch(nt){
		case INT:
		return"integer";
		break;
		case DEC:
		return"decimal";
		break;
		case COM:
		return"complex";
		break;
		case NUL:
		return"null";
		break;
		default:
		return"";
		break;
	}
}

void Variable(std::stringstream& InStream,std::string& name){
	std::string isEqual;
	InStream >> isEqual;
	if(isEqual == "="){
		expression("",InStream);
		CalculatorUI::ProcessInput(CalculatorUI::Expression);
		CalculatorUI::BigNums[name] = TestCore::Calculate(CalculatorUI::BigNums[name].first,CalculatorUI::Expression);
	} else{
		expression(name + isEqual,CalculatorUI::InStream);
		CalculatorUI::ProcessInput(CalculatorUI::Expression);
		std::cout << TestCore::Calculate(COM,CalculatorUI::Expression).second << std::endl;
	}
}

void set(std::stringstream& InStream){
	std::string legalName = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	std::string type;
	std::string name;
	NumberType  nt;
	InStream >> type;
	if(type == "integer"){
		nt = INT;
	} else if(type == "decimal"){
		nt = DEC;
	} else if(type == "complex"){
		nt = COM;
	} else{
		throw("錯誤 : set <type> <name>");
	}
	InStream >> name;
	for(char&c : name){
		if(legalName.find(c) == std::string::npos){
			throw("變數名稱不可含有符號等特殊字元");
		}
	}
	if(CalculatorUI::Commands.find(name) != CalculatorUI::Commands.end()){
		throw("變數名稱不可使用保留字");
	} else if(CalculatorUI::BigNums.find(name) != CalculatorUI::BigNums.end()){
		throw("變數名稱重複");
	} else if(name[0] >= '0'&&name[0] <= '9'){
		throw("變數名不可使用數字開頭");
	} else{
		CalculatorUI::BigNums.insert(std::pair<std::string,std::pair<NumberType,Complex>>(name,std::pair<NumberType,Complex>(nt,Complex())));
	}
	expression("",InStream);
	CalculatorUI::ProcessInput(CalculatorUI::Expression);
	CalculatorUI::BigNums[name] = TestCore::Calculate(nt,CalculatorUI::Expression);
}
void remove(std::stringstream& InStream){
	std::string name;
	InStream >> name;
	if(CalculatorUI::BigNums.find(name) != CalculatorUI::BigNums.end()){
		CalculatorUI::BigNums.erase(name);
		std::cout << name << " 已經被移除" << std::endl;
	} else{
		throw("沒有找到 "+name+" 請確認輸入是否正確 : remove <name>");
	}
}
void integer(std::stringstream& InStream){
	expression("",InStream);
	CalculatorUI::ProcessInput(CalculatorUI::Expression);
	std::cout << (Integer)TestCore::Calculate(COM,CalculatorUI::Expression).second << std::endl;
}
void decimal(std::stringstream& InStream){
	expression("",InStream);
	CalculatorUI::ProcessInput(CalculatorUI::Expression);
	std::cout << (Decimal)TestCore::Calculate(COM,CalculatorUI::Expression).second << std::endl;
}
void complex(std::stringstream& InStream){
	expression("",InStream);
	CalculatorUI::ProcessInput(CalculatorUI::Expression);
	std::cout << TestCore::Calculate(COM,CalculatorUI::Expression).second << std::endl;

}
void ls(){
	Complex temp;
	for(auto const &element : CalculatorUI::BigNums){
		temp = element.second.second;
		std::cout << getTypeName(element.second.first) << ' '\
			<< element.first << ' ';
		switch(element.second.first){
			case INT:
			std::cout << (Integer)temp << std::endl;
			break;
			case DEC:
			std::cout << (Decimal)temp << std::endl;
			break;
			case COM:
			std::cout << temp << std::endl;
			break;
			case NUL:
			std::cout << temp << std::endl;
			break;
		}

	}
}
void help(){
	std::cout << "set,     set <type> <name>" << std::endl
		      << "remove,  remove <name>" << std::endl
		      << "integer, type/cast e.g. integer 1.0" << std::endl
		      << "decimal, type/cast ..." << std::endl
		      << "complex, type/cast ..." << std::endl
		      << "print,   print <name>" << std::endl
		      << "ls,      ls" << std::endl
	      	  << "exit,    exit" << std::endl
		      << "help,    help" << std::endl;
}
void expression(std::string Complete,std::stringstream& InStream){
	CalculatorUI::Expression += Complete;
	std::string legalList = "1234567890+-*/^!().";
	std::string s;
	std::string part;
	std::string newExpression;

	while(InStream >> s){
		CalculatorUI::Expression += s;
	}
	for(char&c : CalculatorUI::Expression){
		if(legalList.find(c) != std::string::npos){
			newExpression += part;
			part.clear();
			newExpression += c;
		} else{
			part += c;
			if(CalculatorUI::BigNums.find(part) != CalculatorUI::BigNums.end()){
				std::stringstream ss;
				ss << "(";
				switch(CalculatorUI::BigNums[part].first){
					case INT:
					ss << (Integer)CalculatorUI::BigNums[part].second;
					break;
					case DEC:
					ss << (Decimal)CalculatorUI::BigNums[part].second;
					break;
					case COM:
					ss << CalculatorUI::BigNums[part].second;
					break;
					default:
					ss << CalculatorUI::BigNums[part].second;
					break;
				}
				ss << ")";
				ss >> part;
			}
		}
	}
	CalculatorUI::Expression = newExpression + part;
}
void Print(std::stringstream& InStream){
	std::string name;
	InStream >> name;
	if(CalculatorUI::BigNums.find(name) == CalculatorUI::BigNums.end()){
		throw("沒有找到 "+name+" 請確認輸入是否正確 : print <name>");
	}
	switch(CalculatorUI::BigNums[name].first){
		case INT:
		std::cout << (Integer)CalculatorUI::BigNums[name].second << std::endl;
		break;
		case DEC:
		std::cout << (Decimal)CalculatorUI::BigNums[name].second << std::endl;
		break;
		case COM:
		std::cout << CalculatorUI::BigNums[name].second << std::endl;
		break;
		default:
		std::cout << CalculatorUI::BigNums[name].second << std::endl;
		break;
	}
}

void SplitInput(std::string& part){
	if(CalculatorUI::Commands.find(part) != CalculatorUI::Commands.end()){
		if(CalculatorUI::Command == ""){
			CalculatorUI::Command = part;
		} else{
			throw("請勿使用保留字");
		}
	}
}

void Bracket(std::string& expression){
	int count = 0;
	for(char& c : expression){
		if(c == '('){
			count++;
		} else if(c == ')'){
			count--;
		}
		if(count < 0){
			throw("括號打錯囉");
		}
	}
	while(count > 0){
		count--;
		expression += ")";
	}
}

void Validation(std::string& expression){
	std::string legalList = "1234567890+-*/^!().";
	std::string frontEx = "1234567890)";
	std::string part;
	char lastChar = '\0';
	// not thing after + - * / ^

	// not thing front * / ! ^ .

	//** /* +* -*

	for(char& c : expression){
		if(legalList.find(c) != std::string::npos){
			if(c == '!'&&frontEx.find(lastChar) == std::string::npos){
				throw(0);
			}else if(part != "" && part != "i"){
				throw (0);
			}
			part.clear();
			lastChar = c;
		} else{
			part += c;
		}
	}
	if(part != "" && part != "i"){
		throw (0);
	}
}

void CalculatorUI::Run(){
	for(;;){
		try{
			ReadInput();
		} catch(const char* msg){
			std::cout << msg << std::endl;
			continue;
		} catch(std::string msg){
			std::cout << msg << std::endl;
			continue;
		} catch(char){
			exit(0);
		} catch(...){
			std::cout << "輸入可能含有非法的運算式或者不存在的指令或字元" << std::endl;
			continue;
		}
	}
}

void CalculatorUI::ReadInput(){
	CalculatorUI::InStream = std::stringstream();
	CalculatorUI::Expression.clear();
	CalculatorUI::Command.clear();
	std::string Input;
	std::getline(std::cin,Input);
	CalculatorUI::InStream << Input;
	Input.clear();
	CalculatorUI::InStream >> Input;
	try{
		if(CalculatorUI::BigNums.find(Input) != CalculatorUI::BigNums.end()){
			Variable(CalculatorUI::InStream,Input);
		} else{
			SplitInput(Input);
			if(CalculatorUI::Commands.find(CalculatorUI::Command) != Commands.end()){
				if(CalculatorUI::Command == "set"){
					set(CalculatorUI::InStream);
				} else if(CalculatorUI::Command == "remove"){
					remove(CalculatorUI::InStream);
				} else if(CalculatorUI::Command == "integer"){
					integer(CalculatorUI::InStream);
				} else if(CalculatorUI::Command == "decimal"){
					decimal(CalculatorUI::InStream);
				} else if(CalculatorUI::Command == "complex"){
					complex(CalculatorUI::InStream);
				} else if(CalculatorUI::Command == "ls"){
					ls();
				} else if(CalculatorUI::Command == "exit"){
					throw 'q';
				} else if(CalculatorUI::Command == "help"){
					help();
				} else if(CalculatorUI::Command == "print"){
					Print(CalculatorUI::InStream);
				}
			} else{
				CalculatorUI::Command = "Expression";
				expression(Input,CalculatorUI::InStream);
				CalculatorUI::ProcessInput(CalculatorUI::Expression);
				std::cout << TestCore::Calculate(COM,CalculatorUI::Expression).second << std::endl;
			}
		}
	} catch(const char* msg){
		std::cout << msg << std::endl;
	}
}
void CalculatorUI::ProcessInput(std::string& s){
	Bracket(s);
	Validation(s);
}
