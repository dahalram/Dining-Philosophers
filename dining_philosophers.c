#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void think(int philo, int n) {

}

void pickup(int philo, int n) {

}

void eat(int philo, int n) {

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
	scanf("%d", &n);

	

	return 0;
}
