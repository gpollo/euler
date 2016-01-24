#include <stdio.h>

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

#define MAX 10001

int main() {
    int number = 1;
    int prime[MAX];
    int i, j;

    i = 1; prime[0] = 2;
    while(i < MAX) {
        j = 0; number += 2;
        while(j < i) {
            if(number % prime[j] == 0) {
                number += 2; j = 0;
            }

            j++;
        }

        prime[i] = number;
        i++;
    }

    printf("The " STR(MAX) "st prime number is %d.\n", prime[MAX-1]);

    return 0;
}
