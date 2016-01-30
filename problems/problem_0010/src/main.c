#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

#define MAXIMUM 2000000
#define INCREMENT 100;

struct primes {
    int estimate;
    int current;
    int* prime;
};

int main() {
    struct primes p;
    int i, j;
    long long sum = 2;

    p.estimate = (int)(MAXIMUM/log(MAXIMUM-1));
    p.prime = malloc(p.estimate*sizeof(int));
    p.prime[0] = 2;
    p.current = 1;

    for(i = 3; i < MAXIMUM; i += 2) {
        for(j = 0; j < p.current; j++)
            if(i%p.prime[j] == 0)
                break;

        if(j == p.current) {
            p.prime[j] = i;
            p.current++;

            if(p.current <= p.estimate) {
                p.estimate += INCREMENT;
                p.prime = realloc(p.prime, p.estimate*sizeof(int));
            }

            sum += i;
        }
    }

    printf("The sum of all primes below " STR(MAXIMUM) " is %lli.\n", sum);

    free(p.prime);
    return 0;
}
