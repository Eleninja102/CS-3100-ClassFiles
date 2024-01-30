#include <stdio.h>
#include <stdlib.h>
#define NUMTIMES 5


int hworld(int repeat){
	for(int i = 0; i < repeat; i++){
		printf("Hello WORLD!!\n");
	}
	return 0;
}

int main(int argc, char *argv[]) {
	int inputvar = argc > 1 ? atoi(argv[1]): 0;

	return hworld((NUMTIMES > inputvar) ? NUMTIMES: inputvar);
}


