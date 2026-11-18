#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Dynamically allocated array of Person pointers, with a dynamically allocated Person
// and name string for each element.
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
    
    // Allocate N slots of type Person *. people points to the first slot.
    // Each people[i] will hold the address of a separately allocated Person.
    Person **people = malloc( sizeof(Person *) * N );
    
    char buffer[101];
    
    for(int i = 0; i < N; i++) {
        // Allocate the Person and save its address in slot i. Because
        // people[i] is a pointer, use -> to reach that Person's members.
        people[i] = malloc( sizeof(Person) );
        
        // This input assumes a single word of at most 100 characters.
        printf("Enter a name (one word): ");
        scanf("%100s", buffer);
        // Allocate the characters separately. The extra byte holds the null terminator.
        // Follow the addresses from people to people[i] to people[i]->name.
        people[i]->name = malloc( sizeof(char) * (strlen(buffer)+1) );
        strcpy( people[i]->name, buffer );
        
        printf("Enter the year: ");
        scanf("%d", &people[i]->year);
        
        // Dereference the pointer to pass a Person value to introduce.
        introduce( *people[i] );
    }
    
    // Free from the innermost block outward. For each slot, free its
    // name string, then its Person. Free the pointer array last.
    for(int i = 0; i < N; i++) {
        free( people[i]->name );
        free( people[i] );
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
