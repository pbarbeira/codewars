/*
 * Jamie is a programmer, and James' girlfriend. She likes diamonds, and wants 
 * a diamond string from James. Since James doesn't know how to make this 
 * happen, he needs your help.
 *
 * Task
 * You need to return a string that looks like a diamond shape when printed on 
 * the screen, using asterisk (*) characters. Trailing spaces should be removed,
 * and every line must be terminated with a newline character (\n).
 *
 * Return null/nil/None/... if the input is an even number or negative, as it is
 * not possible to print a diamond of even or negative size.
 *
 * Examples
 * A size 3 diamond:
 *
 *  *
 * ***
 *  *
 * ...which would appear as a string of " *\n***\n *\n"
 *
 * A size 5 diamond:
 * 
 *   *
 *  ***
 * *****
 *  ***
 *   *
 * ...that is:
 *
 * "  *\n ***\n*****\n ***\n  *\n"
*/

#include <stdio.h>
#include <stdlib.h>

char* diamond(int n){
	if(n < 0 || n % 2 == 0){
		return NULL;
	}
	char* res = calloc(n*n);
	int size = 0; inc = -1; trail = n/2;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < trail; j++){
			
		}
		if(trail == 0){
			inc = +1;
		}
	}

	res = realloc(res, size+1);
	res[size] = '\0';
	return res;	
}

int main(char argc, char* argv[]){
	if(argc != 2){
		fprintf(stderr, "Usage: ./a.out <integer>\n");
	}

	char* res = diamond(atoi(argv[1]));
	if(res != NULL){
		printf("%s\n", res);
	}else{
		fprintf(stderr, "Invalid input\n");
	}
	return 0;
}
