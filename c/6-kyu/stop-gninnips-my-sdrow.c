/*
 * Write a function that takes in a string of one or more words, and returns the
 * same string, but with all words that have five or more letters reversed (Just 
 * like the name of this Kata). Strings passed in will consist of only letters 
 * and spaces. Spaces will be included only when more than one word is present.
 *
 * Examples:
 *
 * \"Hey fellow warriors\"  --> \"Hey wollef sroirraw\" 
 * \"This is a test        --> \"This is a test\" 
 * \"This is another test\" --> \"This is rehtona test\"
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void spin_words(const char* sentence, char* result){
    result[0] = '\0';
    char* str = malloc(strlen(sentence));
    strcpy(str, sentence);

    char* tok = strtok(str, " ");
    while(tok != NULL){
        int len = strlen(tok);
        if(len < 5){
            strcat(result, tok);
        }else{
            char* reverse = malloc(strlen(tok));
            for(int i = 0; i < len; i++){
                reverse[i] = tok[len - 1 - i];
            }
            strcat(result, reverse);
            free(reverse);
        }
        tok = strtok(NULL, " ");
        if(tok != NULL){
            strcat(result, " ");        
        }
    }
    free(str);
}

int main(int argc, char* argv[]){
    if(argc != 2){
        fprintf(stderr, "Usage: ./a.out <sentence>\n");
        return 1;
    }

    char* res = (char*) malloc(strlen(argv[1]));
    spin_words(argv[1], res);

    printf("%s\n", res);
    
    free(res);

    return 0;
}
