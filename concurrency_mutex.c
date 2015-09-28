#include <stdio.h>
#include <pthread.h>

unsigned int counter;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

struct t_arg {
	unsigned int loops;
};

void *f(void *arg)
{
	unsigned int i;
	struct t_arg *a;
	a = arg;
	
	for (i = 0; i < a->loops; i++) {
		pthread_mutex_lock(&m);
		counter++;
		pthread_mutex_unlock(&m);
	}
	return NULL;
}
#define N 5

int main(void)
{
	pthread_t t[N];
	struct t_arg args[N];
	unsigned int n;

	counter = 0;
	for (n = 0; n < N; n++) {
		args[n].loops = 1000000;
		pthread_create(&t[n], NULL, f, &args[n]);
	}

	for (n = 0; n < N; n++) {
		pthread_join(t[n], NULL);
	}

	printf("%d\n", counter);
	return 0;
}
