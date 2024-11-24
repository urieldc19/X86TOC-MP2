#include <stdio.h>
#include <stdlib.h>

extern int imgCvtGrayInttoFloat(int height, int width, int* array);

int main () {
    int height, width, i, j;

    printf("Enter height: ");
    scanf("%d", &height);

    printf("Enter width: ");
    scanf("%d", &width);

    int* array = malloc((height * width) * sizeof(int));

    //imgCvtGrayInttoFloat(height, width, array);
    for (i = 0; i < height * width; i++)
        array[i] = i + 1;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%d ", array[i * width + j]);
        }
        printf("\n");
    }

    return 0;
}