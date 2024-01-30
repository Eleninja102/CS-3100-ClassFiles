#include <stdio.h>
#include <stdbool.h> //boolean

int main(int argc, char *argv[]) {
	int x, x1, x3;
	x = 1;
	float y = 10;
	char something = 'h';
	const double z = 3.14; //constant 
	bool isProgrammingFun = true;
	
	//printf(something); doesn't work
	//printf(x); doesn't work
	x = x << 3; //bit shift 
	printf("Int: %d\n", x);  // Outputs number
	printf("Int: %i\n", x1);  // Outputs number
	printf("Float: %f\n", y);  // Outputs number
	printf("Char: %c\n", something);  // Outputs number
	printf("Double: %lf\n", z);
	printf("Bool: %i\n", isProgrammingFun);  // Outputs number
	printf("Strings: %s\n", (x < 18 ? "Good day": "Good evening"));

	
	float myFloatNum = 3.5;
	
	printf("Float: %f\n", myFloatNum);   // Default will show 6 digits after the decimal point
	printf("Float 1: %.1f\n", myFloatNum); // Only show 1 digit
	printf("Float .2: %.2f\n", myFloatNum); // Only show 2 digits
	printf("Float .20: %.20f\n", myFloatNum);   // Only show 4 digits
	
	 x = 5;
	 y = 3;
	printf("%d\n", x > y); 
	
	float sum = (float) 5 / 2;
	
	printf("%f\n", sum); // 2.500000

	int num1 = 5;
	int num2 = 2;
	sum = (float) num1 / num2;
	
	printf("%.1f\n", sum); // 2.5
	
	printf("Hello World!");
	printf("I am learning C.\n\n");
	printf("And it is awesome!");
	
	
	
	int time = 20;
	if (time < 18) {
		printf("Good day.");
	} else {
		printf("Good evening.");
	}
	// Outputs "Good evening."
	
	 time = 22;
	if (time < 10) {
		printf("Good morning.");
	} else if (time < 20) {
		printf("Good day.");
	} else {
		printf("Good evening.");
	}
	
	// Outputs "Good evening."
	
	time = 20;
	(time < 18) ? printf("Good day.\n") : printf("Good evening.\n");
	printf("Strings: %s\n", (time < 18 ? "Good day": "Good evening"));
	
	int day = 4;
	
	switch (day) {
		case 1:
			printf("Monday");
			break;
		case 2:
			printf("Tuesday");
			break;
		case 3:
			printf("Wednesday");
			break;
		case 4:
			printf("Thursday");
			break;
		case 5:
			printf("Friday");
			break;
		case 6:
			printf("Saturday");
			break;
		case 7:
			printf("Sunday");
			break;
		default:
			printf("AHHHHHHH");
	}
	printf("\n");
	
	
	for (int i = 0; i < 5; i++) {
		printf("%d\n", i);
	}
	int myNumbers[] = {25, 50, 75, 100};
	
	for (int i = 0; i < 4; i++) {
		printf("%d\n", myNumbers[i]);
	}
	
	
	// Declare an array of four integers:
	int declaredArrays[4];
	
	// Add elements
	declaredArrays[0] = 25;
	declaredArrays[1] = 50;
	declaredArrays[2] = 75;
	declaredArrays[3] = 100;
	
	return 0;
}