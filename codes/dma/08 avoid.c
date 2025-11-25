#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100

// Example 8: Avoid this!

int main(void) {
    // Notice that this pointer is uninitialized
    char *str;
    
    // Therefore, this call will lead to undefined behavior
    // because str is not properly allocated
    strcpy(str, "Hello");
    printf("%s\n", str);
    
    // Fix the issue above
    
    // TODO: How do we fix this? We must allocate the space
    // somewhere before line 13 in this code
    // str = malloc(sizeof(char) * (MAX_LEN+1));
    
    // strcpy(str, "Hello");
    // printf("%s\n", str);
    
    // TODO: Don't forget to free the space afterward
    // free(str);

    return 0;
}