#include <stdio.h>

int main()
{
    int choice;
    float number_1;
    float number_2;
    float resultat;

    printf("1 - Addition \n");
    printf("2 - Soustraction \n");
    printf("3 - Multiplication \n");
    printf("4 - Division \n");

    printf("Veuillez saisir une opération : ");
    scanf("%d", &choice);

    printf("Veuillez saisir votre premier nombre : ");
    scanf("%f", &number_1);

    printf("Veuillez saisir votre deuxième nombre : ");
    scanf("%f", &number_2);

    if (choice == 1) {
        resultat = number_1 + number_2;
        printf(" %f + %f = %f", number_1, number_2, resultat);
    } else if (choice == 2) {
        resultat = number_1 - number_2;
        printf(" %f - %f = %f", number_1, number_2, resultat);
    } else if (choice == 3) {
        resultat = number_1 * number_2;
        printf(" %f * %f = %f", number_1, number_2, resultat);
    } else if (choice == 4) {
        resultat = number_1 / number_2;
        printf(" %f / %f = %f", number_1, number_2, resultat);
    } else {
        printf("Veuillez saisir un numéro valide lister ci dessus !");
    }
}