#include "library.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void create_line(int size, int red, int green, int blue) {
	for( int i = 0; i < size ; i ++ ) {
		create_square(red, green , blue);
	}
}

int main() {

	for (int i = 0;i<5;i++) {
		create_square(0, 255, 0);
		for (int j = 0;j<5;j++) {
			create_square(0, 255, 0);
		}
		new_line();
	}
	

	draw();
    return 0;
}
