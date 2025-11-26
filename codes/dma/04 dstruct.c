#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 101

// Example 4: One dynamically allocated Person struct

typedef struct Person_s {
    char name[MAX_LEN];
    int year;
} Person;

Person *create_person(const char *n, int y);     // TODO 0: We want name to be read-only
void destroy_person(Person *p);
void introduce(Person *p);     // TODO 0: Recall, we want to be efficient

int main(void) {
    // TODO 1: Dynamically allocate memory that can store a single Person
    Person *p = create_person("John", 2000);
    
    // TODO 2: Think about the behavior of create_person() and visualize!
    // TODO 3: It used to return Person. Come up with a new strategy for create_person()
    
    
    // TODO 4: Introduce the person
    introduce(p);
    
    
    // TODO 5: Deallocate the person
    destroy_person(p);
    
    return 0;
}

// TODO 4: Function approach (helpers to create/destroy)

Person *create_person(const char *n, int y) {
    Person *np = malloc(sizeof(Person));
    
    if( !np ) return NULL;
    
    strcpy(np->name, n);
    
    // validation
    if( y < 1900 || y > 3000 )
        y = 1900;
        
    np->year = y;
    
    // return a reference
    return np;
}

void destroy_person(Person *p) {
    free(p);
}

void introduce(Person *p) {
    if( !p ) return;
    printf("Hi, I'm %s. I'm currently %d years old.\n", p->name, 2025-p->year);
}
