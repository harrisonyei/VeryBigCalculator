#include <time.h>
#include <iostream>
#include <vector>

#include "BigObject\library\BigNum.h"
#include "GUI\CalculatorGUI.h"
123////
int main(void) {
	
	//Do your stuff here 
	Integer A = "3";
	Decimal B = "3";
	clock_t tStart = clock();
	Sqrt(A);
	printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
	//Test
	std::cout << A.StrNums() << std::endl;
	return 0;

}
