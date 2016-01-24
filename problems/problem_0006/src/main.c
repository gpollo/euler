#include <stdio.h>

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

#define MAX 100

int main() {
    int sum1, sum2;
    int i;

    sum1 = sum2 = 0;
    for(i = 0; i <= MAX; i++) {
        sum1 += i*i;
        sum2 += i;
    }

    printf("The difference between the sum of the squares of the first " STR(MAX) " natural numbers"
           " and the square of the sum is %d.\n", (sum2*sum2)-sum1);

    return 0;
}
