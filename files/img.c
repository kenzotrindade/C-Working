#include <stdio.h>

void generate_image() {
    FILE *f = fopen("image.ppm", "w");
    fprintf(f, "P3\n800 200\n255\n");
    
    for (int y = 0; y < 200; y++) {
        for (int x = 0; x < 800; x++) {
            int r, g, b;
            
            if (x < 133) {
                r = 255;
                g = x * 255 / 133;
                b = 0;
            } else if (x < 266) {
                r = 255 - (x - 133) * 255 / 133;
                g = 255;
                b = 0;
            } else if (x < 400) {
                r = 0;
                g = 255;
                b = (x - 266) * 255 / 134;
            } else if (x < 533) {
                r = 0;
                g = 255 - (x - 400) * 255 / 133;
                b = 255;
            } else if (x < 666) {
                r = (x - 533) * 255 / 133;
                g = 0;
                b = 255;
            } else {
                r = 255;
                g = 0;
                b = 255 - (x - 666) * 255 / 134;
            }
            
            fprintf(f, "%d %d %d ", r, g, b);
        }
        fprintf(f, "\n");
    }
    
    fclose(f);
}

int main() {
    generate_image();
}