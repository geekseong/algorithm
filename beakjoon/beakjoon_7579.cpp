#include <cstdio>
#include <cstring>

int mem[101];
int c[101];
int dp[10001];
int max(int a, int b){

    return a > b ? a : b;
}
int main(void){

    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 1; i<=n; i++) scanf("%d", &mem[i]);
    for(int i = 1; i<=n; i++) scanf("%d", &c[i]);

    for(int i = 1; i<=n; i++){
        for(int j = 10000; j>=c[i]; j--){
            dp[j] = max(dp[j], dp[j - c[i]] + mem[i]);
        }
    }

    for(int i = 0; i<=10000; i++){
        if(dp[i] >= m){
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}
