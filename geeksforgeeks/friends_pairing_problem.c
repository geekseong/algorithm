#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_TESTCASE 101
#define MOD 1000000007

long long int ans[MAX_TESTCASE];

void proc(int n, int idx){

    long long int  memo[n+1];

    for(int i = 1; i<=n; ++i){
        if(i <= 2)
            memo[i] = i;
        else
            memo[i] = (memo[i-1] + (i-1)*memo[i-2])%((int)pow(10,9)+7);
    }

    ans[idx] = memo[n];
}
int main(void){

    int testCase;
    int n;
    scanf("%d", &testCase);

    for(int i = 0; i < testCase ; ++i){
        scanf("%d", &n);
        proc(n, i);
    }

    for(int i = 0; i<testCase; ++i)
        printf("%llu\n",ans[i]);
    return 0;
}
