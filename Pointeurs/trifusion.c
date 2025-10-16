#include <stdio.h>
#include <stdlib.h>

int* array_concat(int *array1, int size1, int *array2, int size2) {
    int *result = malloc((size1 + size2) * sizeof(int));

    for (int i = 0; i < size1; i++) {
        result[i] = array1[i];
    }
    for (int j = 0; j < size2; j++) {
        result[size1 + j] = array2[j];
    }

    return result;
}

int main() {
    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5, 6, 7};

    int size1 = 3;
    int size2 = 4;

    int *result = array_concat(arr1, size1, arr2, size2);

    for (int i = 0; i < size1 + size2; i++) {
        printf("%d ", result[i]);
    }

    free(result);
    return 0;
}
