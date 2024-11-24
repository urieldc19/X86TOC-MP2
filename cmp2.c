#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> // For uint8_t
#include <time.h>


extern void imgCvtGrayIntoFloat(int size, const uint8_t* input, float* output);

int main () {

    // Prompt array size
    int height, width, i, j;

    printf("Enter height: ");
    scanf("%d", &height);

    printf("Enter width: ");
    scanf("%d", &width);

    int size = height * width;
    
    // Allocate memory for input and output images
    uint8_t* inputImage = (uint8_t*)malloc(size * sizeof(uint8_t)); // Use uint8_t
    float* outputImage = (float*)malloc(size * sizeof(float));

    srand(time(NULL));

    // Prompt user to enter pixel values
    //printf("Enter the pixel values (0-255):\n");
    for (i = 0; i < size; i++) {
        inputImage[i] = rand() % 256;
        //scanf("%hhu", &inputImage[i]); // %hhu is still correct for uint8_t
    }

    // Print input image
    printf("\nInput Image before conversion:\n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%d ", inputImage[i * width + j]);
        }
        printf("\n");
    }

    // Call the function
    imgCvtGrayIntoFloat(size, inputImage, outputImage);

    // Print output image
    printf("\nOutput Image after conversion:\n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%.2f ", outputImage[i * width + j]);
        }
        printf("\n");
    }

    free(inputImage);
    free(outputImage);

    return 0;
}