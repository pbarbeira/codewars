/*
 * Hamming number is a positive integer of the form (2^i)(3^j)(5^k), for some 
 * non-negative integers i, j, and k.
 *
 * Write a function that computes the nth smallest Hamming number.
 *
 * Specifically:
 *
 * The first smallest Hamming number is 1 = (2^0)(3^0)(5^0)
 * The second smallest Hamming number is 2 = (2^1)(3^0)(5^0)
 * The third smallest Hamming number is 3 = (2^0)(3^1)(5^0)
 * The fourth smallest Hamming number is 4 = (2^2)(3^0)(5^0)
 * The fifth smallest Hamming number is 5 = (2^0)(3^0)(5^1)
 * The 20 smallest Hamming numbers are given in the Example test fixture.
 *
 * Your code should be able to compute the first 5000 ( LC: 400, Clojure: 
 * 2000, Haskell: 12691, NASM, C, D, C++, Go and Rust: 13282 ) Hamming numbers 
 * without timing out.
*/

#include <stdio.h>
#include <stdlib.h>

#include <stdint.h>
#include <math.h>

void print_arr(int n, int* arr){
    for(int i = 0; i < n; i++){
        printf("%d", arr[i]);
    }
    printf("\n");

}

uint64_t three_min(uint64_t x1, uint64_t x2, uint64_t x3){
    x1 = x1 < x2 ? x1 : x2;
    x1 = x1 < x3 ? x1 : x3;
    return x1;
}

uint64_t hamber(int n){
    uint64_t* arr = (uint64_t*) calloc(n, sizeof(uint64_t));
    int i_2 = 0, i_3 = 0, i_5 = 0;
    arr[0] = 1;

    for(int i = 1; i < n; i++){
        uint64_t x_2 = arr[i_2] * 2;
        uint64_t x_3 = arr[i_3] * 3;
        uint64_t x_5 = arr[i_5] * 5;
        uint64_t min = three_min(x_2, x_3, x_5);
        arr[i] = min; 
        i_2 += min == x_2 ? 1 : 0;
        i_3 += min == x_3 ? 1 : 0;
        i_5 += min == x_5 ? 1 : 0;  
    } 

    return arr[n - 1];
}

int main(int argc, char* argv[]){
    if(argc != 2){
        fprintf(stderr, "Usage: ./a.out <integer>\n");
        return 1;
    }

    int n = atoi(argv[1]);
    printf("%lu\n", hamber(n));
    
    return 0;
}
