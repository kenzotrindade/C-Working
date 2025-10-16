#include <stdio.h>

int main()
{
    float moy;
    float notes[5] = {15, 4, 8, 12, 7};

    for (int i = 0; i < 5; i++) {
        moy += notes[i];
    }
    moy = moy / 5;
    printf("La moyenne est de : %f", moy);
}