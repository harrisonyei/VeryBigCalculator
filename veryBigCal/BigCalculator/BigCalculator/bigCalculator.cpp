#include <time.h>
#include <iostream>

#include "BigObject\library\BigNum.h"
#include "GUI\CalculatorGUI.h"

int main(void) {
	clock_t tStart = clock();
	/* Do your stuff here */
	Integer A = "12345689798499819819819181111876311111111119999999999999999999922222222929119191919191919199453";
	Integer B = "94879453";
	Integer C = A / B;
	std::string result = C.NumberObject::StrNums();
	/*Test*/
	printf("Time taken: %.2fs\n",(double)(clock() - tStart) / CLOCKS_PER_SEC);
	std::cout << result << std::endl;
		
	system("PAUSE");
	return 0;
	
}
