#include <stdio.h>

void clear_buffer() {
    int ch;
    while( (ch = getchar()) != '\n' && ch != EOF );
}

int main(void) {
    int num;
    char alpha;
    
    printf("Enter Number: ");
    scanf("%d", &num);
    
    clear_buffer();
    
    printf("Enter Letter: ");
    scanf("%c", &alpha);
    
    printf("Num: %d Letter: %c\n", num, alpha);
    
    return 0;
}
