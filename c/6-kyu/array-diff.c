/* 
 * Your goal in this kata is to implement a difference function, which subtracts 
 * one list from another and returns the result.
 * 
 * It should remove all values from list a, which are present in list b keeping 
 * their order.
 *
 *  array_diff({1, 2}, 2, {1}, 1, *z) == {2} (z == 1)
 *
 * If a value is present in b, all of its occurrences must be removed from the 
 * other:
 *
 *  array_diff({1, 2, 2, 2, 3}, 5, {2}, 1, *z) == {1, 3} (z == 2)
 *   
 * NOTE: In C, assign return array length to pointer *z
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int *array_diff(const int *arr1, size_t n1, const int *arr2, size_t n2, size_t *z) {
    int* res = calloc(n1, sizeof(int));
    int arrSize = 0;

    for(int i = 0; i < n1; i++){
        bool found = false;
        for(int j = 0; j < n2; j++){
            found |= (arr1[i] == arr2[j]);
        }
        if(!found){
            res[arrSize] = arr1[i];
            arrSize++;
        }
    }    

    res = realloc(res, sizeof(int) * arrSize);
    *z = arrSize;
    
    return res;  
}

int main(){
    const int arr1[14] = {1 , 3, -4, 11, -5, 5, 9, 10, 11, -2, 7, 0, -5, 20};
    const int arr2[13] = {3, 6, 9, 20, 4, 23, 11, -1, 14, 20, -3, 0, 2};

    size_t z;
    const int* res = array_diff(arr1, 14, arr2, 13, &z);

    printf("Size: %lu\n", z);
    for(int i = 0; i < z; i++){
        printf("%d ", res[i]);
    }
    printf("\n");

    return 0;
}
