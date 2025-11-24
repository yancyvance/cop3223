#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 101

// Example 5: Array of pointers to dynamically allocated Person structs

typedef struct Person_s {
    char name[MAX_LEN];
    int year;
} Person;

Person **create_array(int capacity);
void destroy_array(Person **arr);
void destroy_array2(Person **arr, int size);

Person *create_person(const char *n, int y);     
void destroy_person(Person *p);
void introduce(Person *p);

int main(void) {
    // TODO 1: Ask the user how many dynamic Persons to store (N)
    int N = 3;
    
    
    // TODO 2: Dynamically allocate memory that can store N dynamic Persons
    Person **dpeople = create_array(N);
    
    // TODO 3: Best practice in the constructor
    
    
    // TODO 4: Check if malloc was successful
    if( !dpeople ) {
        printf("Error in malloc\n");
        return 0;
    }
    
    // TODO 5: Create N dynamic Persons
    dpeople[0] = create_person("John", 2000);
    
    
    // TODO 6: Introduce everyone
    introduce( dpeople[0] );
    
    
    // TODO 7: Cleanup!?
    //destroy_array( dpeople );
    
    
    // TODO 8: Why cleanup???
    destroy_array2( dpeople, N );
    
    
    return 0;
}

// TODO 4: Function approach (helpers to create/destroy)
Person **create_array(int capacity) {
    Person **arr = malloc(sizeof(Person*) * capacity);
    
    if( !arr ) return NULL;
    
    for(int i = 0; i < capacity; i++)
        arr[i] = NULL;
        
    return arr;
}

void destroy_array(Person **arr) {
    free(arr);
}

void destroy_array2(Person **arr, int size) {
    for(int i = 0; i < size; i++) {
        destroy_person( arr[i] );
    }
    
    free(arr);
}

Person *create_person(const char *n, int y) {
    Person *np = malloc(sizeof(Person));
    
    if( !np ) return NULL;
    
    strcpy(np->name, n);
    
    // validation
    if( y < 1900 || y > 3000 )
        y = 1900;
        
    np->year = y;
    
    return np;
}

void destroy_person(Person *p) {
    free(p);
}

void introduce(Person *p) {
    if( !p ) return;
    printf("Hi, I'm %s. I'm currently %d years old.\n", p->name, 2025-p->year);
}
