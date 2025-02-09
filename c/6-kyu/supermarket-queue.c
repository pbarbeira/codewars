/*
 * There is a queue for the self-checkout tills at the supermarket. Your task 
 * is write a function to calculate the total time required for all the 
 * customers to check out!
 *
 * Input
 * customers: a pointer to an array of positive integers representing the queue.
 * Each integer represents a customer, and its value is the amount of time they 
 * require to check out.
 * customers_length: the length of the array that customers points to.
 * n: a positive integer, the number of checkout tills.
 * 
 * Output
 * The function should return an integer, the total time required.
 *
 * Important
 * Please look at the examples and clarifications below, to ensure you 
 * understand the task correctly :)
 *
 * Examples
 * int customers1[] = {5, 3, 4};
 * int customers1_length = 3;
 * int n1 = 1;
 * queueTime(customers1, customers1_length, n1)
 * // should return 12
 * // because when n=1, the total time is just the sum of the times

 * int customers2[] = {10, 2, 3, 3};
 * int customers2_length = 4;
 * int n2 = 2;
 * queueTime(customers2, customers2_length, n2)
 * // should return 10
 * // because here n=2 and the 2nd, 3rd, and 4th people in the 
 * // queue finish before the 1st person has finished.

 * int customers3[] = {2, 3, 10};
 * int customers3_length = 3;
 * int n3 = 2;
 * queueTime(customers3, customers3_length, n3)
 * // should return 12
 * 
 * Clarifications
 * There is only ONE queue serving many tills, and
 * The order of the queue NEVER changes, and
 * The front person in the queue (i.e. the first element in the array/list) 
 * proceeds to a till as soon as it becomes free.
 * N.B. You should assume that all the test input will be valid, as specified 
 * above.
 * 
 * P.S. The situation in this kata can be likened to the more-computer-science-
 * related idea of a thread pool, with relation to running multiple processes 
 * at the same time: https://en.wikipedia.org/wiki/Thread_pool
*/

#include <stdio.h>
#include <stdlib.h>

int queue_time(const int *customers, int customers_length, int n){
		int acc = 0;
		int* tills = (int*) calloc(n, sizeof(int));	
    for(int i = 0; i < customers_length; i++){
			int min = tills[0], index = 0;
			for(int j = 0; j < n; j++){
				if(tills[j] < min){
					index = j;
					min = tills[j];
				}
			}
			tills[index] += customers[i];
		}
		int max = 0;
		for(int i = 0; i < n; i++){
			max = tills[i] > max ? tills[i]	: max;
		}

		return max;
}

int main(){
	const int arr[3] = {2, 3, 10};
	int res = queue_time(arr, 3, 2);

	printf("%d\n", res);

	return 0;
}
