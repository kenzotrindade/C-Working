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
				create_square(255, 255, 0);
			}
		
		for (int l = 0; l <width; l++) {
			create_empty_square();
		}

		result += 2;
		width -= 1;
		new_line();

		}
	
}
		


int main() {
	graphic();

	draw();
    return 0;
}
