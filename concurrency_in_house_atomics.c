#include <stdio.h>
#include <pthread.h>

typedef struct {
        volatile int a;
} atomic_t;

#define LOCK "lock ; "

#define ATOMIC_OP_1ARG(name, op) \
static inline void atomic_##name(atomic_t *a)   \
{                                               \
	  __asm__ volatile (LOCK op " %0;"                  \
			                  : "=m"(a->a)                    \
			                  : "m"(a->a));                   \
}

ATOMIC_OP_1ARG(inc, "incl")


atomic_t counter;

struct t_arg {
	unsigned int loops;
};

void *f(void *arg)
{
	unsigned int i;
	struct t_arg *a;
	a = arg;
	
	for (i = 0; i < a->loops; i++) {
		atomic_inc(&counter);
	}
	return NULL;
}
#define N 5

int main(void)
{
	pthread_t t[N];
	struct t_arg args[N];
	unsigned int n;

	counter.a = 0;
	for (n = 0; n < N; n++) {
		args[n].loops = 1000000;
		pthread_create(&t[n], NULL, f, &args[n]);
	}

	for (n = 0; n < N; n++) {
		pthread_join(t[n], NULL);
	}

	printf("%d\n", counter.a);
	return 0;
}
