#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXI 22
#define TESTCASE_MAXI 100

int ans[TESTCASE_MAXI];

int max(int a, int b){

    return a > b ? a : b;
}
void proc(int n, int m, int idx){

    int M[MAXI][MAXI];
    int memo[MAXI][MAXI];
    int ans_max = 0;

    memset(memo, 0, sizeof(memo));
    memset(M, 0, sizeof(M));

    for(int i = 1; i<=n; ++i){
        for(int j = 1; j<=m; ++j){
            scanf("%d", &M[i][j]);
        }
    }

    for(int i = 1; i<=n; ++i)
        memo[i][1] = M[i][1];

    for(int j = 2; j<=m; ++j){
        for(int i = 1; i<=n; ++i){
            memo[i][j] = max(memo[i-1][j-1], max(memo[i][j-1], memo[i+1][j-1])) + M[i][j];
        }
    }

    for(int i = 1; i<=n; ++i)
        ans_max = max(ans_max, memo[i][m]);
    
    ans[idx] = ans_max;

}
int main(void){

    int testCase;
    int n, m;
    
    scanf("%d", &testCase);
    for(int i = 0; i<testCase; ++i){
        scanf("%d %d", &n, &m);
        proc(n, m, i);
    }
    
    for(int i = 0; i<testCase; ++i)
        printf("%d\n", ans[i]);
    
    return 0;
}
