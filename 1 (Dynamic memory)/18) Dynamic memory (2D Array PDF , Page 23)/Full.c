#include <stdio.h>
#include <stdlib.h>

// Function to allocate a 2D array of characters
// Takes a triple pointer to char (char ***m), number of rows (r), and columns (c) as input
// Allocates memory for the 2D array and assigns it to the pointer *m
void malloc2d(char ***m, int r, int c) {
    int i;
    char **mat;

    // Allocate memory for row pointers
    mat = (char **) malloc(r * sizeof(char *));
    if (mat == NULL) {
        // Handle memory allocation error
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }

    // Allocate memory for each row
    for (i = 0; i < r; i++) {
        mat[i] = (char *) malloc(c * sizeof(char));
        if (mat[i] == NULL) {
            // Handle memory allocation error by freeing previously allocated memory
            for (int j = 0; j < i; j++) {
                free(mat[j]);
            }
            free(mat);
            fprintf(stderr, "Memory allocation error.\n");
            exit(1);
        }
    }

    // Set the output parameter to point to the allocated matrix
    *m = mat;
    return;
}

// Main function to demonstrate the usage of malloc2d
int main() {
    int rows = 3, cols = 4;
    char **matrix;

    // Allocate a 2D array of characters
    malloc2d(&matrix, rows, cols);

    // Example of assigning values to the 2D array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 'A' + j; // Assign character values (e.g., A, B, C, D)
        }
    }

    // Print the 2D array
    printf("The 2D character array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }

    // Free the allocated memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

/*
Summary of Functions in the Code:

1. malloc2d(char ***m, int r, int c):
   - Allocates memory for a 2D array of characters with the specified number of rows and columns.
   - Handles memory allocation errors and ensures proper cleanup if any allocation fails.
   - Assigns the allocated memory to the provided triple pointer (*m).

2. main():
   - Demonstrates the usage of the malloc2d() function by allocating a 2D array, assigning values, printing the array, and freeing the allocated memory.
*/
