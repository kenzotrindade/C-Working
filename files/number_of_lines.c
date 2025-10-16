#include <stdio.h>

int main() {
    FILE *file;
    char buffer[256];
    int number_of_lines = 0;

    file = fopen("f.txt", "r");

    if (file == NULL) {
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        number_of_lines++;
    }
    printf("Nombre de lignes : %d\n", number_of_lines);
}