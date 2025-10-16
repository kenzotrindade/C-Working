#include "library.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void create_line(int size, int red, int green, int blue) {
	for( int i = 0; i < size ; i ++ ) {
		create_square(red, green , blue);
	}
}

void graphic() {
	int line;
	int R;
	int G;
	int B;

	printf("Veuillez saisir la longueur de la ligne : ");
	scanf("%d", &line);

	printf("Veuillez saisir la nuance de rouge : ");
	scanf("%d", &R);

	printf("Veuillez saisir la nuance de vert : ");
	scanf("%d", &G);


	printf("Veuillez saisir la nuance de bleu : ");
	scanf("%d", &B);

	for (int i = 0;i<line;i++) {
		create_square(R, G, B);
		for (int j = 0;j<line;j++) {
			create_square(R, G, B);
		}
		new_line();
	}
}


int main() {
	graphic();

	draw();
    return 0;
}