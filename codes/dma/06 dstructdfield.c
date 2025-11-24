#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 101

// Example 6: One dynamically allocated Person struct with a dynamic field

typedef struct Person_s {
    char *name;
    int year;
} Person;

// TODO 0: Copy the helper functions
Person *create_person(const char *n, int y);     
void destroy_person(Person *p);
void introduce(Person *p);

int main(void) {
    // TODO 1: Dynamically allocate memory that can store a single Person
    Person *p = create_person("John", 2000);
    
    // TODO 2: Think about the behavior of create_person() and visualize!
    // TODO 3: Come up with a new strategy for create_person()
    
    
    // TODO 4: Introduce the person
    introduce(p);
    
    
    // TODO 5: Deallocate the person
    destroy_person(p);
    
    return 0;
}


Person *create_person(const char *n, int y) {
    Person *np = malloc(sizeof(Person));
    
    if( !np ) return NULL;
    
    // dynamically allocate the string and be mindful
    // of the size requirement for a string '\0' is counted
    np->name = malloc( sizeof(char) * (strlen(n)+1) );
    
    // in case it fails
    if( !np->name ) { 
        free(np);
        return NULL;
    }
    
    strcpy(np->name, n);
    
    // validation
    if( y < 1900 || y > 3000 )
        y = 1900;
        
    np->year = y;
    
    return np;
}

void destroy_person(Person *p) {
    if( !p ) return;
    
    // deallocate first the dynamic fields
    free(p->name);
    
    free(p);
}

void introduce(Person *p) {
    if( !p ) return;
    printf("Hi, I'm %s. I'm currently %d years old.\n", p->name, 2025-p->year);
}
