#include <time.h>
#include <iostream>

#include "BigObject\library\BigNum.h"
#include "GUI\CalculatorGUI.h"

int main(void) {

	//Do your stuff here 
	Decimal A = "8.8506";
	Decimal B = "2.81723351";
	
	clock_t tStart = clock();
	Decimal C = ( A / B );
	printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
	//Test
	std::cout << C.dotExpress << std::endl;

	system("PAUSE");
	return 0;

}
