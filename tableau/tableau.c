#include <stdio.h>
#include <stdlib.h>

int main() {
    int tab[7] = {1, 8, 2, 11, 9, 6, 5};
    int temp;

    for (int i=0;i<7;i++) {
        for (int j=i+1;j<7;j++) {
            if (tab[i] > tab[j]) {
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
        printf("%d\n", tab[i]);
    }
}