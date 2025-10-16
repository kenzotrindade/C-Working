#include <stdio.h>
#include <stdlib.h>

void swap(int p1, int p2) {
    int *ptr1 = &p2;
    int *ptr2 = &p1;

    printf("Voici la valeur de %d %d\n", *ptr1, *ptr2);
}


int main() {
    swap(5, 9);
}