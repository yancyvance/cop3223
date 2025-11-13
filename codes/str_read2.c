#include <stdio.h>
#include <string.h>
#define MAX_LEN 101

// Function Prototypes
void clear_buffer(FILE *fp);
char *trim_string(char *str);

// Design Pattern 2: Known Count

int main(void) {
    FILE *ifile = fopen("fruits2.txt", "r");
    int count;
    char line[MAX_LEN];
    
    fscanf(ifile, "%d", &count);
    printf("Count: %d\n", count);
    
    // clear the buffer when reading string immediately
    // after a number
    clear_buffer(ifile);
    
    for(int i = 0; i < count; i++) {
        fgets(line, MAX_LEN, ifile);
        
        trim_string(line);
        
        printf("Line: %s\n", line);
    }
    
    fclose(ifile);

    return 0;
}

void clear_buffer(FILE *fp) {
    int c;
    if(fp == NULL) return;
    
    while( (c = fgetc(fp)) != '\n' && c != EOF );
}

char *trim_string(char *str) {
    int pos = strcspn(str, "\n");
    
    str[pos] = '\0';
    
    return str;
}
