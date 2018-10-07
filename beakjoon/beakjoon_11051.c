#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 10007
#define MAXI 1001

//nC0 = 1
//nCr = n-1Cr + n-1Cr-1


long long int func(int n, int r){

    long long int bi[MAXI][MAXI];
    bi[1][0] = bi[1][1] = 1;

    for(int i = 2; i<=n; ++i){
        for(int j = 0; j<=i; ++j){

            if(i == j || j == 0) 
                bi[i][j] = 1;
            else
                bi[i][j] = (bi[i-1][j] + bi[i-1][j-1])%MOD;

        }
    }
    return bi[n][r];
}
int main(void){

    int n, r;
    scanf("%d %d", &n, &r);
    printf("%lld", func(n,r));
}
