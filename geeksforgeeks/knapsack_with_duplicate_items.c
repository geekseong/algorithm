#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TESTCASE 100
#define MAX_ITEM 1001

int val[MAX_ITEM];
int weight[MAX_ITEM];
int ans[MAX_TESTCASE];
int memo[MAX_ITEM][MAX_ITEM];

int max(int a ,int b){

    return (a > b) ? a : b;
}
int proc(int n, int w){

    if(n <= 0)
        return memo[n][w] = 0;

    if( memo[n][w] == -1 ){
        int len = w/weight[n-1];
        int ret = 0;

        for(int i = 0; i<=len; ++i){
            memo[n][w] = max(memo[n][w], proc(n-1, w-(weight[n-1]*i)) + val[n-1]*i);
        }
    }
    return memo[n][w];

}
int main(void){

    int testcase;
    int n, w;

    scanf("%d", &testcase);
    for(int i = 0; i<testcase; ++i){

        memset(memo, -1, sizeof(memo));
        
        scanf("%d %d", &n, &w);
        for(int i = 0; i<n; ++i)    scanf("%d", &val[i]);
        for(int i = 0; i<n; ++i)    scanf("%d", &weight[i]);

        ans[i] = proc(n, w);
    }

    for(int i = 0; i<testcase; ++i)
        printf("%d\n", ans[i]);
    return 0;
}
