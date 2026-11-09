#include <stdio.h>
#include <string.h>
#define WORD_SIZE 101
#define MAX_FRUIT 50

void clear_buffer(FILE *fp) {
    int ch;
    while( (ch = fgetc(fp)) != '\n' && ch != EOF );
}

char *trim_string(char *str) {
    str[strcspn(str, "\n")] = '\0';
    
    return str;
}

int main(void) {
    FILE *ifile = fopen("fruits.txt", "r");
    
    // safeguard
    
    // file process
    int T;
    fscanf(ifile, "%d", &T);
    
    clear_buffer(ifile);
    
    char fruits[MAX_FRUIT][WORD_SIZE];
    
    char name[WORD_SIZE];
    for(int i = 0; i < T; i++) {
        fgets(name, WORD_SIZE, ifile);
        trim_string(name);
        //printf("%s\n", name);
        
        // copy from temporary string to the array
        strcpy(fruits[i], name);
    }
    
    // confirm that all strings are stored in the array
    for(int i = 0; i < T; i++) {
        printf("%s\n", fruits[i]);
    }
    
    fclose(ifile);

    return 0;
}
