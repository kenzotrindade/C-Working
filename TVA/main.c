#include <stdio.h>

int main() {
    float TVA = 1.20;
    int HT = 200;
    float result = HT * TVA;
    printf("Prix Hors Taxes : %d\n", HT);

    printf("Prix avec TVA : %f\n", result);

    return 0;
}