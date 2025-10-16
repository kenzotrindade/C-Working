#include <stdio.h>
#include <stdlib.h>

char* dynamic_tab() {
    char *tab = malloc(26 * sizeof(char));
    for (int i = 0; i < 26; i++) {
        tab[i] = 97 + i;
    }
    return tab;
}

int tab[26];

int main() {
    printf("%s\n", dynamic_tab());
}