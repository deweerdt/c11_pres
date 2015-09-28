#include <math.h>
#include <stdio.h>

#define cbrt(X) _Generic((X), long double: cbrtl, default: cbrt, float: cbrtf)(X)

int main(void)
{
	long double a = 0.0;
	printf("%Le\n", cbrt(a));
	return 0;
}
