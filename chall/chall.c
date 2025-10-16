#include <stdio.h>
int main() {
    for (int i=1; i<101;i++) {
        if (i % 3 == 0 && i % 5 == 0) 
            printf("%d FizzBuzz \n", i);
        else if (i % 3 == 0)
            printf("Fizz %d\n", i);
        else if (i % 5 == 0)
            printf("Buzz %d\n", i);
        else
            printf("%d\n", i);       
    }
}