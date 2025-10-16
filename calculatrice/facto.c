#include <stdio.h>

int main() {
    int n = 6;
    int compt = n - 1;

    while (compt>0) {
        n *= compt;
        compt -= 1;
    }
    
    printf("Factorielle de votre nombre : %d\n", n);
}