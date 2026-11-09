#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 10

char *trim_string(char *str) {
    str[strcspn(str, "\n")] = '\0';
    
    return str;
}

int main(void) {
    char name[BUFFER_SIZE];

    printf("Enter Name: ");
    //scanf("%9s", name);
    fgets(name, BUFFER_SIZE, stdin);
    trim_string(name);
    
    printf("%s\n", name);
    printf("Welcome!\n");

    return 0;
}
