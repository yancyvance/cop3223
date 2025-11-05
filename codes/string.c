#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_LEN 101

// Function Prototypes
int get_length(char *word);
int is_vowel(char alpha);
int count_vowels(char *word);
int contains_char(char *word, char alpha);
int is_strong(char *password);


int main(void) {
    char fname[MAX_LEN];
    char lname[MAX_LEN];
    
    scanf("%s", fname);
    scanf("%s", lname);
    
    strcat(fname, lname);
    
    printf("%s\n", fname);
    
    return 0;
}


// Function Definitions
int get_length(char *word) {
    int count = 0;
    
    for(int i = 0; ; i++) {
        if( word[i] == '\0' )
            break;
        
        count++;
    }
    
    return count;
}

int is_vowel(char alpha) {
    char v[] = {'a', 'e', 'i', 'o', 'u'};
    
    alpha = tolower(alpha);
    
    for(int i = 0; i < 5; i++) {
        if( alpha == v[i] )
            return 1;
    }
    
    return 0;
}

int count_vowels(char *word) {
    int count = 0;
    //int len = get_length(word);
    int len = strlen(word);
    
    for(int i = 0; i < len; i++) {
        if( is_vowel(word[i]) )
            count++;
    }

    return count;
}

int contains_char(char *word, char alpha) {
    int len = strlen(word);
    
    for(int i = 0; i < len; i++)
        if( alpha == word[i] )
            return 1;
    
    return 0;
}

int is_strong(char *password) {
    // TODO: Homework
    
    return 0;
}
