/* 
 * Complete the function that
 *
 * - accepts two integer arrays of equal length
 * - compares the value each member in one array to the corresponding member 
 *   in the other
 * - squares the absolute value difference between those two values
 * - and returns the average of those squared absolute value difference between 
 *   each member pair.
 * 
 * Examples
 * [1, 2, 3], [4, 5, 6]              -->   9   because (9 + 9 + 9) / 3
 * [10, 20, 10, 2], [10, 25, 5, -2]  -->  16.5 because (0 + 25 + 25 + 16) / 4
 * [-1, 0], [0, -1]                  -->   1   because (1 + 1) / 2
*/

#include <stdio.h>
#include <stddef.h>
//could've used math.h

double mean_square_error(size_t n, const int a[n], const int b[n]) {
	double acc = 0;
	for(int i = 0; i < n; i++){
		int diff = a[i] - b[i];
		acc += diff * diff;
	}
	return acc / n;
}

int main(){
	int arr1[3] = {1,2,3};
	int arr2[3] = {4,5,6};

	double res = mean_square_error(3, arr1, arr2);

	printf("%f\n", res);

	return 0;
}
