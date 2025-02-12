/*
 * A format for expressing an ordered list of integers is to use a comma 
 * separated list of either
 *
 * - individual integers
 * - or a range of integers denoted by the starting integer separated from the 
 *   end integer in the range by a dash, '-'. The range includes all integers in
 *   the interval including both endpoints. It is not considered a range unless
 *   it spans at least 3 numbers. For example "12,13,15-17"
 *
 * Complete the solution so that it takes a list of integers in increasing order
 * and returns a correctly formatted string in the range format.
 *
 * Example:
 * 
 * range_extraction((const []){-10, -9, -8, -6, -3, -2, -1, 0, 1, 3, 4, 5, 7, 8,
 * 9, 10, 11, 14, 15, 17, 18, 19, 20}, 23);
 * returns "-10--8,-6,-3-1,3-5,7-11,14,15,17-20"
 * Courtesy of rosettacode.org
 */

#include <stdio.h>
#include <stdlib.h>

char *range_extraction(const int *args, size_t n){
  char* buffer = calloc(256, 1);
	char* ptr = buffer;
	int start = 0;
	for(int i = 0; i < n; i++){
		if(i == n-1 || args[i]+1 != args[i+1]){
			if(i - start >= 2){
				ptr += sprintf(ptr, "%d-%d", args[start], args[i]);
			}else{
				for(int j = start; j <= i; j++){
					ptr += sprintf(ptr, "%d", args[j]);
					if(j != i) *ptr++ = ',';	
				}
			}
			start = i + 1;
			if(i != n - 1) *ptr++ = ',';
		}
	}	
	return buffer;
}

int main(){
	const int arr[] = {-10, -9, -8, -6, -3, -2, -1, 0, 1, 3, 4, 5, 7, 8, 9, 10, 11, 14, 15, 17, 18, 19, 20};
	
	char* res = range_extraction(arr, 23);

	printf("%s\n", res);

	return 0;
}

