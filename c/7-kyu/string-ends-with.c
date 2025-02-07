#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool solution(const char* string, const char* ending){
    int offset = strlen(string) - strlen(ending);
    for(int i = strlen(ending - 1); i >= 0; i--){
        if(string[i + offset] != ending[i]){
            return false;
        }
    }   
   return true; 
}

int main(int argc, char* argv[]){
    printf("%d", 'a');    

    return 0;
}
