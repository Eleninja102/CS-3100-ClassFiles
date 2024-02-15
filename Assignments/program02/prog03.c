/*
Author: Coleton Watt
Date: Jan 31, 2022
It took me about 2 hours
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/time.h>

#define NAME "Coleton Watt"

int main(int argc, char *argv[]) {
	clock_t start = clock();
	struct timeval startTime, endTime;
	gettimeofday(&startTime, NULL);
	int cp[2]; //pipe array 0 - read 1 - write

	if(argc < 3){
		printf("Missing file name or process count");
		return -1;
	}
	
	if(pipe(cp)){
		printf("didn't work, couldn't not establish pipe.\n");
		return -1;
	}
	
	printf("My name is: %s\n", NAME);
	int processID;
	for(int processCounter = 0; processCounter < atoi(argv[1]); processCounter++){
		processID = fork();
		if(processID == 0){
			close(0); //close stdin
			close(1); //close stdout
			close(cp[0]); //close write pipe in
			dup2(cp[1], 1); //move stdout to pipe of cp[1]
			close(cp[0]);
			char str[12];
			sprintf(str, "%d", processCounter);

			execl("minMax", "minMax", argv[2], str, (char*)0);
			

		}
	}
	if(processID != 0){
		wait(NULL);

		close(cp[1]);
		
		char printfCh;
		while(read(cp[0], &printfCh, 1) == 1) {
			printf("%c", printfCh);
		}
		
		close(cp[0]);


		float cpuTime = (clock() - start);
		gettimeofday(&endTime, NULL);
		double wallTime = (double) (endTime.tv_usec - startTime.tv_usec) /1000000 +
		(double) (endTime.tv_sec - startTime.tv_sec);
		
		printf("Main process CPU time: %f\n", cpuTime/CLOCKS_PER_SEC);
		printf("Wall time: %f\n", wallTime);
	}
	return 0;
}
