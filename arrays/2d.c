#include <stdio.h>
#define MAX_ROWS 3
#define MAX_COLS 4

// Function Prototypes
void print_2darray_row(int arr[MAX_ROWS][MAX_COLS], int rows, int cols);
void print_2darray_col(int arr[MAX_ROWS][MAX_COLS], int rows, int cols);


int main(void) {
    // Initialize a 2D array
    int nums[MAX_ROWS][MAX_COLS] = {
        {10, 20, 30, 40},
        {50, 60, 70, 80},
        {90, 100, 110, 120}
    };
    
    // Assume that these are the logical sizes
    int r = 3;
    int c = 4;
    
    // Row-Major Printing
    printf("Row Major:\n");
    print_2darray_row( nums, r, c );
    
    // Column-Major Printing
    printf("Column Major:\n");
    print_2darray_col( nums, r, c );

    return 0;
}


// Function Definitions
void print_2darray_row(int arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
    // Think of MAX_ROWS and MAX_COLS as the capacity
    // while rows and cols are the logical sizes.
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void print_2darray_col(int arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
    // Think of MAX_ROWS and MAX_COLS as the capacity
    // while rows and cols are the logical sizes.
    for(int i = 0; i < cols; i++) {
        for(int j = 0; j < rows; j++) {
            printf("%d ", arr[j][i]);
        }
        printf("\n");
    }
}
