#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int balance = 0;

pthread_mutex_t mutex;
pthread_cond_t cond;


void *deposit(void *args){
	for(int i = 0; i < 7; i++){
		pthread_mutex_lock(&mutex);
		balance+=50;
		printf("I deposited 50... \n");
		pthread_cond_signal(&cond);
		pthread_mutex_unlock(&mutex);
	}
	
	return NULL;
}


void *withdraw(void *args){
	pthread_mutex_lock(&mutex);
	while(balance < 300){
		pthread_cond_wait(&cond, &mutex);
	}
	balance -= 200;
	printf("I could withdraw finally.... new balance is %d\n", balance);
	
	pthread_mutex_unlock(&mutex);
	
	
	return NULL;
	
}

int main(int argc, char *argv[]) {
	
	pthread_t t1, t2;
	printf("Proess ID: %id\n", getpid());
	
	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&cond, NULL);
	
	pthread_create(&t1, NULL, withdraw, &t1);
	pthread_create(&t2, NULL, deposit, &t2);
	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	
	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);
	
	
	printf("Count value: %d\n", balance);
	return 0;
}