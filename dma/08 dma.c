#include <stdio.h>
#include <stdlib.h>

// A dynamically allocated 2D array with a separate allocation for each row.
// This is a common pattern for dynamically allocating a 2D array.
// The same pattern works for other element types. For doubles, use
// double ** for arr, sizeof(double *) for each pointer slot, and
// sizeof(double) for each element in a row.
// This demo assumes positive dimensions and successful allocations.
int main(void) {
    int R, C;

    printf("Enter the number of rows: ");
    scanf("%d", &R);
    printf("Enter the number of columns: ");
    scanf("%d", &C);

    // Allocate R slots of type int *. arr points to the first slot.
    int **arr = malloc( sizeof(int *) * R );

    // Each slot gets the address of a row containing C consecutive ints.
    // The rows are separate blocks and may be in different parts of memory.
    for(int i = 0; i < R; i++) {
        arr[i] = malloc( sizeof(int) * C );
    }

    int val = 1;
    // arr[i] points to row i. arr[i][j] accesses column j of that row.
    // Fill each row from left to right before moving to the next row.
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            arr[i][j] = val++;
        }
    }

    // Print one line per row.
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Free each row while its address is still available in arr.
    // Then free the array of row pointers.
    for(int i = 0; i < R; i++) {
        free( arr[i] );
    }

    free( arr );

    return 0;
}
