#include <stdio.h>

int main() {
    float weight;
    int height;
    float result;

    printf("Veuillez saisir votre poid : ");
    scanf("%f", &weight);

    printf("Veuillez saisir votre taille : ");
    scanf("%d", &height);

    result = weight / (height * height) * 10000;

    if (result<18.5) {
        printf("Vous êtes en sous poids, avec une IMC de %f\n", result);
    } else if (18.5<result && result<24.9) {
        printf("Vous êtes normal, avec une IMC de %f\n", result    );
    } else if (25<result && result<29.9) {
        printf("Vous êtes en excès pondéral, avec une IMC de %f\n", result);
    } else if (result>30) {
        printf("Vous êtes en surpoid, avec une IMC de %f\n", result);
}
}