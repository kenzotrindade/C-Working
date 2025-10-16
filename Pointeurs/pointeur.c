#include <stdio.h>
#include <stdlib.h>

void max(int *numbers, int size) {

    int vmax = numbers[0];

    for (int i = 0; i<10; i++) {
        if (vmax < numbers[i]) {
            vmax = numbers[i];
        }
    }

    printf("Voici le max de votre tableau : %d\n", vmax);
}

int numbers[10] = {4, 5, 1, 10, 32, 0, 9, 14, 23, 2};

int main() {
    max(numbers, 10);
}