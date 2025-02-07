/*
 * Welcome
 *
 * In this kata you are required to, given a string, replace every letter with 
 * its position in the alphabet.
 * 
 * If anything in the text isn't a letter, ignore it and don't return it.
 *
 * "a" = 1, "b" = 2, etc.
 *
 * Example
 * Input = "The sunset sets at twelve o' clock."
 * Output = "20 8 5 19 21 14 19 5 20 19 5 20 19 1 20 20 23 5 12 22 5 15 3 12 15 3 11"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* toStr(int num){
    char* ret = (char*) malloc(3);
    if(num > 9){
        int n1 = num / 10;
        int n2 = num % 10;
        ret[0] = n1 + '0';
        ret[1] = n2 + '0';
        ret[2] = '\0';
    }else{
        ret[0] = num + '0';
        ret[1] = '\0';
    }
    return ret;
}

char* alphabet_position(const char* text){
    char* res = (char*) malloc(2 * strlen(text));
    int size = 0; 
    for(int i = 0; text[i] != '\0'; i++){
        char toConvert = text[i];
        if(isalpha(toConvert)){
            int number = tolower(toConvert) - 96;
            char* numStr = toStr(number);
            strcat(res, numStr);
            size += strlen(numStr);
            if(text[i+1] != '\0'){
                strcat(res, " ");
                size++;
            }
        }
    }
    if(res[size-1] == '\0'){
        res[size-1] = '\0';
    } else{
        res[size] = '\0';
    }

    return res;
}

int main(int argc, char* argv[]){
    if(argc != 2){
        fprintf(stderr, "Usage: ./a.out <string>\n");
        return 1;
    }

    char* res = alphabet_position(argv[1]);
    printf("%s\n", res);

    free(res);

    return 0;
}
