#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Dynamically allocated array of Person values, each with a dynamically allocated name string.
// This demo assumes valid input and successful allocations.

typedef struct Person_s {
    char *name;         // Holds the address of the separately allocated string.
    int year;
} Person;

void introduce(Person p);
void set_year(Person *p, int y);

int main(void) {
    int N;
    
    printf("Enter the number of people: ");
    scanf("%d", &N);
    
    // Allocate one contiguous block of N Person values.
    // people points to the first Person. people[i] is a Person, so use a dot.
    Person *people = malloc( sizeof(Person) * N );

    char buffer[101];
    
    for(int i = 0; i < N; i++) {
        printf("Enter a name (one word): ");
        scanf("%100s", buffer);
        
        // Each Person already has room for its name pointer. Allocate its
        // characters separately, including one byte for the null terminator.
        people[i].name = malloc( sizeof(char) * (strlen(buffer)+1) );
        strcpy( people[i].name, buffer );

        printf("Enter the year: ");
        scanf("%d", &people[i].year);
        
        introduce( people[i] );
    }
    
    // Free each name while the Person array is still available.
    // A single free of people then releases all N Person values.
    for(int i = 0; i < N; i++) {
        free( people[i].name );
    }
    
    free( people );

    return 0;
}

// p is a copy of the Person. Its name pointer is copied, so both
// structures refer to the same characters.
void introduce(Person p) {
    printf("%s %d\n", p.name, p.year);
}

// Passing the address lets this function update the original Person.
// p->year is shorthand for (*p).year.
void set_year(Person *p, int y) {
    //p.year = y;
    //(*p).year = y;
    p->year = y;
}
