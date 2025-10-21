#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_tab(char **tab, int size);
char** create_table(int size);
void player_round(char **tab);
void bot_round(char **tab);
int check_win(char** tab);


void print_tab(char **tab, int size) {
    for (int i=0; i<size;i++) {
        for (int j= 0;j<size;j++) {
            printf(" %c ", tab[i][j]);
            if (j<size-1) {
                printf("|");
            }
        }
        printf("\n");

        if (i<size-1) {
            for (int j=0; j<size;j++) {
                printf("---");
                if (j<size-1) {
                    printf("|");
                }
            }
            printf("\n");
        }
    }
}


char** create_table(int size) {

    char **array = malloc(size * sizeof(char *));

    for (int m=0;m<size;m++) {
        array[m] = (char *)malloc(size * sizeof(char));
    }

    for (int i=0;i<size;i++) {
        for (int j=0;j<size;j++) {
            array[i][j] = ' ';
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

    if (tab[x - 1][y - 1] == ' ') {
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
        if (tab[x][y] == ' ') {
            tab[x][y] = 'O';
            checkup = 1;
        }
    }
    print_tab(tab, 3);
}

int check_lines(char **tab, int i, char sym) {
    if (tab[i][0] == sym && tab[i][1] == sym && tab[i][2] == sym){
        return 1;
    }
    return 0;
}

int check_column(char **tab, int j, char sym) {
    if (tab[0][j] == sym && tab[1][j] == sym && tab[2][j] == sym){
        return 1;
    }
    return 0;
}

int check_diag1(char **tab, char sym) {
    if (tab[0][0] == sym && tab[1][1] == sym && tab[2][2] == sym){
        return 1;
    }
    return 0;
}

int check_diag2(char **tab, char sym) {
    if (tab[0][2] == sym && tab[1][1] == sym && tab[2][0] == sym){
        return 1;
    }
    return 0;
}

int check_win(char** tab) {
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            if (check_lines(tab, i, 'X') == 1) {
                return 1;
            } else if (check_lines(tab, i, 'O') == 1) {
                return 2;
            }

            if (check_column(tab, i, 'X') == 1) {
                return 1;
            } else if (check_column(tab, i, 'O') == 1) {
                return 2;
            }

            if (check_diag1(tab, 'X') == 1) {
                return 1;
            } else if (check_diag1(tab, 'O') == 1) {
                return 2;
            }

            if (check_diag2(tab, 'X') == 1) {
                return 1;
            } else if (check_diag2(tab, 'O') == 1) {
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