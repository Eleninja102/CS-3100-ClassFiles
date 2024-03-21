#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <time.h>
#include <sys/time.h>
#include <semaphore.h>
#include <errno.h>
#include <string.h>

int count = 0;
pthread_mutex_t mutex;

sem_t * sem;

void * incfn(){
	
	for(int i = 0; i < 1E2; i++){
		count++;
	}
	
	return NULL;
}


void * incfn2(){
	
	while(count < 2E2){
		count++;
	}
	
	return NULL;
}

void * incfn3(){
	
	for(int i = 0; i < 1E2; i++){
		pthread_mutex_lock(&mutex);
		count++;
		pthread_mutex_unlock(&mutex);

	}
	
	return NULL;
}


void * incfn4(){
	
	for(int i = 0; i < 1E2; i++){
		sem_wait(sem);
		count++;	
		sem_post(sem);

	}
	
	return NULL;
}

int main(int argc, char *argv[]) {
	
	pthread_t t1, t2;
	
	printf("Proess ID: %id\n", getpid());
	clock_t start = clock();
	struct timeval startTime, endTime;
	gettimeofday(&startTime, NULL);

	
	pthread_create(&t1, NULL, incfn, NULL);
	pthread_create(&t2, NULL, incfn, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	
	
	float cpuTime = (clock() - start);
	gettimeofday(&endTime, NULL);
	double wallTime = (double) (endTime.tv_usec - startTime.tv_usec) /1000000 +
	(double) (endTime.tv_sec - startTime.tv_sec);
	
	printf("For %f\n", cpuTime);
	printf("For %f\n",wallTime);
	printf("For Count Value %d\n\n", count);
	count = 0;
	
	start = clock();
	gettimeofday(&startTime, NULL);

	
	pthread_create(&t1, NULL, incfn2, NULL);
	pthread_create(&t2, NULL, incfn2, NULL);
	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	
	cpuTime = (clock() - start);
	gettimeofday(&endTime, NULL);
	wallTime = (double) (endTime.tv_usec - startTime.tv_usec) /1000000 +
	(double) (endTime.tv_sec - startTime.tv_sec);
	
	
	printf("While %f\n", cpuTime);
	printf("While %f\n",wallTime);
	
	
	printf("While Count Value %d\n\n", count);
	
	
	count = 0;
	
	start = clock();
	gettimeofday(&startTime, NULL);
	
	pthread_mutex_init(&mutex, NULL);
	
	pthread_create(&t1, NULL, incfn3, NULL);
	pthread_create(&t2, NULL, incfn3, NULL);
	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	
	cpuTime = (clock() - start);
	gettimeofday(&endTime, NULL);
	wallTime = (double) (endTime.tv_usec - startTime.tv_usec) /1000000 +
	(double) (endTime.tv_sec - startTime.tv_sec);
	
	pthread_mutex_destroy(&mutex);

	printf("Lock %f\n", cpuTime);
	printf("Lock %f\n",wallTime);

	printf("Lock Count Value %d\n\n", count);
	
	
	
	
	count = 0;
	
	start = clock();
	gettimeofday(&startTime, NULL);
	
	char * name = "my_semaphore";
	int VALUE = 2;
	printf("Open or Create a named semaphore, %s, its value is %d\n", name,VALUE);
	sem = sem_open(name, O_CREAT, 0666, VALUE);

	
	pthread_create(&t1, NULL, incfn4, NULL);
	pthread_create(&t2, NULL, incfn4, NULL);
	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	
	sem_close(sem);
	sem_unlink(name);

	
	
	cpuTime = (clock() - start);
	gettimeofday(&endTime, NULL);
	wallTime = (double) (endTime.tv_usec - startTime.tv_usec) /1000000 +
	(double) (endTime.tv_sec - startTime.tv_sec);
	
	
	printf("Semaphore %f\n", cpuTime);
	printf("Semaphore %f\n",wallTime);
	
	printf("Semaphore Count Value %d\n", count);
	
	return 0;
}