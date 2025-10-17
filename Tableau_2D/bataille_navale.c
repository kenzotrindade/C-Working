#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_tab(char **tab, int size);
char** create_table(int size);

typedef struct Navire
{
    char name;
    int size;

} Navire;


void print_tab(char **tab, int size) {
    for (int i=0;i<size;i++) {
        for (int j=0;j<size;j++) {
            printf("%4c", tab[i][j]);
        }
        printf("\n");
    }
}

char** create_table(int size) {

    char **array = malloc(size * sizeof(char *));

    for (int m=0;m<size;m++) {
        array[m] = (char *)malloc(size * sizeof(char));
    }

    for (int i=0;i<size;i++) {
        for (int j=0;j<size;j++) {
            array[i][j] = '.';
        }
    }
    print_tab(array, size);

    return array;
    
}

Navire create_boat() {
    Navire porte_avion;
    porte_avion.name = "Porte Avion";
    porte_avion.size = 5;

    Navire croiseur;
    croiseur.name = "Croiseur";
    croiseur.size = 4;

    Navire contre_torpilleur;
    contre_torpilleur.name = "COntre_Torpilleur";
    contre_torpilleur.size = 3;

    Navire sous_marin;
    sous_marin.name = "Sous-Marin";
    sous_marin.size = 3;

    Navire torpilleur;
    torpilleur.name = "Torpilleur";
    torpilleur.size = 2;
}

int main() {
    char **tab;
    tab = create_table(10);
    printf("\n");
    print_tab(tab, 10);

    for (int i=0;i<3;i++) {
        free(tab[i]);
    }
    free(tab);
}