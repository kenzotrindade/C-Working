#include <stdio.h>

int main() {
    float poid = 80.0;
    int taille = 180;
    float result;

    result = poid / (taille * taille);

    printf("Voici votre IMC : %f\n", result);
}