#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> // For uint8_t

extern int imgCvtGrayInttoFloat(int height, int width, int* array);

int main () {
    int height, width, i, j;

    printf("Enter height: ");
    scanf("%d", &height);

    printf("Enter width: ");
    scanf("%d", &width);

    int size = height * width;
    
    uint8_t* inputImage = (uint8_t*)malloc(size * sizeof(uint8_t)); // Use uint8_t
    float* outputImage = (float*)malloc(size * sizeof(float));

    //imgCvtGrayInttoFloat(height, width, array);

    // Sample values to test print
    for (i = 0; i < height * width; i++)
        inputImage[i] = i + 1;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%d ", inputImage[i * width + j]);
        }
        printf("\n");
    }

    return 0;
}