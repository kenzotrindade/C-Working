#include <stdio.h>

int main()
{
    int numbers[10] = { 4, 5, 1, 10, 32, 0, 9, 14, 23, 2};
    int vmax = numbers[0];

    for (int i = 0; i<10; i++) {
        if (vmax < numbers[i]) {
            vmax = numbers[i];
        }
    }
    
    printf("Le plus grand élément est : %d", vmax);
}