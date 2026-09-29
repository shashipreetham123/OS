#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

sem_t empty, full, mutex;

int in = 0, out = 0;

#define SIZE 5

int buffer[SIZE];

void *producer(void *arg) {

	for (int i = 1; i <= 10; i++) {
	
		int item = i;

		sem_wait(&empty);
		sem_wait(&mutex);

		buffer[in] = item;

		printf("Producer Produced: %d\n", item);

		in = (in + 1) % SIZE;

		sem_post(&mutex);
		sem_post(&full);

	}

	return NULL;

}

void *consumer(void *arg) {


	for (int i = 1; i <= 10; i++) {
	
	
		sem_wait(&full);
		sem_wait(&mutex);

		int item = buffer[out];

		out = (out + 1) % SIZE;

		printf("Consumer Consumer: %d\n", item);

		sem_post(&mutex);
		sem_post(&empty);
		
	}


	return NULL;

}


int main(){

	pthread_t p, c;

	sem_init(&empty, 0, SIZE);
	sem_init(&full, 0, 0);
	sem_init(&mutex, 0, 1);

	pthread_create(&p, NULL, producer, NULL);
	pthread_create(&c, NULL, consumer, NULL);

	pthread_join(p, NULL);
	pthread_join(c, NULL);

	sem_destroy(&empty);
	sem_destroy(&full);
	sem_destroy(&mutex);

	return 0;

}



