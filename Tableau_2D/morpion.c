#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_tab(char **tab, int size);
char** create_table(int size);

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

void player_round(char **tab) {
    int x;
    int y;

    printf("Veuillez entrez la position de votre jeu (x) : ");
    scanf("%d", &x);
    printf("Veuillez entrez la position de votre jeu (y) : ");
    scanf("%d", &y);

    if (tab[x - 1][y - 1] == '.') {
        tab[x - 1][y - 1] = 'X';
        print_tab(tab, 3);
    } else {
        print_tab(tab, 3);
    }
}

void bot_round(char **tab) {
    int checkup = 0;
    for (int t = 0; t < 100 && !checkup; t++) {
        int x = rand() % 3;
        int y = rand() % 3;
        if (tab[x][y] == '.') {
            tab[x][y] = 'O';
            checkup = 1;
        }
    }
    print_tab(tab, 3);
}

int check_win(char** tab) {
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            if (tab[i][0] == 'X' && tab[i][1] == 'X' && tab[i][2] == 'X') {
                return 1;
            } else if (tab[i][0] == 'O' && tab[i][1] == 'O' && tab[i][2] == 'O') {
                return 2;
            }

            if (tab[0][j] == 'X' && tab[1][j] == 'X' && tab[2][j] == 'X') {
                return 1;
            } else if (tab[0][j] == 'O' && tab[1][j] == 'O' && tab[2][j] == 'O') {
                return 2;
            }

            if (tab[0][0] == 'X' && tab[1][1] == 'X' && tab[2][2] == 'X') {
                return 1;
            } else if (tab[0][0] == 'O' && tab[1][1] == 'O' && tab[2][2] == 'O') {
                return 2;
            }

            if (tab[0][2] == 'X' && tab[1][1] == 'X' && tab[2][0] == 'X') {
                return 1;
            } else if (tab[0][2] == 'O' && tab[1][1] == 'O' && tab[2][0] == 'O') {
                return 2;
            }
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));

    char **tab;
    tab = create_table(3);
    int compteur = 0;

    while (compteur<9){
        player_round(tab);
        printf("\n-----------------\n");
        bot_round(tab);
        int winner = check_win(tab);
        if (winner == 1) {
            printf("Player win !\n");
            break;
        } else if (winner == 2) {
            printf("Bot win !\n");
            break;
        }
        compteur++;
    }

    for (int i=0;i<3;i++) {
        free(tab[i]);
    }
    free(tab);
}