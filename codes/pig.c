#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_LEN 101

// Function Prototype
int is_vowel(char alpha);
int begins_with_vowel(char *word);


int main(void) {
    char word[MAX_LEN];
    
    printf("Enter Word: ");
    scanf("%s", word);
    
    printf("Pig Latin: ");
    
    if( begins_with_vowel(word) )
        printf("%sway\n", word);
    else
        printf("%s%cay\n", word+1, word[0]);

    return 0;
}


// Function Definitions
int is_vowel(char alpha) {
    char v[] = {'a', 'e', 'i', 'o', 'u'};
    
    alpha = tolower(alpha);
    
    for(int i = 0; i < 5; i++)
        if( alpha == v[i] )
            return 1;
            
    return 0;
}

int begins_with_vowel(char *word) {
    int len = strlen(word);
    
    if( len > 0 )
        return is_vowel( word[0] );
    
    return 0;
}
