#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool is_pangram(const char *str_in) {
    bool arr[26];
    for(int i = 0; str_in[i] != '\0'; i++){
        if(isalpha(str_in[i])){
            int index = tolower(str_in[i])-97;
            if(!arr[index]) arr[index] = true;
        }
    }      
    bool acc = true;
    for(int i = 0; i < 26; i++){
        acc &= arr[i];
    }
    return acc;
}

int main(int argc, char* argv[]){
    if(is_pangram(argv[1])){
        printf("True\n");
    }else{
        printf("False\n");
    }

    return 0;
}
