#include"Operation\ConsoleUI.h"

#include <time.h>
#include <iostream>
#include <vector>


int main(void) {
	/*
	Integer i = "12345";
	Decimal d = "123.3+i";
	Complex c = "1.0+452.11111333i";

	std::vector<NumberObject*> nums;
	nums.push_back(&i);
	nums.push_back(&d);
	nums.push_back(&c);
	for(const auto& num : nums){
		std::cout << *num << std::endl;
	}
	system("PAUSE");
	*/
	CalculatorUI::Run();
	return 0;
}
