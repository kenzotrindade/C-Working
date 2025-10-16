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
	int height = 5;
	int result = 1;
	int width = 4;
	for (int i = 0; i < height; i++) {
		for (int k = 0; k < width; k++) {
			create_empty_square();
		}

		for (int j = 0; j < result; j++) {	
				if (j % 2 == 0) {
					create_square(0, 255, 0);
				} else {
					create_square(255, 0, 0);
				}
			}
		
		for (int l = 0; l <width; l++) {
			create_empty_square();
		}

		result += 2;
		width -= 1;
		new_line();

		}
	
		for (int m = 0; m <= height + 1; m++) {
			for (int z = 0; z < 6; z++) {
				if (z>=3 && z<=5) {
					create_square(170, 47, 47);
				} else {
					create_empty_square();
			}

			}
		new_line();
		}
}
		


int main() {
	graphic();

	draw();
    return 0;
}
