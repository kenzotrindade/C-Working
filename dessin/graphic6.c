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

	for (int i = 0;i<5;i++) {
		if (i % 2 != 0) {
			create_line(5, 255, 255, 0);
		}
		for (int j = 0;j<5;j++) {
			if (j % 2 != 0 && i % 2 != 1) {
				create_square(0, 0, 255);
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
