#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if(argc > 1){
		int inputvar = atoi(argv[1]);
		for(int i = 0; i < 5; i++){
			printf("%d", inputvar+i);
			printf("%s", i != 4? ", ": "\n");
		}
	}	
	return 0;
}