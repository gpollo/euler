#include <stdio.h>

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

#define MAX 1000
#define MULT_1 3
#define MULT_2 5

int main() {
    int sum, i;

    sum = 0;
    for(i = 0; i < 1000; i++)
        if(i % MULT_1 == 0 || i % MULT_2 == 0)
            sum += i;

	printf("The sum of all the multiples of " STR(MULT_1) " or " STR(MULT_2) " below " STR(MAX)
	       " is %d\n", sum);

    return 0;
}
