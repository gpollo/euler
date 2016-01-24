#include <stdio.h>

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

#define PRIME 100

int main() {
    long dividend = 600851475143;
    int current = 2;
    int largest = 0;

    while(dividend >= current) {
        if(dividend % current == 0) {
            dividend /= current;

            if(current > largest)
                largest = current;

            current = 2;
        }

        current++;
    }

    printf("The largest prime factor of " STR(PRIME) " is %d.\n", largest);

    return 0;
}
