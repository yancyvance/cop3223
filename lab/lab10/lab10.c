#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_WORDS 2000          // Maximum number of words the list can store
#define MAX_LEN 101             // Maximum length of a word (100 chars + null)
#define FILE_NAME "words.txt"


// COP 3223C Fall 2025
// Student Name: TODO_your_name_here
// File Name: practice10_yoursurname.c

// IMPORTANT: Rename this file using your actual surname in lowercase,
// removing any whitespace or dashes. Do not modify or remove any TODO 
// comments, as doing so will interfere with the grading system. 
// Only make changes within the function bodies. No other parts of 
// the file will be graded, so do not alter any other code.


typedef struct WordFreq_s {
    char word[MAX_LEN];         // a single word
    int freq;                   // how many times it appeared
} WordFreq;

typedef struct WordList_s {
    WordFreq words[MAX_WORDS];  // array of WordFreq structs
    int size;                   // current logical size (number of elements used)
    int capacity;               // maximum number of elements allowed
} WordList;


// NOTE ON CONST USAGE:
// When a parameter is written as `const char *word`, it means the function
// is allowed to read the data pointed to by `word` but is NOT allowed to
// modify it. This helps prevent accidental changes to input strings.
// When an entire struct parameter is written as `const WordList *list`,
// the function promises not to modify the contents of the WordList.

// Function Prototypes
WordFreq create_word(const char *word);
WordList create_list(int capacity);
WordFreq *get_word(WordList *list, const char *query);
void increment_count(WordFreq *word);
void add_word(WordList *list, const char *word);
void process_word(WordList *list, char *line);
void print_list(const WordList *list);
int populate_list(WordList *list, const char *filename);
void selection_sort(WordList *list);

// Helper Functions (in case you need them)
char *to_lower(char *str);
void clear_buffer(FILE *fp);
char *trim_string(char *str);



// DO NOT MODIFY THIS PORTION OF THE MAIN FUNCTION
#ifndef MAIN_FUNCTION
int main(void) {
    // Create an empty word list with the MAX_WORDS capacity
    WordList words = create_list(MAX_WORDS);
    
    // Load words from the text file and build the frequency list
    if( !populate_list(&words, FILE_NAME) )
        return 0;
    
    // Sort by frequency (descending), breaking ties alphabetically
    selection_sort(&words);
    
    // Display results
    print_list(&words);

    return 0;
}
#endif
// DO NOT MODIFY THIS PORTION OF THE MAIN FUNCTION



// Function Definitions
WordFreq create_word(const char *word) {
    // TODO: Complete this function
    // TODO 1 BEGIN
    // Create a new WordFreq struct:
    //   1. Copy the word into the struct
    //   2. Initialize its frequency to 1
    WordFreq wf;
    
    strcpy(wf.word, word);
    wf.freq = 1;
    
    // Return the struct by value (the caller receives a copy)
    return wf;
    // TODO 1 END
}

WordList create_list(int capacity) {
    // TODO: Complete this function
    // TODO 2 BEGIN
    // Create a WordList with the given capacity (max allowed words)
    WordList list;
    
    list.capacity = capacity;
    list.size = 0;   // start empty
    
    // Return the struct by value (the caller receives a copy)
    return list;
    // TODO 2 END
}

WordFreq *get_word(WordList *list, const char *query) {
    // TODO: Complete this function
    // TODO 3 BEGIN
    // Search the list to see if the word already exists.
    // If found, return a pointer to that WordFreq.
    // If not found, return NULL.
    for(int i = 0; i < list->size; i++) {
        if( strcmp(list->words[i].word, query) == 0 )
            return list->words+i;   // Return an address (pointer arithmetic)
    }
    
    // Not found in the list
    return NULL;
    // TODO 3 END
}

void increment_count(WordFreq *word) {
    // TODO: Complete this function
    // TODO 4 BEGIN
    // Increase the frequency count of an existing word.
    // Requires a pointer so the original struct can be modified.
    word->freq = word->freq + 1;
    //(*word).freq = (*word).freq + 1;    // The same but awkward
    // TODO 4 END
}

