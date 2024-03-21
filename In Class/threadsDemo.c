#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

#define BIG 10000000UL

void * function1(void* argc){
	int *ptr = (int * )argc;
	
	int *returnData = (int*)malloc(sizeof(int));
	*returnData = 13;
	while (1) {
		printf("\n Function1 running..... ");
		sleep(1);
	}
	return returnData;
}

void * function2(void* argc){
	while (1) {
		printf("\n Function2 AHHHHH running..... ");
		sleep(1);
	}
	return NULL;
}

void * countToBig(void *argc){
	uint32_t counter = 0;
	pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
	for(uint32_t i = 0; i < BIG; i++){
		pthread_mutex_lock(&lock);
		counter ++;
		pthread_mutex_unlock(&lock);

	}
	return NULL;
}

int main(int argc, char *argv[]) {

	
	printf("\n Start ... Main: \n");
	
	pthread_t pthread1, pthread2;
	
	int v = 5;
	
	int rc1 = pthread_create(&pthread1, NULL, function1, &v);
	int rc2 = pthread_create(&pthread2, NULL, function2, NULL);
	
	
	int *result; 
	pthread_join(pthread1, (void *)&result);
	pthread_join(pthread2, NULL);
	
	
	printf("\n End ... Main: \n");	
	return 0;
}