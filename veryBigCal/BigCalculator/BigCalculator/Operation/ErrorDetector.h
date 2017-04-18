
#include <string>

#include "../BigObject/library/BigNum.h"

enum ErrorType{
	Division_Error,
	Power_Error,
	Factorial_Error,
	Root_Error,
	None_Error
};

class ErrorDetector{
private:
	std::string errorMessage;
	ErrorType errorType;

	bool ErrorSelect();

public:

	std::string& ErrorMessage(){
		return errorMessage;
	}

	bool DeError(std::string&,NumberType);
};
