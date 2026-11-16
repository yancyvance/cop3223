#include <stdio.h>

typedef struct Person_s {
    char name[101];
    int year;
} Person;

void introduce(Person p);
void set_year(Person *p, int y);

int main(void) {
    Person p1 = {"John", 2000};
    Person p2 = {"Jane", 2001};
    
    //printf("%s %d\n", p1.name, p1.year);
    //printf("%s %d\n", p2.name, p2.year);
    introduce( p1 );
    introduce( p2 );
    
    set_year( &p2, 2002 );
    introduce( p2 );

    Person p3;
    
    printf("Enter Name: ");
    scanf("%s", p3.name);
    
    printf("Enter Year: ");
    scanf("%d", &p3.year);
    
    printf("%s %d\n", p3.name, p3.year);
    
    Person p4;
    p4 = p3;
    
    printf("%s %d\n", p4.name, p4.year);
    
    p4.year = 2006;
    
    printf("%s %d\n", p4.name, p4.year);
    printf("%s %d\n", p3.name, p3.year);
    

    return 0;
}

void introduce(Person p) {
    printf("%s %d\n", p.name, p.year);
}

void set_year(Person *p, int y) {
    //p.year = y;           // invalid because p is now a pointer to a Person
    //(*p).year = y;
    p->year = y;
}