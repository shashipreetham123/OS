#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5

sem_t forks[N];
sem_t room;


void *philosopher(void *arg) {

	int id = *(int *)arg;

	int left = id;
	int right = (id + 1) % N;


	printf("Philosopher %d is Thinking...\n", id);
	sleep(1);

	printf("Philosopher %d is Hungry\n", id);

	sem_wait(&room);

	sem_wait(&forks[left]);

	printf("Philosopher %d Took the %d Fork\n", id, left);

	sem_wait(&forks[right]);

	printf("Philosopher %d Took the %d Fork\n", id, right);

	printf("Philosopher %d is Eating...\n", id);

	sleep(2);

	sem_post(&forks[left]);

	printf("Philosopher %d has Put Down the Fork %d\n", id, left);

	sem_post(&forks[right]);

	printf("Philosopher %d has Put Down the Fork %d\n", id, right);

	sem_post(&room);

	printf("Philosopher %d has Completed Eating\n", id);

	return NULL;
}

int main() {
	
	sem_init(&room, 0, N - 1);

	for (int i = 0; i < N; i++){
	
		sem_init(&forks[i], 0, 1);

	}

	pthread_t phil_threads[N];

	int id[N];

	for (int i = 0; i < N; i++) {
	
		id[i] = i;

		pthread_create(&phil_threads[i], NULL, philosopher, &id[i]);

	}

	for (int i = 0; i < N; i++) {
	
		pthread_join(phil_threads[i], NULL);

	}

	sem_destroy(&room);
	
	for (int i = 0; i < N; i++) {
	
		sem_destroy(&forks[i]);

	}

	return 0;


}
