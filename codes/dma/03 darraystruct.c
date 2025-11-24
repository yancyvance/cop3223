#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 101

// Example 3: Dynamically allocated array of Person structs

typedef struct Person_s {
    char name[MAX_LEN];
    int year;
} Person;

// Function Prototypes
Person *create_array(int capacity);
void destroy_array(Person *arr);

Person create_person(const char *n, int y);     // TODO 0: We want name to be read-only
void introduce(Person *p);     // TODO 0: Recall, we want to be efficient

int main(void) {
    // TODO 1: Ask the user how many numbers to store (N)
    int N = 3;
    
    
    // TODO 2: Dynamically allocate memory that can store N int values
    Person *people = create_array(N);
    
    
    // TODO 3: Check if malloc was successful
    if( !people ) {
        printf("Error in malloc\n");
        return 0;
    }
    
    // TODO 4: Create the people!
    people[0] = create_person("John", 2000);
    people[1] = create_person("Bob", 2005);
    people[2] = create_person("Jane", 2010);
    
    
    // TODO 5: Introduce everyone!
    for(int i = 0; i < N; i++) {
        introduce( people+i );
    }
    
    // TODO 6: Deallocate the array
    destroy_array(people);
    

    return 0;
}


Person *create_array(int capacity) {
    return malloc(sizeof(Person) * capacity);
}

void destroy_array(Person *arr) {
    free(arr);
}

Person create_person(const char *n, int y) {
    Person np;
    
    strcpy(np.name, n);
    
    // validation
    if( y < 1900 || y > 3000 )
        y = 1900;
        
    np.year = y;
    
    // return by value
    return np;
}

void introduce(Person *p) {
    if( !p ) return;
    printf("Hi, I'm %s. I'm currently %d years old.\n", p->name, 2025-p->year);
}
