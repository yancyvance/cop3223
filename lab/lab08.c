#include <stdio.h>
#define MAX_SIZE 52

// Function Prototypes
// Write the definitions of the functions in the order given but type all
// the prototypes at the onset. Afterward, define the main() function
// first in which you set up the structure to read the file contents.
void reset_art(char canvas[MAX_SIZE][MAX_SIZE], int R, int C);
void print_art(char canvas[MAX_SIZE][MAX_SIZE], int R, int C);
void draw_art(char canvas[MAX_SIZE][MAX_SIZE], int R, int C, int x, int y, char s);


int main(void) {
    char grid[MAX_SIZE][MAX_SIZE];
    FILE *ifile = NULL;
    
    // Open the file
    ifile = fopen("data.txt", "r");
    
    // Check if the file was opened
    if( !ifile ) {
        printf("Error opening file!\n");
        return -1;
    }
    
    // Read the actual dimension of the canvas
    int row, col;
    fscanf(ifile, "%d%d", &row, &col);
    
    // Compute the accurate dimensions with the borders
    int actual_row = row + 2;
    int actual_col = col + 2;
    
    // Reset the canvas with given dimension
    reset_art(grid, actual_row, actual_col);
    
    int x, y;
    char s;
    
    // Sentinel-controlled loop (as long as there is still something to read)
    while( fscanf(ifile, "%d%d %c", &x, &y, &s) != EOF ) {
        //printf("%d %d %c\n", x, y, s);
        draw_art(grid, actual_row, actual_col, x, y, s);
    }
    
    // Close the file
    fclose(ifile);
    
    // Print the artwork
    print_art(grid, actual_row, actual_col);

    return 0;
}


// Function Definitions
void reset_art(char canvas[MAX_SIZE][MAX_SIZE], int R, int C) {
    // The R and C here are the actual dimensions with the borders
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            // First and Last Rows
            if( i == 0 || i == R-1 )
                canvas[i][j] = '*';
            // First and Last Columns
            else if( j == 0 || j == C-1 )
                canvas[i][j] = '*';
            // Otherwise
            else
                canvas[i][j] = ' ';
        }
    }
}

void print_art(char canvas[MAX_SIZE][MAX_SIZE], int R, int C) {
    // The R and C here are the actual dimensions with the borders
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}

void draw_art(char canvas[MAX_SIZE][MAX_SIZE], int R, int C, int x, int y, char s) {
    // The R and C here are the actual dimensions with the borders
    canvas[x][y] = s;
}
