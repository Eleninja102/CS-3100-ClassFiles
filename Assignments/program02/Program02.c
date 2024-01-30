#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	int cp[2]; //pipe array
	int x = 0;

	if(argc < 3){
		printf("Missing file name or process count");
		return -1;
	}
	if(pipe(cp)){
		printf("didn't work, couldn't not establish pipe.\n");
		return -1;
	}
	for(int i = 0; i < atoi(argv[1]); i++){
		int processID = fork();
		if(processID){
			printf("New Program");
			execlp(, (char*)NULL);
		}
	}
}