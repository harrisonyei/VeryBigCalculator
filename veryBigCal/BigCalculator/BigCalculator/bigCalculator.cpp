#include <time.h>
#include <iostream>
#include <vector>

#include "BigObject\library\BigNum.h"
#include "GUI\CalculatorGUI.h"

int main(void) {
	//Do your stuff here 
	Integer A = "1214374657515674156741567416574567456715674657456175156717561257624122";
	Decimal B = "3";
	
	clock_t tStart = clock();
	Sqrt(A);
	printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
	//Test
	std::cout << A.StrNums() << std::endl;

	system("PAUSE");
	return 0;

}
