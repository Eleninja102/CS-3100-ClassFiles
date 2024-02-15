/*
Author: Coleton Watt
Date: Jan 31, 2022
It took me about 2 hours
*/

#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {
	//printf("HELLO!!\n");
	clock_t start = clock();
	struct timeval startTime, endTime;
	gettimeofday(&startTime, NULL);
	
	if(argc < 2){
		printf("Usage: readfile <filename>\n");
		return -1;
	}
	FILE * inputFile;
	inputFile= fopen(argv[1], "rb"); //read binary file
	if(!inputFile){
		printf("File Not Found");
		return -1;
	}
	//int pid = getpid();
	fseek(inputFile, 0, SEEK_END); //go to end of file
	long size = ftell(inputFile);
	fseek(inputFile, 0, SEEK_SET); //go to start of file
	int numberOfIntegers = (int)size / (int) sizeof(int); //the number of int in the file
//	printf("file size: %li bytes\n", size);
//	printf("sizeof(int) = %i bytes\n",(int) sizeof(int));
//	printf("how many integers = %i\n\n", numberOfIntegers);	
	
	//int totalAmount = 0;
	int minNumber;
	int maxNumber;

	for(int i = 0; i < numberOfIntegers; i++){
		int temp = 0;
		fread(&temp,sizeof(int),1,inputFile);
		//if(i == 0){minNumber = temp; maxNumber=temp; continue;}
		//totalAmount +=temp;
		minNumber = minNumber > temp ? temp: minNumber;
		maxNumber = maxNumber < temp ? temp: maxNumber;

	}
	fclose(inputFile);  // close the file now that we're done

	float cpuTime = (clock() - start);
	gettimeofday(&endTime, NULL);
	double wallTime = (double) (endTime.tv_usec - startTime.tv_usec) /1000000 +
	(double) (endTime.tv_sec - startTime.tv_sec);
	
	printf("Child #:%s\t| pid: %d\t| min:%d\t| max: %d\t| Wall(sec): %f\t| CPU(sec) %f\n", argv[2], (int)getpid(), minNumber, maxNumber, wallTime, ((cpuTime)/CLOCKS_PER_SEC));
	
	return 0;
	
}
