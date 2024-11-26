#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> // For uint8_t
#include <time.h>
#include <stdbool.h>
#include <math.h>

// External assembly function declaration
extern void imgCvtGrayIntoFloat(int size, const uint8_t* input, float* output);

// C equivalent of the assembly function
void imgCvtGrayIntoFloat_C(int size, const uint8_t* input, float* output) {
    int i;
    for (i = 0; i < size; i++) {
        output[i] = (float)input[i] / 255.0f;
    }
}

// Function to compare outputs
bool compareOutputs(int size, const float* a, const float* b) {
    int i;
    const float epsilon = 1e-6; // Threshold to allow small differences
    for (i = 0; i < size; i++) {
        if (fabs(a[i] - b[i]) > epsilon) { // Check if the difference is greater than epsilon
            return false;
        }
    }
    return true;
}

// Function to measure the execution time of the assembly function
void measureExecutionTime(int size, const uint8_t* input, float* output) {
    clock_t start, end;
    double cpu_time_used;
    int num_iterations = 100;
    int k;

    start = clock();
    for (k = 0; k < num_iterations; k++) {
        imgCvtGrayIntoFloat(size, input, output);
    }
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC / num_iterations;
    printf("Average execution time of Assembly function: %f seconds\n", cpu_time_used);
}

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
    float* cOutputImage = (float*)malloc(size * sizeof(float));
    float* testOutputImage = (float*)malloc(size * sizeof(float));

    srand(time(NULL));

    // Generate random pixel values
    for (i = 0; i < size; i++) {
        inputImage[i] = rand() % 256;
    }
    
    
    // Print input image
    printf("\nInput Image before conversion:\n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%d ", inputImage[i * width + j]);
        }
        printf("\n");
    }
    

    // Call the Assembly Function
    imgCvtGrayIntoFloat(size, inputImage, outputImage);
    // Call the C equivalent function
    imgCvtGrayIntoFloat_C(size, inputImage, cOutputImage);

    // Print output image
    
    printf("\nOutput Image after conversion:\n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%.2f ", outputImage[i * width + j]);
        }
        printf("\n");
    }
    

    // Compare the outputs
    if (compareOutputs(size, outputImage, cOutputImage)) {
        printf("\nOutputs match! The assembly function is correct.\n");
    } else {
        printf("\nOutputs do not match. There is an issue with the assembly function.\n");
    }

    // Measure the execution time of the assembly function
    measureExecutionTime(size, inputImage, testOutputImage);
    
    free(inputImage);
    free(outputImage);
    free(cOutputImage);

    return 0;
}