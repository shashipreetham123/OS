#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

int shared = 1;
sem_t semaphore;

void *function1(void *arg) {
	int x;
	sem_wait(&semaphore);
	x = shared;
	printf("Thread 1: x = %d, shared = %d\n", x, shared);
	x++;
	printf("Thread 1: x = %d, shared = %d\n", x, shared);
	sleep(1);
	shared = x;
	printf("Thread 1: x = %d, shared = %d\n", x, shared);
	sem_post(&semaphore);
	return NULL;
}

void *function2(void *arg) {
	int y;
	sem_wait(&semaphore);
	y = shared;
	printf("Thread 2: y = %d, shared = %d\n", y, shared);
	y--;
	printf("Thread 2: y = %d, shared = %d\n", y, shared);
	sleep(1);
	shared = y;
	printf("Thread 2: y = %d, shared = %d\n", y, shared);
	sem_post(&semaphore);
	return NULL;
}

int main() {
	pthread_t thread1, thread2;

	if(sem_init(&semaphore, 0, 1) != 0){
		perror("Sem_Init");
		exit(EXIT_FAILURE);
	}

	if(pthread_create(&thread1, NULL, function1, NULL) != 0) {
		perror("pthread_create");
		exit(EXIT_FAILURE);
	}
	if(pthread_create(&thread2, NULL, function2, NULL) != 0) {
		perror("pthread_create");
		exit(EXIT_FAILURE);
	}

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	printf("Final Value of Shared Variable = %d\n", shared);

	sem_destroy(&semaphore);
	return 0;
}

