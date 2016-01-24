#include <stdio.h>
#include <math.h>

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)
#define FALSE 0
#define TRUE 1

#define MAX 999

int num_get_n_digit(int number, int n) {
    return (number%(int)pow(10, n))/pow(10, n-1);
}

int num_get_size(int number) {
    int size = 0;

    while(pow(10, size) < number)
        size++;

    return size;
}

int num_is_palindrome(int number) {
    int size = num_get_size(number);
    int i;

    for(i = 1; i <= (size+1)/2; i++)
        if(num_get_n_digit(number, i) != num_get_n_digit(number, size-i+1))
            return FALSE;

    return TRUE;
}

int main() {
    int largest = 1;
    int a, b, number;

    a = 1;
    while(a <= MAX) {
        b = 1;
        while(b <= MAX) {
            number = a * b;

            if(num_is_palindrome(number) && number > largest)
                largest = number;

            b++;
        }

        a++;
    }

    printf("The largest palindrome made from the product of numbers smaller than " STR(MAX)
           " is %d.\n", largest);

    return 0;
}
