#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Dynamically allocated Person with an embedded name array (one allocation).
// This demo assumes valid input and successful allocations.

typedef struct Person_s {
    // These 101 chars are part of every Person. sizeof(Person) includes them.
    char name[101];
    int year;
} Person;

void introduce(Person p);
void set_year(Person *p, int y);

int main(void) {
    // Allocate room for one complete Person. p1 holds its address.
    Person *p1 = malloc( sizeof(Person) );
    
    char buffer[101];
    // This input assumes a single word of at most 100 characters.
    printf("Enter a name (one word): ");
    scanf("%100s", buffer);
    
    // p1->name means (*p1).name. strcpy copies the characters into
    // the array already inside the allocated Person.
    strcpy( p1->name, buffer );
    
    printf("Enter the year: ");
    scanf("%d", &p1->year);
    
    // Dereference the pointer to pass a Person value to introduce.
    introduce( *p1 );
    
    // This one free releases both members along with the structure.
    free( p1 );

    return 0;
}

// p is a copy of the argument. The embedded name array is copied too.
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
