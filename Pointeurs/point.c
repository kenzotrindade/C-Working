#include <stdio.h>

typedef struct Point
{
    float x;
    float y;
} Point;

typedef struct Vector2D
{
    Point origin;
    Point destination;
} Vector2D;

Point get_middle_point(Vector2D vector) {
    Point middle;
    middle.x = (vector.origin.x + vector.destination.x) / 2;
    middle.y = (vector.origin.y + vector.destination.y) / 2;
    printf("%f %f\n", middle.x, middle.y);

}


int main() {
    Vector2D vector1 ;
    vector1.origin.x = 5;
    vector1.origin.y = 10;
    vector1.destination.x = 15;
    vector1.destination.y = 20;

    get_middle_point(vector1);
}