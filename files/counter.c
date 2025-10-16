#include <stdio.h>

void print_lines() {
    FILE *file;
    char buffer[256];

    file = fopen("count.txt", "r");

    if (file == NULL) {
        printf("Erreur fichier vide");
    }

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    fclose(file);
}


void incrementation() {
    FILE *file;
    int index;

    file = fopen("count.txt", "r");

    if (fscanf(file, "%d", &index) == EOF) {
        printf("Erreur de fscanf");
    }

    fclose(file);

    file = fopen("count.txt", "w");
    index++;
    fprintf(file, "%d\n", index);
    fclose(file);
    print_lines();
}

int main() {
    incrementation();
}