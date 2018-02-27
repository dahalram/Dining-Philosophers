#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

int n;	// Make the number of philosophers as global variable
pthread_mutex_t chopsticks[n];
pthread_t philosophers[n];

void think(int philo) {
	int sleep_time = rand() % n + 1;
	sleep(sleep_time);
}

void pickup(int philo) {

}

void eat(int philo) {
	int sleep_time = rand() %n + 1;
	sleep(sleep_time);
}

void putdown(int philo) {
	pthread_mutex_unlock(&chopsticks[(philo +1) % n];
	pthread_mutex_unlock(&chopsticks[philo % n]); 
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
	
	srand(time(NULL));

	//pthread_attr_t att(n);

	// Create threads
	int i;
	for (i = 0; i < n; i++) {
		pthread_mutex_init(&chopsticks[i], NULL);
	}
	
	for (i = 0; i < n; i++) {
		pthread_create(&philosophers[i], NULL, action, i);
	}
	
	for (i = 0; i < n; i++) {
		pthread_join(philosophers[i], NULL);
	}

	return 0;
}
