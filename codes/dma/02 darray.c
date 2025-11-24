#include <stdio.h>
#include <stdlib.h>

// Example 2: Dynamically allocated array of int values

// Function Prototypes
int *create_array(int capacity);
void destroy_array(int *arr);
void print_array(int *arr, int size);


int main(void) {
    // TODO 1: Ask the user how many numbers to store (N)
    int N = 3;
    
    // TODO 2: Dynamically allocate memory that can store N int values
    int *ptr = create_array(N);
    
    if( !ptr )
        return 0;
    
    // TODO 3: Populate the array (multiples of 5)
    for(int i = 0; i < N; i++) {
        //ptr[i] = 5 * (i+1);
        *(ptr+i) = 5 * (i+1);
    }
    
    // TODO 4: Print the array in reverse
    for(int i = N-1; i >= 0; i--) {
        printf("%d ", ptr[i]);
    }
    printf("\n");
    
    print_array(ptr, N);    // this prints it in forward
    
    // TODO 5: Cleanup!
    destroy_array(ptr);
    
    // TODO 6: Best practice (defensive)
    

    return 0;
}

// TODO 7: Function approach (helpers to create/destroy)
int *create_array(int capacity) {
    return malloc( sizeof(int) * capacity );
}

void destroy_array(int *arr) {
    free(arr);
}


// TODO 8: Function to print all elements
void print_array(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
