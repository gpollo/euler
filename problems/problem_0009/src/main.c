#include <stdio.h>
#include <math.h>

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

#define RESULT 1000

int main() {
    int a, b;
    float c;

    a = 0;
    do {
        b = ++a;

        do {
            c = sqrt(a*a+(++b)*b);
        } while(a+b+c < 1000);

        if(a+b+c == 1000)
            break;
        else
            b = c = 0;
    } while(a+b+c != 1000);

    printf("The product of the Pythagorean triplet whose some is " STR(RESULT)
           " is %d.\n", a*b*(int)c);

    return 0;
}
