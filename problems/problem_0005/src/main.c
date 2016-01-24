#include <stdio.h>

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

#define MIN 1
#define MAX 10

int main() {
    int factor = MAX;
    int product = MAX;
    int i = 1;

    while(1) {
        while(1) {
            if(product % factor == 0) {
                factor--;

                if(factor == 0)
                    goto RESULT;
            } else {
                break;
            }
        }

        i++;
        product = i * MAX;
        factor = MAX;
    }

RESULT:
    printf("The smallest number that can be divided by each numbers from " STR(MIN) " to " STR(MAX)
           " without any remainder is %d.\n", product);

    return 0;
}
