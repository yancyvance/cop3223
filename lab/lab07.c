#include <stdio.h>
#define GRID_SIZE 3

// Function Prototypes
// Note: In C, the second dimension and onward needs to be specified.
// Also, because we want to write reusable codes, we will add a size parameter
// that represents the row/col of a square array.
// Please do not discuss variable-length array.
// Write the definitions of the functions in the order given but type all
// the prototypes at the onset.
// Try to draw to visualize the traversal process based on the direction/loop.
int get_magic_constant(int n);
int is_magic_square(int grid[GRID_SIZE][GRID_SIZE], int size, int target);
int validate_rows(int grid[GRID_SIZE][GRID_SIZE], int size, int target);
int validate_cols(int grid[GRID_SIZE][GRID_SIZE], int size, int target);
int validate_diag1(int grid[GRID_SIZE][GRID_SIZE], int size, int target);
int validate_diag2(int grid[GRID_SIZE][GRID_SIZE], int size, int target);


int main(void) {
    int T, res, data[GRID_SIZE][GRID_SIZE];   // data is a reusable array here
    
    // Get the number of test cases
    scanf("%d", &T);
    
    // Process each test case
    // Notice that we declared the variable i inside the for loop
    for(int i = 1; i <= T; i++) {
        // read all the numbers for the square
        for(int j = 0; j < GRID_SIZE; j++)
            for(int k = 0; k < GRID_SIZE; k++)
                // read a number
                scanf("%d", &data[j][k]);
        
        res = is_magic_square(data, GRID_SIZE, get_magic_constant(GRID_SIZE));
        
        // print test case information
        // Note the new format specifier %s for strings
        // We are also using a ternary IF here
        printf("%d: %s\n", i, res ? "Magic": "Not Magic");
    }
    
    return 0;
}


// Function Definitions
int get_magic_constant(int n) {
    // Helper function to compute the magic constant
    // given the matrix's size for one side
    return n * ( n*n + 1 ) / 2;
}

int is_magic_square(int grid[GRID_SIZE][GRID_SIZE], int size, int target) {
    // must satisfy all the requirements
    return validate_rows(grid, size, target) 
        && validate_cols(grid, size, target)
        && validate_diag1(grid, size, target) 
        && validate_diag2(grid, size, target);
}

int validate_rows(int grid[GRID_SIZE][GRID_SIZE], int size, int target) {
    // checks the sum of each rows
    int sum;
    
    for(int i = 0; i < size; i++) {
        sum = 0;    // reset
        
        for(int j = 0; j < size; j++)
            sum = sum + grid[i][j];
        
        // must be exactly the same
        if(sum != target) return 0;
    }

    return 1;       // no issues found
}

int validate_cols(int grid[GRID_SIZE][GRID_SIZE], int size, int target) {
    // checks the sum of each columns
    int sum;
    
    for(int i = 0; i < size; i++) {
        sum = 0;    // reset
        
        for(int j = 0; j < size; j++)
            sum = sum + grid[j][i];
        
        // must be exactly the same
        if(sum != target) return 0;
    }
    
    return 1;       // no issues found
}

int validate_diag1(int grid[GRID_SIZE][GRID_SIZE], int size, int target) {
    // upper left to lower right diagonal
    int sum = 0;
    
    for(int i = 0; i < size; i++)
        sum = sum + grid[i][i];
    
    // must be exactly the same
    return sum == target;
}

int validate_diag2(int grid[GRID_SIZE][GRID_SIZE], int size, int target) {
    // upper right to lower left diagonal
    int sum = 0;
    
    for(int i = 0; i < size; i++)
        sum = sum + grid[i][size-1-i];
    
    // must be exactly the same
    return sum == target;
}
