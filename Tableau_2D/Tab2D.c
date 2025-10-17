#include <stdio.h>
#include <stdlib.h>

void create_tab(int **tab, int size);
void print_tab(int **tab, int size);
int sum_tab(int **tab, int size);
void choice_tab(int size);


void create_tab(int **tab, int size) {
    int compt = 1;

    for (int i=0;i<size;i++) {
        for (int j=0;j<size;j++) {
            tab[i][j] = compt;
            compt++;
        }
    }
}

void print_tab(int **tab, int size) {
    for (int i=0;i<size;i++) {
        for (int j=0;j<size;j++) {
            printf("%4d", tab[i][j]);
        }
        printf("\n");
    }
}

int sum_tab(int **tab, int size) {
    int sum = 0;

    for (int i=0;i<size;i++) {
        for (int j=0;j<size;j++) {
            sum += tab[i][j];
        }
    }
    return sum;
}

void choice_tab(int size) {

    int **array = malloc(size * sizeof(int *));

    for (int m=0;m<size;m++) {
        array[m] = (int *)malloc(size * sizeof(int));
    }

    for (int i=0;i<size;i++) {
        for (int j=0;j<size;j++) {
            array[i][j] = (i+1) * (j+1);
        }
    }
    print_tab(array, size);

    for (int i=0;i<size;i++) {
        free(array[i]);
    }
    free(array);
    
}

int main() {
    choice_tab(7);
}