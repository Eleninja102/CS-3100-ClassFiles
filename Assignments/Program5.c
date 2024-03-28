#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>

#define NAME "Coleton Watt"



void * printName(void* name) {
	
	
	
	printf("The creator of this thread is %s\n", (char*)name);
	
	return NULL;
}

float fibonacciCalculator(int remaining, float x, float y){
	if(remaining == 0){
		return y;
	}
	remaining -=1;
	return fibonacciCalculator(remaining, y, x+y);	
}


void * fibonacciPrinter(void* input){
	float fibNumber = 0;
	int amount = (*(int*) input);
	if(amount > 0){
		fibNumber = fibonacciCalculator(amount - 1, 0, 1);
	}
	sleep(10);
	printf("The fibonacci Number for the Input %d is %.0f\n", amount,  fibNumber);
	return NULL;
	/*;

	if(remaining == 0){
		return y;
	}
	remaining -=1;
	int z = *(int*)x + *(int*)y;
	int* what = malloc(sizeof(int*));
	what = (int*)fibonacciNumber(&remaining, y, &z);
	
	return what;*/
}


int main(int argc, char *argv[]) {
	
	char input1;
	int menuInput = 0;
	int fibInput;
	int return_value;
	pthread_t printN, printFib;
	
	
	do {
		printf("Welcome!\n1) Print out my name\n2) Find the i-th Fibonacci number\n3) Exit\n");
		
		scanf("%s", &input1);
		
		//scanf("%d", &input);
		
		menuInput = atoi(&input1);
		
		switch (menuInput) {
			case 1:
				pthread_create(&printN, NULL, printName, NAME);
				//pthread_detach(printN);
				break;
			case 2:
				printf("What Fibonacci Number Do You Want: ");
				scanf("%s", &input1);
				fibInput = atoi(&input1);

				pthread_create(&printFib, NULL, fibonacciPrinter, &fibInput);
				//pthread_detach(printFib);
				break;
			case 3:
				pthread_cancel(printFib);
				pthread_cancel(printFib);
				pthread_cancel(printN);

				break;
			default:
				printf("ERROR: That's Not a Valid Number\n");
		}
		
		
	} while (menuInput != 3);
	
	return 0;
}