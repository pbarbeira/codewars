#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double doubles(int maxk, int maxn){
    double acc = 0;
    for(int i = 1 ; i<=maxk; i++){
        for(int j = 1; j <= maxn; j++){
        acc += 1.0 / (i * pow((j + 1), 2 * i));
        }
    }
    return acc;
}

int main(int argc, char* argv[]){
    if(argc!=3){
        fprintf(stderr, "Usage: ./a.out <integer> <integer>\n");
        return 1;
    }

    int maxk = atoi(argv[1]);
    int maxn = atoi(argv[2]);

    double res = doubles(maxk, maxn);
    printf("%lf\n", res);

    return 0;
}

