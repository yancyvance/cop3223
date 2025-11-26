#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_WORDS 200
#define MAX_LEN 101
#define FILE_NAME_1 "words1.txt"
#define FILE_NAME_2 "words2.txt"


// COP 3223C Fall 2025
// Student Name: TODO_your_name_here
// File Name: practice9_yoursurname.c

// IMPORTANT: Rename this file using your actual surname in lowercase,
// removing any whitespace or dashes. Do not modify or remove any TODO 
// comments, as doing so will interfere with the grading system. 
// Only make changes within the function bodies. No other parts of 
// the file will be graded, so do not alter any other code.


// Function Prototypes
char *trim_string(char *str);
char *to_lower(char *str);
int populate_list(char list[MAX_WORDS][MAX_LEN], int *size,
                  int max_size, char *fname);
void print_list(char words[MAX_WORDS][MAX_LEN], int size);
int contains_word(char words[MAX_WORDS][MAX_LEN], int size, char *query);
void combine_lists(char list1[MAX_WORDS][MAX_LEN], int list1_size,
                   char list2[MAX_WORDS][MAX_LEN], int list2_size,
                   char list3[MAX_WORDS][MAX_LEN], int *list3_size);
void selection_sort(char words[MAX_WORDS][MAX_LEN], int size);


// DO NOT MODIFY THIS PORTION OF THE MAIN FUNCTION
#ifndef MAIN_FUNCTION
int main(void) {
    char list1[MAX_WORDS][MAX_LEN];  // assume size up to MAX_WORDS
    char list2[MAX_WORDS][MAX_LEN];  // assume size up to MAX_WORDS
    char list3[MAX_WORDS][MAX_LEN];  // store common words; size up to MAX_WORDS
    
    int list1_size = 0, list2_size = 0, list3_size = 0;
    
    // populate the two lists using the two input files
    int flag1 = populate_list(list1, &list1_size, MAX_WORDS, FILE_NAME_1);
    int flag2 = populate_list(list2, &list2_size, MAX_WORDS, FILE_NAME_2);
    
    // terminate the program if unsuccessful in loading either list
    if( !flag1 || !flag2 )
        return 0;

    // uncomment if needed to test, be sure to comment it back!
    //print_list(list1, list1_size);    // test if read correctly
    //print_list(list2, list2_size);    // test if read correctly
    
    // combine list1 and list2 and put the result in list3
    combine_lists(list1, list1_size, list2, list2_size, list3, &list3_size);
     
    // sort the list in ascending order
    selection_sort(list3, list3_size);
    
    // print the output list
    print_list(list3, list3_size);
    
    return 0;
}
#endif
// DO NOT MODIFY THIS PORTION OF THE MAIN FUNCTION


// Function Definitions
char *trim_string(char *str) {
    // TODO: Complete this function
    // TODO 1 BEGIN
    // get the index of the first \n in the str
    // if it is not there, it returns the length
    // of str (strlen); this is a built-in string
    // function we can use
    int pos = strcspn(str, "\n");

    // make that location the null, effectively
    // trimming the string
    str[pos] = '\0';

    // even if the function does in-place modification,
    // we are doing this pattern so that we can do
    // chaining in the function call later
    return str;    
    // TODO 1 END
}

char *to_lower(char *str) {
    // TODO: Complete this function
    // TODO 2 BEGIN
    int len = strlen(str);      // call only once!

    // convert all characters to lower
    for(int i = 0; i < len; i++) {
        str[i] = tolower(str[i]);
    }

    // even if the function does in-place modification,
    // we are doing this pattern so that we can do
    // chaining in the function call later
    return str;    
    // TODO 2 END 
}

int populate_list(char list[MAX_WORDS][MAX_LEN], int *size,
                  int max_size, char *fname) {
    // TODO: Complete this function
    // TODO 3 BEGIN
    // open the file specified by fname
    FILE *ifile = fopen(fname, "r");

    // if the file cannot be read, report problem
    if( !ifile ) return 0;
    
    // counter of words
    int i = 0;
    char word[MAX_LEN];
    
    // prevent from overflowing
    // fgets returns a char* when successful; here it's word => &word[0]
    // otherwise, it returns NULL
    while( i < max_size && fgets(word, MAX_LEN, ifile) ) {
        // notice the chain of function calls?
        // this is possible due to the design of our string functions
        strcpy( list[i++], to_lower( trim_string(word) ) );
        
        // the statement above is equivalent to the four below:
        //trim_string( word );
        //to_lower( word );
        //strcpy( list[i], word );
        //i++;
    }
    
    // close the file
    fclose(ifile);

    // update the size
    *size = i;
    
    return 1;    
    // TODO 3 END
}

void print_list(char words[MAX_WORDS][MAX_LEN], int size) {
    // TODO: Complete this function
    // TODO 4 BEGIN
    for(int i = 0; i < size; i++)
        printf("%s\n", words[i]);    
    // TODO 4 END
}

int contains_word(char words[MAX_WORDS][MAX_LEN], int size, char *query) {
    // TODO: Complete this function
    // TODO 5 BEGIN
    for(int i = 0; i < size; i++) {
        if( strcmp(words[i], query) == 0 )
            return 1;
    }
    
    return 0;    
    // TODO 5 END
}

void combine_lists(char list1[MAX_WORDS][MAX_LEN], int list1_size,
                   char list2[MAX_WORDS][MAX_LEN], int list2_size,
                   char list3[MAX_WORDS][MAX_LEN], int *list3_size) {
    // TODO: Complete this function
    // TODO 6 BEGIN
    // for every word in list1
    for(int i = 0; i < list1_size; i++) {
        // check if this word exists in list2
        if( contains_word(list2, list2_size, list1[i]) ) {
            // if it exists in list2, check further if this common word
            // exists already in the result list list3;
            // if it does not exists yet, then add it there
            if( !contains_word(list3, *list3_size, list1[i]) ) {
                // order of precedence matters!
                strcpy( list3[(*list3_size)++], list1[i] );
                
                // the statement above is equivalent to:
                //strcpy( list3[*list3_size], list1[i] );
                //*list3_size = *list3_size + 1;
            }
        }
    }  
    // TODO 6 END 
}

void selection_sort(char words[MAX_WORDS][MAX_LEN], int size) {
    // TODO: Complete this function
    // TODO 7 BEGIN
    char tmp[MAX_LEN];

    // for each location (outer loop)
    for(int i = 0; i < size-1; i++) {
        int min_idx = i;
        
        // find the min in the search space (inner loop)
        for(int j = i+1; j < size; j++) {
            if( strcmp( words[j], words[min_idx] ) < 0 ) {
                min_idx = j;
            }
        }
        
        // swap the two elements
        // recall, we cannot do assignment operation here
        // we need to call the correct function
        strcpy(tmp, words[min_idx]);
        strcpy(words[min_idx], words[i]);
        strcpy(words[i], tmp);
    }    
    // TODO 7 END
}
