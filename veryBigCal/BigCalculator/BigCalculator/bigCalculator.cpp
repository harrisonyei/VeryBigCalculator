#include <time.h>
#include <iostream>

#include "BigObject\library\BigNum.h"
#include "GUI\CalculatorGUI.h"

int main(void) {
	
	//Do your stuff here 
	Integer A = "878787878787878787878787878787878787878787878787878787877878787878787545487878545787854487854870070008000900010240";
	Integer B = "87";
	clock_t tStart = clock();
	Integer C = A * B;
	printf("Time taken: %.2fs\n",(double)(clock() - tStart) / CLOCKS_PER_SEC);
	std::string result = C.NumberObject::StrNums();
	//Test
	std::cout << result << std::endl;
	system("PAUSE");
	return 0;
	
}
