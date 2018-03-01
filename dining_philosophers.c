#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int n;	// Make the number of philosophers as global variable
pthread_mutex_t chopsticks[100000];
pthread_t philosophers[100000];

void think(int philosopher_number) {
	int sleep_time = rand() % n + 1;
	printf("Think: philosopher %d thinks for %d seconds\n", philosopher_number, sleep_time);
	sleep(sleep_time);
}

void pickup(int philosopher_number) {
	int left = (philosopher_number + n) % n;
	int right = (philosopher_number + 1) % n;
	if (philosopher_number & 1) {
		printf("Waiting: Philosopher %d is waiting to pickup chopstick %d \n", philosopher_number, right);
		pthread_mutex_lock(&chopsticks[right]);
		printf("Picked up: Philosopher %d, Chopstick %d\n", philosopher_number, right);
		printf("Waiting: Philosopher %d is waiting to pickup chopstick %d \n", philosopher_number, left);
		pthread_mutex_lock(&chopsticks[left]);
		printf("Picked up: Philosopher %d, Chopstick %d\n", philosopher_number, left);
		
	} else {
		printf("Waiting: Philosopher %d is waiting to pickup chopstick %d \n", philosopher_number, left);
		pthread_mutex_lock(&chopsticks[left]);
		printf("Picked up: Philosopher %d, Chopstick %d\n", philosopher_number, left);
		printf("Waiting: Philosopher %d is waiting to pickup chopstick %d \n", philosopher_number, right);
		pthread_mutex_lock(&chopsticks[right]);
		printf("Picked up: Philosopher %d, Chopstick %d\n", philosopher_number, right);
	}

}

void eat(int philosopher_number) {
	int sleep_time = rand() %n + 1;
	printf("Eat: philosopher %d eats for %d seconds\n", philosopher_number, sleep_time);
	sleep(sleep_time);
}

void putdown(int philosopher_number) {
	printf("Putdown: philosopher %d\n", philosopher_number);
	pthread_mutex_unlock(&chopsticks[(philosopher_number +1) % n]);
	pthread_mutex_unlock(&chopsticks[(philosopher_number + n) % n]); 
}

void *action(void *philosopher_number) {
	while (1) {
		think(philosopher_number);
		pickup(philosopher_number);
		eat(philosopher_number);
		putdown(philosopher_number);
	}
}

int main () {
	// Take number of philosophers as input
	// int n;
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
		pthread_create(&philosophers[i], NULL, action, (void *)(i));
	}
	
	for (i = 0; i < n; i++) {
		pthread_join(philosophers[i], NULL);
	}

	return 0;
}
