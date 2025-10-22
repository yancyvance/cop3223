#include <stdio.h>
#define MAX_NUMS 10

// Do the main() function first (with the complete body content). 
// Then define each function one at a time based on the order here.
// Your main() function can simply comment out the function calls 
// if they are not yet available and uncomment as they become available.
// Show an incremental approach to developing a solution.

// Function Prototypes
void print_array(int arr[], int size);          // reuse from last time
int compress_array(int arr[], int size);
int shift_array(int arr[], int size, int index);


int main(void) {
    int T, nums[MAX_NUMS];      // nums is a reusable array here
    
    // Get the number of test cases
    scanf("%d", &T);
    
    // Process each test case
    // Notice that we declared the variable i inside the for loop
    for(int i = 1; i <= T; i++) {
        // NOTE: MAX_COUNT corresponds to the array's capacity 
        // or the max elements it can hold; while the count corresponds
        // to the array's logical size (actual elements it is holding)
        int count = 0;      // the counter of actual numbers (logical size)
        
        // notice the two increments expressions we have in the for loop
        // count cannot be declared inside the inner for block because 
        // we need it later to hold the actual count
        for(int j = 0; j < MAX_NUMS; j++, count++) {
            // read a number
            scanf("%d", &nums[j]);
            
            // if it is the sentinel value 0, exit the inner loop
            if( nums[j] == 0 ) break;
        }
        
        // compress the array and pass the actual count
        count = compress_array(nums, count);
        
        // print test case information
        printf("%d: ", i);
        
        // print the contents after the change
        print_array(nums, count);
    }
    
    return 0;
}


// Function Definitions
void print_array(int arr[], int size) {
    // helper function to print contents of array
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int compress_array(int arr[], int size) {
    // edge case: when the array is empty
    if( size == 0 ) return 0;
    
    int prev = arr[0];  // assume there is at least one element (prev seen)
    int pos = 1;        // start looking at the next element
    
    // while there is still an element to process
    while( pos < size ) {
        // have we seen this element already?
        if( arr[pos] == prev ) {
            // if yes, shift to the left and we will lose one element
            // so update size
            size = shift_array( arr, size, pos );
            // we could have decremented size here (e.g., size--) 
            // instead of doing the current strategy; this can make
            // shift_array() a void function if that's the case
                        
            // note that we don't move forward in this case
        }
        else {
            // if no, update the previous seen element
            prev = arr[pos];
            // move forward to the next element
            pos++;
        }
    }
    
    // since we may have lost some elements, we report back the new size
    return size;
}

int shift_array(int arr[], int size, int index) {
    // idea is to fill in the gap at the location specified by index
    // by shifting all the elements to the left by one
    // notice the condition of the loop, we stop at the second
    // to the last element (otherwise, off by one!)
    for(int i = index; i < size-1; i++) {
        arr[i] = arr[i+1];
    }
    
    // since we lost one element, we report back the new size
    return size-1;
}
