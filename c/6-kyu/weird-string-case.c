/*
 * Write a function that accepts a string, and returns the same string with all
 * even indexed characters in each word upper cased, and all odd indexed 
 * characters in each word lower cased. The indexing just explained is zero 
 * based, so the zero-ith index is even, therefore that character should be 
 * upper cased and you need to start over for each word.
 *
 * The passed in string will only consist of alphabetical characters and spaces
 * (' '). Spaces will only be present if there are multiple words. Words will 
 * be separated by a single space(' ').
 * 
 * Examples:
 * "String" => "StRiNg"
 * "Weird string case" => "WeIrD StRiNg CaSe"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* to_weird_case(char* string){
	int letter = 0;
	for(int i=0; string[i]!='\0'; i++){
		if(letter%2==0)string[i] = 
			toupper(string[i]);
		else 
			string[i] = tolower(string[i]);
		if(string[i] == ' ')
			letter = 0;
		else
			letter++;
	}
	return string;
}

int main(int argc, char* argv[]){
	if(argc != 2){
		fprintf(stderr, "Usage: ./a.out <string>\n");
	}
	
	char* res = (char*) malloc(strlen(argv[1]));
	res = to_weird_case(argv[1]);
	printf("%s\n", res);

	return 0;
}
