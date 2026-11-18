#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Local Person with a dynamically allocated name string (one allocation).
// This demo assumes valid input and successful allocations.

typedef struct Person_s {
    char *name;         // Holds the address of the separately allocated string.
    int year;
} Person;

void introduce(Person p);
void set_year(Person *p, int y);

int main(void) {
    // p1 is a local Person value, so use the dot operator. Its lifetime
    // ends when main returns. Only the characters need malloc.
    Person p1;
    
    char buffer[101];
    printf("Enter a name (one word): ");
    scanf("%100s", buffer);
    
    // Store the string address in p1.name. The extra byte holds the null terminator.
    p1.name = malloc( sizeof(char) * (strlen(buffer)+1) );
    strcpy( p1.name, buffer );

    printf("Enter the year: ");
    scanf("%d", &p1.year);
    
    introduce( p1 );
    
    // Free the string. The local Person is released automatically.
    free( p1.name );

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
