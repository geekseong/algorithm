// 백준 2163번

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 99999999
#define MAXI 301

int min(int a, int b){
    return a > b ? b : a;
}

int proc(int n, int m){

    static int memo[MAXI][MAXI];
    
    if(n  == 1 && m == 1) 
        return memo[n][m] = 0;

    if( !memo[n][m] ){ 

        memo[n][m] = INF;
        for(int i = 1; i<n; ++i)
            memo[n][m] = min(memo[n][m], proc(i, m) + proc(n-i, m) + 1);
        for(int i = 1; i<m; ++i)
            memo[n][m] = min(memo[n][m], proc(n, i) + proc(n, m-i) + 1);
    }

    return memo[n][m];
}
int main(void){

    int n, m;
    scanf("%d %d", &n, &m);
    printf("%d", proc(n, m));
}
