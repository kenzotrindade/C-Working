#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Player {
    char name[50];
    int pvm;
    int pv;
} Player;

typedef struct Dragon {
    int pvm;
    int pv;
} Dragon;

void display_player(Player player_1);
void display_dragon(Dragon dragon_1);
void init_characters(Player *player_1, Dragon *dragon_1);
int roll_dice(int size);
int roll_dices(int dices_number, int size);
int player_attack();
int dragon_attack();
void gameTurn(Player *player_1, Dragon *dragon_1);


void display_player(Player player_1) {
    printf("Nom : %s\n", player_1.name);
    printf("Pv : %d/%d", player_1.pv, player_1.pvm);
}

void display_dragon(Dragon dragon_1) {
    printf("Pv : %d/%d\n", dragon_1.pv, dragon_1.pvm);
}

void init_characters(Player *player_1, Dragon *dragon_1) {

    player_1->pv = 100;
    dragon_1->pv = 100;
    player_1->pvm = 100;
    dragon_1->pvm = 100;

    printf("Veuillez saisir votre pseudo : ");
    scanf("%s", player_1->name);

    display_player(*player_1);
    printf("\n");
    display_dragon(*dragon_1);
}

int roll_dice(int size) {
    int dice_face = rand() % size + 1;
    return dice_face;
}

int roll_dices(int dices_number, int size) {
    int result = 0;
    for (int i=0;i<dices_number;i++) {
        result += roll_dice(size);
    }
    return result;
}

int player_attack() {
    int attack = roll_dices(3, 6);
    return attack;
}

int dragon_attack() {
    int attack = roll_dices(3, 6);
    return attack;
}

void gameTurn(Player *player_1, Dragon *dragon_1) {

    int player_dice = roll_dice(6);
    int dragon_dice = roll_dice(6);
    int player_atk = player_attack();
    int dragon_atk = dragon_attack();

    if (player_dice > dragon_dice) {
        player_atk;
        dragon_1->pv -= player_atk;
        printf("Le joueur attaque avec %d points de dgt, vie du dragon : %d\n", player_atk, dragon_1->pv);
    } else {
        dragon_atk;
        player_1->pv -= dragon_atk;
        printf("Le dragon attaque avec %d points de dgt, vie du joueur : %d\n", dragon_atk, player_1->pv);
    }
}

int main() {
    srand(time(NULL));
    Player player_1;
    Dragon dragon_1;
    init_characters(&player_1, &dragon_1);
    while (player_1.pv > 0 && dragon_1.pv > 0) {
        gameTurn(&player_1, &dragon_1);
    }
    if (dragon_1.pv <= 0) {
        printf("Vous avez gagné avec %d pv restant !", player_1.pv);
    } else {
        printf("Vous avez perdu avec %d pv restant !", dragon_1.pv);
    }
}