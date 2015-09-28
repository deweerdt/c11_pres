#include <stdio.h>
#include <uchar.h>

int main(void)
{
	printf("%ld\n", sizeof("café"));
	printf("%ld\n", sizeof(u8"café"));
	printf("%ld\n", sizeof(u"café"));
	printf("%ld\n", sizeof(U"café"));
	return 0;
}
