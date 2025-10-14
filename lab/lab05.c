#include <stdio.h>
#define DIGIT_COUNT 5

// SUGGESTION
// Do the main() function first (with the complete body content). 
// Then define each function one at a time based on the order here.
// Your main() function can simply comment out the function calls 
// if they are not yet available and uncomment as they become available.
// Show an incremental approach to developing a solution.

// Function Prototypes
void populate_array(int arr[], int size, int num);
void print_array(int arr[], int size);
int get_next_pos(int cur_pos, int size, int shift);
void left_shift_array(int arr[], int size, int shift);


int main(void) {
    int T, digits[DIGIT_COUNT], num, shift;
    
    // Get the number of test cases
    scanf("%d", &T);
    
    // Process each test case
    // Notice that we declared the variable i inside the for loop
    for(int i = 1; i <= T; i++) {
        // enter number
        scanf("%d", &num);
        
        // populate the array
        populate_array(digits, DIGIT_COUNT, num);
        
        // get the shift
        scanf("%d", &shift);
        
        // shift the contents
        left_shift_array(digits, DIGIT_COUNT, shift);

        // print test case information
        printf("%d: ", i);
        
        // print the contents after the change
        print_array(digits, DIGIT_COUNT);
    }
    
    return 0;
}


// Function Definitions
void populate_array(int arr[], int size, int num) {
    // pass by reference and we need to know size of array
    // We don't rely on the constant because we want our solution
    // to be reusable and not coupled only to this program
    // note the condition because we want to account for
    // leading zeros where the num is less than 5 digits
    for(int i = size-1; i >= 0; i--) {
        arr[i] = num % 10;
        num = num / 10;
    }
    
    // so if num goes beyond 99999, then only the 5 rightmost digits are handled
    // and this function ignores the remaining digits (notice the condition)
}

void print_array(int arr[], int size) {
    // helper function to print contents of array
    for(int i = 0; i < size; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

int get_next_pos(int cur_pos, int size, int shift) {
    // compute next position
    int new_pos = cur_pos + shift;
    
    // the range of valid values are 0 to size-1
    // we perform a modulo to in case the new_pos
    // is beyond this range
    return new_pos % size;
}

void left_shift_array(int arr[], int size, int shift) {
    // pass by reference and we need to know size of array
    
    // initial position will be at 0
    int pos = 0, next_pos;
    
    // the first element (index 0) will be replaced, so we
    // remember this and put it back later so it won't be lost
    int tmp = arr[pos];
    
    // perform a cycle walk (which eventually ends; so infinite loop is fine)
    while( 1 ) {
        // get the next position after pos
        next_pos = get_next_pos(pos, size, shift);
        
        // print details of cycle walk
        //printf("%d -> %d\n", pos, new_pos);
        
        // the value at next_pos will replace the value at pos
        // so move this value
        arr[pos] = arr[next_pos];
        
        // stop once the next position is going to be 0 or where we started
        if( next_pos == 0 ) break;
        
        // go to the next location
        pos = next_pos;
    }
    
    // the element that we temporarily stored earlier
    // needs to be put back to the array, currently
    // the pos variable holds the correct location to put it
    arr[pos] = tmp;
}
