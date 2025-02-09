/*
 * Task
 * You will be given an array of numbers. You have to sort the odd numbers in 
 * ascending order while leaving the even numbers at their original positions.
 *
 * Examples
 * [7, 1]  =>  [1, 7]
 * [5, 8, 6, 3, 4]  =>  [3, 8, 6, 5, 4]
 * [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]  =>  [1, 8, 3, 6, 5, 4, 7, 2, 9, 0]
*/

#include <stdio.h>
#include <stdlib.h>

void print_array(int n, int arr[n]){
	for(int i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

}

int is_odd(int n){
	return n%2 == 1 || n%2 == -1;
}

void sort_array(size_t n, int arr[n]){
	for(int i=0; i<n; i++){
		if(is_odd(arr[i])){
			int index = i, min = arr[i]; 
			for(int j=i+1; j<n; j++){
				if(is_odd(arr[j]) && arr[j] < min){
					min = arr[j];
					index = j;
				}
			}
			arr[index] = arr[i];
			arr[i] = min;	
		}
	}
}

int main(){
	int arr[6] = {5,3,2,8,-1,4};
	sort_array(6, arr);
	
	print_array(6, arr);	
	return 0;
}
