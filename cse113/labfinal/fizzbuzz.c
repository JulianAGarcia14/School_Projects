#include <stdio.h>

int main() {
	//your code goes here.
	int i = 1;
	for(; i< 101; i++){

		if (i%5 == 0 && i%3 ==0) {
		       printf("FizzBuzz\n");
	        } else if (i%3 == 0) {
			printf("Fizz\n");
		} else if(i%5 == 0) {
			printf("Buzz\n");
		} else if (i%5 != 0 && i%3 !=0) {
			printf("%d\n", i);
		}

	}


	return 0;
}
