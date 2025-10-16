#include <stdio.h>
#include <stdbool.h>

void facto();

void facto() {
    int n;
    bool premier = true;
    
    printf("Veuillez entrer votre nombre : ");
    scanf("%d", &n);

    if (n<2) {
        printf("Non premier");
    }

    for (int i = 2;i<n; i++) {
        if ((n % i) == 0) {
            premier = false;
        }
    }
    if (premier == true) {
        printf("Premier");
    } else {
        printf("Non premier");
    }
}

int main() {
    facto();
}