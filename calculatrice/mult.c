#include <stdio.h>

int main()
{
    int number;
    int result;

    printf("Veuillez saisir la taille de la table : ");
    scanf("%d", &number);

    for (int i = 0; i<=number; i++) {
        for (int j = 0; j<=10; j++){
            result = i*j;
            printf("%d * %d = %d\n", i, j, result);
        }
        
    }
}