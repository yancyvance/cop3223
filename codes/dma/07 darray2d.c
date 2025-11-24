#include <stdio.h>
#include <stdlib.h>

// Example 2: Dynamically allocated 2D array of int values (Jagged Arrays)

int main(void) {
    // TODO 1: Ask the user how many Rows and Cols
    int rows = 2;
    int cols = 3;

    // TODO 2: Dynamically allocate the 2D array (rows first)
    int **arr = malloc( sizeof(int *) * rows );
    
    // TODO 3: Dynamically allocate the 2D array (columns)
    for(int i = 0; i < rows; i++) {
        arr[i] = malloc( sizeof(int) * cols );
    }
    
    // TODO 4: Populate the array with multiples of 5
    int num = 5;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            arr[i][j] = num;
            num = num + 5;
        }
    }
    
    // TODO 5: Print all the values
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    
    // TODO 6: Cleanup!
    for(int i = 0; i < rows; i++) {
        free( arr[i] );
    }
    free(arr);
    

    return 0;
}
