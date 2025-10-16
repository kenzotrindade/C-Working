#include <stdio.h>

int main() {
    float number;
    float TVA;
    float result;

    printf("Veuillez saisir un prix HT : ");
    scanf("%f", &number);
    printf("Veuillez saisir un taux de TVA :");
    scanf("%f", &TVA);
    result = number + number * TVA;

    printf("Le prix après TVA est de : %f\n", result);
}