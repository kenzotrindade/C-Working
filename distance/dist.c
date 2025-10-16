#include <stdio.h>
#include <math.h>

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


float get_vector_distance(Vector2D vector) {
    float distance;
    distance = sqrt(pow(vector.destination.x - vector.origin.x, 2)
     + pow(vector.destination.y - vector.origin.y, 2)) ;
     printf("La distance est de : %f\n", distance);
     return distance;
    
}

int main() {
    Vector2D vector1 ;
    vector1.origin.x = 5;
    vector1.origin.y = 10;
    vector1.destination.x = 15;
    vector1.destination.y = 20;

    get_vector_distance(vector1);
}