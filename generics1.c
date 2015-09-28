#include <stdio.h>
#include <time.h>


#define type_idx(T) _Generic( (T), 	\
		int: 1, 		\
		long: 2, 		\
		char *: 3,		\
		struct my_struct: 42,	\
		default: 0		\
		)

struct my_struct {
	int things;
};
int main(void)
{
	printf("%d\n", type_idx(123));
	printf("%d\n", type_idx(123L));
	printf("%d\n", type_idx("a"));
	printf("%d\n", type_idx((struct my_struct){.things=1}));
	return 0;
}
