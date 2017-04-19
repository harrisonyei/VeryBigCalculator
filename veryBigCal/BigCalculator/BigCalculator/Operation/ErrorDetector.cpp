
#include "ErrorDetector.h"
bool DivisionE(std::string& s);
bool PowerE(std::string& s);
bool FactorialE(std::string& s);
bool RootE(std::string& s);

bool ErrorDetector::ErrorSelect(){
	switch(ErrorDetector::errorType){
		case Division_Error:
		ErrorDetector::errorMessage = "DivisionError";
		break;
		case Power_Error:
		ErrorDetector::errorMessage = "PowerError";
		break;
		case Factorial_Error:
		ErrorDetector::errorMessage = "FactorialError";
		break;
		case Root_Error:
		ErrorDetector::errorMessage = "RootError";
		break;
		default:
		ErrorDetector::errorMessage = "NoneError";
		return false;
		break;
	}
	return true;
}
bool ErrorDetector::DeError(std::string& s,NumberType type){
	if(DivisionE(s)){
		ErrorDetector::errorType = Division_Error;
	} else if(PowerE(s)){
		ErrorDetector::errorType = Power_Error;
	} else if(FactorialE(s)){
		ErrorDetector::errorType = Factorial_Error;
	} else if(RootE(s)){
		ErrorDetector::errorType = Root_Error;
	} else{
		ErrorDetector::errorType = None_Error;
	}
	return ErrorDetector::ErrorSelect();
}

bool DivisionE(std::string& s){
	return false;
}
bool PowerE(std::string& s){
	return false;
}
bool FactorialE(std::string& s){
	return false;
}
bool RootE(std::string& s){
	return false;
}