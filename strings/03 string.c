#include <stdio.h>
#define BUFFER_SIZE 10

void clear_buffer() {
    int ch;
    while( (ch = getchar()) != '\n' && ch != EOF );
}

int main(void) {
    char word1[BUFFER_SIZE];
    char word2[BUFFER_SIZE];
    
    printf("Enter W1: ");
    scanf("%9s", word1);
    
    clear_buffer();
    
    printf("Enter W2: ");
    scanf("%9s", word2);
    
    printf("w1: %s\n", word1);
    printf("w2: %s\n", word2);


    return 0;
}
