#include <stdio.h>
#define NUM_COUNT 5

// Function Prototypes
int compute_sum(int arr[], int size);
double compute_average(int arr[], int size);
int find_value(int arr[], int size, int query);
void print_array(int arr[], int size);
void reverse_array(int arr[], int size);        // uses while loop
void reverse_array_v2(int arr[], int size);     // uses for loop


int main(void) {
    int nums[NUM_COUNT];
    
    // Task 1: Ask the user to enter 5 numbers
    printf("Enter %d Numbers: ", NUM_COUNT);
    
    for(int i = 0; i < NUM_COUNT; i++) {
        scanf("%d", &nums[i]);
    }
    
    // Task 2: Print the numbers in reverse
    for(int i = NUM_COUNT-1; i >= 0; i--) {
        printf("%d ", nums[i]);
    }
    
    printf("\n");
    printf("Sum: %d\n", compute_sum(nums, NUM_COUNT) );
    printf("Average: %.2lf\n", compute_average(nums, NUM_COUNT) );
    
    
    int query;
    printf("Enter Query: ");
    scanf("%d", &query);
    
    int found = find_value( nums, NUM_COUNT, query );
    
    if( !found )
        printf("Not ");
    printf("Found\n");
    
    //reverse_array(nums, NUM_COUNT);
    reverse_array_v2(nums, NUM_COUNT);
    
    // confirm change
    print_array(nums, NUM_COUNT);
    
    return 0;
}


// Function Definitions
int compute_sum(int arr[], int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum = sum + arr[i];
    }
    return sum;
}

double compute_average(int arr[], int size) {
    return (double)compute_sum( arr, size ) / size;
}

int find_value(int arr[], int size, int query) {
    for(int i = 0; i < size; i++) {
        int tmp = arr[i];
        
        if( tmp == query ) {
            return 1;
        }
    }
    
    return 0;
}

void print_array(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void reverse_array(int arr[], int size) {
    int i = 0;
    
    while( i < size-1-i ) {
        int tmp = arr[i];
        arr[i] = arr[size-1-i];
        arr[size-1-i] = tmp;
        
        i++;
    }
}

void reverse_array_v2(int arr[], int size) {
    for(int i = 0; i < size/2; i++) {
        int tmp = arr[i];
        arr[i] = arr[size-1-i];
        arr[size-1-i] = tmp;
    }
}
