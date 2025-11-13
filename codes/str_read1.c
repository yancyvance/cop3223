#include <stdio.h>
#include <string.h>
#define MAX_LEN 101

// Function Prototypes
char *trim_string(char *str);

// Design Pattern 1: Unknown Count

int main(void) {
    FILE *ifile = fopen("fruits.txt", "r");
    char line[MAX_LEN];

    // fgets() returns NULL if either done or there is an issue
    // fscanf() returns EOF when done
    while( fgets(line, MAX_LEN, ifile) ) {
        trim_string(line);
        
        printf("Line: %s\n", line);
    }
    
    fclose(ifile);

    return 0;
}


char *trim_string(char *str) {
    int pos = strcspn(str, "\r\n");
    
    str[pos] = '\0';
    
    return str;
}
