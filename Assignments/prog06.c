/*
	NAME : Coleton Watt
	DUE DATE: APRIL 06
	DESCRIPTION: A menu that allows for fib sequences printed on diffrent threads
	Time Taken: 3 hours
*/


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

typedef unsigned long long int type_ulli;

void * printName(void* name) {

	printf("The name is %s", (char*)name); //prints the input from name type char*
	
	return NULL;
}

type_ulli fibonacciCalculator(int remaining, type_ulli x, type_ulli y){
	if(remaining <= 0){
		return y; //Once it has done a set amount of recursions return the correct number
	}
	remaining -=1; //Counter for loop around
	return fibonacciCalculator(remaining, y, x+y);	//Continues the recursion
}


void * fibonacciPrinter(void* input){
	type_ulli fibNumber = 0;
	int amount = (*(int*) input);
	if(amount < 0){
		printf("The fibonacci Number for the Input %d is %d\n", amount, 0); //If fib is 0 
		return NULL;
	}
		fibNumber = fibonacciCalculator(amount - 1, 0, 1); //Send in the amount requested minus one to match online sequence. Along with the two starting number
	
	sleep(3);
	printf("The fibonacci Number for the Input %d is %.0lld\n", amount,  fibNumber); //print the number with zero decimal points
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
	
	char input1; //the input as char
	int menuInput = 0; //The menu item chosen
	int fibInput; //The amount of recrusion 
	pthread_t printN, printFib; //The threads
	char name[24] = ""; //The name of the user
	
	
	do {
		printf("Welcome!\n1) Print out my name\n2) Find the i-th Fibonacci number\n3) Exit\n");
		
		scanf("%s", &input1);
		
		
		menuInput = atoi(&input1);
		
		switch (menuInput) {
			case 1:
				if(strcmp(name, "") == 0){
					printf("Looks like you don't have a name set what is it: "); //if name is null it request for the name of the user
					getchar();                         // catching newline character.
					fgets(name, 23, stdin);
				}
				pthread_create(&printN, NULL, printName, name); //Sends the name to be printed
				//pthread_detach(printN);
				break;
			case 2:
				printf("What Fibonacci Number Do You Want: ");
				scanf("%s", &input1);
				fibInput = atoi(&input1); //Sets the input to an int if it can't it'll be zero

				pthread_create(&printFib, NULL, fibonacciPrinter, &fibInput);
				//pthread_detach(printFib);
				break;
			case 3:
				pthread_cancel(printFib); //Clears the thread
				pthread_cancel(printFib); //Clears the thread
				pthread_cancel(printN); //Clears the thread

				break;
			default:
				printf("ERROR: That's Not a Valid Number\n"); //Error for input failed
		}
		
		
	} while (menuInput != 3); //quites when input is 3
	
	return 0; //Ends
}