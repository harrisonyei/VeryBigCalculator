#include <time.h>
#include <iostream>

#include "BigObject\library\BigNum.h"
#include "GUI\CalculatorGUI.h"

int main(void) {
	
	/* Do your stuff here */
	Integer A = "787878787878787878787878787878787878787878787878787878787878787878787878787878987987987498748974987489749874987498748974897498749874987498749874987498749874987498749874";
	Integer B = "871561561561515612232126165";
	clock_t tStart = clock();
	Integer C = A / B;
	printf("Time taken: %.2fs\n",(double)(clock() - tStart) / CLOCKS_PER_SEC);
	std::string result = C.NumberObject::StrNums();
	/*Test*/
	std::cout << result << std::endl;
	system("PAUSE");
	return 0;
	
}
