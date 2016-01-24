#include <stdio.h>

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

#define MAX 4000000

int main() {
    int sum = 0;
    int n[] = {0, 1, 1};
    int i = 0;

    while(n[0] <= MAX || n[1] <= MAX || n[2] <= MAX) {
        if(n[i] % 2 == 0)
            sum += n[i];

        switch(i) {
            case 0:
                n[0] = n[1]+n[2]; i++;
                break;
            case 1:
                n[1] = n[2]+n[0]; i++;
                break;
            case 2:
                n[2] = n[0]+n[1]; i=0;
                break;
        }
    };

    printf("The sum of the even-valued terms in the fibonacci sequence up to " STR(MAX)
           " is %d.\n", sum);

    return 0;
}
