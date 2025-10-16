#include <stdio.h>

void print_words() {
    FILE *file;
    int compt = 0;
    char letter;

    file = fopen("f.txt", "r");

    while ((letter = fgetc(file)) != EOF) {
        if (letter == ' ') {
            compt++;
        } else if (letter == '\n') {
            compt++;
        }
    }

    printf("%d\n", compt);
    fclose(file);
}

int main() {
    print_words();
}