#include <stdio.h>
#include <string.h>

int main() {
    char mot[100];
    int i = 1;
    int longueur = 1;
    int pal = 1;

    printf("Entrez un mot : ");
    scanf("%s", mot);

    longueur = strlen(mot);

    for (i = 0; i < longueur; i++) {
        if (mot[i] != mot[longueur - 1 - i]) {
            pal = 0;
        }
    }

    if (pal)
        printf("Palindrome\n");
    else
        printf("Pas Palindrome\n");

    return 0;
}
