#include <stdio.h>
#include <stdlib.h>


void str_len(char *str) {
    int compt = 0;
    while (*str != '\0') {
        compt++;
        str++;
    }
    printf("La longueur de votre mot est : %d\n", compt);
}


int main() {
    str_len("coucou");
}