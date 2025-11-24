#include <stdio.h>
#include <stdlib.h>

// Example 1: One dynamically allocated int

void print_value(int *p);

int main(void) {
    // TODO 1: Dynamically allocate memory that can store a single int value
    int *ptr = malloc( sizeof(int) );
    
    *ptr = 10;
    //scanf("%d", ptr);   // if you want user input
        
    // TODO 2: Print the value at that location
    printf("%d\n", *ptr);
    
    // TODO 3: Define a function that prints the value at that location
    print_value(ptr);

    
    // TODO 4: Memory leak; Deallocate the dynamically allocated space 
    free( ptr );
    
    return 0;
}

void print_value(int *p) {
    printf("%d\n", *p);
}
