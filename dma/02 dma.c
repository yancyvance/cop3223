#include <stdio.h>
#include <stdlib.h>

// A common pattern is to pair a helper that allocates an array with a
// helper that frees it. This makes cleanup easier to find and remember.
// The caller still needs to call destroy_array when done with the array.
//
// This example uses int elements. For another type, use the matching
// pointer type and sizeof in the allocation. For example, use double *
// and size * sizeof(double) for an array of doubles.
int *create_array(int size);
void destroy_array(int *arr);
void print_array(int *arr, int size);

int main(void) {
    int N = 5;
    
    // create_array gives main the address of the first element.
    // main is responsible for releasing the allocation.
    int *nums = create_array( N );
    
    for(int i = 0; i < N; i++) {
        // nums + i is the address of nums[i], which scanf needs.
        scanf("%d", nums+i);
    }
    
    // process
    // The pointer carries an address. Pass N separately so the function
    // knows how many elements it can access.
    print_array( nums, N );
    
    // After this call, nums can no longer be used to access the array.
    destroy_array( nums );


    return 0;
}

int *create_array(int size) {
    // The local pointer arr goes out of scope when this function returns.
    // The allocated array remains alive until the caller frees it.
    // This demo assumes a positive size, successful allocation, and valid input.
    int *arr = malloc( sizeof(int) * size );
    return arr;
}

void destroy_array(int *arr){
    // arr is a copy of the caller's pointer. free releases their shared block.
    free( arr );
}

void print_array(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d\n", arr[i]);
    }
}
