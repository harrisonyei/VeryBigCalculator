
#include <iostream>

#include "BigObject\library\BigNum.h"
#include "GUI\CalculatorGUI.h"

int main(void) {
	Integer a ="0";
	Integer b = "-1";
	Integer c = "1000";
	Integer d = "-5";
	Integer result;

	result = a*b;//0*-1

	result = b*c;//-1*1000

	result = d*c;//-5*1000

	result = c*a;//1000*0

	result = b*d;//-1*-5
	
	/*Test*/
	return 0;
}
