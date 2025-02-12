/*
 * Your job is to write a function which increments a string, to create a new 
 * string.
 *
 * If the string already ends with a number, the number should be incremented 
 * by 1.
 * If the string does not end with a number. the number 1 should be appended 
 * to the new string.
 * 
 * Examples:
 *
 * foo -> foo1
 *
 * foobar23 -> foobar24
 *
 * foo0042 -> foo0043
 *
 * foo9 -> foo10
 *
 * foo099 -> foo100
 *
 * Attention: If the number has leading zeros the amount of digits should be 
 * considered.
*/

#include <stdio.h>

#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* incrementString(const char* str){
    int digit = 0;
    int exp = 1;
    int len= strlen(str);
    char* ret = (char*) calloc(len + 1, 1);
    int i = len-1;
    for(; i >=0; i--){
        if(isdigit(str[i])){
            digit += str[i] - '0' * exp;
            exp *= 10;
        }else{
            break;
        } 
    }
    printf("%d\n", digit);
    if(digit == 0){
        ret[len] = '1';
    }else{
       digit++; 
    }
    return ret;
}

int main(int argc, char* argv[]){
    if(argc != 2){
        fprintf(stderr, "Usage: ./.aout <string>\n");
        return 1;
    }
    
    char* res = incrementString(argv[1]);
    printf("%s\n", res);

    return 0;
}
