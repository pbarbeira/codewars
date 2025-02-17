/*
 * Given the string representations of two integers, return the string 
 * representation of the sum of those integers.
 *
 * For example:
 *
 * strsum("1", "2") => 3
 * A string representation of an integer will contain no characters besides 
 * the ten numerals "0" to "9".
 *
 * I have removed the use of BigInteger and BigDecimal in java
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* remove_trailing(int size, const char* str){
    int start = 0;
    while(str[start] == '0'){
        start++;
    }
    if(size == start){
        char* res = (char*) malloc(2);
        res[0] = '0';
        res[1] = '\0';
        return res;
    }
    char* res = (char*) malloc(size - start);
    for(int i = start; i < size; i++){
        res[i-start] = str[i];
    }
    res[size-start] = '\0';
    return res;
}

char* reverse(int size, const char* str){
    char* res = (char*) malloc(size);
    for(int i = 0; i < size; i++){
        res[i] = str[size - 1 - i];
    }
    res[size] = '\0';
    return res;
}


char* strsum(const char* a, const char* b){
    int sizeA = strlen(a);
    int sizeB = strlen(b);
    int size = sizeA > sizeB ? sizeA : sizeB;
    char* res = (char*) malloc(size + 1);
    
    char* tmpA = reverse(sizeA, a);
    char* tmpB = reverse(sizeB, b); 
    
    int carry = 0;
    for(int i = 0; i < size; i++){
        int value = carry;
        if(i < sizeA){
            value += tmpA[i] - '0';
        }
        if(i < sizeB){
            value += tmpB[i] - '0';
        }
        res[i] = (value % 10) + '0';
        carry = value / 10;
    }

    if(carry){
        res[size] = '1';
        size++;
    } 

    free(tmpA);
    free(tmpB);
    return remove_trailing(size, reverse(size, res));
}

int main(int argc, char* argv[]){
    if(argc != 3){
        fprintf(stderr, "Usage: ./a.out \"<integer>\" \"<integer>\"");
        return 1;
    }

    char* res = strsum(argv[1], argv[2]);
    printf("%s\n", res);

    free(res);

    return 0;
}


