#include <cstdio>
#include <cstring>
#include <cstdlib>

#define MOD 1000000007

long long int proc(int n, int m){

    long long int map[n][m];
    memset(map, -1, sizeof(map));

    for(int i = 0; i<n; ++i)
        map[i][0] = 1;
    for(int i = 0; i<m; ++i){
        map[0][i] = 1;
    }
    for(int i = 1; i<n; ++i){
        for(int j = 1; j<m; ++j){
            map[i][j] = map[i-1][j] + map[i][j-1] + map[i-1][j-1];
            map[i][j] %= MOD;
        }
    }


    return map[n-1][m-1];
}
int main(void){

    int n, m;
    scanf("%d %d", &n, &m);
    printf("%lld", proc(n, m));

    return 0;
}
