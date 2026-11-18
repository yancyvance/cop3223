#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Dynamically allocated Person with a dynamically allocated name string (two allocations).
// This demo assumes valid input and successful allocations.

typedef struct Person_s {
    char *name;         // Holds the address of the separately allocated string.
    int year;
} Person;

void introduce(Person p);
void set_year(Person *p, int y);

int main(void) {
    // sizeof(Person) includes the name pointer and year. Allocate the
    // characters separately after finding out how many are needed.
    Person *p1 = malloc( sizeof(Person) );
    
    char buffer[101];
    // This input assumes a single word of at most 100 characters.
    printf("Enter a name (one word): ");
    scanf("%100s", buffer);
    // strlen counts the name characters. Add one byte for the null terminator.
    p1->name = malloc( sizeof(char) * (strlen(buffer)+1) );
    strcpy( p1->name, buffer );
    
    printf("Enter the year: ");
    scanf("%d", &p1->year);
    
    // Dereference the pointer to pass a Person value to introduce.
    introduce( *p1 );
    
    // Free the name first while p1 still gives access to its address.
    // Then free the Person itself.
    free( p1->name );
    free( p1 );

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
