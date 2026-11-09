#include <stdio.h>
#include <string.h>

int get_length(char *str);

int main(void) {
    /*
    char word[10] = "Hello";
    
    for(int i = 0; i < 10; i++) {
        printf("'%c' - %d\n", word[i], word[i]);
        //printf("%c", word[i]);
    }
    
    printf("'%s'\n", word);
    printf("%d\n", get_length(word));
    printf("%d\n", strlen(word));

    printf("Enter Word: ");
    scanf("%9s", word);
    
    printf("%s\n", word);
    
    for(int i = 0; i < 10; i++) {
        printf("'%c' - %d\n", word[i], word[i]);
        //printf("%c", word[i]);
    }
    
    scanf("%s", word);
    printf("%s\n", word);
    */
    
    char word2[10];
    
    // string assignment
    //word2 = "Hi";
    
    strcpy(word2, "Hi");
    
    printf("%s\n", word2);
    
    // string concatenation
    //word2 = word2 + "there";
    
    strcat(word2, "there");
    
    printf("%s\n", word2);
    
    
    char word3[10];
    char word4[10];
    
    scanf("%9s", word3);
    scanf("%9s", word4);
    
    int res = strcmp(word3, word4);
    
    if( res < 0 ) {
        printf("%s %s\n", word3, word4);
    }
    else if( res > 0 ) {
        printf("%s %s\n", word4, word3);
    }
    else {
        printf("The same!\n");
    }
    
    
    

    return 0;
}

int get_length(char *str) {
    int count = 0;
    
    for(int i = 0; str[i] != '\0'; i++) {
        count++;
    }
    
    return count;    
}
