#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

void think(int philo, int n) {
	int sleep_time = rand() % n + 1;
	sleep(sleep_time);
}

void pickup(int philo, int n) {

}

void eat(int philo, int n) {
	int sleep_time = rand() %n + 1;
	sleep(sleep_time);
}

void putdown(int philo, int n) {

}

void action(void *philo) {
	think(philo);
	pickup(philo);
	eat(philo);
	putdown(philo);
}

int main () {
	// Take number of philosophers as input
	int n;
	printf("Enter number of philosophers: \n");
	scanf("%d", &n);

	pthread_mutex_t chopsticks(n);
	pthread_t philosophers(n);
	pthread_attr_t att(n);

	// Create threads
	int i;
	for (i = 0; i < n; i++) {
		pthread_mutex_init(&chopsticks[i], NULL);
	}
	

	return 0;
}
