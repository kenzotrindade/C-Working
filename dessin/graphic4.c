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
	srand(time(NULL));

	for (int i = 0;i<5;i++) {
		int R = rand() % 256;
		int G = rand() % 256;
		int B = rand() % 256;
		create_square(R, G, B);
		for (int j = 0;j<4;j++) {
			R = rand() % 256;
			G = rand() % 256;
			B = rand() % 256;
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
