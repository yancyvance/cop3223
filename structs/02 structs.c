#include <stdio.h>
#include <string.h>

typedef struct Person_s {
    char name[101];
    int year;
} Person;

void introduce(Person p);
void set_year(Person *p, int y);

int main(void) {
    FILE *ifile = fopen("people.txt", "r");
    
    // safeguard
    
    // process
    int N;
    fscanf(ifile, "%d", &N);
    
    Person people[100];
    int y;
    char buffer[101];
    
    for(int i = 0; i < N; i++) {
        fscanf(ifile, "%s %d", buffer, &y);
        
        //people[i].year = y;
        //set_year( &people[i], y );
        set_year( people+i, y );
        
        //people[i].name = buffer;
        strcpy( people[i].name, buffer );
    }
    
    for(int i = 0; i < N; i++) {
        //printf("%s %d\n", people[i].name, people[i].year);
        introduce( people[i] );
    }
    
    fclose(ifile);


    return 0;
}

void introduce(Person p) {
    printf("%s %d\n", p.name, p.year);
}

void set_year(Person *p, int y) {
    //(*p).year = y;
    p->year = y;
}
