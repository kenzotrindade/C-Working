#include <stdio.h>

void facto();

void facto() {
    int n;
    
    printf("Veuillez entrer votre nombre : ");
    scanf("%d", &n);

    int compt = n - 1;

    while (compt>0) {
        n *= compt;
        compt -= 1;
    }
    
    printf("Factorielle de votre nombre : %d\n", n);
}

int main() {
    facto();
}