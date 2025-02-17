/* The drawing shows 6 squares the sides of which have a length of 1, 1, 2, 3, 
 * 5, 8. It's easy to see that the sum of the perimeters of these squares is : 
 * 4 * (1 + 1 + 2 + 3 + 5 + 8) = 4 * 20 = 80 
 *
 * Could you give the sum of the perimeters of all the squares in a rectangle 
 * when there are n + 1 squares disposed in the same manner as in the drawing:
 *
 * [Drawing of squares in a fibonacci sequence]
 *
 * Hint:
 * See Fibonacci sequence
 *
 * Ref:
 * http://oeis.org/A000045
  *  //
  *  //The function perimeter has for parameter n where n + 1 is the number of 
  *  //squares (they are numbered from 0 to n) and returns the total perimeter 
  *  //of all the squares.
  *  //
  *  //perimeter(5)  should return 80
  *  //perimeter(7)  should return 216
  */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;

ull perimeter(int n){
    ull acc=0;
    
    ull* arr=(ull*)calloc(n+1, sizeof(ull));
    arr[0]=1;
    arr[1]=1;

    for(int i=0; i<=n; i++){
        if(arr[i]==0){
            arr[i]=arr[i-1]+arr[i-2];
        }
        acc+=arr[i];
    }
    return 4*acc;
}

int main(int argc, char* argv[]){
    if(argc!=2){
        fprintf(stderr, "Usage: ./a.out <integer>");
    }

    int n=atoi(argv[1]);
    int res=perimeter(n);

    printf("%d\n", res);

    return 0;
}
