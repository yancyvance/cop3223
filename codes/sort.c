#include <stdio.h>
#define ARRAY_SIZE 5

// Function Prototypes
void square(int arr[], int size);
void print_array(int arr[], int size);
void selection_sort(int arr[], int size);
void swap(int *a, int *b);
void print_array_v2(int *arr, int size);


int main(void) {
    //int nums[] = {10, 20, 30, 40, 50};
    int nums[] = {90, 20, 10, 30, 40};
      
    printf("&nums[0] = %p\n", &nums[0]);
    printf("&nums = %p\n", &nums);
    printf("nums = %p\n", nums);
    
    print_array_v2(nums, ARRAY_SIZE);
    //square( nums, ARRAY_SIZE );
    selection_sort(nums, ARRAY_SIZE); 
    print_array_v2(nums, ARRAY_SIZE);  

    return 0;
}


// Function Definitions
void square(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        arr[i] = arr[i] * arr[i];
    }
}

void print_array(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selection_sort(int arr[], int size) {
    // for loop for the rounds
    for(int i = 0; i < size; i++) {
        // for loop to find the min
        // initial guess where the min is
        int min_idx = i;
        
        for(int j = i+1; j < size; j++) {
            
            if( arr[j] < arr[min_idx] ) {
                min_idx = j;
            }
        }
        
        // swap with the left most position
        //int tmp = arr[i];
        //arr[i] = arr[min_idx];
        //arr[min_idx] = tmp;
        swap( &arr[i], &arr[min_idx] );
    }
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void print_array_v2(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        //printf("%d ", *(arr+i));
        printf("%d ", arr[i]);
    }
    printf("\n");
}
