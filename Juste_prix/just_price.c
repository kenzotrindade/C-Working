#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));
    int rdm = rand() % 1000 + 1;
    int choice;
    int compteur = 0;

    while(choice != rdm) {
        printf("Veuillez entrer votre nombre : ");
        scanf("%d", &choice);
        if (choice == rdm) {
            printf("Vous avez gagné, le nombre était : %d, avec : %d essais", rdm, compteur);
        } else if (choice < rdm) {
            printf("C'est plus grand !\n");
            compteur += 1;
        } else if (choice > rdm) {
            printf("C'est plus petit !\n");
            compteur += 1;
        }
    }
}