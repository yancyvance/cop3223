#include <stdio.h>
#include <stdlib.h>

// This demo assumes malloc succeeds. A failed allocation returns NULL.
// These examples allocate space for ints. For a different type, use a
// matching pointer type and sizeof. For example, use double * and
// sizeof(double) for one double, or N * sizeof(double) for N doubles.
int main(void) {
    // num is a local int. Its storage lasts until main returns.
    int num = 5;
    
    printf("%d\n", num);
    
    // We plan to store one int, so we request sizeof(int) bytes.
    // We use int * so that *ptr accesses the allocated space as an int.
    int *ptr;
    ptr = malloc( sizeof(int) );
    
    // malloc leaves the contents uninitialized. Write a value before reading it.
    *ptr = 100;
    
    printf("%d\n", *ptr);
    
    
    int N = 5;
    // One allocation holds N consecutive ints. arr points to the first.
    int *arr = malloc( sizeof(int) * N );
    
    // arr[i] means *(arr + i). Adding 1 advances by one int.
    *arr = 10;
    *(arr+1) = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;
    
    for(int i = 0; i < N; i++) {
        printf("%d\n", arr[i]);
    }
    
    
    // Pass each original allocation address to free once.
    // One free releases the entire array. Its elements share a single block.
    free(ptr);
    free(arr);
    
    // Assigning NULL changes the pointer variable. free released the old block.
    ptr = NULL;
    
    ptr = malloc(sizeof(int));
    *ptr = 200;
    printf("%d\n", *ptr);
    
    // Intentional leak example. This assignment overwrites the only pointer
    // to the block holding 200. The block holding 300 is also left unfreed.
    ptr = malloc(sizeof(int));
    *ptr = 300;
    printf("%d\n", *ptr);


    return 0;
}