void add_word(WordList *list, const char *word) {
    // TODO: Complete this function
    // TODO 5 BEGIN
    // Create a new WordFreq entry for this word.
    WordFreq wf = create_word(word);
    
    // Add it to the list only if we have not exceeded capacity.
    if(list->size < list->capacity)
        list->words[list->size++] = wf;   // Note the order of precedence
                                          // list->size = list->size + 1;
    // TODO 5 END
}

void process_word(WordList *list, char *line) {
    // TODO: Complete this function
    // TODO 6 BEGIN
    WordFreq *wf_ptr;
    
    // Convert the word to lowercase for uniform comparisons.
    // This normalizes "Apple" and "apple" to the same word.
    line = to_lower(line);
    
    // Check whether the word already exists in the list.
    wf_ptr = get_word(list, line);
    
    // If found (non-NULL), increment its count.
    // Otherwise, add a new WordFreq entry.
    if( wf_ptr )
        increment_count(wf_ptr);
    else
        add_word(list, line);
    // TODO 6 END
}

void print_list(const WordList *list) {
    // TODO: Complete this function
    // TODO 7 BEGIN
    // Print each word and its frequency, one pair per line.
    for(int i = 0; i < list->size; i++) {
        printf("%d %s\n", list->words[i].freq, list->words[i].word);
        // struct, access the array, then access element via index
        // which in turn is another struct, so access the field freq/word
    }
    // TODO 7 END
}

int populate_list(WordList *list, const char *filename) {
    // TODO: Complete this function
    // TODO 8 BEGIN
    // Open the file and read words into the WordList.
    FILE *ifile = fopen(filename, "r");
    
    // If the file cannot be opened, stop the program gracefully.
    if( !ifile ) return 0;
    
    int count;
    char line[MAX_LEN];
    
    // First number in the file tells how many words to read.
    fscanf(ifile, "%d", &count);
    
    // Read words one at a time, up to the count AND up to list capacity.
    for(int i = 0; i < count && list->size < list->capacity; i++) {
        // Read a word; %s ignores leading whitespace.
        fscanf(ifile, "%s", line);
        
        // Process the word (normalize, check duplicates, count it)
        process_word(list, line);
    }
    
    fclose(ifile);
    return 1;
    // TODO 8 END
}

void selection_sort(WordList *list) {
    // TODO: Complete this function
    // TODO 9 BEGIN
    // Sort the array of WordFreq using selection sort.
    // Primary key: descending frequency
    // Secondary key: alphabetical order when frequencies tie
    WordFreq tmp;

    for(int i = 0; i < list->size-1; i++) {
        int max_idx = i;
        
        // Search the unsorted portion for the best candidate.
        for(int j = i+1; j < list->size; j++) {
            // Higher frequency should come first
            if( list->words[j].freq > list->words[max_idx].freq ) {
                max_idx = j;
            }
            // If frequencies tie, use alphabetical order
            else if( list->words[j].freq == list->words[max_idx].freq ) {
                if( strcmp(list->words[j].word, list->words[max_idx].word) < 0 )
                    max_idx = j;
            }
        }
        
        // Swap the selected element into position i
        tmp = list->words[max_idx];
        list->words[max_idx] = list->words[i];
        list->words[i] = tmp;
    }
    // TODO 9 END
}



// Provided Helper Functions

char *to_lower(char *str) {
    // Convert a string to lowercase (in place)
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}

void clear_buffer(FILE *fp) {
    // Clear all characters until newline or EOF.
    int c;
    if(fp == NULL) return;
    
    while( (c = fgetc(fp)) != '\n' && c != EOF );
}

char *trim_string(char *str) {
    // Remove the first newline character from a string.
    int pos = strcspn(str, "\n");
    str[pos] = '\0';
    return str;
}
