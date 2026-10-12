#include <stdio.h>

// Function Prototypes
void print_array(const int arr[], int size);
void print_reverse_array(int arr[], int size);
int compute_sum(int arr[], int size);
double compute_average(int arr[], int size);
int search_value(int arr[], int size, int query);
void reverse_array(int arr[], int size);


int main(void) {
    int nums[5] = {10, 20, 30, 40, 50};
    
    printf("Enter 5 Numbers: ");
    
    for(int i = 0; i < 5; i++) {
        scanf("%d", &nums[i]);
    }

    print_reverse_array( nums, 5 );
    
    int s = compute_sum(nums, 5);
    printf("Sum: %d\n", s);
    
    double a = compute_average(nums, 5);
    printf("Average: %.2lf\n", a);
    
    int q;
    printf("Enter Query: ");
    scanf("%d", &q);
    
    //int r = search_value( nums, 5, q );
    
    if( search_value( nums, 5, q ) ) {
        printf("Found");
    }
    else {
        printf("Not Found");
    }
    
    printf("\n");
    
    print_array(nums, 5);
    reverse_array(nums, 5);
    print_array(nums, 5);
    
    return 0;
}

void print_array(const int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void print_reverse_array(int arr[], int size) {
    for(int i = size-1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int compute_sum(int arr[], int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum = sum + arr[i];
    }
    return sum;
}

double compute_average(int arr[], int size) {
    int s = compute_sum( arr, size );
    
    return (double)s / size;
}

int search_value(int arr[], int size, int query) {
    for(int i = 0; i < size; i++) {
        if( arr[i] == query ) {
            return 1;
        }
    }
    return 0;
}

void reverse_array(int arr[], int size) {
    for(int i = 0; i < size/2; i++) {
        int tmp = arr[i];
        arr[i] = arr[size-1-i];
        arr[size-1-i] = tmp;
    }
}
