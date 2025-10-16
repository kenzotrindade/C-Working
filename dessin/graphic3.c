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
		create_square(255, 0, 0);
		for (int j = 0;j<4;j++) {
			if (i>=1 && i<=3 && j>=0 && j<=2) {
				create_square(0, 255, 0);
			} else {
				create_square(255, 0, 0);
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
