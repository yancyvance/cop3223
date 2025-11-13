#include <stdio.h>
#include <string.h>
#define MAX_SIZE 10
#define MAX_LEN 101
#define FILE_NAME "people.txt"

// Function Prototypes
char *trim_string(char *str);
void clear_buffer(FILE *fp);


int main(void) {
    // Parallel Arrays
    char names[MAX_SIZE][MAX_LEN];
    int years[MAX_SIZE];
    
    FILE *ifile = fopen(FILE_NAME, "r");
    
    if( !ifile ) return -1;
    
    // read the first line
    int count;
    
    fscanf(ifile, "%d", &count);
    
    for(int i = 0; i < count; i++) {
        // clear the buffer
        clear_buffer(ifile);
        
        // read a string
        fgets( names[i], MAX_LEN, ifile );
        
        // trim string
        trim_string( names[i] );
        
        // read an int
        fscanf(ifile, "%d", &years[i]);
    }
    
    fclose(ifile);
    
    for(int i = 0; i < count; i++) {
        printf("%d %s\n", 2025-years[i], names[i]);
    }
    
    // TODO: Print the name of the oldest person
    
    
    
    return 0;
}


char *trim_string(char *str) {
    int pos = strcspn(str, "\r\n");
    
    str[pos] = '\0';
    
    return str;
}

void clear_buffer(FILE *fp) {
    int ch;
    while( (ch = fgetc(fp)) != '\n' && ch != EOF );
}
